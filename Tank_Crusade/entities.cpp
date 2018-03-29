#ifndef __ENTITIES_CPP__
#define __ENTITIES_CPP__

#include <iostream>

#include "entities.h"
#ifndef __ENTITIES_H__   // si entities.h n'a pas encore été ajouté
#define __ENTITIES_H__   // alord dire au compilateur qu'il vient d'être ajouté

#include "SDL2/SDL.h"

//STRUCTURES DES ENTITEES


//Joueur
struct player{
    int hp;     //vie du joueur
    int score;  //score du joueur
    float a;    //angle du curseur
    SDL_Rect c; //coordonnées et hitbox du joueur
    int mspeed;//vitesse du joueur
    float bspeed;//vitesse des projectiles
    float reload;//temps de rechargement
    float munition;//quelle munition ?
    float canons;//quel canon ?
    float elevation;//elevation maximale du canon
    float depression;//elevation minimale du canon

};

//Projectiles
struct bullet{
    SDL_Rect c; //coordonnées et hitbox du projectile
    float v;    //vitesse de
    float a;    //angle v
};

//Ennemis
struct tank{
    int hp;     //vie de l'ennemi
    SDL_Rect c; //coordonnées et hitbox du tank
    float a;    //angle de tir de l'ennemi
};

//Bâtiments
struct bat{
    int hp;       //vie du bêtiment
    SDL_Rect c; //coordonnées et hitbox du batiment
};

//PROTOTYPES DES FONCTIONS

void initPlayer (player* P1);

#endif

void initPlayer (player* P1)
{
    (*P1).hp=10;
    (*P1).score=0;
    (*P1).a=0;
    (*P1).c.x=0;
    (*P1).c.y=450;
    (*P1).c.w=80;
    (*P1).c.h=70;
    (*P1).mspeed=5;
    (*P1).bspeed=0.1;
    (*P1).reload=10000;
    (*P1).munition=0;
    (*P1).canons=0;
    (*P1).elevation=0.523599;
    (*P1).depression=-0.0872665;
}
void initBullet (bullet* B1,player* P1)
{
(*B1).c.x=(*P1).c.x;
(*B1).c.y=(*P1).c.y;
(*B1).a=atan (*mouse_y - (*P1).c.y / *mouse_x - (*P1).c.x);


}

#endif
