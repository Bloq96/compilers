#ifndef _GABRIEL_FUNCTIONS_H_
#define _GABRIEL_FUNCTIONS_H_

int compareStrings(char *string1, char *string2, int length);

int readLine(FILE* file,char *buffer, int max_length);

int stringLength(char *string);
    
int stringToInteger(char *string, int length);

#endif // _GABRIEL_FUNCTIONS_H_
