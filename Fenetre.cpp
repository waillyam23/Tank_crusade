#include <iostream>
#include <SDL.h>
using namespace std;

int main( int argc,char *argv[])
{

// creation de la fenetre

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Texture *surf, *ecran=NULL;
    32 ,100, 100, 100, 0;
  SDL_Renderer* renderer;
  SDL_Surface* Loading_Surf;

  SDL_Window *window;
  window = SDL_CreateWindow("Tank Crusade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500,800,SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
  if(window==NULL)
    {
      cout<<"BRUH";
    }


      //tous les test vont ici



//mise a jour
  SDL_Event event;
  bool running=true;
  while(running)
    {
    {//endroit ou on code tout






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
