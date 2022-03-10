#ifndef Image_H
#define Image_h
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1368
#define SCREEN_H 801

typedef struct 
{
char quest[100];
char rep1[100];
char rep2[100];
char rep3[100];
SDL_Surface *image;
int rep_juste;
}enigme;
void initEnigme(enigme *e,char *nomfichier);
enigme generer (char *nomfichier);
void afficherEnigme(enigme e,SDL_Surface *screen);
void animer(enigme *e);
