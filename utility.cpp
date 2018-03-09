#include <stdio.h>
#include "Entities.cpp"

//Perte de hp du joueur
void hpLossPlayer(Player joueur){
        joueur.hp-=1;
}

//Perte de hp des tanks ennemis
void hpLossTank(Tank ennemi){
    ennemi.hp-=1;
    if (ennemi.hp<1)
        delete enemi;
}
