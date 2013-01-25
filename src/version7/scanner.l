%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "userdef.h"
#include "node.h"
#include "y.tab.h"
int column=0; 
int lineno=1;
int MAX=65526;
extern char sBuff[10][20];
extern int iBuffX;
extern int iBuffY;
extern int iMaxIndex;
extern int iCurIndex;
struct VarDefine G_Def[MAX_DEFS];            
char G_sBuff[MAX_BUFF_ROWS][MAX_BUFF_COLS];   
int G_iBuffRowCount=0;       /* 当前语句行数 */
int G_iBuffColCount=0;       /* 当前语句列数 */
void count(); /* Function that counts the current column */
void rubyprint(char s[]); /* Function that prints the string */
void yyerror(char *);
void add_buff(char *);
extern void add_var(char *);
extern VarIndex strMem[10000];
%}
F ([0-9]+\.[0-9]*)
I ([0-9]+)
S (\"[^\n\"]*\")
ID ([$@]?[a-zA-Z_][a-zA-Z_0-9]*)
D ([a-zA-Z][a-zA-Z0-9_]*)
%%

{I}  {count();yylval.ival = atof(yytext);add_buff(yytext);return INT;}
{F}  {count();yylval.fval = atof(yytext);add_buff(yytext);return FLOAT;}
{S}  {count();yylval.sval = (char*)malloc(sizeof(char)*(strlen(yytext)+1));strcmp(yylval.sval,yytext);add_buff(yytext); return STRING;}


"return" { count(); yylval.index = RETURN - USER_DEF_NUM; G_Def[yylval.index].name="return";add_buff(yytext);  return(RETURN); }
"class"  { count();  yylval.index = CLASS - USER_DEF_NUM; G_Def[yylval.index].name="class";  add_buff(yytext);return(CLASS); }
"def"    { count();  yylval.index = DEF - USER_DEF_NUM; G_Def[yylval.index].name="def";  add_buff(yytext);return(DEF); }
"in"     { count();  yylval.index = IN - USER_DEF_NUM; G_Def[yylval.index].name="in";  add_buff(yytext);return(IN); }

".."	 { count(); return(TO); }
"&&"     { count(); return(AND); }
"||"     { count(); return(OR); }
";"	 { count(); return(';'); }
","	 { count(); return(','); }

[\n]  {G_iBuffColCount=0;G_iBuffRowCount++;lineno++; column = 0; return ('\n');} /* 回车 */

"for"    {count();yylval.index = FOR - USER_DEF_NUM;  G_Def[yylval.index].name="for";add_buff(yytext);   return FOR; }
"while"  {count();yylval.index = WHILE -USER_DEF_NUM; G_Def[yylval.index].name="while";add_buff(yytext);  return WHILE;}
"if"     {count();yylval.index = IF - USER_DEF_NUM;   G_Def[yylval.index].name="if";add_buff(yytext);    return IF;}
"else"   {count();yylval.index = ELSE - USER_DEF_NUM; G_Def[yylval.index].name="else"; add_buff(yytext);  return ELSE;}
"unless" {count();yylval.index = UNLESS - USER_DEF_NUM; G_Def[yylval.index].name="unless";add_buff(yytext);return UNLESS;}
"print"  {count();yylval.index = PRINT -USER_DEF_NUM ; G_Def[yylval.index].name="print";add_buff(yytext);return PRINT;}

"then"    { count(); yylval.index = THEN - USER_DEF_NUM; G_Def[yylval.index].name="then";  add_buff(yytext); return(THEN); }
"end"     { count(); yylval.index = END - USER_DEF_NUM; G_Def[yylval.index].name="end";  add_buff(yytext); return(END); }
"do"      { count();  yylval.index = DO - USER_DEF_NUM; G_Def[yylval.index].name="do";  add_buff(yytext);return(DO); }
"to"      { count();  yylval.index = TO - USER_DEF_NUM; G_Def[yylval.index].name="to";  add_buff(yytext);return(TO); }

"++" { yylval.index = ADD_T-USER_DEF_NUM; G_Def[yylval.index].name="++"; G_Def[yylval.index+1].name="++";  add_buff(yytext); return ADD_T; }
"--" { yylval.index = MUS_T-USER_DEF_NUM; G_Def[yylval.index].name="--"; G_Def[yylval.index+1].name="++";  add_buff(yytext); return MUS_T; }
">=" { yylval.index = GEQ - USER_DEF_NUM;  G_Def[yylval.index].name=">=";  add_buff(yytext); return GEQ;}
"<=" { yylval.index = LEQ - USER_DEF_NUM;  G_Def[yylval.index].name="<=";  add_buff(yytext); return LEQ;}
"==" { yylval.index = EQ - USER_DEF_NUM;  G_Def[yylval.index].name="==";  add_buff(yytext); return EQ;}
"!=" { yylval.index = NEQ - USER_DEF_NUM;  G_Def[yylval.index].name="!=";  add_buff(yytext); return NEQ;}
[()<>=+\-*/;{}.] {yylval.index = *yytext;add_buff(yytext);return *yytext;} 
[\t]         ;
.            ;
{ID} {count();add_var(yytext);yylval.index = G_iVarCurIndex;add_buff(yytext);return ID;}
%%
void count(){
  int i;
  for (i = 0; yytext[i] != '\0'; i++) {
    if (yytext[i] == '\n')
      column = 0;
    else if (yytext[i] == '\t')
      column += 8 - (column % 8);
    else
      column++;
  }
}

void rubyprint(char s[]) {
  int i = 0;
  while(s[i]!= '\"'){
    printf("%c",s[i]);
    i++;
  }
  printf("\n");
}
void yyerror(char *s){
  fprintf(stderr,"%s line %d col %d\n",s,lineno,column);
}
 
void add_buff(char * buff) {
   strcat(sBuff[iBuffX],buff);
   iBuffY+=strlen(buff);
}
