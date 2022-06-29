#include <stdio.h>

char *TOKEN_N[] = {NULL, "DARROW"};

extern int yylex(void);
//extern char *yytext;
extern int curr_lineno;
//extern void *yylval;
extern FILE *fin;

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
            printf("\n");
        }
        printf("%4d: %s ", curr_lineno, yytoken[ntoken-258]);
        old_lineno = curr_lineno;
        ntoken = yylex();
    }
    printf("\n");

    fclose(fin);
    return 0;
}
