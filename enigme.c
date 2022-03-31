#include "enigme.h"



int resolutionEnigme(enigme *e)
{
    SDL_Event event;
   	
	SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_KEYDOWN:
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_1 :
                e->reponseuser=1;
                break;
            case SDLK_2 :
                e->reponseuser=2;
                break;
            case SDLK_3 :
                e->reponseuser=3;
                break;
		
            }
        }
        break;
        
    }
	printf("\n");
	printf("Vous avez choisi la réponse numéro :%d",e->reponseuser);
	printf("\n");
    if(e->reponseuser==e->reponsejuste)
        return 1;
        else
    return 0;
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
    police = TTF_OpenFont("",50);
    pQ = TTF_OpenFont("",70);
    Question = TTF_RenderText_Blended(pQ,e.question,CouleurNoir);
    choix1  = TTF_RenderText_Blended(police,e.reponse1,CouleurNoir);
    choix2  = TTF_RenderText_Blended(police,e.reponse2,CouleurNoir);
    choix3  = TTF_RenderText_Blended(police,e.reponse3,CouleurNoir);


// rect :

    positionQ.x=100;
    positionQ.y=75;

    positionr1.x=100;
    positionr1.y=150;

    positionr2.x=100;
    positionr2.y=200;

    positionr3.x=100;
    positionr3.y=250;



    SDL_BlitSurface(Question,NULL,screen,&positionQ);

    SDL_BlitSurface(choix1,NULL,screen,&positionr1);

    SDL_BlitSurface(choix2,NULL,screen,&positionr2);

    SDL_BlitSurface(choix3,NULL,screen,&positionr3);

    SDL_Flip(screen);

}


void genererEnigme(enigme *e )
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
        fscanf(fq,"%s\n",e->question);
        fscanf(fch,"%s %s %s\n",e->r1,e->r2,e->r3);
        fscanf(frep,"%d\n",&e->reponsejuste);
    }

}

void genererEnigmemed(enigme *e )
{
    int r,i;
    srand(time(NULL));
    FILE *fq=NULL;
    FILE *fch=NULL;
    FILE *frep=NULL;

    fq=fopen("medquestion.txt","r");
    fch=fopen("medchoix.txt","r");
    frep=fopen("medreponseJuste.txt","r");

    r=rand()%4;

    for (i=0 ; i<=r ; i++)
    {
        fscanf(fq,"%s\n",e->question);
        fscanf(fch,"%s %s %s\n",e->r1,e->r2,e->r3);
        fscanf(frep,"%d\n",&e->reponsejuste);
    }

}

void genererEnigmehard(enigme *e )
{
    int r,i;
    srand(time(NULL));
    FILE *fq=NULL;
    FILE *fch=NULL;
    FILE *frep=NULL;

    fq=fopen("hardquestion.txt","r");
    fch=fopen("hardchoix.txt","r");
    frep=fopen("hardreponseJuste.txt","r");

    r=rand()%4;

    for (i=0 ; i<=r ; i++)
    {
        fscanf(fq,"%s\n",e->question);
        fscanf(fch,"%s %s %s\n",e->r1,e->r2,e->r3);
        fscanf(frep,"%d\n",&e->reponsejuste);
    }

}


