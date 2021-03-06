/*
 *  cool.y
 *              Parser definition for the COOL language.
 *
 */
%{
#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"

extern char *curr_filename;

void yyerror(char *s);        /*  defined below; called for each parse error */
extern int yylex();           /*  the entry point to the lexer  */
extern int node_lineno;

/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */

Program ast_root;	      /* the result of the parse  */
Classes parse_results;        /* for use in semantic analysis */
int omerrs = 0;               /* number of errors in lexing and parsing */
%}

/* A union of all the types that can be the result of parsing actions. */
%union {
  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
  char *error_msg;
}

/* 
   Declare the terminals; a few have types for associated lexemes.
   The token ERROR is never used in the parser; thus, it is a parse
   error when the lexer returns it.

   The integer following token declaration is the numeric constant used
   to represent that token internally.  Typically, Bison generates these
   on its own, but we give explicit numbers to prevent version parity
   problems (bison 1.25 and earlier start at 258, later versions -- at
   257)
*/
%token CLASS 258 ELSE 259 FI 260 IF 261 IN 262 
%token INHERITS 263 LET 264 LOOP 265 POOL 266 THEN 267 WHILE 268
%token CASE 269 ESAC 270 OF 271 DARROW 272 NEW 273 ISVOID 274
%token <symbol>  STR_CONST 275 INT_CONST 276 
%token <boolean> BOOL_CONST 277
%token <symbol>  TYPEID 278 OBJECTID 279 
%token ASSIGN 280 NOT 281 LE 282 ERROR 283

/*  DON'T CHANGE ANYTHING ABOVE THIS @1.first_line = curr_lineno, OR YOUR PARSER WONT WORK       */
/**************************************************************************/
 
   /* Complete the nonterminal list below, giving a type for the semantic
      value of each non terminal. (See section 3.6 in the bison 
      documentation for details). */

/* Declare types for the grammar's non-terminals. */
%type <program> program
%type <classes> class_list
%type <class_> class
/* You will want to change the following line. */
%type <features> dummy_feature_list
%type <feature> feature
%type <formals> formal_list
%type <formal> formal
%type <expressions> expr_list dummy_expr_list
%type <expression> expr
%type <cases> case_match_list
%type <case_> case_match
%type <expression> let_list

/* Precedence declarations go here. */
%left LETPREC
%left CALLPREC
%nonassoc '('
%right ASSIGN
%left NOT
%left LE '<' '='
%left '+' '-'
%left '*' '/'
%left ISVOID
%left '~'
%left '@'
%left '.'

%%
/* 
   Save the root of the abstract syntax tree in a global variable.
*/
program	: {@0.first_line = curr_lineno;} class_list	{ node_lineno = @1.first_line; ast_root = program($2);}
        ;

class_list : class			/* single class */            
             { $$ = single_Classes($1);
              parse_results = $$; }
	         | class_list class	                        
             { $$ = append_Classes($1,single_Classes($2)); 
               parse_results = $$; }
	         ;

/* If no parent is specified, the class inherits from the Object class. */
class	: CLASS TYPEID {@1.first_line = curr_lineno;} '{' dummy_feature_list '}' ';'	
        { node_lineno = @1.first_line; $$ = class_($2,idtable.add_string((char *)"Object"),$5,
			    stringtable.add_string(curr_filename)); }
	    | CLASS TYPEID INHERITS TYPEID {@1.first_line = curr_lineno;} '{' dummy_feature_list '}' ';'
        { node_lineno = @1.first_line;
          $$ = class_($2,$4,$7,stringtable.add_string(curr_filename)); }
	    ;

/* Feature list may be empty, but no empty features in list. */
dummy_feature_list :		/* empty */ { $$ = nil_Features(); }
                   | dummy_feature_list feature       
                     { $$ = append_Features($1,single_Features($2));}
                   ;

feature : OBJECTID '(' ')' ':' TYPEID '{' {@1.first_line = curr_lineno;} expr '}' ';' 
          { node_lineno = @1.first_line; $$ = method($1, nil_Formals(), $5, $8); }
        | OBJECTID '(' {@1.first_line = curr_lineno;} formal formal_list ')' ':' TYPEID '{' expr '}' ';'
          { node_lineno = @1.first_line; $$ = method($1, append_Formals($5, single_Formals($4)), $8, $10); }
        | OBJECTID ':' TYPEID ';' {@1.first_line = curr_lineno;}                     
          { node_lineno = @1.first_line; $$ = attr($1, $3, no_expr());}
        | OBJECTID ':' TYPEID ASSIGN {@1.first_line = curr_lineno;} expr ';'
          { node_lineno = @1.first_line; $$ = attr($1, $3, $6);}
        ;

formal_list : /* empty */  { $$ = nil_Formals();}
            | formal_list ',' formal                  
              { $$ = append_Formals($1, single_Formals($3));}
            ;
        
formal : OBJECTID ':' TYPEID {@1.first_line = curr_lineno;}
         { {node_lineno = @1.first_line;} $$ = formal($1, $3);}

expr_list : expr                           
            { $$ = single_Expressions($1); }
          | expr_list expr ';'             
            { $$ = append_Expressions($1, single_Expressions($2)); }
          ;

dummy_expr_list : /* empty */ { $$ = nil_Expressions(); }
                | dummy_expr_list ',' expr  
                  { $$ = append_Expressions($1, single_Expressions($3));}
                ;

let_list : IN expr           %prec LETPREC  
           { $$ = $2; }
         | ',' OBJECTID ':' TYPEID let_list 
           { $$ = let($2, $4, no_expr(), $5); } 
         | ',' OBJECTID ':' TYPEID ASSIGN expr let_list 
           { $$ = let($2, $4, $6, $7); }                 
         ;

case_match : OBJECTID ':' TYPEID DARROW {@1.first_line = curr_lineno;} expr ';' 
             { node_lineno = @1.first_line; $$ = branch($1, $3, $6);}
           ;

case_match_list : case_match                
                  { $$ = single_Cases($1); }
                | case_match_list case_match 
                  { $$ = append_Cases($1, single_Cases($2)); }
                ;

expr : OBJECTID ASSIGN {@1.first_line = curr_lineno;} expr                 
       { node_lineno = @1.first_line; $$ = assign($1, $4); }
     | expr '.' OBJECTID '(' ')'          
       { node_lineno = @1.first_line; $$ = dispatch($1, $3, nil_Expressions()); }  
     | expr '.' OBJECTID '(' expr dummy_expr_list ')'
       { node_lineno = @1.first_line; 
         $$ = dispatch($1, $3, append_Expressions($6, single_Expressions($5))); }
     | expr '@' TYPEID '.' OBJECTID '(' ')' 
       { node_lineno = @1.first_line; $$ = static_dispatch($1, $3, $5, nil_Expressions()); }
     | expr '@' TYPEID '.' OBJECTID '(' expr dummy_expr_list ')'
       { node_lineno = @1.first_line; 
         $$ = static_dispatch($1, $3, $5, append_Expressions($8, single_Expressions($7))); }
     | OBJECTID '(' ')'          
       { @1.first_line = curr_lineno; node_lineno = @1.first_line;
         $$ = dispatch(object(idtable.add_string((char *)"self")), $1, nil_Expressions()); }
     | OBJECTID '(' {@1.first_line = curr_lineno;} expr dummy_expr_list ')' 
       { node_lineno = @1.first_line;
         $$ = dispatch(object(idtable.add_string((char *)"self")), $1, 
                      append_Expressions($5, single_Expressions($4))); }
     | IF {@1.first_line = curr_lineno;} expr THEN expr ELSE expr FI       
       { node_lineno = @1.first_line; $$ = cond($3, $5, $7); }
     | WHILE {@1.first_line = curr_lineno;} expr LOOP expr POOL            
       { $$ = loop($3, $5); }
     | '{' {@1.first_line = curr_lineno;} expr_list '}'                    
       { node_lineno = @1.first_line; $$ = block($3); }
     | LET OBJECTID ':' TYPEID {@1.first_line = curr_lineno;} let_list     
       { $$ = let($2, $4, no_expr(), $6); }
     | LET OBJECTID ':' TYPEID ASSIGN {@1.first_line = curr_lineno;} expr let_list 
       { node_lineno = @1.first_line; $$ = let($2, $4, $7, $8); }
     | CASE {@1.first_line = curr_lineno;} expr OF case_match_list ESAC    
       { node_lineno = @1.first_line; $$ = typcase($3, $5); }
     | NEW TYPEID                           
       { @1.first_line = curr_lineno; node_lineno = @1.first_line; $$ = new_($2); }
     | ISVOID {@1.first_line = curr_lineno;} expr                          
       { node_lineno = @1.first_line; $$ = isvoid($3); }
     | expr '+' expr                        
       { node_lineno = @1.first_line; $$ = plus($1, $3); }
     | expr '-' expr                        
       { node_lineno = @1.first_line; $$ = sub($1, $3); }
     | expr '*' expr                        
       { node_lineno = @1.first_line; $$ = mul($1, $3); }
     | expr '/' expr                        
       { node_lineno = @1.first_line; $$ = divide($1, $3); }
     | '~' {@1.first_line = curr_lineno;} expr                             
       { node_lineno = @1.first_line; $$ = neg($3); }
     | expr '<' expr                        
       { node_lineno = @1.first_line; $$ = lt($1, $3); }
     | expr LE expr                         
       { node_lineno = @1.first_line; $$ = leq($1, $3); }
     | expr '=' expr                        
       { node_lineno = @1.first_line; $$ = eq($1, $3); }
     | NOT {@1.first_line = curr_lineno;} expr                             
       { node_lineno = @1.first_line; $$ = neg($3); }
     | '(' {@1.first_line = curr_lineno;} expr ')'                         
       { node_lineno = @1.first_line; $$ = $3; }
     | OBJECTID %prec CALLPREC 
       { @1.first_line = curr_lineno; node_lineno = @1.first_line; $$ = object($1); }
     | INT_CONST                            
       { @1.first_line = curr_lineno; node_lineno = @1.first_line; $$ = int_const($1); }
     | STR_CONST                            
       { @1.first_line = curr_lineno; node_lineno = @1.first_line; $$ = string_const($1); }
     | BOOL_CONST                           
       { @1.first_line = curr_lineno; node_lineno = @1.first_line; $$ = bool_const($1); }

/* end of grammar */
%%

/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s)
{
  extern int curr_lineno;

  cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
    << s << " at or near ";
  print_cool_token(yychar);
  cerr << endl;
  omerrs++;

  if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
}

