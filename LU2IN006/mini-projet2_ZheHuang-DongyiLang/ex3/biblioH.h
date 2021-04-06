#ifndef BIBLIOH_H
#define BIBLIOH_H

typedef struct livreh
{
    int clef;
    int num;
	char *titre;
	char *auteur;
    struct livreh *suivant;
} LivreH;

typedef struct table {
    int nE;
    int m;
    LivreH **T;
}BiblioH;

int fonctionClef(char* auteur);
LivreH* creer_livreH(int num,char* titre,char* auteur);
void liberer_livreH(LivreH* l);
BiblioH* creer_biblioH(int m);
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle,int m);
void inserer(BiblioH* b,int num,char* titre, char* auteur);
void afficher_livreH(LivreH *l);
void afficher_biblioH(BiblioH *b);
int recherche_numH(BiblioH *b,int num);
int recherche_titreH(BiblioH *b,char *titre);
BiblioH* meme_auteur(BiblioH *b,char* auteur);
BiblioH* supprimer(BiblioH *b,int num,char* titre, char* auteur);
BiblioH* fusion(BiblioH *b1,BiblioH *b2);
LivreH* tous_exemplaireH(BiblioH *b);



#endif