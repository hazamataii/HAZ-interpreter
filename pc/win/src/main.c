#include <stdio.h>
#include "file.h"
#include <unistd.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Compiled/normal/CNmain.h"
#include "unCompiled/normal/Nmain.h"
#include "Compile/normal/NComMain.h"

int main(int arcv, char ** argv) {
unsigned char Debug = 0x00, Compile = 0x00;
int FName = 0;
char* FPath = (void*)0;
int i = 0;
while (i < arcv) {
    if (argv[i][0] == '-') {
        switch(argv[i][1]) {
            case 'd':{
                Debug = 0x01;
                printf("RUNNING IN DEBUG MODE\n");
                break;
            }
            case 'D':{
                Debug = 0x01;
                printf("RUNNING IN DEBUG MODE\n");
                break;
            }
            case 'c':{
                Compile = 0x01;
                if (Debug == 0x01){
                printf("COMPILING SOURCE\n");
                break;
                }
            }
            case 'C':{
                Compile = 0x01;
                if (Debug == 0x01){
                printf("COMPILING SOURCE\n");
                }
                break;
            }
            default:{
                printf("WARNING: \"%s\" IS NOT A VALID ARGUMENT\n", argv[i]);
                break;
            }
        }
    } else {
        FName = i;
        int Ti = 0;
        while (argv[FName][Ti] != '\0') {
            ++Ti;
        }
        FPath = (char*)calloc((Ti+1),sizeof(char*));
        int TTi = 0;
        while (TTi <= Ti) {
            FPath[TTi] = argv[FName][TTi];
            ++TTi;
        }
        unsigned char F = 0x00;
        while (argv[FName][TTi] != '\\' && argv[FName][TTi] != '/') {
            --TTi;
        }
        if (argv[FName][TTi] == '/') {
            F = 0x01;
        }
        char Dirr[TTi+1];
        Ti = 0;
        while (Ti != TTi) {
            Dirr[Ti] = argv[FName][Ti];
            ++Ti;
        }
        if (F == 0x01) {
        Dirr[TTi] = '/';
        } else {
        Dirr[TTi] = '\\';
        }
        chdir(Dirr);
    }
    ++i;
}

char* FileCont = (void*)0;
unsigned long long FileSize = 0;
if (FileR(argv[FName], &FileCont, &FileSize, Debug) != 0) {
if (Debug == 0x01) {
    printf("ATTEMPT TO READ \"%s\" HAS FAILED\n", argv[i]);
}
return -1;
}
unsigned char FType = 0x00;
if (FileCont[0] == 0x7F) {
    if (FileCont[1] == 'H') {
    if (FileCont[2] == 'A') {
    if (FileCont[3] == 'Z') {
    if (FileCont[4] == 'C') {
    if (FileCont[5] == 'P') {
        FType = 0x01;
}}}}}
}
if (SDL_Init(SDL_INIT_NOPARACHUTE) != 0) {
    if (Debug == 0x01) {
        printf("SDL INITIALIZATION FAILED");
    }
    return -1;
}

/*printf("%i, %i\n", Compile, FType);*/
switch(Compile) {
    case 0x00:{
        if (FType == 0x00) {
            Nmain(FileCont, FileSize);
        } else {
            CNmain(FileCont, FileSize);
        }
    }
    case 0x01:{
        NComMain(FileCont, FileSize);
    }
    default:{
        break;
    }
}

/*if (Debug == 0x01){
printf("Success\n%s\n", argv[FName]);
}*/
/*SDL_Delay(2000);
printf("%s\n", FileCont);*/
free(FileCont);
return 0;
}