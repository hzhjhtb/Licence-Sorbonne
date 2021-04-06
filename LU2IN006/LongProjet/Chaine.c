#include "Chaine.h"
#include <stdlib.h>
#include <string.h>


void inseration_cellchaine_debut(CellChaine* cellchaine, CellChaine* cellchaine_insere){
    if (cellchaine){
        cellchaine_insere->suiv = cellchaine->suiv;
        cellchaine->suiv = cellchaine_insere;       
    }else{
        cellchaine = cellchaine_insere;
    }
}


void inseration_cellpoint_debut(CellPoint* cellpoint, CellPoint* cellpoint_insere){
    if (cellpoint){
        cellpoint_insere->suiv = cellpoint->suiv;
        cellpoint->suiv = cellpoint_insere;       
    }else{
        cellpoint = cellpoint_insere;
    }
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
    CellChaine* cellchaine = (CellChaine*)(malloc(sizeof(CellChaine)));
    for (int i=0; i<nbChaines; i++){
        /* lecture de la (i+2)ieme ligne */
        fgets(buf, 256, f);
        buf[strlen(buf) - 1] = '\0';
        /* les deux premieres donnees dans la ligne */
        CellChaine* cellchaine_insere = (CellChaine*)(malloc(sizeof(CellChaine)));
        int numero, nbPoint;
        sscanf(buf, "%d %d %[^\n]\n", &numero, &nbPoint, buf);
        cellchaine_insere->numero = numero;
        /* les restes donnees dans la ligne */
        CellPoint* cellpoint = (CellPoint*)(malloc(sizeof(CellPoint)));
        for (int j=0; j<nbPoint; j++){
            CellPoint* cellpoint_insere = (CellPoint*)(malloc(sizeof(CellPoint)));
            double x, y;
            sscanf(buf, " %lf %lf %[^\n]\n", &x, &y, buf);
            cellpoint_insere->x = x;
            cellpoint_insere->y = y;
            cellpoint_insere->suiv = NULL;
            inseration_cellpoint_debut(cellpoint, cellpoint_insere);
        }
        cellchaine_insere->points = cellpoint;
        cellchaine_insere->suiv = NULL;
        inseration_cellchaine_debut(cellchaine, cellchaine_insere);
    }
    chaines->chaines = cellchaine;
    
    return chaines;
}


void ecrireChaines(Chaines *C, FILE *f){
    /* ligne 1 */
    fprintf(f, "NbChain: %d\n", C->nbChaines);
    /* ligne 2 */
    fprintf(f, "Gamma: %d\n", C->gamma);
    /* les restes lignes */
    for(int i=0; i<C->nbChaines; i++){
        fprintf(f, "%d ", i);
        CellChaine* cellchaine = C->chaines->suiv;
        for (int j=0; j<i; j++) cellchaine = cellchaine->suiv;
        CellPoint* cellpoint = cellchaine->points->suiv;
        /* on compte le nombre des points */
        int cmp = 0;
        while(cellpoint){
            cmp++;
            cellpoint = cellpoint->suiv;
        } 
        /* dans la sortie de la boucle, cellpoint est le derniere point dans cette ligne */
        fprintf(f, "%d", cmp);
        cellpoint = cellchaine->points->suiv;
        /* l'affichage des points dans cette ligne */
        while(cellpoint){
            fprintf(f, " %.2f %.2f", cellpoint->x, cellpoint->y);
            cellpoint = cellpoint->suiv;
        }
        fprintf(f, "\n");
    }
}
