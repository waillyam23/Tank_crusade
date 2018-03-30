#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <iostream>
#include "entities.h"

//Perte de hp du joueur
void hpLossPlayer(player joueur);

//Perte de hp des tanks ennemis
void hpLossTank(tank ennemi);

void procedural_generation();

#endif
