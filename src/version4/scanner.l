%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "userdef.h"
#include "y.tab.h"
int column=0; 
int lineno=0;
int MAX=65526;
extern char sBuff[10][20];
extern int iBuffX;
extern int iBuffY;
extern int iMaxIndex;
extern int iCurIndex;
void count(); /* Function that counts the current column */
void rubyprint(char s[]); /* Function that prints the string */
void yyerror(char *);
void add_buff(char *);
void add_var(char *);
extern VarIndex strMem[10000];
%}
F ([0-9]+\.[0-9]*)
I ([0-9]+)
S (\"[^\n\"]*\")
ID ([$@]?[a-zA-Z_][a-zA-Z_0-9]*)
D ([a-zA-Z][a-zA-Z0-9_]*)
%%
{ID}     { count();  yylval.sval = (char*)malloc(strlen(yytext)+1);add_buff(yytext);strcpy(yylval.id, yytext);count(); return(ID);   } 
{I}      { count(); yylval.fval = atoi(yytext); add_buff(yytext);return(INT);  }
{F}      { count(); yylval.ival = atof(yytext); add_buff(yytext);return(FLOAT);}
{S}      { count(); yylval.sval = (char*)malloc(strlen(yytext)+1);strcpy(yylval.sval,yytext);rubyprint(yytext+1); add_buff(yytext);printf("=>nil\n");}
puts[\ ]+{S} {count();rubyprint(yytext + 6);printf("=>nil\n");}
"for"    { count(); return(FOR); }
"while"  { count(); return(WHILE);}
"if"     { count(); return(IF); }
"then"   { count(); return(THEN); }
"else"   { count(); return(ELSE); }
"return" { count(); return(RETURN); }
"class"  { count(); return(CLASS); }
"def"    { count(); return(DEF); }
"in"     { count(); return(IN); }
"end"    { count(); return(END); }
"do"     { count(); return(DO); }
".."	 { count(); return(TO); }
"<="	 { count(); return(LEQ); }
">="     { count(); return(GEQ); }
"=="	 { count(); return(EQ); }
"!="	 { count(); return(NEQ); }
"&&"     { count(); return(AND); }
"||"     { count(); return(OR); }
";"	 { count(); return(';'); }
","	 { count(); return(','); }
[\n]     { lineno++; column = 0; return ('\n'); } 
[()<>=+\-*/;{}.] {yylval.index = *yytext;add_buff(yytext);return *yytext;} 
[\t]         ;
.            ;

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
void add_var(char *mark) {

   if(iMaxIndex==0){
    strcpy(strMem[0].name,mark);
    iMaxIndex++;
    iCurIndex=0;
    return;
   }
   int i;
   for(i=0;i<=iMaxIndex-1;i++) {
    if(strcmp(strMem[i].name,mark)==0) {
     iCurIndex=i;
     return;
    }
   }
   strcpy(strMem[iMaxIndex].name,mark);
   iCurIndex=iMaxIndex;
   iMaxIndex++;
  }
  int yywrap(void) {
  return 1;
}
