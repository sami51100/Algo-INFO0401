#include <stdio.h>
#include <math.h>
#include "polynome.h"
#include <stdlib.h>

void saisie(polynome *p){
    do
    {  
        printf("entrez le degres du polynome\n");
        scanf("%d",&p->deg);  
    } while(p->deg < 0);
    
      

    (*p).tab = (double*)malloc((*p).deg * sizeof(double));

    for (int i = 0; i < (*p).deg + 1; i++)
    {
        printf("entrez une valeur pour la case %d :\n",i);
        scanf("%lf",&(*p).tab[i]) ;   
    }  
}

void affichage(polynome p){

    for (int i = 0; i < (p).deg + 1; i++)
    {
        printf("%.3lf |",(p).tab[i]);
    } 
    printf("\n"); 
}

double evaluer(polynome p , double x){
    double somme =0;
    for (int i = 0; i < (p).deg + 1; i++)
    {
        somme+= ((p).tab[i])*pow(x,i);
       
    }  
    return somme;
}



void liberer(polynome *p){ 
    free((*p).tab);
}
