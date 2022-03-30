#include <stdio.h>
#include <stdlib.h>
#include "ListeCh.h"

int main(void)
{

    ListeCh c;
    CreerListe(&c);
    Inserer(&c, 3);

    Inserer(&c, 8);

    Inserer(&c, 5);

    Inserer(&c, 23);

    Inserer(&c, 9);
    afficherListe(c);

    Supprimer(&c, Rechercher(c, 23));
    afficherListe(c);

    Avancer(&c);
    printf("valeur courante : %d \n", ValeurCourante(c));

    AllerFin(&c);
    printf("valeur courante : %d \n", ValeurCourante(c));
    printf("Sommes nous au debut ? %s\n", EstDebut(c) ? "oui" : "non");
    printf("Sommes nous a la fin ? %s\n", EstFin(c) ? "oui" : "non");

    Supprimer(&c, Rechercher(c, 8));
    afficherListe(c);
    printf("valeur courante : %d \n", ValeurCourante(c));
    printf("Sommes nous au debut ? %s\n", EstDebut(c) ? "oui" : "non");
    printf("Sommes nous a la fin ? %s\n", EstFin(c) ? "oui" : "non");

    return 0;
}