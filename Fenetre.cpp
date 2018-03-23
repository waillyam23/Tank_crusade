#include <iostream>
#include <SDL.h>
using namespace std;
int main( int argc,char *argv[])
{

// creation de la fenetre

  SDL_Init(SDL_INIT_EVERYTHING);
//initialisation des variables utiles
SDL_Rect destR;
destR.x= 0;
destR.y=500;
destR.w=40;
destR.h=35;


  SDL_Renderer* renderer; //l'oultil de rendu
  SDL_Surface* surf;//la surface possedant l'image

  SDL_Window *window;//la fenètre
//lancement de la fenètre
  window = SDL_CreateWindow("Tank_Crusade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500,800,SDL_WINDOW_RESIZABLE);
//initialisation du rendu et association avec la fenètre
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//test si la fenetre est créée
  if(window==NULL)
    {
      cout<<"BRUH";
      }


      //tous les test vont ici
  surf = SDL_LoadBMP("sdl_icone.bmp");//charge l'image dans la surface

      SDL_RenderPresent(renderer);//?


//mise a jour
  SDL_Event event;
  bool running=true;
  while(running)
    {
    {//endroit ou on code tout
destR.x=destR.x+1;
if(destR.x>1400)
destR.x=100;

  SDL_BlitSurface(surf, NULL, SDL_GetWindowSurface(window),&destR);//Blite la surface sur le rendu de la fenetre
SDL_UpdateWindowSurface(window);//rafraichit le rendu dans la fenètre
SDL_Delay(5);


    }
      while(SDL_PollEvent(&event))
	{
	  if(event.type==SDL_QUIT)
	  {
	    running=false;
	    break;
	  }
      }
    }
//fermeture de la fenètre
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

