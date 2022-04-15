#include <stdio.h>
#include <stdlib.h>
#include "Liste_Chainage/ListeCh.h"

void initialisation(ListeCh *liste1, int nb);

int main(void)
{

    ListeCh c;
    printf("combien de valeur voulez vous entrer dans la liste ?\n");
    int nb;
    scanf("%d", &nb);
    initialisation(&c, nb);

    printf("valeur courante : %d \n", ValeurCourante(c));

    AllerDebut(&c);
    printf("valeur courante : %d \n", ValeurCourante(c));
    printf("Sommes nous au debut ? %s\n", EstDebut(c) ? "oui" : "non");
    printf("Sommes nous a la fin ? %s\n", EstFin(c) ? "oui" : "non");

    Supprimer(&c, Rechercher(c, 3));
    afficherListe(c);
    printf("valeur courante : %d \n", ValeurCourante(c));
    printf("Sommes nous au debut ? %s\n", EstDebut(c) ? "oui" : "non");
    printf("Sommes nous a la fin ? %s\n", EstFin(c) ? "oui" : "non");

    return 0;
}

void initialisation(ListeCh *liste1, int nb)
{
    CreerListe(liste1);
    int valeur = 0;
    for (size_t i = 0; i < nb; i++)
    {
        saisir(&valeur);
        Inserer(liste1, valeur);
    }
    printf("initialisation terminée : ");
    afficherListe(*liste1);
}