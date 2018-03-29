#ifndef __ENTITIES_H__   // si entities.h n'a pas encore été ajouté
#define __ENTITIES_H__   // alord dire au compilateur qu'il vient d'être ajouté

#include "SDL2/SDL.h"

//STRUCTURES DES ENTITEES

//Hitbox
struct hitbox{
    float x, y, w, h; //position des 4 coordonnées d'une hitbox rectangulaire
};

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
    float x;    //position x
    float y;    //position y
    float v;    //vitesse de
    float a;    //angle v
    hitbox h;
};

//Ennemis
struct tank{
    int hp;     //vie de l'ennemi
    float x;    //position x de l'ennemi
    float y;    //position y de l'ennemi
    float a;    //angle de tir de l'ennemi
    hitbox h;  //hitbox de l'ennemi
};

//Bâtiments
struct bat{
    int hp;       //vie du bêtiment
    float x, y;   //position x et y
    hitbox h;    //hitbox du batiment
};

//PROTOTYPES DES FONCTIONS

void initPlayer (player* P1);

#endif
