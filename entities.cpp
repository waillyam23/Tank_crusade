#include <stdio.h>

//Hitbox
struct hitbox{
    float x, y, w, h; //position des 4 coordonnées d'une hitbox rectangulaire
};

//Joueur
struct Player{
    int hp;     //vie du joueur
    int score;  //score du joueur
    float x;    //position x du joueur
    float y;    //position y du joueur
    float a;    //angle du curseur
    hitbox h;//hitbox du joueur
    float mspeed;//vitesse du joueur
    float bspeed;//vitesse des projectiles
    float reload;//temps de rechargement
    
};

//Projectiles
struct Bullet{
    float x;    //position x
    float y;    //position y
    float v;    //vitesse de
    float a;    //angle v
    hitbox h;
};

//Ennemis
struct Tank{
    int hp;     //vie de l'ennemi
    float x;    //position x de l'ennemi
    float y;    //position y de l'ennemi
    float a;    //angle de tir de l'ennemi
    Hitbox h;  //hitbox de l'ennemi
};

//Bâtiments
struct Bat{
    int hp;       //vie du bêtiment
    float x, y;   //position x et y
    Hitbox h;    //hitbox du batiment
};

void initPayer (Player*)
{
    (*Player).score=0;
    (*Player).
}
