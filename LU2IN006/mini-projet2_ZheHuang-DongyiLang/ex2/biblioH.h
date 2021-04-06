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
LivreH* creer_livre(int num,char* titre,char* auteur);
void liberer_livre(LivreH* l);
BiblioH* creer_biblio(int m);
void liberer_biblio(BiblioH* b);
int fonctionHachage(int cle,int m);
void inserer(BiblioH* b,int num,char* titre, char* auteur);
void afficher_livre(LivreH *l);
void afficher_biblio(BiblioH *b);
int recherche_num(BiblioH *b,int num);
int recherche_titre(BiblioH *b,char *titre);
BiblioH* meme_auteur(BiblioH *b,char* auteur);
BiblioH* supprimer(BiblioH *b,int num,char* titre, char* auteur);
BiblioH* fusion(BiblioH *b1,BiblioH *b2);
LivreH* tous_exemplaire(BiblioH *b);



#endif
