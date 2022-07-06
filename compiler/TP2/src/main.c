#include <stdio.h>
#include "utilities.h"

char *TOKEN_N[] = {NULL, "DARROW"};

extern int yylex(void);
//extern char *yytext;
extern int curr_lineno;
extern YYSTYPE yylval;
extern FILE *fin;
char string[20];

int integerToString(int integer, char *string, int length) {
    int signal = 0;
    if(string==NULL) {
        return 0;
    }
    if(integer<0) {
        signal = 1;
        integer *= -1;
    }
    int it;
    for(it = 0; it<(length-1); ++it) {
        string[it] = (char)((integer%10)+48);
        integer /= 10;
        if(integer == 0) {
            ++it;
            if(signal==1) {
                string[it] = '-';
                ++it;
            }
            break;
        }
    }
    string[it] = '\0';
    char aux;
    int temp = it/2;
    for(int it2 = 0; it2<temp; ++it2) {
        aux = string[it2];
        string[it2] = string[it-1-it2];
        string[it-1-it2] = aux;
    }
    return it;
}

char *getValue(int number) {
    switch(number) {
        case 276:
            integerToString(yylval.integer,string,20);
            return string;
        case 277:
            return (yylval.boolean)?"true":"false";
        case 258:
        case 259:
        case 260:
        case 261:
        case 262:
        case 263:
        case 264:
        case 265:
        case 266:
        case 267:
        case 268:
        case 269:
        case 270:
        case 271:
        case 272:
        case 273:
        case 274:
        case 280:
        case 281:
        case 282:
            return "";
        default:
            return yylval.string;
    }
}

int main() {

    char *yytoken[] = {
        "CLASS",
        "ELSE",
        "FI",
        "IF",
        "IN",
        "INHERITS",
        "LET",
        "LOOP",
        "POOL",
        "THEN",
        "WHILE",
        "CASE",
        "ESAC",
        "OF",
        "DARROW",
        "NEW",
        "ISVOID",
        "STR_CONST",
        "INT_CONST",
        "BOOL_CONST",
        "TYPEID",
        "OBJECTID",
        "ASSIGN",
        "NOT",
        "LE",
        "ERROR",
        "LET_STMT"
    }; 

    fin = fopen("input/input.txt","r");
    if(fin==NULL) {
        printf("main: Can not open input file!\n");
        return 1;
    }

    int ntoken;
    int old_lineno = 0;

    ntoken = yylex();
    while(ntoken) {
        if(old_lineno<curr_lineno) {
            printf("\n%4d: ", curr_lineno);
        }
        printf("%s[%s] ",
        (ntoken<258||ntoken>285)?"":
        ((ntoken==285)?yytoken[26]:yytoken[ntoken-258]),
        getValue(ntoken));
        old_lineno = curr_lineno;
        ntoken = yylex();
    }
    printf("\n");

    fclose(fin);
    return 0;
}
