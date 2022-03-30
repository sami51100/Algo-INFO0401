#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAILLE 200
typedef int tab1D[TAILLE];

void remplir(int *t,int longueur);
void afficher(int *t , int longueur);
int somme(int *t , int longueur);
int max(int *t , int longueur);
int indicemax(int *t , int longueur);

void remplir(int *t,int longueur){
    int i;
    for (size_t i = 0; i < longueur ; i++)
    {
        t[i]= rand()%11 + 10 ;
    }
    
}

void afficher(int *t,int longueur){
    int i;
    for (size_t i = 0; i < longueur ; i++)
    {
        printf("%d |",t[i]);
    }
    printf("\n");
}

int main(void){
    srand(time(NULL));
   
    int longueur = 0;
    printf("entrez la taille du tableau %c tri%ce :\n",133,130);
    scanf("%d",&longueur);
    tab1D t;

    remplir(t , longueur);

    printf("tableau non tri%ce : \n",130);
    afficher(t , longueur);

    return EXIT_SUCCESS;
}