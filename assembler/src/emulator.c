#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define BUFFER_LENGTH 5
#define MEMORY_LENGTH 1000

int readNext(FILE *file,char *buffer, int length) {
    if(file==NULL) {
        printf("emulator: readNext: NULL file.\n");
        return -2;
    }
    if(buffer==NULL) {
        printf("emulator: readNext: NULL buffer.\n");
        return -2;
    }
    if(length<1) {
        return 0;
    }
    int aux = fscanf(file,"%c",&(buffer[0]));
    while(aux!=EOF&&(buffer[0]==' '||buffer[0]=='\n')) {
        aux = fscanf(file,"%c",&(buffer[0]));
    }
    if(aux==EOF) {
        buffer[0] = '\0';
        return EOF;
    }
    int cnt = 0;
    while(cnt<(length-1)&&aux!=EOF&&buffer[cnt]!=' '&&
    buffer[cnt]!='\n') {
        ++cnt;
        aux = fscanf(file,"%c",&(buffer[cnt]));
    }
    buffer[cnt] = '\0'; 
    return cnt;
}

int main(int argc, char *argv[]) {
    if(argc<2) {
        printf("emulator: Specify an input file.\n");
        return 1;
    }
    FILE *inputFile;
    inputFile = fopen(argv[1],"r");
    if(inputFile == NULL) {
        printf("emulator: File does not exist.\n");
        return 1;
    }
    char buffer[BUFFER_LENGTH];
    int aux;
    aux = readNext(inputFile,buffer,BUFFER_LENGTH);
    if(aux!=EOF&&compareStrings(buffer,"MV1",aux)) {
        fclose(inputFile);
        printf("emulator: Program must start with MV1.\n");
        return 1;
    }
    int pc;
    aux = readNext(inputFile,buffer,BUFFER_LENGTH);
    if(aux!=EOF) {
        pc = stringToInteger(buffer,aux);
    }
    int sp;
    aux = readNext(inputFile,buffer,BUFFER_LENGTH);
    if(aux!=EOF) {
        sp = stringToInteger(buffer,aux);
    }
    int programLength;
    aux = readNext(inputFile,buffer,BUFFER_LENGTH);
    if(aux!=EOF) {
        programLength = stringToInteger(buffer,aux);
    }
    int memory[MEMORY_LENGTH]; 
    int it = 0;
    aux = readNext(inputFile,buffer,BUFFER_LENGTH);
    while(aux!=EOF&&it<MEMORY_LENGTH) {
        memory[it] = stringToInteger(buffer,aux);
        aux = readNext(inputFile,buffer,BUFFER_LENGTH);
        ++it;
    }
    fclose(inputFile);
    for(aux=0;aux<it;++aux) {
        printf("%d: %d\n",aux,memory[aux]);
    }
    int ac = 0;
    printf("PC: %d - SP: %d - AC: %d - MEMORY: %d\n",pc,sp,ac,memory[pc]);
    while(memory[pc]!=16) {
        //printf("PC: %d - SP: %d - AC: %d - MEMORY: %d => ",pc,sp,ac,memory[pc]);
        ++pc;
        switch(memory[pc-1]) {
            case 1:
                printf("%d: LOAD %d => ",pc-1,memory[pc]);
                ac = memory[pc+1+memory[pc]];
                printf("AC = %d\n",ac);
                break;
            case 2:
                printf("%d: STORE %d => ",pc-1,memory[pc]);
                memory[pc+1+memory[pc]] = ac;
                printf("MEMORY[%d] =  %d\n",pc+1+memory[pc],
                memory[pc+1+memory[pc]]);
                break;
            case 3:
                printf("%d: ADD %d => ",pc-1,memory[pc]);
                ac = ac + memory[pc+1+memory[pc]];
                printf("AC = %d\n",ac);
                break;
            case 4:
                printf("%d: SUB %d => ",pc-1,memory[pc]);
                ac = ac - memory[pc+1+memory[pc]];
                printf("AC = %d\n",ac);
                break;
            case 5:
                printf("%d: JMP %d => ",pc-1,memory[pc]);
                pc = pc+memory[pc];
                printf("PC = %d\n",pc+1);
                break;
            case 6:
                printf("%d: JPG %d => ",pc-1,memory[pc]);
                if(ac>0) {
                    pc = pc+memory[pc];
                }
                printf("PC = %d\n",pc+1);
                break;
            case 7:
                printf("%d: JPL %d => ",pc-1,memory[pc]);
                if(ac<0) {
                    pc = pc+memory[pc];
                }
                printf("PC = %d\n",pc+1);
                break;
            case 8:
                printf("%d: JPE %d => ",pc-1,memory[pc]);
                if(ac==0) {
                    pc = pc+memory[pc];
                }
                printf("PC = %d\n",pc+1);
                break;
            case 9:
                printf("%d: JPNE %d => ",pc-1,memory[pc]);
                if(ac!=0) {
                    pc = pc+memory[pc];
                }
                printf("PC = %d\n",pc+1);
                break;
            case 10:
                printf("%d: PUSH %d => ",pc-1,memory[pc]);
                --sp;
                memory[sp] = memory[pc+1+memory[pc]];
                printf("SP = %d | MEMORY[%d] =  %d\n",sp,sp,
                memory[sp]);
                break;
            case 11:
                printf("%d: POP %d => ",pc-1,memory[pc]);
                memory[pc+1+memory[pc]] = memory[sp];
                ++sp;
                printf("SP = %d | MEMORY[%d] =  %d\n",sp,
                pc+1+memory[pc],memory[pc+1+memory[pc]]);
                break;
            case 12:
                printf("%d: READ %d => ",pc-1,memory[pc]);
                scanf("%d",&(memory[pc+1+memory[pc]]));
                printf("MEMORY[%d] =  %d\n",pc+1+memory[pc],
                memory[pc+1+memory[pc]]);
                break;
            case 13:
                printf("%d: WRITE %d => ",pc-1,memory[pc]);
                printf("%d\n",memory[pc+1+memory[pc]]);
                break;
            case 14:
                printf("%d: CALL %d => ",pc-1,memory[pc]);
                --sp;
                memory[sp] = pc+1;
                pc = pc+memory[pc];
                printf("PC = %d | SP = %d | MEMORY[%d] =  %d\n",pc+1,
                sp,sp,memory[sp]);
                break;
            case 15:
                --pc;
                printf("%d: RET => ",pc);
                pc = memory[sp]-1;
                ++sp;
                printf("PC = %d | SP = %d\n",pc+1,sp);
                break;
        }
        //printf("PC: %d - SP: %d - AC: %d - MEMORY: %d => ",pc,sp,ac,memory[pc]);
        ++pc;
    }
    return 0;
}
