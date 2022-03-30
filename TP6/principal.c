#include <stdio.h>
#include <stdlib.h>
#include "FileTabC.h"
#include "PileCh.h"

int main()
{
    printf("\tpartie File\n");
    //---------------partie file------------------------

    FileTabC f;
    creerFile(&f);

    printf("La File est-elle vide ? %s\n", fileVide(f) ? "oui" : "non");
    enfiler(&f, 3);
    enfiler(&f, 5);
    enfiler(&f, 7);
    printf("nombre d'element de la file : %d\n", compter(f));
    defiler(&f);
    afficherFile(f);
    printf("La File est-elle vide ? %s\n", fileVide(f) ? "oui" : "non");
    printf("%d\n", tete(f));
    viderFile(&f);
    afficherFile(f);

    printf("\tpartie Pile\n");
    //---------------partie pile------------------------

    PileCh p;

    creerPile(&p);
    printf("La Pile est-elle vide ? %s\n", pileVide(p) ? "oui" : "non");
    empiler(&p, 12);
    empiler(&p, 5);
    empiler(&p, 2);
    empiler(&p, 6);
    printf("sommet : %d\n", sommet(p));
    depiler(&p);
    printf("sommet : %d\n", sommet(p));
    afficherPile(p);
    viderPile(&p);
    printf("La Pile est-elle vide ? %s\n", pileVide(p) ? "oui" : "non");

    return EXIT_SUCCESS;
}