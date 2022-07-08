#include "window.h"
#include<stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>

struct Node {
    SDL_Window* win;
    struct Node* next;
};

struct Node* head = NULL;

int Win_create(const char* Title, unsigned char X, int Width, int Height, unsigned char Type, unsigned char winNum) {

    uint32_t Flag = 0, xx = 0, yy = 0;
    switch(X) {
        case 0x00:{
            xx = SDL_WINDOWPOS_CENTERED;
            yy = SDL_WINDOWPOS_CENTERED;
            break;
        }
        case 0x01:{
            xx = SDL_WINDOWPOS_CENTERED;
            yy = SDL_WINDOWPOS_UNDEFINED;
            break;
        }
        case 0x10:{
            xx = SDL_WINDOWPOS_UNDEFINED;
            yy = SDL_WINDOWPOS_CENTERED;
            break;
        }
        case 0x11:{
            xx = SDL_WINDOWPOS_UNDEFINED;
            yy = SDL_WINDOWPOS_UNDEFINED;
            break;
        }
        default:{
            break;
        }
    }

    switch(Type) {
        case 0x00:{
            Flag = SDL_WINDOW_SHOWN;
            break;
        }
        case 0x01:{
            Flag = SDL_WINDOW_OPENGL;
            break;
        }
        case 0x02:{
            Flag = SDL_WINDOW_VULKAN;
            break;
        }
        default:{
            break;
        }
    }

   /* switch(winNum){
        case 0:{
            head = (struct Node*)calloc(1, sizeof(struct Node));
            head->win = SDL_CreateWindow(Title, xx, yy, Width, Height, Flag);
            printf("%llu\n", sizeof(*head));
            if(head->win == NULL) {
            return -1;
            }
        }
    }*/
    if (winNum == 0){
    }

    return 0;
}