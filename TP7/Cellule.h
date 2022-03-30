#ifndef __CELLULE__
#define __CELLULE__
#include "Element.h"


typedef struct Cellule Cellule;
struct Cellule
{
    Element element;
    
    Cellule *succ ;
    Cellule *pred ;
};


#endif