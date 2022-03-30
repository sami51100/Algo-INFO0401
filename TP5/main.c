#include <stdio.h>
#include <math.h>
#include "polynome.h"
#include <stdlib.h>


int main(){
    double a = 2.21 ;

    polynome p ;

    saisie(&p);
    affichage(p);

    double res = evaluer(p , a);
    printf("resultat pour f(%.3lf) = %.3lf ",a,res);


    liberer(&p);
    



    return 0 ;
}