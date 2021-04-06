#ifndef BIBLIOLC_H
#define BIBLIOLC_H
// Q1.1
typedef struct livre{
	int num;
	char *titre;
	char *auteur;
	struct livre* suiv;
}Livre;

typedef struct{
	Livre* L;
}Biblio;
// Q1.2
Livre* creer_livreLC(int num, char* titre, char* auteur);
void liberer_livreLC(Livre* l);
Biblio* creer_biblioLC();
void liberer_biblioLC(Biblio *b);
void inserer_en_tete(Biblio *b,int num,char *titre,char *auteur);
// Q1.6
void afficher_livreLC(Livre *l);
void afficher_biblioLC(Biblio *b);
int recherche_numLC(Biblio *b,int num);
int recherche_titreLC(Biblio *b,char *titre);
Biblio *livres_meme_auteur(Biblio *b,char *auteur);
void supprimer_livre(Biblio *b,int num,char *titre,char *auteur);
Biblio *fusion_de_deux(Biblio *b1,Biblio *b2);
Livre *tous_exemplaireLC(Biblio *b);

#endif
