#include <stdio.h>
#include "Element.h"
#include <stdlib.h>



void saisir(Element *e){
    
    printf("entrez la valeur de l'element :\n");
    scanf("%d",&(*e));
    
}


void afficher(Element e){
    printf("%d\n",e);
}


