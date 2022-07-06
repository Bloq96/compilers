#include <stdio.h>
#include "utilities.h"

#define MAX_STR_CONST 1025

FILE *fin;
int curr_lineno = 1;

YYSTYPE yylval;
