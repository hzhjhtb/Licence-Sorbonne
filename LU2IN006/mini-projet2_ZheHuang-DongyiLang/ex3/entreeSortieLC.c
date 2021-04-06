#include "entreeSortieLC.h"
#include<stdio.h>
#include<stdlib.h>

Biblio* charger_n_entreesLC(char* nomfic,int n){
    Biblio *b = creer_biblioLC();
    FILE *F = fopen(nomfic,"r+");
    int num;
    char *titre = (char *)(malloc(sizeof(char))); // il faut les allouer
    char *auteur = (char *)(malloc(sizeof(char)));
    for(int i=0;i<n;i++){ // on va lire n lignes
        fscanf(F,"%d %s %s\n",&num,titre,auteur); // titre et auteur sont deja adresses
        inserer_en_tete(b,num,titre,auteur);
    }
    fclose(F);
    return b;
}

void enregistrer_biblio(Biblio *b,char* nomfic){
    FILE *F = fopen(nomfic,"w+");
    Livre *lc = b->L;
    while(lc != NULL){ // on va parcourir la liste chainé
        fprintf(F,"%d %s %s\n",lc->num,lc->titre,lc->auteur);
        lc = lc->suiv;
    }
    fclose(F);
}
