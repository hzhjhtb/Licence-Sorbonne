#include "Chaine.h"
#include <stdlib.h>
#include <string.h>
#include "SVGwriter.h"

void libererChaines(Chaines* C){
    CellChaine* ccour = C->chaines;
    while(ccour){
        CellChaine* courant = ccour;
        CellPoint* pcour = ccour->points;
        while(pcour){
           CellPoint* courant = pcour; 
           pcour = pcour->suiv;
           free(courant);
        }
        ccour = ccour->suiv;
        free(courant);
    }
    free(C);
    C = NULL;
}




Chaines* lectureChaines(FILE *f){
    Chaines* chaines = (Chaines*)(malloc(sizeof(Chaines)));
    
    /* lecture de les deux premieres lignes */
    char buf[256];
    int nbChaines, gamma;
    fgets(buf, 256, f);
    buf[strlen(buf) - 1] = '\0';
    sscanf(buf, "NbChain: %d", &nbChaines);
    chaines->nbChaines = nbChaines;
    fgets(buf, 256, f);
    buf[strlen(buf) - 1] = '\0';
    sscanf(buf, "Gamma: %d", &gamma);
    chaines->gamma = gamma;

    /* lecture des lignes restes */
    CellChaine* cellchaine = NULL;
    for (int i=0; i<nbChaines; i++){
        /* lecture de la (i+2)ieme ligne */
        fgets(buf, 256, f);
        buf[strlen(buf) - 1] = '\0';
        /* les deux premieres donnees dans la ligne */
        CellChaine* cellchaine_insere = (CellChaine*)(malloc(sizeof(CellChaine)));
        int numero, nbPoint;
        sscanf(buf, "%d %d %[^\n]\n", &numero, &nbPoint, buf);
        /* les restes donnees dans la ligne */
        CellPoint* cellpoint = NULL;
        for (int j=0; j<nbPoint; j++){
            CellPoint* cellpoint_insere = (CellPoint*)(malloc(sizeof(CellPoint)));
            double x, y;
            sscanf(buf, " %lf %lf %[^\n]\n", &x, &y, buf);
            cellpoint_insere->x = x;
            cellpoint_insere->y = y;
            cellpoint_insere->suiv = NULL;
            cellpoint_insere->suiv = cellpoint;
            cellpoint = cellpoint_insere;       
        }
        cellchaine_insere->points = cellpoint;
        cellchaine_insere->suiv = NULL;
        cellchaine_insere->suiv = cellchaine; 
        cellchaine = cellchaine_insere;
        cellchaine->numero = numero;    
    }
    chaines->chaines = cellchaine;
    return chaines;
}


void ecrireChaines(Chaines *C, FILE *f){
    /* ligne 1 */
    fprintf(f, "NbChain: %d\n", C->nbChaines);
    /* ligne 2 */
    fprintf(f, "Gamma: %d\n", C->gamma);
    CellChaine* cc = C->chaines;
    /* les restes lignes */
    for(int i=0; i<C->nbChaines; i++){
        fprintf(f,"%d ",cc->numero);
        cc = cc->suiv;
        CellChaine* cellchaine = C->chaines;
        for (int j=0; j<i; j++) cellchaine = cellchaine->suiv;
        CellPoint* cellpoint = cellchaine->points;
        /* on compte le nombre des points */
        int cmp = 0;
        while(cellpoint){
            cmp++;
            cellpoint = cellpoint->suiv;
        } 
        /* dans la sortie de la boucle, cellpoint est le derniere point dans cette ligne */
        fprintf(f, "%d", cmp);
        cellpoint = cellchaine->points;
        /* l'affichage des points dans cette ligne */
        while(cellpoint){
            fprintf(f, " %.2f %.2f", cellpoint->x, cellpoint->y);
            cellpoint = cellpoint->suiv;
        }
        fprintf(f, "\n");
    }
}

void afficheChainesSVG(Chaines *C, char* nomInstance){
    double maxx=0,maxy=0,minx=1e6,miny=1e6;
    CellChaine *ccour;
    CellPoint *pcour;
    double precx,precy;
    SVGwriter svg;
    ccour=C->chaines;
    /* on trouve maxx et maxy */
    while (ccour!=NULL){
            pcour=ccour->points;
            while (pcour!=NULL){
                if (maxx<pcour->x) maxx=pcour->x;
                if (maxy<pcour->y) maxy=pcour->y;
                if (minx>pcour->x) minx=pcour->x;
                if (miny>pcour->y) miny=pcour->y;  
                pcour=pcour->suiv;
            }
        ccour=ccour->suiv;
    }
    /* on crée le ficher SVG */
    SVGinit(&svg,nomInstance,500,500);
    ccour=C->chaines;
    while (ccour!=NULL){
        pcour=ccour->points;
        /* on donne un couleur aléatoirement à cette chaine */
        SVGlineRandColor(&svg);
        SVGpoint(&svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny)); 
        precx=pcour->x;
        precy=pcour->y;  
        pcour=pcour->suiv;
        while (pcour!=NULL){
            /* on connecte les deux points adjacents */
            SVGline(&svg,500*(precx-minx)/(maxx-minx),500*(precy-miny)/(maxy-miny),500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            SVGpoint(&svg,500*(pcour->x-minx)/(maxx-minx),500*(pcour->y-miny)/(maxy-miny));
            precx=pcour->x;
            precy=pcour->y;    
            pcour=pcour->suiv;
        }
        ccour=ccour->suiv;
    }
    SVGfinalize(&svg);
}

double longueurChaine(CellChaine *c){
    double l = 0, lcour = 0;
    CellPoint *pcour = c->points;
    /* on parcout la chaine */
    while(pcour->suiv){
        CellPoint *psuiv = pcour->suiv;
        lcour = sqrt((psuiv->x - pcour->x)*(psuiv->x - pcour->x) + (psuiv->y - pcour->y)*(psuiv->y - pcour->y));
        l += lcour;
        pcour = pcour->suiv;
    }
    return l;
}

double longueurTotale(Chaines *C){
    double lt = 0;
    CellChaine *ccour = C->chaines;
    /* on parcout la chaine */
    while (ccour){
        lt += longueurChaine(ccour);
        ccour = ccour->suiv;
    }
    return lt;  
}

int comptePointsTotal(Chaines *C){
    int nbPoints = 0;
    /* on a juste besoin de parcourir tous les points */
    CellChaine *ccour = C->chaines;
    while(ccour){
        CellPoint *pcour = ccour->points;
        while(pcour){
            nbPoints ++;
            pcour = pcour->suiv;
        } 
        ccour = ccour->suiv;
    }
    return nbPoints;
}