#ifndef __HACHAGE_H__
#define __HACHAGE_H__
#include "Reseau.h"


typedef struct cellnoeudh {
    double clef;
    Noeud *nd;               
    struct cellnoeudh *suiv;         
} CellNoeudH;

typedef struct tablehachage{
    int nE;                 // nombre d'élément dans la table de hachage
    int M;                  // taille de la table de hachage
    CellNoeudH **T;
}TableHachage;


double fonctionClef(int x,int y);
int fonctionHachage(double cle,int M);
TableHachage* initialise_table(int M);
void libererHachage(TableHachage* H);
Noeud* rechercheCreeNoeudHachage(Reseau *R, TableHachage *H, double x, double y);
Reseau *reconstitueReseauHachage(Chaines *C, int M);

#endif