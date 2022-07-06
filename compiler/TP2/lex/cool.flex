/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
//#define yylval cool_yylval
//#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

#include <stdbool.h>

int countLines(char *string) {
    int lines = 0;
    for(int it = 0; string[it] != '\0'; ++it) {
        if(string[it] == '\n') {
            ++lines;
        }
    }
    return lines;
}

int copyString(char *inputString, char *outputString, int length) {
    if(inputString==NULL||outputString==NULL) {
        return -1;
    }
    for(int it = 0; it<length; ++it) {
        outputString[it] = inputString[it];
    }
    return 0;
}

int unscapeString(char *inputString, char *outputString, int length) {
    if(inputString==NULL||outputString==NULL) {
        return -1;
    }
    int diff = 0;
    for(int it = 0; it<length; ++it) {
        if(inputString[it] == '\\') {
            ++it;
            ++diff;
            switch(inputString[it]) {
                case 'b':
                    outputString[it-diff] = '\b';
                    break;
                case 'f':
                    outputString[it-diff] = '\f';
                    break;
                case 'n':
                    outputString[it-diff] = '\n';
                    break;
                case 't':
                    outputString[it-diff] = '\t';
                    break;
                default:
                    outputString[it-diff] = inputString[it];
            }
        } else {
            outputString[it-diff] = inputString[it];
        }
    }
    return diff;
}

int stringToInteger(char *string, int length) {
    if(string==NULL||length==0) {
        return 0;
    }

    int it = 0;
    int signal = 1;

    if(string[it]=='-') {
        signal *= -1;
        ++it; 
    } else if(string[it]=='+') {
        ++it;
    }

    int result = 0;
    int value;

    while(it<length) {
        value = (int) string[it];
        result *= 10;
        if(value>=48&&value<=57) {
            result += value - 48;
        } else {
            return 0;
        }
        ++it;
    }

    return signal*result;
}

int hasNull(char *string, int length) {
    for(int it=0; it<length; ++it) {
        if(string[it]=='\0') {
            return 1;
        }
    }
    return 0;
}

int string_index;

extern YYSTYPE yylval;

%}

/*
 * Define names for regular expressions here.
 */

%x COMMENT
%x END_STRING
%x STRING

/*
 * RX_DARROW          =>
 */
RE_WHITE                    [\ \f\r\t\v]
RE_WHILE                    [wW][hH][iI][lL][eE]
RE_TYPEID                   [A-Z][a-zA-Z0-9_]*
RE_THEN                     [tT][hH][eE][nN]
RE_POOL                     [pP][oO]{2}[lL]
RE_OF                       [oO][fF]
RE_OBJECTID                 [a-z][a-zA-Z0-9_]*
RE_NOT                      [nN][oO][tT]
RE_NEW                      [nN][eE][wW]
RE_LOOP                     [lL][oO]{2}[pP]
RE_LIN_CMT                  --.*
RE_LET                      [lL][eE][tT]
RE_ISVOID                   [iI][sS][vV][oO][iI][dD]
RE_INT_CONST                [0-9]+
RE_INHERITS                 [iI][nN][hH][eE][rR][iI][tT][sS]
RE_IN                       [iI][nN]
RE_IF                       [iI][fF]
RE_FI                       [fF][iI]
RE_ESAC                     [eE][sS][aA][cC]
RE_ELSE                     [eE][lL][sS][eE]
RE_COMMENT                  [\-][\-][^\n]*[\n]
RE_CLASS                    [cC][lL][aA][sS]{2}
RE_CHARS                    [{}()\[\],:@.;+\-*~<=]
RE_CASE                     [cC][aA][sS][eE]
RE_BOOL_CONST               (([t][rR][uU][eE])|([f][aA][lL][sS][eE]))

%%

 /*
  *  Nested comments
  */

 /*
  *  The multiple-character operators.
  */


<COMMENT>"*)"            { BEGIN(INITIAL); }
<COMMENT><<EOF>>         { BEGIN(INITIAL);
                           copyString("EOF in comment",
                           yylval.string, 14);
                           yylval.string[14] = '\0';
                           return (ERROR); }
<COMMENT>"\n"            { ++curr_lineno; }
<COMMENT>.               { ; }

<END_STRING>"\\\n"       { ; }
<END_STRING><<EOF>>      { BEGIN(INITIAL); }
<END_STRING>"\""         { BEGIN(INITIAL); }
<END_STRING>"\n"         { BEGIN(INITIAL); }
<END_STRING>.            { ; }

<STRING>"\\\n"           { ++curr_lineno; }
<STRING><<EOF>>          { BEGIN(INITIAL);
                           copyString("EOF in string constant",
                           yylval.string, 22);
                           yylval.string[22] = '\0';
                           return (ERROR); }
<STRING>"\""             { BEGIN(INITIAL);
                           int diff = unscapeString(string_buf,
                           yylval.string, string_index);
                           yylval.string[string_index-diff] = '\0';
                           return (STR_CONST); }
<STRING>"\n"             { BEGIN(INITIAL);
                           ++curr_lineno;
                           copyString("Unterminated string constant",
                           yylval.string, 28);
                           yylval.string[28] = '\0';
                           return (ERROR); }
<STRING>"\0"             { BEGIN(END_STRING);
                           copyString("String contains null character",
                           yylval.string, 30);
                           yylval.string[30] = '\0';
                           return (ERROR); }
<STRING>.                { if(string_index>=MAX_STR_CONST) {
                               BEGIN(END_STRING);
                               copyString("String constant too long",
                               yylval.string, 24);
                               yylval.string[24] = '\0';
                               return (ERROR);
                            }
                            string_buf[string_index] = yytext[0];
                            ++string_index;
                         }

{RE_COMMENT}             { ; }
{RE_WHILE}               { return (WHILE); }
{RE_THEN}                { return (THEN); }
{RE_POOL}                { return (POOL); }
{RE_OF}                  { return (OF); }
{RE_NOT}                 { return (NOT); }
{RE_NEW}                 { return (NEW); }
{RE_LOOP}                { return (LOOP); }
{RE_LET}                 { return (LET); }
{RE_ISVOID}              { return (ISVOID); }
{RE_INHERITS}            { return (INHERITS); }
{RE_IN}                  { return (IN); }
{RE_IF}                  { return (IF); }
{RE_FI}                  { return (FI); }
{RE_ESAC}                { return (ESAC); }
{RE_ELSE}                { return (ELSE); }
{RE_CLASS}               { return (CLASS); }
{RE_CASE}                { return (CASE); }
{RE_TYPEID}              { if(yyleng>MAX_STR_CONST-1) {
                               copyString("Type identifier too long",
                               yylval.string, 24);
                               yylval.string[24] = '\0';
                               curr_lineno += countLines(yytext);
                               return (ERROR);
                           }
                           copyString(yytext,yylval.string,yyleng);
                           yylval.string[yyleng] = '\0';
                           return (TYPEID); }
{RE_BOOL_CONST}          { if(yytext[0]=='t') {
                               yylval.boolean = true;
                           } else {
                               yylval.boolean = false;
                           }
                           return (BOOL_CONST); }
{RE_OBJECTID}            { if(yyleng>MAX_STR_CONST-1) {
                               copyString("Object identifier too long",
                               yylval.string, 26);
                               yylval.string[26] = '\0';
                               curr_lineno += countLines(yytext);
                               return (ERROR);
                           }
                           copyString(yytext,yylval.string,yyleng);
                           yylval.string[yyleng] = '\0';
                           return (OBJECTID); }
{RE_INT_CONST}           { yylval.integer = stringToInteger(yytext, yyleng); 
                           return (INT_CONST); }
"(*"                     { BEGIN(COMMENT); }
"*)"                     { copyString("Unmatched *)",
                           yylval.string, 12);
                           yylval.string[12] = '\0';
                           return (ERROR); }
"<-"                     { return (ASSIGN); }
"=>"                     { return (DARROW); }
"<="                     { return (LE); }
<<EOF>>                  { yyterminate(); }
"\""                     {  string_index = 0;
                            BEGIN(STRING); }
{RE_CHARS}               { yylval.string[0] = yytext[0];
                           yylval.string[1] = '\0';
                           return ((int) yytext[0]); }
{RE_WHITE}               { ; }
"\n"                     { ++curr_lineno; }
.                        { yylval.string[0] = yytext[0];
                           yylval.string[1] = '\0';
                           return (ERROR); }
 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */


%%

int yywrap(void) {
    return 1;
}
