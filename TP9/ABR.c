#include <stdio.h>
#include <stdlib.h>
#include "ABR.h"

void ABR_creer(ABR *px)
{
    *px = NULL;
}

int ABR_vide(ABR x)
{
    return (x == NULL);
}

Noeud *ABR_rechercher(ABR x, int k)
{
    if (ABR_vide(x))
        return NULL;
    else if (x->cle == k)
        return x;
    else if (k < x->cle)
        return ABR_rechercher(x->filsGauche, k);
    else
        return ABR_rechercher(x->filsDroit, k);
}

Noeud *ABR_minimum(ABR x)
{
    if (x == NULL)
        return NULL;
    else if (x->filsGauche == NULL)
        return x;
    else
        return ABR_minimum(x->filsGauche);
}

Noeud *ABR_maximum(ABR x)
{
    if (x == NULL)
        return NULL;
    else if (x->filsDroit == NULL)
        return x;
    else
        return ABR_maximum(x->filsDroit);
}

Noeud *ABR_successeur(Noeud *x) // il est enracine
{
    if (x == NULL)
        return x;
    // else
    if (x->filsDroit != NULL)
        return ABR_minimum(x->filsDroit);
    else
    {
        Noeud *y = x->pere;
        while (y != NULL && x == y->filsDroit)
        {
            x = y;
            y = y->pere;
        }
        return y;
    }
}

Noeud *ABR_predecesseur(Noeud *x)
{
    if (x == NULL)
        return x;
    // else
    if (x->filsGauche != NULL)
        return ABR_maximum(x->filsGauche);
    else
    {
        Noeud *y = x->pere;
        while (y != NULL && x == y->filsGauche)
        {
            x = y;
            y = y->pere;
        }
        return y;
    }
}

// routine (interne)
Noeud *nouveau_noeud(int k)
{
    Noeud *p = (Noeud *)malloc(sizeof(Noeud));
    p->cle = k;
    // noeud isole : tous pointeurs a NULL
    p->pere = NULL;
    p->filsGauche = NULL;
    p->filsDroit = NULL;
    return p;
}

void ABR_inserer(ABR *px, int k)
{
    if (ABR_vide(*px))
    {
        *px = nouveau_noeud(k);
    }
    else
    {
        Noeud *p = *px;
        while (p != NULL)
        {
            if (k < p->cle)
            {
                if (p->filsGauche == NULL)
                {
                    p->filsGauche = nouveau_noeud(k);
                    p->filsGauche->pere = p;
                    break;
                }
                else
                    p = p->filsGauche;
            }
            else
            {
                if (p->filsDroit == NULL)
                {
                    p->filsDroit = nouveau_noeud(k);
                    p->filsDroit->pere = p;
                    break;
                }
                else
                    p = p->filsDroit;
            }
        }
    }
}

void ABR_supprimer(ABR *px, Noeud *p)
{
    if (p == NULL)
        return;
    // else
    if (p->filsGauche == NULL && p->filsDroit == NULL)
    {
        if (p->pere == NULL)
            *px = NULL;
        else
        {
            if (p == p->pere->filsGauche)
                p->pere->filsGauche = NULL;
            else
                p->pere->filsDroit = NULL;
        }
        free(p);
    }
    else if (p->filsGauche == NULL)
    {
        if (p->pere == NULL)
            *px = p->filsDroit;
        else
        {
            if (p == p->pere->filsGauche)
                p->pere->filsGauche = p->filsDroit;
            else
                p->pere->filsDroit = p->filsDroit;
        }
        p->filsDroit->pere = p->pere;
        free(p);
    }
    else if (p->filsDroit == NULL)
    {
        if (p->pere == NULL)
            *px = p->filsGauche;
        else
        {
            if (p == p->pere->filsGauche)
                p->pere->filsGauche = p->filsGauche;
            else
                p->pere->filsDroit = p->filsGauche;
        }
        p->filsGauche->pere = p->pere;
        free(p);
    }
    else
    {
        Noeud *q = ABR_successeur(p);
        p->cle = q->cle;
        ABR_supprimer(px, q);
    }
}
