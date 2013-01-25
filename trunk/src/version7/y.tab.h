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
     STRING = 258,
     FLOAT = 259,
     INT = 260,
     ID = 261,
     CLASS = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     END = 266,
     WHILE = 267,
     DO = 268,
     UNLESS = 269,
     DEF = 270,
     LEQ = 271,
     GEQ = 272,
     FOR = 273,
     TO = 274,
     RETURN = 275,
     IN = 276,
     PRINT = 277,
     NEQ = 278,
     EQ = 279,
     OR = 280,
     AND = 281,
     MUS_TT = 282,
     MUS_T = 283,
     ADD_TT = 284,
     ADD_T = 285
   };
#endif
/* Tokens.  */
#define STRING 258
#define FLOAT 259
#define INT 260
#define ID 261
#define CLASS 262
#define IF 263
#define THEN 264
#define ELSE 265
#define END 266
#define WHILE 267
#define DO 268
#define UNLESS 269
#define DEF 270
#define LEQ 271
#define GEQ 272
#define FOR 273
#define TO 274
#define RETURN 275
#define IN 276
#define PRINT 277
#define NEQ 278
#define EQ 279
#define OR 280
#define AND 281
#define MUS_TT 282
#define MUS_T 283
#define ADD_TT 284
#define ADD_T 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 46 "parse.y"

  int index;
  int ival;
  float fval;
  char *sval;
  Node *node;



/* Line 2068 of yacc.c  */
#line 120 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


