#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int* generer(int taille  ){

    srand(time(NULL));

    int i ;
    int *tab = NULL ;

    tab=(int*)calloc(taille,sizeof(int));

    if (tab== NULL)
    {
        exit(0);
    }
    

    for ( i = 0; i < taille ; i++)
    {
        tab[i]=rand() % 3 ;
    }
    
    

    return tab ;
}

void afficher(int taille , int tab[taille])
{
    int i ;
    for (int i = 0; i < taille; i++)
    {
        printf("  %d |", tab[i]);
    }

}

void trier(int taille , int tab[taille]){
    int i  = 0;
    int j = 0;
    int k = taille;
    int tmp ;
    
    while (j <= k)
    {
        
       while( tab[i] == 0){
           i++ ;
           if(tab[i] != 0){
               j= i+1 ;
           }
           
       }
       while (tab[k] == 2)
       {
           k-- ;
       }
       if (tab[j]==0)
       {
          tmp = tab[j];
          tab[j]=tab[i];
          tab[i]=tmp ;
          i++ ;
       }
       else if (tab[j]==2)
       {
          tmp = tab[j];
          tab[j]=tab[k];
          tab[k]=tmp ;
          k-- ;
       }
       else 
       {
          j++;
       }
       

    }
    
   
}

int main(void)
{
    int taille ;
    int *tab=NULL ;
    
    printf("entrez la taille du tableau :");
    scanf("%d",&taille);
    
    tab=generer(taille);

    afficher(taille , tab);
    //fflush(stdin);
    printf("\n");

    trier(taille , tab);

    afficher(taille , tab);


    free(tab);
    
    
    return 0;
}