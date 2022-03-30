#ifndef __FILETABC__
#define __FILETABC__
#include "Cellule.h"

typedef struct FileTabC
{
    Cellule *queue;
    Cellule *tete;
} FileTabC;

void creerFile(FileTabC *f);

int fileVide(FileTabC f);

void enfiler(FileTabC *f, Element e);

void afficherFile(FileTabC f);

void defiler(FileTabC *f);

Element tete(FileTabC f);

int compter(FileTabC f);

void viderFile(FileTabC *f);

#endif