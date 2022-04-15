#ifndef __HASHTABLE__
#define __HASHTABLE__
#include "../Liste_Recherche/ListeR.h"
#define MAX 10

typedef LR TH[MAX];

void creerTableHashage(TH *hash_table);

int hashage(int cle);

void viderTable(TH hash_table);

void afficherTable(TH hash_table);

void InsererTable(TH *hash_table, int val);

Element2p *RechercherTable(TH hash_table, int val);

void SupprimerTable(TH *hash_table, Element2p *p);

void InsererListeTable(TH *hash_table, LR liste);

#endif