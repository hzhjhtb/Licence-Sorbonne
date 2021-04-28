#include "ArbreQuat.h"
#include <stdlib.h>


void chaineCoordMinMax(Chaines* C, double* xmin, double*ymin, double* xmax, double* ymax){
    CellChaine* chaines = C->chaines; // on crée un pointeur pour parcourir les chaines
    CellPoint* points = chaines->points; // on crée un pointeur pour parcourir les points
    *xmin = points->x;  // dans le début, les minimums et maximum sont les coors de la première point
    *ymin = points->y;
    *xmax = points->x;
    *ymax = points->y;

    /* on parcout tous les points */
    while(chaines){
        points = chaines->points;
        while(points){
            if (points->x < *xmin) *xmin = points->x;
            if (points->y < *ymin) *ymin = points->y;
            if (points->x > *xmax) *xmax = points->x;
            if (points->y > *ymax) *ymax = points->y;
            points = points->suiv;
        }
        chaines = chaines->suiv;
    }
}


ArbreQuat* creerArbreQuat(double xc, double yc, double coteX, double coteY){
    ArbreQuat* aq_res = (ArbreQuat*)malloc(sizeof(ArbreQuat));
    aq_res->xc = xc;
    aq_res->yc = yc;
    aq_res->coteX = coteX;
    aq_res->coteY = coteY;
    
    aq_res->noeud = NULL;
    aq_res->so = NULL;
    aq_res->se = NULL;
    aq_res->no = NULL;
    aq_res->ne = NULL;

    return aq_res;
}


void insererNoeudArbre(Noeud* n, ArbreQuat** a, ArbreQuat* parent){
    double xc, yc, coteX, coteY;
    coteX = (parent->coteX)/2;
    coteY = (parent->coteY)/2;

    if (*a == NULL){  /* cas 1: Arbre vide */
        if ((n->x < parent->xc) && (n->y < parent->yc)){   // Sous-arbre sud-ouest du parent
            xc = parent->xc - coteX/2;
            yc = parent->yc - coteY/2;
            *a = creerArbreQuat(xc, yc, coteX, coteY);
            (*a)->noeud = n;
        }
        if ((n->x >= parent->xc) && (n->y < parent->yc)){  // Sous-arbre sud-est du parent
            xc = parent->xc + coteX/2;
            yc = parent->yc - coteY/2;
            *a = creerArbreQuat(xc, yc, coteX, coteY);
            (*a)->noeud = n;
        }
        if ((n->x < parent->xc) && (n->y >= parent->yc)){  // Sous-arbre nord-ouest du parent
            xc = parent->xc - coteX/2;
            yc = parent->yc + coteY/2;
            *a = creerArbreQuat(xc, yc, coteX, coteY);
            (*a)->noeud = n;
        }
        if ((n->x >= parent->xc) && (n->y >= parent->yc)){ // Sous-arbre nord-est du parent
            xc = parent->xc + coteX/2;
            yc = parent->yc + coteY/2;
            *a = creerArbreQuat(xc, yc, coteX, coteY);
            (*a)->noeud = n;
        }
        return;
    }else if ((*a)->noeud != NULL){  /* cas 2: Feuille */
        Noeud* ancient = (*a)->noeud;
        //4 situation de ancient
		//ne
		if(ancient->x >= (*a)->xc && ancient->y >= (*a)->yc) insererNoeudArbre(ancient, &((*a)->ne), (*a));
		//no
		if(ancient->x < (*a)->xc && ancient->y >= (*a)->yc) insererNoeudArbre(ancient, &((*a)->no), (*a));
		//se
		if(ancient->x >= (*a)->xc && ancient->y < (*a)->yc) insererNoeudArbre(ancient, &((*a)->se), (*a));
		//so
		if(ancient->x < (*a)->xc && ancient->y < (*a)->yc) insererNoeudArbre(ancient, &((*a)->so), (*a));
		//4 situation de n
		//ne
		if(n->x >= (*a)->xc && n->y >= (*a)->yc) insererNoeudArbre(n, &((*a)->ne), (*a));
		//no
		if(n->x < (*a)->xc && n->y >= (*a)->yc) insererNoeudArbre(n, &((*a)->no), (*a));
		//se
		if(n->x >= (*a)->xc && n->y < (*a)->yc) insererNoeudArbre(n, &((*a)->se), (*a));		
		//so
		if(n->x < (*a)->xc && n->y < (*a)->yc) insererNoeudArbre(n, &((*a)->so), (*a));
        (*a)->noeud = NULL;
        return;
	}  /* cas 3: Cellule interne  */
    if ((n->x < (*a)->xc) && (n->y < (*a)->yc)) insererNoeudArbre(n, &((*a)->so), *a);// Sous-arbre sud-ouest du *a
    if ((n->x >= (*a)->xc) && (n->y < (*a)->yc)) insererNoeudArbre(n, &((*a)->se), *a);// Sous-arbre sud-est du *a
    if ((n->x < (*a)->xc) && (n->y >= (*a)->yc)) insererNoeudArbre(n, &((*a)->no), *a);// Sous-arbre nord-ouest du *a 
    if ((n->x >= (*a)->xc) && (n->y >= (*a)->yc)) insererNoeudArbre(n, &((*a)->ne), *a);// Sous-arbre nord-est du *a 
}


void libererArbreQuat(ArbreQuat* a){
    if (a == NULL){ /* cas 1: Arbre vide */
        return ;
    }else if (a->noeud != NULL){  /* cas 2: Feuille */
        free(a);
        return ;
    }else{ /* cas 3: Cellule interne  */
        libererArbreQuat(a->so);
        libererArbreQuat(a->se);
        libererArbreQuat(a->no);
        libererArbreQuat(a->ne);
        free(a);
    }
}


Noeud* rechercheCreeNoeudArbre(Reseau* R, ArbreQuat** a, ArbreQuat* parent, double x, double y){
    if (*a == NULL){  /* cas 1: Arbre vide */
        // on crée le noeud correspondant au ce point et l'insère dans le reseau
        Noeud* n = (Noeud *)(malloc(sizeof(Noeud)));
        n->x = x;
        n->y = y;
        n->voisins = NULL;
        n->num = (R->nbNoeuds)++;
        //on l'insère dans R
        CellNoeud* celln = (malloc(sizeof(CellNoeud)));
        celln->nd = n;
        celln->suiv = R->noeuds;
        R->noeuds = celln;
        R->nbNoeuds++;
        // on l'insère dans l'arbre
        insererNoeudArbre(n, a, parent);
        return n;

    }else if ((*a)->noeud != NULL){  /* cas 2: Feuille */
        if (((*a)->noeud->x == x) && ((*a)->noeud->y == y)){
            return (*a)->noeud;
        }else{
            // on crée le noeud correspondant au ce point et l'insère dans le reseau
            Noeud* n = (Noeud *)(malloc(sizeof(Noeud)));
            n->x = x;
            n->y = y;
            n->voisins = NULL;
            n->num = R->nbNoeuds++;
            CellNoeud* celln = (malloc(sizeof(CellNoeud)));
            celln->nd = n;
            celln->suiv = R->noeuds;
            R->noeuds = celln;
            R->nbNoeuds++;
            // on l'insère dans l'arbre
            insererNoeudArbre(n, a, parent);
            return n;
        }

    }else{  /* cas 3: Cellule interne  */
        Noeud* n = NULL;
        if ((x < (*a)->xc) && (y < (*a)->yc)){   // Sous-arbre sud-ouest du *a
            n = rechercheCreeNoeudArbre(R, &((*a)->so), *a, x, y);
        }
        if ((x >= (*a)->xc) && (y < (*a)->yc)){  // Sous-arbre sud-est du *a
            n = rechercheCreeNoeudArbre(R, &((*a)->se), *a, x, y);
        }
        if ((x < (*a)->xc) && (y >= (*a)->yc)){  // Sous-arbre nord-ouest du *a 
            n = rechercheCreeNoeudArbre(R, &((*a)->no), *a, x, y);
        }
        if ((x >= (*a)->xc) && (y >= (*a)->yc)){ // Sous-arbre nord-est du *a 
            n = rechercheCreeNoeudArbre(R, &((*a)->ne), *a, x, y);
        }
        return n;
    }
}


Reseau* reconstitueReseauArbre(Chaines* C){
    // création du ensemble de noeuds V avec ArbreQuat
    double xmin, ymin, xmax, ymax;
    chaineCoordMinMax(C, &xmin, &ymin, &xmax, &ymax);
    ArbreQuat* V = creerArbreQuat((xmin + xmax)/2, (ymin + ymax)/2, xmax-xmin, ymax-ymin);

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
        //pointeur pour stoker le point précédent
        CellPoint *pprecedent = NULL;
        while(pcour){
            if(pprecedent == NULL){
                if ((pcour->x < V->xc) && (pcour->y < V->yc)){ // Sous-arbre sud-ouest du V 
                    commoditescour->extrA = rechercheCreeNoeudArbre(R, &(V->so), V, pcour->x, pcour->y);
                }
                if ((pcour->x >= V->xc) && (pcour->y < V->yc)){ // Sous-arbre sud-est du V
                    commoditescour->extrA = rechercheCreeNoeudArbre(R, &(V->se), V, pcour->x, pcour->y);
                }
                if ((pcour->x < V->xc) && (pcour->y >= V->yc)){ // Sous-arbre nord-ouest du V
                    commoditescour->extrA = rechercheCreeNoeudArbre(R, &(V->no), V, pcour->x, pcour->y);
                }
                if ((pcour->x >= V->xc) && (pcour->y >= V->yc)){ // Sous-arbre nord-est du V
                    commoditescour->extrA = rechercheCreeNoeudArbre(R, &(V->ne), V, pcour->x, pcour->y);
                } 
            }else{
                Noeud *p = NULL;
                if ((pcour->x < V->xc) && (pcour->y < V->yc)){ // Sous-arbre sud-ouest du V 
                    p = rechercheCreeNoeudArbre(R, &(V->so), V, pcour->x, pcour->y);
                }
                if ((pcour->x >= V->xc) && (pcour->y < V->yc)){ // Sous-arbre sud-est du V
                    p = rechercheCreeNoeudArbre(R, &(V->se), V, pcour->x, pcour->y);
                }
                if ((pcour->x < V->xc) && (pcour->y >= V->yc)){ // Sous-arbre nord-ouest du V
                    p = rechercheCreeNoeudArbre(R, &(V->no), V, pcour->x, pcour->y);
                }
                if ((pcour->x >= V->xc) && (pcour->y >= V->yc)){ // Sous-arbre nord-est du V
                    p = rechercheCreeNoeudArbre(R, &(V->ne), V, pcour->x, pcour->y);
                }
                Noeud *pp = NULL;
                if ((pprecedent->x < V->xc) && (pprecedent->y < V->yc)){ // Sous-arbre sud-ouest du V 
                    pp = rechercheCreeNoeudArbre(R, &(V->so), V, pprecedent->x, pprecedent->y);
                }
                if ((pprecedent->x >= V->xc) && (pprecedent->y < V->yc)){ // Sous-arbre sud-est du V
                    pp = rechercheCreeNoeudArbre(R, &(V->se), V, pprecedent->x, pprecedent->y);
                }
                if ((pprecedent->x < V->xc) && (pprecedent->y >= V->yc)){ // Sous-arbre nord-ouest du V
                    pp = rechercheCreeNoeudArbre(R, &(V->no), V, pprecedent->x, pprecedent->y);
                }
                if ((pprecedent->x >= V->xc) && (pprecedent->y >= V->yc)){ // Sous-arbre nord-est du V
                    pp = rechercheCreeNoeudArbre(R, &(V->ne), V, pprecedent->x, pprecedent->y);
                }
                //chaine pour parcourir les voisins
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
                if ((pcour->x < V->xc) && (pcour->y < V->yc)){ // Sous-arbre sud-ouest du V 
                    commoditescour->extrB = rechercheCreeNoeudArbre(R, &(V->so), V, pcour->x, pcour->y);
                }
                if ((pcour->x >= V->xc) && (pcour->y < V->yc)){ // Sous-arbre sud-est du V
                    commoditescour->extrB = rechercheCreeNoeudArbre(R, &(V->se), V, pcour->x, pcour->y);
                }
                if ((pcour->x < V->xc) && (pcour->y >= V->yc)){ // Sous-arbre nord-ouest du V
                    commoditescour->extrB = rechercheCreeNoeudArbre(R, &(V->no), V, pcour->x, pcour->y);
                }
                if ((pcour->x >= V->xc) && (pcour->y >= V->yc)){ // Sous-arbre nord-est du V
                    commoditescour->extrB = rechercheCreeNoeudArbre(R, &(V->ne), V, pcour->x, pcour->y);
                }
                commoditescour->suiv = NULL;
            }
            pprecedent = pcour;
            pcour = pcour->suiv;
        }
        //ajouter les commodites
        commoditescour->suiv = R->commodites;
        R->commodites = commoditescour;
        Ccour = Ccour->suiv;
    }    
    libererArbreQuat(V);
    return R;
}



