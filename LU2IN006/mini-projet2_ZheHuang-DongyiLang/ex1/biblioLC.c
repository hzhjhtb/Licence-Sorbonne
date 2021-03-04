#include "biblioLC.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Livre* creer_livre(int num, char* titre, char* auteur){
	Livre* l = (Livre*)(malloc(sizeof(Livre)));
	l->num = num;
	l->titre = strdup(titre); // strdup peut allouer les mémoire qu'on veut
	l->auteur = strdup(auteur);
	l->suiv = NULL;
	return l;
}

void liberer_livre(Livre* l){
	while(l != NULL){ // on desalloue tous les livres
		free(l->titre); // il faut desalloue les strings avant on desalloue le livre
		free(l->auteur);
		l = l->suiv; 
	}
	free(l);
}

Biblio* creer_biblio(){
	Biblio* B = (Biblio*)(malloc(sizeof(Biblio))); // le bib
	B->L = (Livre*)(malloc(sizeof(Livre))); // le (premier) livre contenue dans le bib
	return B;
}

void liberer_biblio(Biblio* b){
	liberer_livre(b->L);
	free(b);
}

void inserer_en_tete(Biblio* b, int num, char* titre, char* auteur){
	Livre* l = creer_livre(num,titre,auteur);
	if(b->L == NULL){ // si c'est le premier livre dans le bib
		b->L = l;
	}else{ // sinon
		l->suiv = b->L;
		b->L = l;
	}
}

void afficher_livre(Livre *l){
	printf("numéro :%d titre:%s auteur:%s\n",l->num,l->titre,l->auteur);
}

void afficher_biblio(Biblio *b){
	Livre *lc = b->L;
	while(lc != NULL){
		afficher_livre(lc);
		lc = lc->suiv;
	}
	liberer_livre(lc); // il faut liberer le pointeur on crée
}

int recherche_num(Biblio *b,int num){
	int i = 0;
	Livre *lc = b->L;
	while(lc != NULL){
		if(lc->num == num){
			i = 1; // si on trouve le livre on retourne 1
			afficher_livre(lc);
		}
		lc = lc->suiv;
	}
	liberer_livre(lc);
	return i; // sinon on retourne 0
}

int recherche_titre(Biblio *b,char *titre){
	int i = 0;
	Livre *lc = b->L;
	while(lc != NULL){
		if(strcmp(lc->titre,titre) == 0){
			i = 1;
			afficher_livre(lc);
		}
		lc = lc->suiv;
	}
	liberer_livre(lc);
	return i;
}

Biblio *livres_meme_auteur(Biblio *b,char *auteur){
	Livre *lc = b->L;
	Biblio *B = creer_biblio(); // on creer un nouveau bib pour stocker les livres
	while(lc != NULL){
		if(strcmp(lc->auteur,auteur) == 0){
			inserer_en_tete(B,lc->num,lc->titre,lc->auteur); 
		}
		lc = lc->suiv;
	}
	liberer_livre(lc);
	return B; // on retourne le bib contenant tous les livres de ce auteur
}

void supprimer_livre(Biblio *b,int num,char *titre,char *auteur){
	Livre *lc;
	Livre *lt;
	if(b != NULL){ // le bib ne doit pas etre vide
		lc = b->L;
		if((strcmp(lc->auteur,auteur) == 0) && (strcmp(lc->titre,titre) == 0) && (lc->num == num)){ // on supprime le premier liver
			lt = b->L->suiv;
			liberer_livre(b->L);
			b->L = lt;
		}else{ // le livre on veut supprimer n'est pas le premier
			lt = b->L;
			lc = lc->suiv;
			while((lc != NULL) && (strcmp(lc->auteur,auteur) == 0) | (strcmp(lc->titre,titre) == 0) | (lc->num == num)){
				lt = lc;
				lc = lc->suiv;
			}
			if(lc != NULL){ // le livre on veut supprmer n'est pas le dernier
				lt->suiv = lc->suiv;
				liberer_livre(lc);
			}		
		}
	}	
}

Biblio *fusion_de_deux(Biblio *b1,Biblio *b2){
	Livre *lc = b1->L;
	while(lc->suiv != NULL){
		lc = lc->suiv;
	}
	lc->suiv = b2->L;
	free(b2); // la liste chaine de B2 reste
	return b1;
}

Livre *tous_exemplaire(Biblio *b){
	Biblio *B = creer_biblio(); // on creer un nouveau bib pour stocker les livres
	Livre *lc = b->L; // on utilise lc pour parcourir tous les livres
	while (lc->suiv != NULL){
		Livre *ld = b->L; // ld pareil
		while (ld->suiv != NULL){
			if ((lc->titre == ld->titre)&&(lc->auteur == ld->auteur)&&(lc->num != ld->num)){ // il y a deux ouvrages identiques
				inserer_en_tete(B,lc->num,lc->titre,lc->auteur);
				break;		
			}	
			ld = ld->suiv;	
		}
		
		lc = lc->suiv;	
	}

	return B->L;
}

