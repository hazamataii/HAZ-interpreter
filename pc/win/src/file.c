#include "file.h"
#include <stdio.h>
#include <stdlib.h>

int FileR(const char* src, char** dest, unsigned long long* i, const unsigned char Debug) {

    if (Debug == 0x01) {
        if (src == (void*)0) {
            printf("ERROR: NO SOURCE FILE NAME\n");
            return -1;
        }
        FILE* f = fopen(src, "r");
        if (f == (void*)0){
        printf("THE FILE \"%s\" HAS FAILED TO OPEN\n", src);
        return -1;
        }
        fseek(f, 0L, SEEK_END);
        *i = ftell(f);
        rewind(f);
        *dest = (char*)calloc((*i + 1), sizeof(char*));
        if (*dest == (void*)0) {
            printf("DESTINATION ALLOCATION FAILED\n");
            return -1;
        }
        fread(*dest, 1, *i, f);
        fclose(f);
    } else {
        if (src == (void*)0) {
            return -1;
        }
        FILE* f = fopen(src, "r");
        if (f == (void*)0){
        return -1;
        }
        fseek(f, 0L, SEEK_END);
        *i = ftell(f);
        rewind(f);
        *dest = (char*)calloc((*i + 1), sizeof(char*));
        if (*dest == (void*)0) {
            return -1;
        }
        fread(*dest, 1, *i, f);
        fclose(f);
    }
    return 0;
}