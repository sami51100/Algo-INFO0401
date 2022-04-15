#ifndef ArbreBinaire_H
#define ArbreBinaire_H

// Définition d'une structure d'un arbre binaire de recherche
typedef struct Noeud
{
    int cle;
    struct Noeud *pere;
    struct Noeud *filsGauche;
    struct Noeud *filsDroit;
} Noeud;

typedef Noeud *ABR; // typedef ABR  = Noeud

// Prototype
/*********************************/

void ABR_creer(ABR *px);
int ABR_vide(ABR x);

Noeud *ABR_rechercher(ABR x, int k); // renvoient une position
Noeud *ABR_minimum(ABR x);
Noeud *ABR_maximum(ABR x);
Noeud *ABR_successeur(Noeud *x);
Noeud *ABR_predecesseur(Noeud *x); // il est enracine

void ABR_inserer(ABR *px, int k);
void ABR_supprimer(ABR *px, Noeud *p);

Noeud *nouveau_noeud(int k);

#endif /* ArbreBinaire_H */