%{
  #include <stdio.h>
  #include <unistd.h>
 //#include "typval.h"

//#include"hashcode.h"

#define I 0
#define F 1
#define S 2
#define B 3
#define U -1
int nb_ligne=1;
int nb_erreur=0;
int tab_plus[4][4];
int tab_moins[4][4];
int tab_mult[4][4];
int tab_div[4][4];
int tab_cmp[4][4];
void init(int tab[4][4])
{
      int i=0;int j=0;
       for(i=0;i<4;i++){for(j=0;j<4;j++){tab[i][j]=-1;}}
}
void init_tab(){

init(tab_plus);
     tab_plus[I][I]=I;
     tab_plus[I][F]=F;
     tab_plus[F][I]=F;
     tab_plus[F][F]=F;
     tab_plus[S][S]=S;

 init(tab_moins);
      tab_moins[I][I]=I;
      tab_moins[I][F]=F;
      tab_moins[F][I]=F;
      tab_moins[F][F]=F;

init(tab_mult);
      tab_mult[I][I]=I;
      tab_mult[I][F]=F;
      tab_mult[F][I]=F;
      tab_mult[F][F]=F;

init(tab_div);
      tab_div[I][I]=F;
      tab_div[I][F]=F;
      tab_div[F][I]=F;
      tab_div[F][F]=F;

init(tab_cmp);
      tab_cmp[I][I]=B;
      tab_cmp[I][F]=B;
      tab_cmp[F][I]=B;
      tab_cmp[F][F]=B;
      tab_cmp[S][S]=B;
}

/* variables globales */
typedef enum {Entier = 0, Rationnel = 1, Chaine = 2, Boolean = 3, Aucun = 4} typpo;

typedef struct strHashEntry {
   char * nom ;
   typpo type;
   union {int e ; float f ; char* s ; enum { vrai = 0, faux = 1} Bool ;} valeur ;
   struct strHashEntry * homonyme ;
} * HashEntry ;  
//HashEntry TS = NULL; /* la table des symboles */


typedef struct Table{
     HashEntry courant ;
     HashEntry englobant;
     struct Table * back ;	
}*t;

t table= NULL;
t table2 = NULL;


HashEntry NewEntry(char *k) {
  HashEntry ret = (HashEntry)malloc(sizeof(*ret)) ;
  ret->nom = (char*)malloc(sizeof(char) * (strlen(k) + 1)) ;
  strcpy(ret->nom,k) ;
   //ret->type = Aucun ;
  ret->homonyme = NULL ;
  return ret ;
}

int LookUp(char * k) {      // tester  l'existence d'une variable dans la table de symbole à partir de son nom 
  HashEntry ret = table->courant; 
  while( ret != NULL ) {
    if (strcmp(k,ret->nom) == 0) return 1 ;
     else ret = ret->homonyme ;
  }
  return 0 ;
}

void ajouter( char * k) {      // tester  l'existence d'une variable dans la table de symbole à partir de son nom 
  HashEntry ret = NewEntry(k) ;
  ret -> homonyme = table->courant ;
  table->courant=ret;
}

void ajouter_symbole(char * k, int type) {      // tester  l'existence d'une variable dans la table de symbole à partir de son nom 
  HashEntry ret = NewEntry(k) ;
  ret->type = type ;
  ret -> homonyme = table->courant ;
  table->courant=ret;
}

int val(char * k) {      
  HashEntry ret = table->courant; 
  while( ret != NULL ) {
    if (strcmp(k,ret->nom) == 0) return ret->type;
     else ret = ret->homonyme ;
  }
  return -1 ;
}

void liberer_table(){
  HashEntry ret = table->courant; 
  while( table->courant != NULL ) {
   ret = table->courant;
   table->courant=table->courant-> homonyme;
   free(ret);
  }
}

t cree_nouveau_table(){
    table2 =table ;
   t ret = (t)malloc(sizeof(*ret)) ;
   ret->courant=NULL;
   ret->englobant=table2->courant;
   ret->back=table2;
   return ret ;

}


%}
/* types des attributs */


%union {
	int ival;
	float fval;
	char *sval;
        char *id;


struct s {
  int Type ;
   enum {Integer = 0, Float = 1, String = 2, Bool = 3, Undef = -1, Aucun_Type = 4} type;
   union {int e ; float f ; char* s ; enum { false = 0, true = 1} Booleen ;} valeur ;
} G ;

struct c {
   char *id;
   int type;  
} C;
}
%start program	 /* L'axiome (par defaut, le symbole gauche de la premiere regle) */
/* declaration simple des symboles terminaux */

%token AND OR CLASS IF THEN ELSE END WHILE DO DEF LEQ GEQ 
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%token <id> ID
%token  FOR TO RETURN IN NEQ
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ
%left AND OR


/*type des variables associees aux symboles non terminaux */
%type <G> additive_expr 
%type <G> primary
%type <G> multiplicative_expr
%type <G> comp_expr
%type <G> expr 
%type <C> lhs 
  
%%
 /*notre programme*/
program	:  topstmts opt_terms
;

topstmts        :      
| topstmt
| topstmts terms topstmt
;
topstmt	        : CLASS ID  { table=cree_nouveau_table(); } term stmts  { liberer_table(); table=table->back; } END 
                | CLASS ID '<' ID term stmts END
                | stmt
;

stmts	        : /* none */
                | stmt
                | stmts terms stmt
                ;

stmt		: IF expr THEN stmts terms END                   {if($2.type!=Bool){
                                                                     printf(" Line %d: semantic error, conditional structure IF [using not boolean expression]\n",nb_ligne);
								     nb_erreur++;}
                                                                 }
              
                | IF expr THEN stmts terms ELSE stmts terms END  {if($2.type!=Bool){
                                                                     printf(" Line %d: semantic error, conditional structure IF [using not boolean expression]\n",nb_ligne);
                                                                     nb_erreur++;}
                                                                 }
                | FOR ID IN expr TO expr term stmts terms END   // {if($2.type!=Integer){printf(" ID n est pas entier ");}}
                | WHILE expr DO term stmts terms END              {if($2.type!=Bool){
                                                                     printf("  Line %d :  semantic error, boucle WHILE [using not boolean expression]\n",nb_ligne);
								   nb_erreur++;}
                                                                 }
                | lhs '=' expr       { 
				     if($3.type==-1){ 
                                         printf(" Line %d: semantic error, assignment [incorrect expression]\n",nb_ligne);
					 nb_erreur++;}
                                     else if(LookUp($1.id)==0){
                                         ajouter_symbole($1.id,$3.type);}
                                     else{
					  if($3.type!=val($1.id)){ 
						printf(" Line %d: semantic error, assignment [redefined with a different type]\n",nb_ligne);}
						nb_erreur++;}	    			              
			             } 
                | RETURN expr
                | DEF ID opt_params term stmts terms END
; 

opt_params      : /* none */
                | '(' ')'
                | '(' params ')'
;
params          : ID ',' params
                | ID   
; 
lhs             : ID   { $$.id = (char*)malloc(strlen($1)+1);
                        strcpy($$.id,$1);
                        if(LookUp($1)==1)
			    $$.type=val($1);
			else{
                        $$.type=Aucun_Type;
			}
			}        
                              
                | ID '.' primary     { 
                                       if(LookUp($1)==0) {
					   if(($3.type!=Undef)  && ($3.type!=Aucun_Type ))
                                              ajouter_symbole($1,$3.type);
			             }
                                      else{
					  if($3.type!=val($1)){
							        printf(" Line %d : semantic error, ...\n",nb_ligne);
								nb_erreur++;}
					  }	    
				      $$.id = (char*)malloc(strlen($1)+1);
                                      strcpy($$.id,$1);
                                      $$.type=$3.type;
			              
			             }                         
                | ID '(' exprs ')'    {   $$.id = (char*)malloc(strlen($1)+1);
                                          strcpy($$.id,$1);
			                  $$.type=val($1);
			                  } 
;      

exprs           : exprs ',' expr
                | expr
;
primary         : lhs                  {$$.type =$1.type;} 
                | STRING               {$$.type =String;} 
                | FLOAT                {$$.type =Float;}
                | INT                  {$$.type =Integer;}                                
                | '(' expr ')'         {$$.type =$2.type;}
;
expr            : expr AND comp_expr   {  
                                       if(($1.type==Bool)&&($3.type==Bool)) 
                                             $$.type=Bool; 
                                       else{
                                           $$.type=Undef; 
                                           printf(" Line %d: semantic error, Boolean expression [using AND with not boolean expression]\n",nb_ligne);
					   nb_erreur++;}
                                       }
                | expr OR comp_expr    {
                                       if(($1.type==Bool)&&($3.type==Bool))
                                           $$.type=Bool; 
                                       else{
                                           $$.type=Undef; 
                                           printf(" Line %d: semantic error, Boolean expression [using OR with not boolean expression]\n",nb_ligne);
					   nb_erreur++;}
                                       }
                | comp_expr            {$$.type = $1.type;}
;
comp_expr       : additive_expr '<' additive_expr
			       {
                               $$.type = tab_cmp[$1.type][$3.type]; 
                               if($$.type==Undef){
                                   printf(" Line %d: semantic error, comparison [incompatible type]\n",nb_ligne);
			           nb_erreur++;}
                               }
                | additive_expr '>' additive_expr
                               {
                               $$.type = tab_cmp[$1.type][$3.type]; 
                               if($$.type==Undef){
                                   printf(" Line %d: semantic error, comparison [incompatible type]\n",nb_ligne);
				   nb_erreur++;}
                               }
                | additive_expr LEQ additive_expr
			       {
                               $$.type = tab_cmp[$1.type][$3.type]; 
                               if($$.type==Undef){
                                  printf(" Line %d: semantic error, comparison [incompatible type]\n",nb_ligne);
				  nb_erreur++;}
                               }
                | additive_expr GEQ additive_expr
			       {
                               $$.type = tab_cmp[$1.type][$3.type]; 
                               if($$.type==Undef){
                                  printf(" Line %d: semantic error, comparison [incompatible type]\n",nb_ligne);
				  nb_erreur++;}
                               }
                | additive_expr EQ additive_expr
			       {
                               $$.type = tab_cmp[$1.type][$3.type]; 
                               if($$.type==Undef){
                                  printf(" Line %d: semantic error, comparison [incompatible type]\n",nb_ligne);
                                  nb_erreur++;}
                               }
                | additive_expr NEQ additive_expr
			       {
                               $$.type = tab_cmp[$1.type][$3.type]; 
                               if($$.type==Undef){
                                  printf(" Line %d: semantic error, comparison [incompatible type]\n",nb_ligne);
				  nb_erreur++;}
                               }
                | additive_expr          {$$.type = $1.type;}
;
additive_expr   : multiplicative_expr    {$$.type = $1.type;}
                | additive_expr '+' multiplicative_expr
                               {
                               $$.type = tab_plus[$1.type][$3.type]; 
                               if($$.type==Undef){
				     printf(" Line %d: semantic error, addition [incompatible type]\n",nb_ligne);
				     nb_erreur++;}
                               }
                | additive_expr '-' multiplicative_expr
			      {
                               $$.type = tab_moins[$1.type][$3.type]; 
                               if($$.type==Undef){
                                     printf(" Line %d: semantic error, substructure [incompatible type]\n",nb_ligne);
				     nb_erreur++;}
                               }
;
multiplicative_expr : multiplicative_expr '*' primary  
                               {
                               $$.type = tab_mult[$1.type][$3.type]; 
                               if($$.type==Undef){
                                     printf(" Line %d: semantic error, multiplication [incompatible type]\n",nb_ligne);
				     nb_erreur++;}
                               }
                    | multiplicative_expr '/' primary  
                              {
                               $$.type = tab_div[$1.type][$3.type]; 
                               if($$.type==Undef){
                                     printf(" Line %d: semantic error, division [incompatible type]\n",nb_ligne);
				     nb_erreur++;}
                               }
                    | primary  { $$.type=$1.type;
                                 if($1.type==Aucun_Type){
                                          printf(" Line %d: semantic error, undeclared variable\n",nb_ligne);
					  nb_erreur++;
                                         $$.type = -1;}
                               } 
;
opt_terms	: /* none */
		| terms
		;

terms		: terms ';'
                | terms '\n'    {nb_ligne++;}
		| ';'
                | '\n'          {nb_ligne++;}
		;
term            : ';'
                | '\n'          {nb_ligne++;}
;
%%
int main() {
nb_ligne=0;
table = (t)malloc(sizeof(*table)) ;
table->courant = NULL;
table->englobant = NULL;
table->back=NULL;
  init_tab();
  yyparse(); 
if(nb_erreur!=0)
  printf("compilation failed :%d error \n\n",nb_erreur);
else
  printf("compilation ends with success \n\n");
  return 0;
}
