#ifndef __UTILITY_CPP__
#define __UTILITY_CPP__

#include <iostream>

#include "utility.h"

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

#endif
