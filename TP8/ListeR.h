#ifndef __LISTER__
#define __LISTER__

typedef struct Element2p Element2p;

struct Element2p
{
    int cle;
    Element2p *succ;
    Element2p *pred;
};

typedef Element2p *LR;

void CreerListe(LR *px);

int ListeVide(LR x);

void Inserer(LR *px, int val);

void Supprimer(LR *px, Element2p *p);

void afficherListe(LR x);

Element2p *Rechercher(LR x, int val);

#endif