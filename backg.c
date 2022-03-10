//#include "backg.h"
/*void initialiser_background (background *b)
{
b->background=IMG_Load("backg.jpg");
b->camera.x=0;
b->camera.y=0;
b->camera.w=1368;
b->camera.h=800;

}
void afficher_background (SDL_Surface *screen,background *b)
{
	SDL_BlitSurface(b->background,&(b->camera),screen,NULL);
}
void scrolling_right (background *b)
{
	if (b->camera.x<=b->camera.w){
		 
		b->camera.x+=70; }

/*if (b->posback1.x<=b->posback1.w){
		
		b->posback1.x+=70; }
   if (b->posback2.x<=b->posback2.w){
		
		b->posback2.x+=70; }
*/
/*
}
void scrolling_left (background *b)
{
	if (b->camera.x>=0){

b->camera.x-=70 ;}
/*if (b->posback1.x>=0){
		
		b->posback1.x-=70; }
   if (b->posback2.x>=0){
		
		b->posback2.x-=70; }
*/
/*
}
void free_memory (background *b )
{ SDL_FreeSurface (b->mq) ;
 SDL_FreeSurface (b->mq2) ;
 
 
 SDL_FreeSurface (b->background) ;



 SDL_Quit () ;

}
*/
#include "backg.h"
void initBackground(Background *B)
{
  Mix_Music *music;
  B->PositionBg.x=0;
  B->PositionBg.y=0;

  B->positionperso.x=0;
  B->positionperso.y=150;

  B->camera.x=0;
  B->camera.y=0;
  B->camera.w = 1368;
  B->camera.h = 801;

 //image
  B->BgImg= IMG_Load("backg.jpg");
  if (B->BgImg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  B->PersoImg=IMG_Load("perso.jpeg");
  if (B->PersoImg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  //son
  if(SDL_Init(SDL_INIT_AUDIO)==-1)
  {
    printf("SDL_Init: %s\n", SDL_GetError());
  }
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
  {
    printf("Mix_OpenAudio: %s\n", Mix_GetError());
  }
  music=Mix_LoadMUS("music.mp3");
  Mix_PlayMusic(music, -1);
  Mix_AllocateChannels(10);
  Mix_VolumeMusic(MIX_MAX_VOLUME);

  }
void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
}
void afficherBack (Background *B,SDL_Surface *screen)
{

  SDL_BlitSurface(B->BgImg,&(B->camera),screen,&(B->PositionBg));
  SDL_BlitSurface(B->PersoImg,NULL,screen,&(B->positionperso));

}





void scrolling(Background *B, bool b[])
{
  const int speed=5;
  if (b[0]) //right
  {
    if(B->positionperso.x<640)
    {
      B->positionperso.x+= 8;
    }

    if(B->positionperso.x>=640)
    {
      B->camera.x += speed;
    }

    if(B->camera.x >=2555-1368)
    {
      B->camera.x = 0;
      B->positionperso.x=0;
    }
  }
  if(b[1]) //left
  {
    if(B->positionperso.x<=640)
    {
      B->camera.x -= speed;
    }

    if(B->camera.x  <= 0)
    {
      B->camera.x  = 0;
      B->positionperso.x-=8;
    }
  }
  if(b[2]) //up
  {
    B->positionperso.y-=8;

    if(B->positionperso.y<=0)
    {
      B->positionperso.y=0;
    }
  }
  if(b[3]) //down
  {
    B->positionperso.y+=8;
    if(B->positionperso.y>=801)
    {
      B->positionperso.y=150;
    }
  }
}
