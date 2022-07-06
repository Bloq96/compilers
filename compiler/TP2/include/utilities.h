#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stdbool.h>

typedef union BasicTypes{
    int integer;
    bool boolean;
    char string[1025];
} YYSTYPE;

#endif //_UTILITIES_H_
