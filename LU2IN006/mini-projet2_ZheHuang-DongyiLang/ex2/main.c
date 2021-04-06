#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieH.h"
#include "biblioH.h"

void menu(){
    printf("Bienvenu,actions possibles:\n");
    printf("0-Sortie du programme\n1-Affichage\n2-Insérer un livre\n3-Recherche par numéro\n4-Recherche par titre\n5-Livre de même auteur\n6-Supprimer un livre\n7-Liste des exemplaires\n");
}

int main(int argc,char **argv){
    char *nomfic = strdup(argv[1]);
    int n = atoi(argv[2]);
    BiblioH *b = charger_n_entrees(nomfic,n);
    int rep;
    do{
        menu();
        scanf(" %d",&rep);
        switch (rep){
        case 1:
        {
            printf("Affichage :\n");
            afficher_biblio(b);
            break;
        }
        case 2:
        {
            int num;
            char titre[256];
            char auteur[256];
            printf("Veuillez saisir le numéro, le titre et l'auteur de l'ouvrage.\n");
            if(scanf(" %d %s %s",&num,titre,auteur)==3){
                inserer(b,num,titre,auteur);
                printf("Ajout fait.\n");
            }else{
                printf("Erreur format\n");
            }
            break;
        }
        case 3:
        {
            int num;
            printf("Veuillez saisir le numéro de l'ouvrage:\n");
            if(scanf(" %d",&num) == 1){
                int i = recherche_num(b,num);
                if(i == 1){
                    printf("l'ouvrage est trouvé\n");
                }else{
                    printf("l'ouvrage n'est pas trouvé");
                }
            }
            break;
        }
        case 4:
        {
            char titre[256];
            printf("Veuillez saisir le titre de l'ouvrage:\n");
            fgets(titre,256,stdin);
            if(scanf(" %s",titre) == 1){
                int i = recherche_titre(b,titre);
                if(i == 0){
                    printf("l'ouvrage n'est pas trouvé\n");
                }
            }else{
                printf("Erreur lecture\n");
            }
            break;
        }
        case 5:
        {
            char auteur[256];
            printf("Veuillez saisir l'auteur:\n");
            if(scanf(" %s",auteur)==1){
                BiblioH *a = meme_auteur(b,auteur);
                printf("les ouvrages de l'auteur:\n");
                afficher_biblio(a);
            }else{
                printf("Erreur lecture\n");
            }
            break;
        }
        case 6:
        {
            int num;
            char titre[256];
            char auteur[256];
            printf("Veuillez saisir le numéro, le titre et l'auteur de l'ouvrage.\n");
            if(scanf(" %d %s %s",&num,titre,auteur)==3){
                supprimer(b,num,titre,auteur);
                printf("Supprime fait.\n");
            }else{
                printf("Erreur format\n");
            }
            break;
        }
        case 7:
        {
            LivreH *l = tous_exemplaire(b);
            LivreH *lc = l;
            while(lc != NULL){
                afficher_livre(l);
                lc = lc->suivant;
            }
            liberer_livre(l);
        }
        }
    }while(rep != 0);
    printf("Merci et au revoir.\n");
    liberer_biblio(b);
    return 0;
}
