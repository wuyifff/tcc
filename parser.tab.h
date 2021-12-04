
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     INT = 258,
     ID = 259,
     RELOP = 260,
     TYPE = 261,
     FLOAT = 262,
     CHAR = 263,
     DPLUS = 264,
     LP = 265,
     RP = 266,
     LS = 267,
     RS = 268,
     LC = 269,
     RC = 270,
     SEMI = 271,
     COMMA = 272,
     MINUSMINUS = 273,
     PLUSPLUS = 274,
     PLUS = 275,
     MINUS = 276,
     STAR = 277,
     DIV = 278,
     ASSIGNOP = 279,
     AND = 280,
     OR = 281,
     NOT = 282,
     IF = 283,
     ELSE = 284,
     WHILE = 285,
     FOR = 286,
     RETURN = 287,
     SWITCH = 288,
     CASE = 289,
     COLON = 290,
     DEFAULT = 291,
     PLUSASSIGNOP = 292,
     MINUSASSIGNOP = 293,
     STARASSIGNOP = 294,
     DIVASSIGNOP = 295,
     BREAK = 296,
     CONTINUE = 297,
     EXT_DEF_LIST = 298,
     EXT_VAR_DEF = 299,
     FUNC_DEF = 300,
     FUNC_DEC = 301,
     EXT_DEC_LIST = 302,
     PARAM_LIST = 303,
     PARAM_DEC = 304,
     VAR_DEF = 305,
     DEC_LIST = 306,
     DEF_LIST = 307,
     COMP_STM = 308,
     STM_LIST = 309,
     EXP_STMT = 310,
     IF_THEN = 311,
     IF_THEN_ELSE = 312,
     ARRAY_LIST = 313,
     ARRAY_ID = 314,
     FUNC_CALL = 315,
     ARGS = 316,
     FUNCTION = 317,
     PARAM = 318,
     ARG = 319,
     CALL = 320,
     LABEL = 321,
     GOTO = 322,
     JLT = 323,
     JLE = 324,
     JGT = 325,
     JGE = 326,
     EQ = 327,
     NEQ = 328,
     UMINUS = 329,
     LOWER_THEN_ELSE = 330
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "parser.y"

	int    type_int;
	float  type_float;
        char   type_char;
	char   type_id[32];
	struct ASTNode *ptr;



/* Line 1676 of yacc.c  */
#line 137 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

