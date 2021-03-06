#include <iostream>

#include "SDL2/SDL.h"
//#include "./SDL2_ttf-2.0.14/SDL_ttf.h"

#include "entities.h"
#include "utility.h"

using namespace std;

#define W_MAX 1500
#define H_MAX 800

int main(int argc, char *argv[])
{
    //INITIALISATION DE LA LIBRAIRIE SDL

    SDL_Init(SDL_INIT_EVERYTHING);

    //initialisation des surfaces & textures de bases

    SDL_Window *window;     //La fenètre
    SDL_Renderer* renderer; //l'outil de rendu
    SDL_Surface* surface_background;    //la surface contenant l'image de fond
    SDL_Texture* texture_background;  //sprite de l'image de fond

    //initialisation des surfaces et textures supplémentaires

    SDL_Surface* surface_player;    //la surface contenant l'image du joueur
    SDL_Texture* texture_player;    //sprite du joueur


    //INITIALISATION D'OPENGL
    SDL_GLContext contexteOpenGL;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

    //INITIALISATION DES VARIABLES

    //intégration de la résolution de l'écran
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    DM.w = min(DM.w, W_MAX);
    DM.h = min(DM.h, H_MAX);

    //initialisation du joueur
    player p;
    initPlayer(&p);

    //coordonnées du backgroud
    SDL_Rect destb;
    destb.x= 0;
    destb.y=0;
    destb.w=1500;
    destb.h=800;

    int mouse_x, mouse_y; // coordonnées de la souris par rapport à la fenêtre

    SDL_Point terrain[30]={{0,0}}; //création des coordonnées du terrain
    procedural_init(terrain);

    //infos texture :
    Uint32 format;
    int tw; //largeur de la texture en pixel
    int th; //hauteur de la texture en pixel

    //LANCEMENT DE LA FENETRE

    window = SDL_CreateWindow("Tank_Crusade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DM.w, DM.h, SDL_WINDOW_MINIMIZED);


    //test si la fenetre est créée
      if(window==NULL)
	{
	  cout<<"BRUH";
	  return 1;
	}

	//CHARGEMENT DES IMAGES

    surface_player = SDL_LoadBMP("./Textures/player_idle.bmp"); //charge l'image dans la surface
    surface_background = SDL_LoadBMP("./Textures/background.bmp");

    //MISE A JOUR

      SDL_Event event; //nom général d'un évènement

      bool running=true;

      while(running) //boucle du jeu
	{
        //code pour faire avancer le tank en ligne droite (obsolète)
	    if(p.c.x>1500)
            p.c.x=-300;

	    //CREATION DU RENDU

	    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        //création de l'image de fond
	    texture_background = SDL_CreateTextureFromSurface(renderer,surface_background);
	    SDL_QueryTexture(texture_background,&format,NULL,&tw,&th);
	    SDL_RenderCopy(renderer,texture_background,NULL,&destb);

	    //création de l'image du joueur
	    texture_player = SDL_CreateTextureFromSurface(renderer,surface_player);
	    SDL_QueryTexture(texture_player,&format,NULL,&tw,&th);
	    SDL_RenderCopy(renderer,texture_player,NULL,&(p.c));

	    //création du terrain
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	    SDL_RenderDrawLines(renderer, terrain, 30);

	    SDL_RenderPresent(renderer);    //création du rendu au premier plan
	    SDL_RenderClear(renderer);      //mise au second plan du rendu
	    SDL_DestroyRenderer(renderer);  //supprime le rendu actuel
	    SDL_DestroyTexture(texture_player); //enlève l'image actuel du joueur pour le prochain rendu (libère l'espace mémoire)

	    SDL_Delay(10); //délai avant une nouvelle mise à jour en mili-secondes

	    //ENTREES CLAVIER & SOURIS

	    while(SDL_PollEvent(&event))
		{
            //conditions de fermeture de la fenêtre
		    if(event.type==SDL_QUIT || event.key.state == SDLK_ESCAPE)
			{
			    running=false;
			    break;
			}

            if(event.key.state == SDLK_d )
                p.c.x = p.c.x + p.mspeed;

            if(event.key.state == SDLK_q )
                p.c.x = p.c.x - p.mspeed;

            if(event.key.state == SDLK_s )
                p.c.y = p.c.y + p.mspeed;

            if(event.key.state == SDLK_z )
                p.c.y = p.c.y - p.mspeed;

            if(event.key.state == SDLK_p )
                cout << " pause ou menu";

            if(SDL_GetMouseState(&mouse_x, &mouse_y) == SDL_BUTTON(1)) //SDL_GetMouseState renvoie le bouton appuyé
                cout << "tirer à x : " << mouse_x << " et y : " << mouse_y;
		}
	}
    //fermeture de la fenètre
    SDL_GL_DeleteContext(contexteOpenGL);
    SDL_DestroyWindow(window);
    SDL_Quit();

      return 0;
}
