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


      	float vx;
      	float vy;



        vx = cos((*B).a)*(*B).v;
        vy = sin((*B).a)*(*B).v;
        (*B).c.x += vx;
        (*B).c.y += (vy-9.81);
        (*B).v = sqrt(pow(vx,2)+pow((vy-9.81),2));
        (*B).a = atan2f((vy-9.81),vx);

    }
#endif
