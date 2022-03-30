#include <stdio.h>
#include <stdlib.h>
#include "PileCh.h"

void creerPile(PileCh *p)
{
    p->sommet = NULL;
}

int pileVide(PileCh p)
{
    if (p.sommet == NULL)
    {
        return 1;
    }
    return 0;
}

void empiler(PileCh *p, Element e)
{

    Cellule *nouveau = malloc(sizeof(*nouveau));
    nouveau->element = e;
    nouveau->succ = NULL;
    if (pileVide(*p))
    {
        p->sommet = nouveau;
    }
    else
    {
        nouveau->succ = p->sommet;
        p->sommet = nouveau;
    }
}

Element sommet(PileCh p)
{
    if (pileVide(p))
    {
        return -1;
    }

    return p.sommet->element;
}

void depiler(PileCh *p)
{
    if (pileVide(*p))
    {
        return;
    }

    Cellule *tmp = malloc(sizeof(*tmp));
    tmp = p->sommet->succ;
    free(p->sommet);
    p->sommet = tmp;
}

void viderPile(PileCh *p)
{
    if (pileVide(*p))
    {
        return;
    }

    while (p->sommet != NULL)
    {
        depiler(p);
    }
}

void afficherPile(PileCh p)
{
    if (pileVide(p))
    {
        return;
    }

    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = p.sommet;

    while (actuel != NULL)
    {
        printf("| %d |\n", actuel->element);
        actuel = actuel->succ;
    }
    printf("NULL\n");
}