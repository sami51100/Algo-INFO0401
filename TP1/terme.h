#ifndef __TERME__
#define __TERME__


typedef struct terme {
    int nb ;
    int *elts  ; 
}terme;

terme premier(void);

void afficher(terme c);

terme suivant(terme a); 



#endif 