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

void viderP(PileCh *p)
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

void afficherP(PileCh p)
{
    if (pileVide(p))
    {
        return;
    }

    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = p.sommet;

    printf("sommet ->");
    while (actuel != NULL)
    {
        printf("| %d |", actuel->element);
        actuel = actuel->succ;
    }
    printf("NULL\n");
}

// methode inverser pile
void inverserPile(PileCh *p)
{
    PileCh p2;
    creerPile(&p2);
    while (!pileVide(*p))
    {
        empiler(&p2, sommet(*p));
        depiler(p);
    }
    *p = p2;
}

// methode transferer pile
void transfererPile(PileCh *p1, PileCh *p2)
{
    while (!pileVide(*p1))
    {
        empiler(p2, sommet(*p1));
        depiler(p1);
    }
    inverserPile(p2);
}

// methode inverser pile
void inverserP(PileCh *p)
{
    PileCh p2;
    creerPile(&p2);
    while (!pileVide(*p))
    {
        empiler(&p2, sommet(*p));
        depiler(p);
    }
    *p = p2;
}

// methode longueur pile
int longueurP(PileCh *p)
{
    int i = 0;
    if (pileVide(*p))
    {
        return 0;
    }
    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = p->sommet;
    while (actuel != NULL)
    {
        i++;
        actuel = actuel->succ;
    }
    return i;
}