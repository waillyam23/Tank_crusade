#ifndef __ENTITIES_CPP__
#define __ENTITIES_CPP__

#include <iostream>

#include "entities.h"
#include "defines.h"

void initPlayer (player* P1)
{
    (*P1).hp=10;
    (*P1).score=0;
    (*P1).a=0;
    (*P1).c.x=0;
    (*P1).c.y=450;
    (*P1).c.w=PLAYER_W;
    (*P1).c.h=PLAYER_H;
    (*P1).mspeed=5;
    (*P1).bspeed=0.1;
    (*P1).reload=10000;
    (*P1).munition=0;
    (*P1).canons=0;
    (*P1).elevation=0.523599;
    (*P1).depression=-0.0872665;
}

void destroyPlayer()
{

}

void initEnnemi (tank* T)
{
    (*T).hp=1;
    (*T).c.x=600;
    (*T).c.y=450;
    (*T).c.w=80;
    (*T).c.h=70;
    (*T).a=135;
}

void initBullet (bullet* B, player* P1, SDL_Rect curseur)
{
    (*B).c.x=(*P1).c.x+55;
    (*B).c.y=(*P1).c.y;
    (*B).a=((curseur.y)-(*B).c.y)/15;
    (*B).c.w=30;
    (*B).c.h=20;
    (*B).v=50;
}

//void initBullet
#endif
