/*bool collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
    if(rect1->y >= rect2->y + rect2->h)
        return 0;
    if(rect1->x >= rect2->x + rect2->w)
        return 0;
    if(rect1->y + rect1->h <= rect2->y)
        return 0;
    if(rect1->x + rect1->w <= rect2->x)
        return 0;
    return 1;
}
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include<SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "backg.h"

int main()
{
    Background B;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen=NULL;

    screen = SDL_SetVideoMode(1368,801, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(screen==NULL)
    {
      printf("unable to set video mode: %s /n",SDL_GetError());
    }

    bool gamerunning = 1;
    const int FPS = 30;
    const int speed = 5;
    Uint32 start;
    int direction;

    initBackground(&B);

    bool b[4] = {0,0,0,0};
    while(gamerunning) {
        start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    gamerunning = 0;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP :
                            b[2]=1;
                            break;
                        case SDLK_RIGHT:
                            b[0] = 1;
                            break;
                        case SDLK_LEFT:
                            b[1] = 1;
                            break;
                        case SDLK_DOWN:
                            b[3]=1;
                            break;
                        case SDLK_ESCAPE:
                            gamerunning = 0;
                            break;
                    }
                    break;

                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_UP :
                            b[2]=0;
                            break;
                        case SDLK_RIGHT:
                            b[0] = 0;
                            break;
                        case SDLK_LEFT:
                            b[1] = 0;
                            break;
                        case SDLK_DOWN:
                            b[3]=0;
                            break;

                    }
                    break;
            }
        }

        scrolling(&B,b);
        afficherBack (&B,screen);

        SDL_Flip(screen);
        if(1000/FPS > SDL_GetTicks()-start)
        {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }
    freeBackground(&B);
    SDL_Quit();
    return 0;
}

