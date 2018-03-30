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
    SDL_Rect c; //coordonnées et hitbox du joueur
    float v;    //vitesse de
    float a;    //angle v

};

//Ennemis
struct tank{
    int hp;     //vie de l'ennemi
    SDL_Rect c; //coordonnées et hitbox du joueur
    float a;    //angle de tir de l'ennemi

};

//Bâtiments
struct bat{
    int hp;       //vie du bêtiment
    SDL_Rect c; //coordonnées et hitbox du joueur
};

//PROTOTYPES DES FONCTIONS

void initPlayer (player* P1);

void initBullet (bullet* B, player* P1,int mouse_x, int mouse_y);

#endif
