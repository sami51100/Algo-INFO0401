#ifndef __FILECH__
#define __FILECH__
#include "../Cellule/Cellule.h"

typedef struct FileCh
{
    Cellule *queue;
    Cellule *tete;
} FileCh;

void creerFile(FileCh *f);

int fileVide(FileCh f);

void enfiler(FileCh *f, Element e);

void afficherFile(FileCh f);

void defiler(FileCh *f);

Element tete(FileCh f);

int compter(FileCh f);

void viderFile(FileCh *f);

#endif