#ifndef Enigme_H
#define Enigme_h
#include <SDL/SDL.h>
#include <SDL/SDL_enigme.h>
#define SCREEN_W 1367
#define SCREEN_H 797

typedef struct
{
	char question[30] ;
	char reponse1[30] ;
	char reponse2[30] ;
	char reponse3[30] ;
	int reponsejuste ;
	SDL_Surface *q;
	SDL_Surface *r1;
	SDL_Surface *r2;
	SDL_Surface *r3;
	SDL_Rect pos1;
        SDL_Rect pos2;
	SDL_Rect pos3;
	SDL_Rect pos4;

}enigme;


void afficherEnigme(enigme e, SDL_Surface * screen);
void InitEnigme(enigme * e, char *nomfichier);
void animer (enigme * e);
void sauvegarder (personne p, background b, char * nomfichier) ; 
int charger ( personne * p, background *b , char * nomfichier);
enigme genererEnigme(char * nom_du _fichier) ;
enigme genererEnigmemed(char * nom_du _fichier) ;
enigme genererEnigmehard(char * nom_du _fichier) ;


#endif
