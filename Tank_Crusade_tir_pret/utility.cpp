#ifndef __UTILITY_CPP__
#define __UTILITY_CPP__

#include <iostream>
#include <cstdlib>

#include "utility.h"
#include "entities.h"

#define MAX 400
#define MIN 30

//Perte de hp du joueur
void hpLossPlayer(player joueur){
    joueur.hp-=1;
}

//Perte de hp des tanks ennemis
void hpLossTank(tank ennemi){
    ennemi.hp-=1;
    if (ennemi.hp<1)
        std::cout << "supprimer ennemi";
}

void procedural_generation(){
}


void tir(bullet* B)
    {
        (*B).c.x += (*B).v;
        if((*B).v>15)
        (*B).v-=1;
        (*B).a =(*B).a+1;
        (*B).c.y = (*B).c.y+(*B).a;

    }
#endif
