#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <iostream>
#include "entities.h"

//Perte de hp du joueur
void hpLossPlayer(player joueur);

//Perte de hp des tanks ennemis
void hpLossTank(tank ennemi);

void procedural_generation();

void procedural_init(SDL_Point t[]);

bool colliProjEnnemi (bullet* box1, tank* box2);

bool colliProjJoueur (bullet* box1, player* box2);

bool colliProjJoueur (bullet* box1, player* box2);


#endif
