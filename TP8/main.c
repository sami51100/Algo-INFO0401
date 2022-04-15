#include <stdio.h>
#include <stdlib.h>
#include "Table_Hashage/hashtable.h"

int main(void)
{

    LR x;
    TH hash_table;

    CreerListe(&x);

    Inserer(&x, 3);
    Inserer(&x, 5);
    Inserer(&x, 8);
    Inserer(&x, 12);
    Inserer(&x, 9);
    afficherListe(x);

    creerTableHashage(&hash_table);

    InsererListeTable(&hash_table, x);
    afficherTable(hash_table);

    SupprimerTable(&hash_table, RechercherTable(hash_table, 8));
    SupprimerTable(&hash_table, RechercherTable(hash_table, 132));
    afficherTable(hash_table);
    viderTable(hash_table);

    return 0;
}