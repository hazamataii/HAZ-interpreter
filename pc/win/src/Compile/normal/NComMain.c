#include "NComMain.h"
#include <stdlib.h>


int NComMain(char* src, unsigned long long size) {
    char* newSrc = (char*)calloc(size, sizeof(char*));
    unsigned long long newSize = 0;
    unsigned long long index = 0;
    newSrc[newSize] = 0x7f;
    ++newSize;
    newSrc[newSize] = 'H';
    ++newSize;
    newSrc[newSize] = 'A';
    ++newSize;
    newSrc[newSize] = 'Z';
    ++newSize;
    newSrc[newSize] = 'C';
    ++newSize;
    newSrc[newSize] = 'P';
    ++newSize;
    while (index < size) {
        switch(src[index]) {
            case 's':{

                break;
            }
            case 'p':{
                ++index;
                if (src[index] == 'r'){
                ++index;
                if (src[index] == 'i'){
                ++index;
                if (src[index] == 'n'){
                ++index;
                if (src[index] == 't'){
                    ++index;
                    newSrc[newSize] = 0x00;
                    while (src[index] == ' ') {
                        ++index;
                    }
                    if (src[index] == '"') {
                        ++index;
                        while (src[index] != '"') {
                            newSrc[newSize] = src[index];
                            ++newSize;
                            ++index;
                        }
                        ++index;
                        newSrc[newSize] = 0x00;
                        ++newSize;
                    } else {
                        while (src[index] != ' ') {
                            newSrc[newSize] = src[index];
                            ++newSize;
                            ++index;
                        }
                        ++index;
                        newSrc[newSize] = 0x00;
                        ++newSize;
                    }
                }
                }
                }
                }
                break;
            }

            default:{
                break;
            }
        }
        ++index;
    }


    return 0;
}