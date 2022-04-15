#include "ListeR.h"
#include <stdio.h>
#include <stdlib.h>

void CreerListe(LR *px)
{
    *px = NULL;
}

int ListeVide(LR x)
{
    if (x == NULL)
    {
        return 0;
    }
    return 1;
}

void Inserer(LR *px, int val)
{
    /* Création du nouvel élément */
    Element2p *nouveau = malloc(sizeof(*nouveau));
    // nouveau : ptr(Element2p)
    // nouveau <- allouer(Element2p)
    if (nouveau == NULL)
    {
        printf("erreur \n");
        exit(EXIT_FAILURE);
    }

    nouveau->cle = val;
    nouveau->pred = NULL;
    if (*px == NULL)
    {
        nouveau->succ = NULL;
    }
    else
    {
        nouveau->succ = *px;
        (*px)->pred = nouveau;
    }
    *px = nouveau;
}

void afficherListe(LR x)
{
    if (ListeVide(x) == 0)
    {
        exit(EXIT_FAILURE);
    }

    Element2p *actuel = x;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->cle);
        actuel = actuel->succ;
    }
    printf("NULL\n");
}

Element2p *Rechercher(LR x, int val)
{
    if (ListeVide(x) == 0)
    {
        exit(EXIT_FAILURE);
    }

    Element2p *actuel = x;

    while (actuel != NULL && actuel->cle != val)
    {

        actuel = actuel->succ;
    }

    return actuel;
}

void Supprimer(LR *px, Element2p *p)
{
    if (p != NULL)
    {
        if (p->succ != NULL)
        {
            p->succ->pred = p->pred;
        }
        if (p->pred != NULL)
        {
            p->pred->succ = p->succ;
        }
        else
        {
            *px = p->succ;
        }
    }

    free(p);
}
