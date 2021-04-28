#include "Reseau.h"
#include <stdio.h>
#include <stdlib.h>
#include "SVGwriter.h"

void libererNoeud(Noeud* n){
    // on libère le voisins
    CellNoeud *nsuiv = n->voisins;
    CellNoeud* courant;
    while(nsuiv){
        courant = nsuiv;
        nsuiv = nsuiv->suiv;
        free(courant);
    }
    courant = NULL;
    free(n);
}

void libererReseau(Reseau* R){
    // on crée un tableau pour tester si un noeud est libère déja
    int tabN[R->nbNoeuds];
    for (int i = 0;i < R->nbNoeuds;i++) tabN[i] = 1;
    // on libère les noeuds
    CellNoeud *ncour = R->noeuds;
    CellNoeud* courant;
    while (ncour){
        if (tabN[(ncour->nd->num) - 1]){
            tabN[(ncour->nd->num) - 1] = 0;
            libererNoeud(ncour->nd);
        }
        courant = ncour;
        ncour = ncour->suiv;
        free(courant);
    }
    // on libère les commodites
    while (R->commodites){
        CellCommodite* courant = R->commodites;
        R->commodites = R->commodites->suiv;
        free(courant);
    }
    free(R);
}

Noeud* rechercheCreeNoeudListe(Reseau *R, double x, double y){
    /* on crée un pointeur pour parcourir la chaine des noeuds */
    CellNoeud *ncour = R->noeuds;
    while(ncour){
        if((ncour->nd->x == x) && (ncour->nd->y == y)){
            return ncour->nd;
        }
        ncour = ncour->suiv;
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
    return n;
}

Reseau* reconstitueReseauListe(Chaines *C){
    //création d'un réseau
    Reseau *R = (Reseau *)(malloc(sizeof(Reseau)));
    R->noeuds = NULL;
    R->gamma =  C->gamma;
    R->nbNoeuds = 0;
    R->commodites = NULL;
    //pointeur pour parcourir la liste des chaines
    CellChaine *Ccour = C->chaines;
     CellPoint *pcour = NULL;
    while(Ccour){
        //pointeur pour parcourir des points 
        pcour = Ccour->points;
        CellCommodite *commoditescour = (CellCommodite *)(malloc(sizeof(CellCommodite)));
        commoditescour->extrA = rechercheCreeNoeudListe(R,pcour->x,pcour->y);
        //pointeur pour stoker le point précédent
        CellPoint *pprecedent = NULL;
        while(pcour){
            if(pprecedent == NULL){
                rechercheCreeNoeudListe(R,pcour->x,pcour->y);
            }else{
                Noeud *p = rechercheCreeNoeudListe(R,pcour->x,pcour->y);
                Noeud *pp = rechercheCreeNoeudListe(R,pprecedent->x,pprecedent->y);
                //chaine parcourir stoker les voisins
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
                commoditescour->extrB = rechercheCreeNoeudListe(R,pcour->x,pcour->y);
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
    return R;
}

int nbCommodites(Reseau *R){
    int nb = 0;
    //créer un pointeur pour parcourir
    CellCommodite *ccour = R->commodites;
    while(ccour){
        nb++;
        ccour = ccour->suiv;
    }
    return nb;
}

int nbLiaisons(Reseau *R){
    int cpt = 0;
    // on crée un pointeur pour parcourir le reseau
    CellNoeud* ncour= R->noeuds;
    while(ncour){
        // on parcout tous les voisins des noeuds
        CellNoeud* voisinscour = ncour->nd->voisins;
        while(voisinscour){
            cpt++;
            voisinscour = voisinscour->suiv;
        }
        ncour = ncour->suiv;
    }
    // en fait, on compte deux fois les meme liansons
    return cpt/2;
}


void ecrireReseau(Reseau *R, FILE *f){
    /* partie 1: les quatre premières lignes */
    fprintf(f, "NbNoeuds: %d\n", R->nbNoeuds);         // le nombre de noeuds du réseau
    fprintf(f, "NbLiaisons: %d\n", nbLiaisons(R));     // le nombre de cables(liasons)
    fprintf(f, "NbCommodites: %d\n", nbCommodites(R)); // le nombre de commodités
    fprintf(f, "Gamma: %d\n", R->gamma);               // le nombre maximal de fibles optiques par cable
    fprintf(f,"\n");

    /* partie 2: les lignes commençant par 'v' donnent les noeuds du réseau */
    CellNoeud* ncour = R->noeuds; // on crée un pointeur pour parcourir les noeuds
    while (ncour){
        fprintf(f, "v %d %f %f\n", ncour->nd->num, ncour->nd->x, ncour->nd->y); 
        ncour = ncour->suiv;
    }
    fprintf(f,"\n");
    
    /* partie 3: les lignes commençant par 'l' contiennent une liaison(les numéros de ses deux extrémités) */
    ncour = R->noeuds; // on parcout les noeuds
    while (ncour){
        int num_noeud_1 = ncour->nd->num;
        int num_noeud_2 = 0;
        CellNoeud* voisins = ncour->nd->voisins; // on crée un pointeur pour parcourir les voisins du noeud courant
        while(voisins){
            if (num_noeud_1 < voisins->nd->num){ // le probleme de répétition
                num_noeud_2 = voisins->nd->num;
                fprintf(f, "l %d %d\n", num_noeud_1, num_noeud_2);
            }
            voisins = voisins->suiv;
        }  
        ncour = ncour->suiv; 
    }
    fprintf(f,"\n");
    
    /* partie 4: les lignes commençant par 'k' correspondant à une commodité(une paire de numéros de noeuds) */
    CellCommodite* ccour= R->commodites; // on crée un pointeur pour parcourir les commodités
    while (ccour){
        fprintf(f, "k %d %d\n", ccour->extrA->num, ccour->extrB->num);
        ccour = ccour->suiv;
    }
}


void afficheReseauSVG(Reseau *R, char* nomInstance){
    CellNoeud *courN,*courv;
    SVGwriter svg;
    double maxx=0,maxy=0,minx=1e6,miny=1e6;

    courN=R->noeuds;
    while (courN!=NULL){
        if (maxx<courN->nd->x) maxx=courN->nd->x;
        if (maxy<courN->nd->y) maxy=courN->nd->y;
        if (minx>courN->nd->x) minx=courN->nd->x;
        if (miny>courN->nd->y) miny=courN->nd->y;
        courN=courN->suiv;
    }
    SVGinit(&svg,nomInstance,500,500);
    courN=R->noeuds;
    while (courN!=NULL){
        SVGpoint(&svg,500*(courN->nd->x-minx)/(maxx-minx),500*(courN->nd->y-miny)/(maxy-miny));
        courv=courN->nd->voisins;
        while (courv!=NULL){
            if (courv->nd->num<courN->nd->num)
                SVGline(&svg,500*(courv->nd->x-minx)/(maxx-minx),500*(courv->nd->y-miny)/(maxy-miny),500*(courN->nd->x-minx)/(maxx-minx),500*(courN->nd->y-miny)/(maxy-miny));
            courv=courv->suiv;
        }
        courN=courN->suiv;
    }
    SVGfinalize(&svg);
}
