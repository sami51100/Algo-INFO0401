#include "Cellule.h"
#ifndef __PILECH__
#define __PILECH__

typedef struct PileCh
{
    Cellule *sommet;

} PileCh;

void creerPile(PileCh *p);

int pileVide(PileCh p);

void empiler(PileCh *p, Element e);

void depiler(PileCh *p);

Element sommet(PileCh p);

void viderPile(PileCh *p);

void afficherPile(PileCh p);

#endif