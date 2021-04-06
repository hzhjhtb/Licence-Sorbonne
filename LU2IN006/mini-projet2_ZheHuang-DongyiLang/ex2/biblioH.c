#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioH.h"
#include "math.h"


int fonctionClef(char* auteur){
    int s;
    for(int i=0;i<strlen(auteur);i++){
        s += auteur[i];
    }
    return s;
}

 // les quatre fonctions ci dessous sont pareil que dans ex1
LivreH* creer_livre(int num,char* titre,char* auteur){
    LivreH *l = (LivreH *)(malloc(sizeof(LivreH)));
    l->clef = fonctionClef(auteur);
    l->num = num;
    l->titre = strdup(titre);
	l->auteur = strdup(auteur);
	l->suivant = NULL;
	return l;
}

void liberer_livre(LivreH* l){
    while(l != NULL){
        free(l->titre);
        free(l->auteur);
        l = l->suivant;
    }
    free(l);
}

BiblioH* creer_biblio(int m){
    BiblioH* b = (BiblioH *)(malloc(sizeof(BiblioH)));
    b->nE = 0;
    b->m = m;
    b->T = (LivreH **)(malloc(sizeof(LivreH*)*m));
    for(int i=0;i<m;i++){
        (b->T)[i] = NULL;
    }
    return b;
}

void liberer_biblio(BiblioH* b){
    for(int i=0;i<b->m;i++){
        liberer_livre((b->T)[i]);
    }
    free(b);
}

int fonctionHachage(int cle,int m){
    double A = (sqrt(5) - 1) / 2;
    return ((int)(m*(cle*A - ((int)(cle*A))))); // cle est comme K dans la forlule
}

void inserer(BiblioH* b,int num,char* titre, char* auteur){
    LivreH *l = creer_livre(num,titre,auteur);
    int i = fonctionHachage(fonctionClef(auteur),b->m);
    if((b->T)[i] == NULL){
        (b->T)[i] = l;
    }else{
        l->suivant = (b->T)[i];
        (b->T)[i] = l;
    }
    b->nE++;
}

void afficher_livre(LivreH *l){
    printf("numéro:%d titre:%s auteur:%s\n",l->num,l->titre,l->auteur);
}

void afficher_biblio(BiblioH *b){
    LivreH **l = b->T;
    for(int i=0;i<b->m;i++){
        printf("%d  ",i);
        LivreH *ld = l[i];
        while(ld != NULL){
            afficher_livre(ld);
            ld = ld->suivant;
        }
    }
}

int recherche_num(BiblioH *b,int num){
    for(int i=0;i<b->m;i++){
        LivreH *ld = (b->T)[i];
        while(ld != NULL){
            if(ld->num == num){
                printf("livre trouvé:\n");
                afficher_livre(ld);
                return 1;// si on trouve le livre on retourne 1
            }
            ld = ld->suivant;
        }
    }
    return 0;// sinon on retourne 0
}

int recherche_titre(BiblioH *b,char *titre){
    for(int i=0;i<b->m;i++){
        LivreH *ld = (b->T)[i];
        while(ld != NULL){
            if(strcmp(ld->titre,titre) == 0){
                printf("livre trouvé:\n");
                afficher_livre(ld);
                return 1;// si on trouve le livre on retourne 1
            }
            ld = ld->suivant;
        }
    }
    return 0;// sinon on retourne 0
}


BiblioH* meme_auteur(BiblioH *b,char* auteur){
    BiblioH* B = creer_biblio(b->m);
    int s = 0;
    for(int i=0;i<b->m;i++){
    	LivreH *l = (b->T)[i];
        while(l != NULL){
        	if(strcmp(l->auteur, auteur) == 0){ // si on les trouve
            	inserer(B,l->num,l->titre, l->auteur);	// on l'ajoute 
                s++; // s : nE
            }
           	l = l->suivant;
        }
    }
    B->nE = s; 
    return B;
}

BiblioH* supprimer(BiblioH *b,int num,char* titre, char* auteur){
    // on trouve la liste chaine de livres ayant le meme clef 
    LivreH *L = b->T[fonctionHachage(fonctionClef(auteur),b->m)];
    // la reste est meme que on supprime un livre dans une liste chainée dans ex1 
    LivreH *lc;
	LivreH *lt;
	if(b != NULL){ // le bib ne doit pas etre vide
		lc = L;
		if((strcmp(lc->auteur,auteur) == 0) && (strcmp(lc->titre,titre) == 0) && (lc->num == num)){ // on supprime le premier liver
			lt = L->suivant;
			liberer_livre(L);
			L = lt;
		}else{ // le livre on veut supprimer n'est pas le premier
			lt = L;
			lc = lc->suivant;
			while((lc != NULL) && ((strcmp(lc->auteur,auteur) != 0) || (strcmp(lc->titre,titre) != 0) || (lc->num != num))){
				lt = lc;
				lc = lc->suivant;
			}
			// lt est juste avant le livre que on veut supprime
			if(lc != NULL){ // le livre on veut supprmer n'est pas le dernier
				lt->suivant = lc->suivant;
				liberer_livre(lc);
			}		
		}
	}	
	return b;
}

BiblioH* fusion(BiblioH *b1,BiblioH *b2){
	// on crée une nouveau bibliothèque 
    BiblioH *b = creer_biblio(b1->m+b2->m);
    // on parcout tous les livres dans les deux bib et les insère dans le nouveau bib
    for(int i= 0;i<b1->m;i++){
        while(b1->T[i] != NULL){
            inserer(b,b1->T[i]->num,b1->T[i]->titre,b1->T[i]->auteur);
            b1->T[i] = b1->T[i]->suivant;
        }
    }
    for(int i= 0;i<b2->m;i++){
        while(b2->T[i] != NULL){
            inserer(b,b2->T[i]->num,b2->T[i]->titre,b2->T[i]->auteur);
            b2->T[i] = b2->T[i]->suivant;
        }
    }
    return b;
}

LivreH* tous_exemplaire(BiblioH *b){
    LivreH *l = NULL;
    LivreH **T = b->T; 
    for(int i=0;i<b->m;i++){
    	LivreH *lc = T[i]; // on utilise lc pour parcourir tous les livres
        while(lc != NULL){
            LivreH *ld = T[i]; // ld est la liste chaine dans case lc[i]
            while(ld != NULL){
                if((strcmp(ld->titre,lc->titre) == 0)&&(ld->num != lc->num)&&(strcmp(lc->auteur,ld->auteur) == 0)){ // il y a deux ouvrages identiques
                    if(l == NULL){
                        l = creer_livre(ld->num,ld->titre,ld->auteur);
                    }else{
                    	// on le insère au bout de la liste chainée
                    	LivreH* lm = l;
                    	while (lm->suivant != NULL){
                        	lm = lm->suivant;
                    	}
                    	lm->suivant = creer_livre(ld->num,ld->titre,ld->auteur);
                    }
                }
                ld = ld->suivant;
            }
            lc = lc->suivant;
        }
    }
    return l;
}

