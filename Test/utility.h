#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <iostream>
#include "entities.h"

//Perte de hp du joueur
void hpLossPlayer(player* P);

//Perte de hp des tanks ennemis
void hpLossTank(tank ennemi);

void procedural_generation(SDL_Point t[]);

void procedural_init(SDL_Point t[]);

void surLaLigneP(player* P, SDL_Point t[]);

void surLaLigneE (tank* T, SDL_Point t[]);

void cameraCentered(SDL_Rect* camera, player* P);

bool colliProjEnnemi (bullet* box1, tank* box2);

bool colliProjJoueur (bullet* box1, player* box2);

bool colliProjJoueur (bullet* box1, player* box2);

void tir(bullet* B);

#endif
