#include <stdio.h>

int compareStrings(char *string1, char *string2, int length) {
    for(int it=0;it<length;++it) {
        if((int)string1[it]<(int)string2[it]) {
            return -1;
        } else if((int)string1[it]>(int)string2[it]) {
            return 1;
        } else if(string1[it]=='\0') { //!Permite que uma string menor seja reconhecida como correta!
            break;
        }
    }
    return 0; 
}
int readLine(FILE* file, char *buffer, int max_length) {
    if(file==NULL||buffer==NULL) return -1;
    int it;
    for(it=0;it<max_length-1;++it) {
        if(fscanf(file,"%c",&buffer[it])==EOF) {
            buffer[it] = '\0';
            return it?it:-1;
        } else if(buffer[it]=='\n') {
            break;
        }
    }
    buffer[it] = '\0';
    return it;
}

int stringLength(char *string) {
    if(string==NULL) {
        return 0;
    }

    int length = 0;
    while(string[length]!='\0') {
        ++length;
    }

    return length;
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
