#include "ListeCh.h"
#include <stdio.h>
#include <stdlib.h>

void CreerListe(ListeCh *liste)
{
    liste->courant = NULL;
    liste->debut = NULL;
    liste->fin = NULL;
}

int ListeVide(ListeCh liste)
{
    if (liste.debut == NULL && liste.fin == NULL && liste.courant == NULL)
    {
        return 1;
    }
    return 0;
}

void Inserer(ListeCh *liste, Element e)
{
    /* Création du nouvel élément */
    Cellule *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        return;
    }
    nouveau->element = e;
    nouveau->pred = NULL;
    if (ListeVide(*liste))
    {
        nouveau->succ = NULL;
        liste->courant = nouveau;
        liste->debut = nouveau;
        liste->fin = nouveau;
    }
    else if (liste->courant->succ == NULL)
    {
        nouveau->pred = liste->courant;
        liste->courant->succ = nouveau;
        nouveau->succ = NULL;
    }
    else
    {
        liste->courant->succ->pred = nouveau;
        nouveau->pred = liste->courant;
        nouveau->succ = liste->courant->succ;
        liste->courant->succ = nouveau;
    }

    if (nouveau->succ == NULL)
    {
        liste->fin = nouveau;
    }
}

void afficherListe(ListeCh liste)
{
    if (ListeVide(liste))
    {
        return;
    }

    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = liste.debut;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->element);
        actuel = actuel->succ;
    }
    printf("NULL\n");
}

Cellule *Rechercher(ListeCh liste, int val)
{
    if (ListeVide(liste))
    {
        EXIT_FAILURE;
    }

    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = liste.debut;

    while (actuel != NULL && actuel->element != val)
    {

        actuel = actuel->succ;
    }

    return actuel;
}

void Supprimer(ListeCh *liste, Cellule *p)
{
    if (p != NULL)
    {
        if (p->succ != NULL)
        {
            p->succ->pred = p->pred;
            liste->courant = p->succ;
        }
        else
        {
            liste->fin = p->pred;
        }
        if (p->pred != NULL)
        {
            liste->courant = p->pred;
            p->pred->succ = p->succ;
        }
        else
        {
            liste->courant = p->succ;
            liste->debut = p->succ;
        }
    }

    free(p);
}

Element ValeurCourante(ListeCh liste)
{
    if (ListeVide(liste))
    {
        EXIT_FAILURE;
    }
    return liste.courant->element;
}

void AllerDebut(ListeCh *liste)
{
    if (ListeVide(*liste))
    {
        return;
    }
    liste->courant = liste->debut;
}

void AllerFin(ListeCh *liste)
{
    if (ListeVide(*liste))
    {
        return;
    }
    liste->courant = liste->fin;
}

void Avancer(ListeCh *liste)
{
    if (ListeVide(*liste))
    {
        return;
    }

    if (liste->courant->succ != NULL)
    {
        liste->courant = liste->courant->succ;
    }
}

int EstDebut(ListeCh liste)
{
    if (liste.courant->pred == NULL)
    {
        return 1;
    }
    return 0;
}

int EstFin(ListeCh liste)
{
    if (liste.courant->succ == NULL)
    {
        return 1;
    }
    return 0;
}