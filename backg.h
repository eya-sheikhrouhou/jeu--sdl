/*#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct  
{

SDL_Surface *background,*mq,*mq2; /* !< Surface. */
/*SDL_Rect camera,posback2,posback1; /* !< Rectangle */

/*}background;
void initialiser_background (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b);
void scrolling_left (background *b);
void free_memory (background *b );
*/
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

