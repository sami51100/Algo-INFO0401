#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define TAILLE 100
typedef int tab1D[TAILLE];

void remplir(int *t,int longueur);
void afficher(int *t , int longueur);
int somme(int *t , int longueur);
int max(int *t , int longueur);
int indicemax(int *t , int longueur);
void recopier(int *t1 , int *t2 , int longueur);
void trie_bulle(int *t , int longueur);

//remplir le tableau de valeur aléatoire
void remplir(int *t,int longueur){
    int i;
    for (size_t i = 0; i < longueur ; i++)
    {
        t[i]= rand()%11 + 10 ;
    }    
}

//afficher le tableau
void afficher(int *t,int longueur){
    int i;
    for (size_t i = 0; i < longueur ; i++)
    {
        printf("%d |",t[i]);
    }
    printf("\n");
}

void recopier(int *t1 , int *t2 , int longueur){

    for (size_t i = 0; i < longueur ; i++)
    {
        t2[i]=t1[i];
    }
    
}

void trie_bulle(int *t , int longueur)
{
    int tmp;
    for (size_t i = 0; i < longueur-1; i++)
    {
        for (size_t j = 0; j <longueur-i-1 ; j++)
        {
            if (t[j] > t[j+1])
            {
                tmp = t[j] ;
                t[j] = t[j+1] ; 
                t[j+1] = tmp;
            }
            
        }
        
    }
    
}
int main(void)
{
    srand(time(NULL));
   
    int longueur = 0;
    printf("entrez la taille du tableau %c tri%ce :\n",133,130);
    scanf("%d",&longueur);
    tab1D t;
    tab1D t2;
    remplir(t , longueur);

    printf("tableau non tri%ce : \n",130);
    afficher(t , longueur);

    recopier(t , t2 ,longueur);

    printf("tableau non tri%ce, recopi%c: \n",130,130);
    afficher(t2 , longueur);
    
    trie_bulle(t , longueur);
    printf("tableau tri%ce, recopi%c: \n",130,130);
    afficher(t , longueur);

    return EXIT_SUCCESS;
}