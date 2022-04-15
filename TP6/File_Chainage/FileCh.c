#include "FileCh.h"
#include <stdio.h>
#include <stdlib.h>

void creerFile(FileCh *f)
{
    f->queue = NULL;
    f->tete = NULL;
}

int fileVide(FileCh f)
{
    if (f.queue == NULL && f.tete == NULL)
    {
        return 1;
    }

    return 0;
}

void enfiler(FileCh *f, Element e)
{

    Cellule *nouveau = malloc(sizeof(*nouveau));
    nouveau->element = e;
    nouveau->succ = NULL;
    if (fileVide(*f))
    {
        f->queue = nouveau;
        f->tete = nouveau;
    }
    else
    {
        f->queue->succ = nouveau;
        f->queue = nouveau;
    }
}

void afficherFile(FileCh f)
{
    if (fileVide(f))
    {
        return;
    }

    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = f.tete;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->element);
        actuel = actuel->succ;
    }
    printf("NULL\n");
}

void defiler(FileCh *f)
{
    if (fileVide(*f))
    {
        return;
    }

    Cellule *tmp = malloc(sizeof(*tmp));

    if (f->tete == f->queue)
    {
        f->tete = NULL;
        f->queue = NULL;
    }
    else
    {
        tmp = f->tete->succ;
        free(f->tete);
        f->tete = tmp;
    }
}

Element tete(FileCh f)
{
    if (fileVide(f))
    {
        return -1;
    }
    return f.tete->element;
}

int compter(FileCh f)
{
    if (fileVide(f))
    {
        return 0;
    }
    int compteur = 0;

    Cellule *actuel = malloc(sizeof(*actuel));
    actuel = f.tete;

    while (actuel != NULL)
    {
        compteur++;
        actuel = actuel->succ;
    }

    return compteur;
}

void viderFile(FileCh *f)
{
    if (fileVide(*f))
    {
        return;
    }

    while (f->tete != NULL)
    {
        defiler(f);
    }
}