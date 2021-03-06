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
#include <vector>

#define YYLTYPE int 
extern char *curr_filename;
#define cool_yylloc curr_lineno

#define YYLLOC_DEFAULT(Current, Rhs, N)         \
Current = Rhs[1];                             \
node_lineno = Current;


#define SET_NODELOC(Current)  \
node_lineno = Current;

void yyerror(char *s);        /*  defined below; called for each parse error */
extern int yylex();           /*  the entry point to the lexer  */
extern int node_lineno;

typedef struct {
  Symbol id;
  Symbol type;
  Expression init;
  int lineNumber;
} Let_structure;

typedef std::vector<Let_structure> ListLet;


Expression letConstruct(ListLet* list, Let_structure letD, Expression expr){
  SET_NODELOC(letD.lineNumber);
  Expression aux = let(letD.id, letD.type, letD.init, expr);
  if(list->size() == 0) {
    return aux;
  }
  for(int i = list->size() - 1; 0 < i  ; i--){
    SET_NODELOC((*list)[i].lineNumber);
    aux = let((*list)[i].id, (*list)[i].type, (*list)[i].init, aux);
  }
  SET_NODELOC((*list)[0].lineNumber);
  return let((*list)[0].id, (*list)[0].type, (*list)[0].init, aux);
}


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
  Let_structure letS;
  ListLet * listLet;
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

/*  DON'T CHANGE ANYTHING ABOVE THIS LINE, OR YOUR PARSER WONT WORK       */
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
%type <letS> let_declare 
%type <listLet> let_list 
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
program	: class_list	{ @$ = @1; ast_root = program($1);}
         ;

class_list : class			/* single class */            
             { $$ = single_Classes($1); parse_results = $$; }
           | class_list class	                        
             { $$ = append_Classes($1, single_Classes($2)); parse_results = $$; }
           | error ';' {}           
           ;

/* If no parent is specified, the class inherits from the Object class. */
class	: CLASS TYPEID '{' dummy_feature_list '}' ';'		
        { @$ = @1;
          $$ = class_($2,idtable.add_string((char *)"Object"),$4,
			             stringtable.add_string(curr_filename)); }
	    | CLASS TYPEID INHERITS TYPEID '{' dummy_feature_list '}' ';'
        { @$ = @1;
          $$ = class_($2,$4,$6,stringtable.add_string(curr_filename)); }
	    ;

/* Feature list may be empty, but no empty features in list. */
dummy_feature_list :		/* empty */  { $$ = nil_Features(); }
                   | dummy_feature_list feature       
                     { $$ = append_Features($1,single_Features($2));}
                   | error ';' {}
                   ;

feature : OBJECTID '(' ')' ':' TYPEID '{' expr '}' ';' 
          { @$ = @1;
            $$ = method($1, nil_Formals(), $5, $7); }
        | OBJECTID '(' formal_list formal ')' ':' TYPEID '{' expr '}' ';'
          { @$ = @1;
            $$ = method($1, append_Formals($3, single_Formals($4)), $7, $9); }
        | OBJECTID ':' TYPEID ';'                     
          { SET_NODELOC(0);
            Expression no_expr_temp = no_expr();
            SET_NODELOC(@1);
            $$ = attr($1, $3, no_expr_temp);}
        | OBJECTID ':' TYPEID ASSIGN expr ';'         
          { @$ = @1;
            $$ = attr($1, $3, $5);}
        | OBJECTID '(' ')' error  ';' {}
        | OBJECTID '(' formal_list formal ')' error ';' {}
        | OBJECTID '(' error ')' ':' TYPEID '{' error ';' {}
        | OBJECTID '(' error ')' ':' TYPEID '{' expr '}' ';' {}
        ;

formal_list : /* empty */  { $$ = nil_Formals();}
            | formal_list formal ','
              { $$ = append_Formals($1, single_Formals($2));}
            ;
        
formal : OBJECTID ':' TYPEID                          
         { @$ = @1;
           $$ = formal($1, $3);}
       ;

expr_list : expr  ';'
            { $$ = single_Expressions($1); }
          | expr_list  expr ';'             
            { $$ = append_Expressions($1,  single_Expressions($2)); }
          | error ';' {}
          ;

dummy_expr_list : /* empty */  { $$ = nil_Expressions(); }
                | dummy_expr_list expr ','
                  { $$ = append_Expressions($1, single_Expressions($2));}
                ;
let_declare : OBJECTID ':' TYPEID   
              { Let_structure letD;
                SET_NODELOC(0);
                letD.id = $1; letD.type = $3; letD.init = no_expr();
                letD.lineNumber = @1;
                @$ = @1;
                $$ = letD; }
            | OBJECTID ':' TYPEID ASSIGN expr
              { Let_structure letD;
                letD.id = $1; letD.type = $3; letD.init = $5;
                letD.lineNumber = @1;
                @$ = @1;
                $$ = letD; }
            ;
let_list : let_declare ','
           { ListLet * tmp = new ListLet();
             tmp->size();
             tmp->push_back($1);
            @$ = @1;
             $$ = tmp; } 
         | let_list let_declare ',' 
           { @$ = @1;
             $1->push_back($2);
             $$ = $1; } 
         | error ',' { $$ = new ListLet();} /* Quando o primeiro ta errado mas o resto ta certo */
         ;

case_match : OBJECTID ':' TYPEID DARROW expr ';' 
             { @$ = @1;
               $$ = branch($1, $3, $5);}
           | error ';' {}
           ;

case_match_list : case_match                
                  { $$ = single_Cases($1); }
                | case_match_list case_match 
                  { $$ = append_Cases($1, single_Cases($2)); }
                ;

expr : OBJECTID ASSIGN expr                 
       { @$ = @1; 
         $$ = assign($1, $3); }
     | expr '.' OBJECTID '(' ')'            
       { @$ = @1; 
         $$ = dispatch($1, $3, nil_Expressions()); }  
     | expr '.' OBJECTID '(' dummy_expr_list expr ')'
       { @$ = @1;  
         $$ = dispatch($1, $3, append_Expressions($5, single_Expressions($6)));}
     | expr '@' TYPEID '.' OBJECTID '(' ')' 
       { SET_NODELOC(@5); 
         $$ = static_dispatch($1, $3, $5, nil_Expressions()); }
     | expr '@' TYPEID '.' OBJECTID '(' dummy_expr_list expr ')'
       { SET_NODELOC(@5);  
         $$ = static_dispatch($1, $3, $5, append_Expressions($7, single_Expressions($8))); }
     | OBJECTID '(' ')'                     
       { @$ = @1;
         $$ = dispatch(object(idtable.add_string((char *)"self")), 
                       $1, nil_Expressions()); }
     | OBJECTID '(' dummy_expr_list expr ')' 
       { @$ = @1;
         $$ = dispatch(object(idtable.add_string((char *)"self")), 
                      $1, append_Expressions($3,single_Expressions($4))); }
     | IF expr THEN expr ELSE expr FI       
       { @$ = @1; 
         $$ = cond($2, $4, $6); }
     | WHILE expr LOOP expr POOL            
       { @$ = @1; 
         $$ = loop($2, $4); }
     | '{' expr_list '}'                    
       { @$ = @1;
         $$ = block($2); }
     | LET let_declare IN expr %prec LETPREC
       { @$ = @2;
         SET_NODELOC(@2);
         $$ = let($2.id, $2.type, $2.init, $4); }
     | LET let_list let_declare IN expr %prec LETPREC
       { @$ = @2;
         SET_NODELOC(@2);
         $$ = letConstruct($2, $3, $5); }
     | CASE expr OF case_match_list ESAC    
       { @$ = @1;
         $$ = typcase($2, $4); }
     | NEW TYPEID                           
       { @$ = @1; 
         $$ = new_($2); }
     | ISVOID expr                          
       { @$ = @1;
         $$ = isvoid($2); }
     | expr '+' expr                        
       { SET_NODELOC(@2);
         @$ = @1;
         $$ = plus($1, $3); }
     | expr '-' expr                        
       { SET_NODELOC(@2);
         @$ = @1;
         $$ = sub($1, $3); }
     | expr '*' expr                        
       { SET_NODELOC(@2);
         @$ = @2;
         $$ = mul($1, $3); }
     | expr '/' expr                        
       { SET_NODELOC(@2);
         @$ = @1;
         $$ = divide($1, $3); }
     | '~' expr                            
       { @$ = @1;
         $$ = neg($2); }
     | expr '<' expr                        
       { SET_NODELOC(@2);
         @$ = @1;
         $$ = lt($1, $3); }
     | expr LE expr                         
       { SET_NODELOC(@2);
         @$ = @1;
         $$ = leq($1, $3); }
     | expr '=' expr                        
       { SET_NODELOC(@2);
         @$ = @1;
         $$ = eq($1, $3); }
     | NOT expr                             
       { @$ = @1;
         $$ = comp($2); }
     | '(' expr ')'                         
       { @$ = @1;
         $$ = $2; }
     | OBJECTID %prec CALLPREC 
       { @$ = @1;
         $$ = object($1); }
     | INT_CONST                            
       { @$ = @1;
         $$ = int_const($1); }
     | STR_CONST                            
       { @$ = @1;
         $$ = string_const($1); }
     | BOOL_CONST                           
       { @$ = @1;
         $$ = bool_const($1); }
     | LET error IN {}
     | CASE error OF case_match_list ESAC  {}
     ;


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

