#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "terme.h"

int main(void){
   

    
    int taille ;
    int X0 = 1 ;
    
    terme c = premier();
    terme b ;

    
    afficher(c);

    

    
   

    b = suivant(c);

    afficher(b);

     c = suivant(b);

    afficher(c);

    free(c.elts);


    return EXIT_SUCCESS ;
}