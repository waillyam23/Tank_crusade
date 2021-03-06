#include <iostream>
#include <SDL.h>
using namespace std;
int main( int argc,char *argv[])
{

// creation de la fenetre

SDL_Init(SDL_INIT_EVERYTHING);
//initialisation des variables utiles
SDL_Rect destp;
destp.x= 0;
destp.y=800-350;
destp.w=80;
destp.h=70;

SDL_Rect destb;
destb.x= 0;
destb.y=0;
destb.w=1500;
destb.h=800;

//infos texture :
Uint32 format;
int tw=171;
int th=35;






SDL_Renderer* renderer; //l'outil de rendu
SDL_Surface* surf;//la surface possedant l'image
SDL_Surface* background;
SDL_Texture* texture;//crée une texture
SDL_Texture* textureb;//crée une texture
SDL_Window *window;//la fenètre
//lancement de la fenètre
  window = SDL_CreateWindow("Tank_Crusade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500,800,SDL_WINDOW_RESIZABLE);
//initialisation du rendu et association avec la fenètre


	//test si la fenetre est créée
  if(window==NULL)
    {
      cout<<"BRUH";
    }


      //tous les test vont ici
surf = SDL_LoadBMP("sdl_icone.bmp");//charge l'image dans la surface
background = SDL_LoadBMP("background.bmp");

//mise a jour
  SDL_Event event;
  bool running=true;
  while(running)
    {
    //endroit ou on code tout
        destp.x=destp.x+1;
        if(destp.x>1500)
        destp.x=-400;
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


        textureb = SDL_CreateTextureFromSurface(renderer,background);
        SDL_QueryTexture(textureb,&format,NULL,&tw,&th);
        SDL_RenderCopy(renderer,textureb,NULL,&destb);

        texture = SDL_CreateTextureFromSurface(renderer,surf);
        SDL_QueryTexture(texture,&format,NULL,&tw,&th);
        SDL_RenderCopy(renderer,texture,NULL,&destp);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);


        SDL_Delay(5);




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
