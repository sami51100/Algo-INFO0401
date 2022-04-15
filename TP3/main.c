#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int nbJours(int mois, int annee);

int main(void)
{
    struct
    {
        int jour;
        int mois;
        int annee;
    } maintenant; // variable structurée

    maintenant.annee = 2022;
    maintenant.mois = 1 + rand() % 12;

    do
    {
        printf("Entrez le jour : ");
        scanf("%d", &(maintenant.jour));
    } while (maintenant.jour < 1 || maintenant.jour > nbJours(maintenant.mois, maintenant.annee));
    printf("Today is %d/%d/%d\n", maintenant.annee, maintenant.mois, maintenant.jour);

    return 0;
}

int nbJours(int mois, int annee)
{
    if (mois == 1, 3, 5, 7, 8, 10, 12)
    {
        return 31;
    }
    if (mois == 2)
    {
        return 29;
    }
    if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
    {
        return 30;
    }
}