#include "alloc.h"
#include <stdlib.h>

unsigned char** Pools;
unsigned char** Pointers;

int CreatePools(int PoolNum) {
    Pools = (unsigned char**)calloc(PoolNum, sizeof(unsigned char**));    
    if(Pools == (void*)0) {
        
        return -1;
    }
    return 0;
}

int InitPool(int PoolNum, int bytesInPool) {

    Pools[PoolNum] = (unsigned char*)calloc(bytesInPool, sizeof(unsigned char*));

    if(Pools[PoolNum] == (void*)0){
        return -1;
    }

    return 0;
}

int GetSpot(int PoolNum, int* Location, unsigned char Type)  {

    unsigned int i = 0;
    while (Pools[PoolNum][i] != 0) {
        ++i;
    }

    Location = &Pools[PoolNum][i];
    switch(Type) {
        case 0x00:{/*Unsigned char/Char*/
            Pointers[PoolNum][i] = 1;
            break;
        }
        case 0x01:{/*Short*/
            Pointers[PoolNum][i] = 1;
            ++i;
            Pointers[PoolNum][i] = 1;
            break;
        }
        default:{
            break;
        }
    }

    return 0;
}