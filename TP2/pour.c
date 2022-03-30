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
void afficherREC(int *t , int longueur,int ind);
void afficherRecL(int *t , int longueur);
int indicemaxREC(int *t ,int longueur,int ind ,int max,int indice);
int indicemaxRECL(int*t,int longueur );

void remplir(int *t,int longueur){
    int i;
    for (size_t i = 0; i < longueur && sizeof(int[TAILLE])/sizeof(t[0]); i++)
    {
        t[i]= rand()%11 + 10 ;
    }
    
}

void afficher(int *t,int longueur){
    int i;
    for (size_t i = 0; i < longueur && sizeof(int[TAILLE])/sizeof(t[0]); i++)
    {
        printf("%d |",t[i]);
    }
    printf("\n");
}

int somme(int *t,int longueur){
    int i;
    int s =0 ;
    for (size_t i = 0; i < longueur && sizeof(int[TAILLE])/sizeof(t[0]); i++)
    {
        s+=t[i];
    }
    
    return s;
}

int max(int *t,int longueur){
    int i;
    int max =t[0] ;
    for (size_t i = 0; i < longueur && sizeof(int[TAILLE])/sizeof(t[0]); i++)
    {
        if (max < t[i])
        {
             max=t[i];
        }
    }  
    return max;
}

int indicemax(int *t,int longueur){
    int i;
    int max =t[0] ;
    int indice=0 ;
    for (size_t i = 0; i < longueur && sizeof(int[TAILLE])/sizeof(t[0]); i++)
    {
        if (max < t[i])
        {
             max=t[i];
             indice = i;
        }    
    } 
    return indice;
}

//afficher de façon recursive un tableau
void afficherRecL(int *t ,int longueur){
    afficherREC(t,longueur,0);
}

void afficherREC(int *t, int longueur,int ind){
    if (longueur > ind)
    {
       printf("%d |",t[ind]);
       ind++;
       afficherREC(t,longueur,ind);
    }
    
} 

int indicemaxREC(int *t,int longueur,int ind,int max,int indice){
   
   if (longueur> ind)
   {
       if (t[ind]>max)
       {
           max = t[ind] ;
           indice=ind ;
           ind++ ;
           indicemaxREC(t,longueur,ind,max,indice);
       }else{
           ind++;
           indicemaxREC(t,longueur,ind,max,indice);
       }           
   }
   else
   {
       return indice ;
   }   
}

int indicemaxRECL(int*t ,int longueur){
    int max = t[0];
    int i =0;
    int indice =indicemaxREC(t,longueur,i,max,i);
    return indice;
}

int main(void){
    srand(time(NULL));
   
    int longueur = 5;
    int s ;
    int m ;
    int i;
    int ir;
    tab1D t;

    remplir(t , longueur);

    afficher(t , longueur);

    s=somme(t,longueur);
    printf("somme = %d\n", s);

    m=max(t,longueur);
    printf("max = %d\n", m);

    i=indicemax(t,longueur);
    printf("indice max = %d\n", i);

    afficherRecL(t,longueur);
    printf("\n");

    ir=indicemaxRECL(t,longueur);
    printf("indice max rec = %d\n",ir);
    return EXIT_SUCCESS;
}