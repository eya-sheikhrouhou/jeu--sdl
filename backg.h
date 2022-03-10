#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
typedef struct
{
  SDL_Surface *BgImg;
  SDL_Surface *PersoImg;
  SDL_Rect PositionBg;
  SDL_Rect positionperso;
  SDL_Rect camera;
}Background;
void initBackground(Background *B);
void freeBackground(Background *B);
void afficherBack (Background *B,SDL_Surface *screen);
void scrolling(Background *B, bool b[]);

