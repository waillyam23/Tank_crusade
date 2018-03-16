#include <stdio.h>

//Hitbox
struct hitbox{
    float x, y, w, h; //position des 4 coordonnées d'une hitbox rectangulaire
};

//Joueur
struct player{
    int hp;     //vie du joueur
    int score;  //score du joueur
    float x;    //position x du joueur
    float y;    //position y du joueur
    float a;    //angle du curseur
    hitbox h;//hitbox du joueur
    float mspeed;//vitesse du joueur
    float bspeed;//vitesse des projectiles
    float reload;//temps de rechargement
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
    Hitbox h;  //hitbox de l'ennemi
};

//Bâtiments
struct bat{
    int hp;       //vie du bêtiment
    float x, y;   //position x et y
    Hitbox h;    //hitbox du batiment
};

void initPlayer (Player* P1)
{
    (*P1).score=0;
    (*P1).hp=3;
    (*P1).x = 20;
    (*P1).y = 201;
    (*P1).a = 0;
    (*P1).h.x=(*P1).x;
    (*P1).h.y=(*P1).y;
    (*P1).h.w=171;
    (*P1).h.h=125;
    (*P1).mspeed=0.01;
    (*P1).bspeed=0.1;
    (*P1).reload=10000;
    (*P1).elevation=0.523599;
    (*P2).depression=-0.0872665
}

void initBullet
