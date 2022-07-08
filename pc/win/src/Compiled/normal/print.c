#include "print.h"
#include <stdio.h>


int print(char* src, unsigned long long* CurrIndex) {
    printf("%s", &src[*CurrIndex]);
    while (src[*CurrIndex] != 0x00) {
        ++*CurrIndex;
    }
    return 0;
}