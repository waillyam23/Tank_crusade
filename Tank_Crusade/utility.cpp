#ifndef __UTILITY_CPP__
#define __UTILITY_CPP__

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "utility.h"

#define MAX 500
#define MIN 30

//Perte de hp du joueur
void hpLossPlayer(player joueur)
{
    joueur.hp-=1;
}

//Perte de hp des tanks ennemis
void hpLossTank(tank ennemi)
{
    ennemi.hp-=1;
    if (ennemi.hp<1)
        std::cout << "supprimer ennemi";
}

void procedural_generation()
{

}

void procedural_init(SDL_Point t[])
{
    t[0].x=0;
    t[0].y=800-100;
    int yint;
    for(int i=1; i<30; i++)
    {
        yint = t[i-1].y+rand()%(50) - 25; //yint prends une valeur entre -25 et 25
        if(t[i].y+yint>MAX)
            yint=-1*yint;
        if(t[i].y+yint<MIN)
            yint=-1*yint;
        t[i].y=t[i].y+yint;
        t[i].x=t[i-1].x+rand() % 200+ 50;
    }
}

#endif
