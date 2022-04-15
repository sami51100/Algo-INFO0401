#ifndef __PILECH__
#define __PILECH__
#include "../Cellule/Cellule.h"
typedef struct PileCh
{
    Cellule *sommet;

} PileCh;

void creerPile(PileCh *p);

int pileVide(PileCh p);

void empiler(PileCh *p, Element e);

void depiler(PileCh *p);

Element sommet(PileCh p);

void viderP(PileCh *p);

void afficherP(PileCh p);

void inverserP(PileCh *p);

int longueurP(PileCh *p);

#endif