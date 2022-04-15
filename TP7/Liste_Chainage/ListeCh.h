#ifndef __LISTECH__
#define __LISTECH__
#include "../Cellule/Cellule.h"

typedef struct ListeCh
{
    Cellule *fin;
    Cellule *debut;
    Cellule *courant;

} ListeCh;

void CreerListe(ListeCh *liste);

int ListeVide(ListeCh liste);

void afficherListe(ListeCh liste);

void Inserer(ListeCh *liste, Element e);

Cellule *Rechercher(ListeCh liste, int val);

void Supprimer(ListeCh *liste, Cellule *c);

Element ValeurCourante(ListeCh liste);

void AllerDebut(ListeCh *liste);

void AllerFin(ListeCh *liste);

void Avancer(ListeCh *liste);

int EstDebut(ListeCh liste);

int EstFin(ListeCh liste);

#endif