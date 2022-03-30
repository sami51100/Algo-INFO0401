#include <stdio.h>
#include "terme.h"
#include <stdlib.h>

terme premier(void)
{
    terme x0;
    x0.nb = 1;
    x0.elts = (int *)calloc(x0.nb, sizeof(int));
    x0.elts[0] = 1;

    return x0;
}

void afficher(terme c)
{

    for (int i = 0; i < c.nb; i++)
    {
        printf("%d | ", c.elts[i]);
    }

    printf("\n");
}

terme suivant(terme c)
{
    int taille = 1;
    int compteur = 1;
    for (int i = 0; i <= c.nb; i++)
    {
        if (c.elts[i] != c.elts[i] + 1)
        {
            compteur++;
        }
    }
    taille += compteur;

    terme b;
    b.nb = taille;
    b.elts = (int *)calloc(b.nb, sizeof(int));

    return b;
}