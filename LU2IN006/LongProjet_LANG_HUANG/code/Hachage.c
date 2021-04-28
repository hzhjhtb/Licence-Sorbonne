#include "Hachage.h"
#include <stdlib.h>

void libererHachage(TableHachage* H){
    int m = H->M;
    CellNoeudH** t = H->T;
    for(int i = 0;i<m;i++){
        if(t[i]){
            CellNoeudH* ccour = t[i];
            CellNoeudH* csuiv = NULL;
            while(ccour){
                csuiv = ccour;
                ccour = ccour->suiv;
                free(csuiv);
            }
        }
    }
    free(t);
    free(H);
}

double fonctionClef(int x,int y){
    return y+(x+y)*(x+y+1)/2;
}

int fonctionHachage(double cle,int M){
    double A = (sqrt(5) - 1) / 2;
    return ((int)(M*(cle*A - ((int)(cle*A))))); //
}

TableHachage* initialise_table(int M){
    TableHachage *H = (TableHachage *)(malloc(sizeof(TableHachage)));
    CellNoeudH **T = (CellNoeudH **)(malloc(sizeof(CellNoeudH *)*M));
    for(int i = 0;i<M;i++){
        T[i] = NULL;
    }
    H->T = T;
    H->nE = 0;
    H->M = M;
    return H;
}

Noeud* rechercheCreeNoeudHachage(Reseau *R, TableHachage *H, double x, double y){
    //vérifier si le noeud est dans la table   
    CellNoeudH *courNH = H->T[fonctionHachage(fonctionClef(x,y),H->M)];
    while(courNH){
        if(courNH->nd->x == x && courNH->nd->y == y){
            return courNH->nd;
        }
        courNH = courNH->suiv;
    }
    /* on crée un nouveau noeud n */
    Noeud *n = (Noeud *)(malloc(sizeof(Noeud)));
    n->x = x;
    n->y = y;
    n->num = R->nbNoeuds + 1;
    n->voisins = NULL;
    /* on l'ajoute à la tête de la chaine */
    CellNoeud *celln = (CellNoeud *)(malloc(sizeof(CellNoeud)));
    celln->nd = n;
    celln->suiv = R->noeuds;
    R->noeuds = celln;
    R->nbNoeuds++;
    /* on l'ajoute dans la table de hachage*/
    CellNoeudH *cellnh = (CellNoeudH *)(malloc(sizeof(CellNoeudH)));
    cellnh->clef = fonctionClef(x,y);
    cellnh->nd = n;
    cellnh->suiv = H->T[fonctionHachage(cellnh->clef,H->M)];
    H->T[fonctionHachage(cellnh->clef,H->M)] = cellnh;
    H->nE++;

    return n;
}

Reseau *reconstitueReseauHachage(Chaines *C, int M){
    /* on crée une table de hachage*/
    TableHachage *H = initialise_table(M);
    //création d'un réseau
    Reseau *R = (Reseau *)(malloc(sizeof(Reseau)));
    //CellCommodite *commodites = (CellCommodite *)(malloc(sizeof(CellCommodite)));
    R->noeuds = NULL;
    R->gamma =  C->gamma;
    R->nbNoeuds = 0;
    R->commodites = NULL;
    //pointeur pour parcourir la liste des chaines
    CellChaine *Ccour = C->chaines;
    while(Ccour){
        //pointeur pour parcourir des points
        CellPoint *pcour = Ccour->points;
        CellCommodite *commoditescour = (CellCommodite *)(malloc(sizeof(CellCommodite)));
        commoditescour->extrA = rechercheCreeNoeudHachage(R,H,pcour->x,pcour->y);
        //pointeur pour stoker le point précédent
        CellPoint *pprecedent = NULL;
        while(pcour){
            if(pprecedent == NULL){
                rechercheCreeNoeudHachage(R,H,pcour->x,pcour->y);
            }else{
                Noeud *p = rechercheCreeNoeudHachage(R,H,pcour->x,pcour->y);
                Noeud *pp = rechercheCreeNoeudHachage(R,H,pprecedent->x,pprecedent->y);
                //chaine pour stoker les voisins
                CellNoeud *pvoisinscour = p->voisins;
                CellNoeud *ppvoisinscour = pp->voisins;
                int cmpp = 0;//pour compter si il y a noeud répétitif
                int cmppp = 0;
                while(pvoisinscour){
                   if(pvoisinscour->nd == pp){
                       cmpp++;
                   }
                   pvoisinscour = pvoisinscour->suiv;
                }
                if(cmpp == 0){
                    CellNoeud *pvoisins = (CellNoeud *)(malloc(sizeof(CellNoeud)));
                    pvoisins->nd = pp;
                    pvoisins->suiv = p->voisins;
                    p->voisins = pvoisins;
                    pvoisins = NULL;
                }
                while(ppvoisinscour){
                   if(ppvoisinscour->nd == p){
                       cmppp++;
                   }
                   ppvoisinscour = ppvoisinscour->suiv;
                }
                if(cmppp == 0){
                    CellNoeud *ppvoisins = (CellNoeud *)(malloc(sizeof(CellNoeud)));
                    ppvoisins->nd = p;
                    ppvoisins->suiv = pp->voisins;
                    pp->voisins = ppvoisins;
                    ppvoisins = NULL;
                }
            }
            if(pcour->suiv == NULL){
                commoditescour->extrB = rechercheCreeNoeudHachage(R,H,pcour->x,pcour->y);
                commoditescour->suiv = NULL;
            }
            pprecedent = pcour;
            pcour = pcour->suiv;
        }
        //ajouter les commodites
        if(R->commodites == NULL){
            R->commodites = commoditescour;
        }else{
            commoditescour->suiv = R->commodites;
            R->commodites = commoditescour;
        }
        Ccour = Ccour->suiv;
    }
    libererHachage(H);
    return R;       
}