#ifndef __UTILITY_CPP__
#define __UTILITY_CPP__

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "utility.h"
#include "defines.h"

#define MAX 500
#define MIN 30

//Perte de hp du joueur
void hpLossPlayer(player* P)
{
    (*P).hp-=1;
}

//Perte de hp des tanks ennemis
void hpLossTank(tank ennemi)
{
    ennemi.hp-=1;
    if (ennemi.hp<1)
        std::cout << "supprimer ennemi";
}

void procedural_generation(SDL_Point t[])
{
    for(int i=0; i<29; i++)
        t[i]=t[i+1];

    int yint = t[29].y+rand()%(CURV) - CURV/2;
    if(t[30].y+yint>MAX)
        yint=-1*yint;
    if(t[30].y+yint<MIN)
        yint=-1*yint;
    t[30].y=t[30].y+yint;
    t[30].x=t[29].x+rand() % 200 + 50;
}

void procedural_init(SDL_Point t[])
{
    t[0].x=0;
    t[0].y=800-250;
    int yint;
    for(int i=1; i<30; i++)
    {
        yint = t[i-1].y+rand()%(CURV) - CURV/2;
        if(t[i].y+yint>MAX)
            yint=-1*yint;
        if(t[i].y+yint<MIN)
            yint=-1*yint;
        t[i].y=t[i].y+yint;
        t[i].x=t[i-1].x+rand() % 200 + 50;
    }
}

void surLaLigneP (player* P, SDL_Point t[])
{
    int i=1;
    while(t[i].x <= (*P).c.x)
        i++;

    float dy = t[i].y-t[i-1].y;
    float dx = t[i].x-t[i-1].x;
    float a = dy/dx;
    float b = t[i-1].y - a*t[i-1].x;

    (*P).c.y = a*((*P).c.x) + b - ((*P).c.h);
}

void surLaLigneE (tank* T, SDL_Point t[])
{
    int i=1;
    while(t[i].x <= (*T).c.x)
        i++;

    float dy = t[i].y-t[i-1].y;
    float dx = t[i].x-t[i-1].x;
    float a = dy/dx;
    float b = t[i-1].y - a*t[i-1].x;

    (*T).c.y = a*((*T).c.x) + b - ((*T).c.h);
}

void cameraCentered(SDL_Rect* camera, player* P)
{
    (*camera).x = ( (*P).c.x + PLAYER_W / 2 ) - SCREEN_W / 2;
    (*camera).y = ( (*P).c.y + PLAYER_H / 2 ) - SCREEN_H / 2;
}

void tir(bullet* B)
{
    (*B).c.x += (*B).v;
    if((*B).v>15)
        (*B).v-=1;
    (*B).a =(*B).a+1;
    (*B).c.y = (*B).c.y+(*B).a;
}

bool colliProjEnnemi (bullet* box1, tank* box2)
{
  if(((*box2).c.x >= (*box1).c.x + (*box1).c.w)      // trop à droite
     || ((*box2).c.x + (*box2).c.w <= (*box1).c.x) // trop à gauche
     || ((*box2).c.y >= (*box1).c.y + (*box1).c.h) // trop en bas
     || ((*box2).c.y + (*box2).c.h <= (*box1).c.y))  // trop en haut
          return false;
 else
          return true;
}

//FONCTION collision entre projectile tank et joueur
bool colliProjJoueur (bullet* box1, player* box2)
{
  if(((*box2).c.x >= (*box1).c.x + (*box1).c.w)      // trop à droite
     || ((*box2).c.x + (*box2).c.w <= (*box1).c.x) // trop à gauche
     || ((*box2).c.y >= (*box1).c.y + (*box1).c.h) // trop en bas
     || ((*box2).c.y + (*box2).c.h <= (*box1).c.y))  // trop en haut
          return false;
  else
          return true;
}

//FONCTION collision entre projectile et batiment
bool colliProjBatiment (bullet* box1, bat* box2)
{
  if(((*box2).c.x >= (*box1).c.x + (*box1).c.w)      // trop à droite
     || ((*box2).c.x + (*box2).c.w <= (*box1).c.x) // trop à gauche
     || ((*box2).c.y >= (*box1).c.y + (*box1).c.h) // trop en bas
     || ((*box2).c.y + (*box2).c.h <= (*box1).c.y))  // trop en haut
          return false;
  else
          return true;
}


/*void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    //Recuperation des coordonnées
    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}*/

#endif
