#ifndef __POLYNOME__
#define __POLYNOME__

typedef struct polynome
{
    int deg ;
    double *tab ;

}polynome;


void saisie(polynome *p);

void affichage(polynome p);

double evaluer(polynome p , double x);

polynome add(polynome p , polynome d);

void liberer(polynome *p);

#endif