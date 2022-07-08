#include "CNmain.h"
#include "print.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include "window.h"

int CNmain(char* src, unsigned long long size) {
unsigned long long index = 0x0000000000000006;
int Pools = 0;
unsigned char Window = 0x00;
while (index < size) {
    switch(src[index]) {
        case 0x00:{
            ++index;
            print(src, &index);
            break;
        }
        case 0x01:{
            ++index;
            char *TMP = &src[index];
            while (src[index] != 0x00) {
                ++index;
            }
            ++index;
            unsigned char X = src[index];
            uint32_t W = src[index+4] + (src[index+3] << 8) + (src[index+2] << 16) + (src[index+1] << 24);
            index = index + 4;
            uint32_t H = src[index+4] + (src[index+3] << 8) + (src[index+2] << 16) + (src[index+1] << 24);
            index = index + 5;
            unsigned char Flag = src[index];
            
            Win_create(TMP, X, W, H, Flag, Window);
            ++Window;
            
            break;
        }
        case 0x02:{
            uint32_t Time = src[index+4] + (src[index+3] << 8) + (src[index+2] << 16) + (src[index+1] << 24);
            index = index + 4;
            SDL_Delay(Time);
            break;
        }
        case 0x03:{
            if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) {
                return -1;
            }
        }
        default:{
            break;
        }
    }
    int i = 0xFFFFFFF;
    ++index;
}


return 0;
}