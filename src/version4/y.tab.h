/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     IF = 259,
     THEN = 260,
     ELSE = 261,
     END = 262,
     WHILE = 263,
     DO = 264,
     DEF = 265,
     LEQ = 266,
     GEQ = 267,
     STRING = 268,
     FLOAT = 269,
     INT = 270,
     ID = 271,
     FOR = 272,
     TO = 273,
     RETURN = 274,
     IN = 275,
     NEQ = 276,
     EQ = 277,
     OR = 278,
     AND = 279
   };
#endif
/* Tokens.  */
#define CLASS 258
#define IF 259
#define THEN 260
#define ELSE 261
#define END 262
#define WHILE 263
#define DO 264
#define DEF 265
#define LEQ 266
#define GEQ 267
#define STRING 268
#define FLOAT 269
#define INT 270
#define ID 271
#define FOR 272
#define TO 273
#define RETURN 274
#define IN 275
#define NEQ 276
#define EQ 277
#define OR 278
#define AND 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 32 "parse.y"

  int index;
  int ival;
  float fval;
  char *sval;
  int bval;
  int type;
  char *id;
  VarIndex *node;
 


/* Line 2068 of yacc.c  */
#line 111 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


