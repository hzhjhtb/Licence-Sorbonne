#include "entreeSortieH.h"
#include<stdio.h>
#include<stdlib.h>

BiblioH* charger_n_entrees(char* nomfic,int n){
    BiblioH *b = creer_biblio(n);
    FILE *F = fopen(nomfic,"r+");
    int num;
    char *titre = (char *)(malloc(sizeof(char)));
    char *auteur = (char *)(malloc(sizeof(char)));
    for(int i=0;i<n;i++){
        fscanf(F,"%d %s %s",&num,titre,auteur);
        inserer(b,num,titre,auteur); // on juste change la fonction de insertion
    }
    fclose(F);
    return b;
}

void enregistrer_biblio(BiblioH *b,char* nomfic){
    FILE *F = fopen(nomfic,"w+");
    LivreH **lc = b->T;
    for(int i=0;i<b->m;i++){ // on va parcourir tous les livres
        LivreH *ld = lc[i];
        while(ld != NULL){
            fprintf(F,"%d %s %s\n",lc[i]->num,lc[i]->titre,lc[i]->auteur);
            ld = ld->suivant;
        }
    }
    free(lc);
    fclose(F);
}
