#include "Nmain.h"
#include <stdio.h>

int Nmain(char* src, unsigned long long size) {
unsigned long long index = 0;
while (index < size) {
    switch(src[index]) {
        case 'p':{
            ++index;
            if (src[index] == 'r') {
            ++index;
            if (src[index] == 'i') {
            ++index;
            if (src[index] == 'n') {
            ++index;
            if (src[index] == 't') {
            while (src[index] != '"') {
                ++index;
            }
            ++index;
            unsigned long long TMP = index;
            while (src[index] != '"') {
                ++index;
            }
            src[index] = 0x00;
            printf("%s", src[TMP]);
            }
            }
            }
            }
            break;
        }
        case ';': {
            ++index;
            while (src[index] != ';') {++index;}
            break;
        };
        default:{
            break;
        }
    }
    ++index;
}
return 0;
}