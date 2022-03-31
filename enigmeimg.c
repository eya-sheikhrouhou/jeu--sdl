#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "enigme.h"
#include <time.h>
enigme initEnigme ()
{
  enigme e;
  e.f = fopen("lesenigmes.txt", "r");
 e.back = IMG_Load("letter.jpg");
 return e;
}

void genererEnigme(enigme *e)
{
    int r,i;
    srand(time(NULL));
    FILE *fq=NULL;
    FILE *fch=NULL;
    FILE *frep=NULL;

    fq=fopen("question.txt","r");
    fch=fopen("choix.txt","r");
    frep=fopen("reponseJuste.txt","r");

    r=rand()%4;

    for (i=0 ; i<=r ; i++)
    {
        fscanf(fq,"%s",e->question);
        fscanf(fch,"%s %s %s",e->r1,e->r2,e->r3);
        fscanf(frep,"%d",&e->numRepJuste);
    }
}
void afficherEnigme(enigme e, SDL_Surface * screen)
{
    SDL_Surface * Question=NULL, * choix1=NULL, * choix2=NULL, *choix3=NULL;
    TTF_Font *police=NULL;
    TTF_Font *pQ=NULL;
    SDL_Rect positionQ;
    SDL_Rect positionr1;
    SDL_Rect positionr2;
    SDL_Rect positionr3;
    SDL_Color CouleurNoir = {255,255,255};
    police=TTF_OpenFont("font.ttf",50);
    pQ=TTF_OpenFont("font.ttf",70);
    Question=TTF_RenderText_Blended(pQ,e.question,CouleurNoir);
    choix1=TTF_RenderText_Blended(police,e.r1,CouleurNoir);
    choix2=TTF_RenderText_Blended(police,e.r2,CouleurNoir);
    choix3=TTF_RenderText_Blended(police,e.r3,CouleurNoir);
// rect :
    positionQ.x=100;
    positionQ.y=75;
    positionr1.x=100;
    positionr1.y=150;
    positionr2.x=100;
    positionr2.y=200;
    positionr3.x=100;
    positionr3.y=250;
    //Les Blits
    SDL_BlitSurface(Question,NULL,screen,&positionQ);
    SDL_BlitSurface(choix1,NULL,screen,&positionr1);
    SDL_BlitSurface(choix2,NULL,screen,&positionr2);
    SDL_BlitSurface(choix3,NULL,screen,&positionr3);
    SDL_Flip(screen);
}
