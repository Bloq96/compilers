#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define BUFFER_LENGTH 256
#define LOOKUP_LENGTH 10

struct LookupTable {
    char name[LOOKUP_LENGTH][BUFFER_LENGTH/4];
    int value[LOOKUP_LENGTH];
};

int lookup(struct LookupTable *lut,char *var,int length) {
    for(int it=0;it<LOOKUP_LENGTH;++it) {
        if(!compareStrings(lut->name[it],var,length)) {
            return lut->value[it];
        }
    }
    return -1;
}

int encode(char *var,int length) {
    if(length<3) {
        return 16;
    }
    switch(var[0]) {
        case 'L':
            return 1;
        case 'S':
            if(var[1]=='T') {
                return 2;
            } else {
                return 4;
            }
        case 'A':
            return 3;
        case 'J':
            if(var[2]=='G') {
                return 6;
            } else if(var[2]=='L') {
                return 7;
            } else if(var[2]=='E') {
                return 8;
            } else if(var[2]=='N') {
                return 9;
            } else {
                return 5;
            }
        case 'P':
            if(var[1]=='O') {
                return 11;
            } else {
                return 10;
            }
        case 'R':
            if(var[2]=='T') {
                return 15;
            } else {
                return 12;
            }
        case 'W':
            if(var[1]=='O') {
                return 0;
            } else {
                return 13;
            }
        case 'C':
            return 14;
        case 'H':
            return 16;
        default:
            return 17;
    }
}

void splitLine(char *input,int inputLength,char *output[3],
int *outputLength) {
    int el = 0, it2 = 0;
    for(int it=0;it<inputLength;++it) {
        if(input[it]>32&&input[it]!=';') {
            it2 = 0;
            while(input[it]>32&&input[it]!=';'&&input[it]!=':'&&
            it2<(outputLength[el]-1)) {
                output[el][it2] = input[it];
                ++it2;
                ++it;
            }
            if(input[it]==':'&&it2<(outputLength[el]-1)) {
                output[el][it2] = ':';
                ++it2;
            }
            output[el][it2] = '\0';
            outputLength[el] = it2;
            ++el; 
        }
        if(input[it]=='\0'||input[it]==';'||el==3) {
            for(;el<3;++el) {
                output[el][0] = '\0';
                outputLength[el] = 0;
            }
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc<2) {
        return 1;
    }
    FILE *inputFile;
    inputFile = fopen(argv[1],"r");
    if(inputFile == NULL) {
        return 1;
    }

    char buffer[BUFFER_LENGTH];

    const int SMALL_BUFFER_LENGTH = BUFFER_LENGTH/4;
    char array[3][SMALL_BUFFER_LENGTH];
    char *strings[3];
    int lengths[3] = {SMALL_BUFFER_LENGTH,SMALL_BUFFER_LENGTH,
    SMALL_BUFFER_LENGTH};

    struct LookupTable lut;
    

    int index = 0;
    int pc = 0;
    int len;

    len = readLine(inputFile,buffer,BUFFER_LENGTH);
    while(len!=EOF) {
        lengths[0] = SMALL_BUFFER_LENGTH;
        lengths[1] = SMALL_BUFFER_LENGTH;
        lengths[2] = SMALL_BUFFER_LENGTH;
        strings[0] = array[0];
        strings[1] = array[1];
        strings[2] = array[2];
        splitLine(buffer,BUFFER_LENGTH,strings,lengths);
        if(strings[0][lengths[0]-1]==':') {
            for(len=0;len<(lengths[0]-1);++len) {
                lut.name[index][len] = strings[0][len];
            }
            lut.name[index][len] = '\0';
            lut.value[index] = pc;
            ++index;
        } else {
            if(!compareStrings(strings[0],"END",lengths[0])) {
                break;
            } else if(compareStrings(strings[0],"WORD",lengths[0])) {
                ++pc;
            }
        }
        if(lengths[1]>0) {
            if(!compareStrings(strings[1],"END",lengths[1])) {
                break;
            } else if(compareStrings(strings[1],"WORD",lengths[1])) {
                ++pc;
            }
        } 
        if(lengths[2]>0) {
            ++pc;
        }
        len = readLine(inputFile,buffer,BUFFER_LENGTH);
    }
    
    for(int it=0;it<index;++it) {
        printf("%s: %d\n",lut.name[it],lut.value[it]);
    }

    fclose(inputFile);

    inputFile = fopen(argv[1],"r");
    FILE *outputFile;
    outputFile = fopen("output.txt","w");
    
    fprintf(outputFile,"MV1 0 999 %d ",pc);
    
    pc = 0; 
    len = readLine(inputFile,buffer,BUFFER_LENGTH);
    while(len!=EOF) {
        lengths[0] = SMALL_BUFFER_LENGTH;
        lengths[1] = SMALL_BUFFER_LENGTH;
        lengths[2] = SMALL_BUFFER_LENGTH;
        strings[0] = array[0];
        strings[1] = array[1];
        strings[2] = array[2];
        splitLine(buffer,BUFFER_LENGTH,strings,lengths);
        ++pc;
        if(strings[0][lengths[0]-1]!=':') {
            len = encode(strings[0],lengths[0]);
            if(len>0) {
                if(len<17) {
                    fprintf(outputFile,"%d ",encode(strings[0],
                    lengths[0]));
                }
                if(len<15) {
                    ++pc;
                    fprintf(outputFile,"%d ",(lookup(&lut,strings[1],
                    lengths[1])-pc));
                }
            }
        } else {
            len = encode(strings[1],lengths[1]);
            if(len>0) {
                if(len<17) {
                    fprintf(outputFile,"%d ",encode(strings[1],
                    lengths[1]));
                }
                if(len<15) {
                    ++pc;
                    fprintf(outputFile,"%d ",(lookup(&lut,strings[2],
                    lengths[2])-pc));
                }
            } else if(len==0) {
                fprintf(outputFile,"%s ",strings[2]);
            }
        }
        len = readLine(inputFile,buffer,BUFFER_LENGTH);
    }
    fprintf(outputFile,"\n");

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
