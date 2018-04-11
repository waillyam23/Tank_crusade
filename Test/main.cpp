#include <iostream>
#include <vector>
#include "SDL2/SDL.h"
#include "entities.h"
#include "utility.h"
#include "defines.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand((double)time(NULL));
    //INITIALISATION DE LA LIBRAIRIE SDL

    SDL_Init(SDL_INIT_EVERYTHING);

    //initialisation des surfaces & textures de bases

    SDL_Window *window;     //La fenètre
    SDL_Renderer* renderer; //l'outil de rendu
    SDL_Surface* surface_background;    //la surface contenant l'image de fond
    SDL_Texture* texture_background;  //sprite de l'image de fond
    SDL_Rect camera ={0,0,SCREEN_W, SCREEN_H}; //création du rectangle de la caméra

    //initialisation des surfaces et textures supplémentaires

    SDL_Surface* surface_player;    //la surface contenant l'image du joueur
    SDL_Texture* texture_player;    //sprite du joueur
    SDL_Surface* surface_ennemis;   //la surface contenant l'image des ennemis
    SDL_Texture* texture_ennemis;   //sprite du ennemis
    SDL_Surface* surface_bullet;    //la surface contenant l'image de l'obus
    SDL_Texture* texture_bullet;    //sprite de l'obus
    SDL_Surface* surface_cursor;    //la surface contenant le curseur
    SDL_Texture* texture_cursor;    //sprite du curseur
    SDL_Surface* icon;  //icone du jeu

    //INITIALISATION DES VARIABLES

    //intégration de la résolution de l'écran
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    DM.w = min(DM.w, SCREEN_W);
    DM.h = min(DM.h, SCREEN_H);

    //initialisation du joueur
    player p;
    initPlayer(&p);



    //variable si le joueur tire ou pas
    bool tir_p=false;

    //variable si l'ennemi tire ou pas
    bool tir_e=false;

    //initialisation du vect des ennemis
    tank e;
     //initialisation dellennemi
    initEnnemi(&e);

    //initialisation de l'obus du joueur
    bullet Bp;

    SDL_Rect cursr;
    cursr.w=40;
    cursr.h=40;
    //coordonnées du curseur
    cursr.x=SCREEN_W/2;
    cursr.y=SCREEN_H/2; // coordonnées du curseur par rapport à la fenêtre

    //coordonnées du backgroud
    SDL_Rect destb;
    destb.x= 0;
    destb.y=0;
    destb.w=SCREEN_W;
    destb.h=SCREEN_H;

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
    surface_ennemis = SDL_LoadBMP("./Textures/tanks_tankNavy1.bmp");
    surface_bullet = SDL_LoadBMP("./Textures/bullet_player.bmp");
    surface_cursor = SDL_LoadBMP("./Textures/cursor.bmp");
    icon = SDL_LoadBMP("./Textures/player_idle.bmp");

    SDL_SetWindowIcon(window, icon); //création de l'icone du jeu


    //MISE A JOUR

      SDL_Event event; //nom général d'un évènement

      bool running=true;

      while(running) //boucle du jeu
	{
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

            if(event.key.state == SDLK_k )
                e.hp-=1;

            if(event.key.state == SDLK_q )
                p.c.x = p.c.x - p.mspeed;

            if(event.key.state == SDLK_z )  //déplace le curseur vers le haut
                cursr.y = cursr.y - 10;

            if(event.key.state == SDLK_s )  //déplace le curseur vers le bas
                cursr.y = cursr.y + 10;

            if(tir_p==false)   //teste si un il existe un autre obus
            {
                if(event.key.state == SDLK_SPACE)  //initilalise un obus si la barre espace est pressée
                    {
                        initBullet(&Bp,&p,cursr);
                        tir_p=true;
                    }

}
		}

        //MISE À JOUR DE LA SIMULATION
        cameraCentered(&camera, &p);
        if (p.hp<=0)
            destroyPlayer();



        surLaLigneP (&p, terrain);
        surLaLigneE (&e, terrain);

	    //CREATION DU RENDU

	    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        //création de l'image de fond
	    texture_background = SDL_CreateTextureFromSurface(renderer,surface_background);
	    SDL_QueryTexture(texture_background,&format,NULL,&tw,&th);
	    SDL_RenderCopy(renderer,texture_background,NULL,&destb);

	    //création de l'image de l'ennemi
	    if(e.hp>0)
        {
            texture_ennemis = SDL_CreateTextureFromSurface(renderer,surface_ennemis);
            SDL_QueryTexture(texture_ennemis,&format,NULL,&tw,&th);
            SDL_RenderCopy(renderer,texture_ennemis,NULL,&(e.c));
            if(e.c.x>1450)
                e.c.x -= 10;


            if(Bp.c.y<e.c.y+80&&tir_p==true)
            {   if(e.c.x<Bp.c.x)
                    e.c.x -= 5;
                else
                {
                    if(e.c.x>Bp.c.x)
                        e.c.x += 10;
                }
            }
            else
            e.c.x -= 2;

        }

        //création de l'image du joueur
	    texture_player = SDL_CreateTextureFromSurface(renderer,surface_player);
	    SDL_QueryTexture(texture_player,&format,NULL,&tw,&th);
	    SDL_RenderCopy(renderer,texture_player,NULL,&(p.c));

        //création du curseur
	    texture_cursor = SDL_CreateTextureFromSurface(renderer,surface_cursor);
	    SDL_QueryTexture(texture_cursor,&format,NULL,&tw,&th);
	    SDL_RenderCopy(renderer,texture_cursor,NULL,&cursr);

        //teste si tir_p est vrai et lance le calcul du tir
        if(tir_p==true)
        {
            tir(&Bp);

            //création de m'image de l'obus

            texture_bullet = SDL_CreateTextureFromSurface(renderer,surface_bullet);
            SDL_QueryTexture(texture_bullet,&format,NULL,&tw,&th);
            SDL_RenderCopy(renderer,texture_bullet,NULL,&(Bp.c));
        }

        //teste si l'obus actuel est encore dans la zone prédéfinie et le cas contraire, l'arrète
        if(Bp.c.y>900||Bp.c.x>3500)
        {tir_p=false;}

	    //création du terrain
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	    SDL_RenderDrawLines(renderer, terrain, 30);

	    SDL_RenderPresent(renderer);    //création du rendu au premier plan
	    SDL_RenderClear(renderer);      //mise au second plan du rendu
	    SDL_DestroyRenderer(renderer);  //supprime le rendu actuel
	    SDL_DestroyTexture(texture_player); //enlève l'image actuel du joueur pour le prochain rendu (libère l'espace mémoire)
	    SDL_DestroyTexture(texture_bullet); //enlève l'image actuel de l'obus pour le prochain rendu (libère l'espace mémoire)

	    SDL_Delay(10); //délai avant une nouvelle mise à jour en mili-secondes
	}
    //fermeture de la fenètre
    SDL_DestroyWindow(window);
    SDL_Quit();

      return 0;
}
