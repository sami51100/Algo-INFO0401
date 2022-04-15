#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

void creerTableHashage(TH *hash_table)
{
    LR x;
    CreerListe(&x);
    for (size_t i = 0; i < MAX; i++)
    {
        (*hash_table)[i] = x;
    }
}

int hashage(int cle)
{
    return cle % MAX;
}

void viderTable(TH hash_table)
{
    for (int i = 0; i < MAX; i++)
    {
        (hash_table)[i] = NULL;
    }
}

void afficherTable(TH hash_table)
{
    for (int i = 0; i < MAX; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t[%i] --> NULL\n", i);
        }
        else
        {
            printf("\t[%i] -->  ", i);
            afficherListe(hash_table[i]);
        }
    }
    printf("\n");
}

void InsererTable(TH *hash_table, int val)
{
    int index = hashage(val);
    if (hash_table[index] == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Inserer(&((*hash_table)[index]), val);
}

Element2p *RechercherTable(TH hash_table, int val)
{
    int index = hashage(val);
    Element2p *actuel = hash_table[index];
    while (actuel != NULL && actuel->cle != val)
    {
        actuel = actuel->succ;
    }
    return actuel;
}

void SupprimerTable(TH *hash_table, Element2p *p)
{
    if (p != NULL)
    {
        int k = p->cle;
        int index = hashage(k);
        if (hash_table[index] != NULL)
        {

            Supprimer(&((*hash_table)[index]), p);
        }
    }
}

void InsererListeTable(TH *hash_table, LR liste)
{
    int index;
    while (liste != NULL)
    {
        index = hashage(liste->cle);
        if (hash_table[index] == NULL)
        {
            exit(EXIT_FAILURE);
        }
        Inserer(&((*hash_table)[index]), liste->cle);

        liste = liste->succ;
    }
}