#include <iostream>
#include <SDL.h>
using namespace std;
int main( int argc,char *argv[])
{

// creation de la fenetre

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Texture *texture, *ecran=NULL;

  SDL_Renderer* renderer;
  SDL_Surface* surf;
  SDL_Texture* BlueShapes;

  SDL_Window *window;
  window = SDL_CreateWindow("Tank_Crusade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500,800,SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(window==NULL)
    {
      cout<<"BRUH";
      }


      //tous les test vont ici
  surf = SDL_LoadBMP("sdl_icone.bmp");
  BlueShapes = SDL_CreateTextureFromSurface(renderer, surf);

      SDL_RenderPresent(renderer);
      SDL_BlitSurface(surf, NULL, SDL_GetWindowSurface(window),NULL);
  //SDL_FreeSurface(surf);

//mise a jour
  SDL_Event event;
  bool running=true;
  while(running)
    {
    {//endroit ou on code tout


SDL_UpdateWindowSurface(window);





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
