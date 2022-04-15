#include <stdio.h>
#include <stdlib.h>
#include "File_Chainage/FileCh.h"
#include "Pile_Chainage/PileCh.h"

void initialisationFile(FileCh *file1, int nb);
void initialisationPile(PileCh *pile1, int nb);

int main()
{
    printf("\tpartie File\n");
    //---------------partie file------------------------

    FileCh f;
    printf("combien de valeur voulez vous entrer dans la file ?\n");
    int nb;
    scanf("%d", &nb);

    initialisationFile(&f, nb);

    printf("nombre d'element de la file : %d\n", compter(f));
    defiler(&f);
    afficherFile(f);
    printf("La File est-elle vide ? %s\n", fileVide(f) ? "oui" : "non");
    viderFile(&f);
    afficherFile(f);

    printf("\tpartie Pile\n");
    //---------------partie pile------------------------

    PileCh p;
    printf("combien de valeur voulez vous entrer dans la pile ?\n");
    scanf("%d", &nb);

    initialisationPile(&p, nb);

    printf("sommet : %d\n", sommet(p));
    depiler(&p);
    printf("sommet : %d\n", sommet(p));
    afficherP(p);
    viderP(&p);
    printf("La Pile est-elle vide ? %s\n", pileVide(p) ? "oui" : "non");

    return EXIT_SUCCESS;
}

void initialisationFile(FileCh *file1, int nb)
{
    creerFile(file1);
    int valeur = 0;
    for (size_t i = 0; i < nb; i++)
    {
        saisir(&valeur);
        enfiler(file1, valeur);
    }
    printf("initialisation terminée : ");
    afficherFile(*file1);
}

void initialisationPile(PileCh *pile1, int nb)
{
    creerPile(pile1);
    int valeur = 0;
    for (size_t i = 0; i < nb; i++)
    {
        saisir(&valeur);
        empiler(pile1, valeur);
    }
    printf("initialisation terminée : ");
    afficherP(*pile1);
}