#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entreeSortieLC.h"
#include "biblioLC.h"

void menu(){
    printf("actions possibles:\n");
    printf("0-Sortie du programme\n1-Affichage\n2-Insérer un livre\n3-Recherche par numéro\n4-Recherche par titre\n5-Livre de même auteur\n6-Supprimer un livre\n7-Liste des exemplaires\n");
}

int main(int argc,char **argv){
    char *nomfic = strdup(argv[1]);
    int n = atoi(argv[2]);
    Biblio *b = charger_n_entrees(nomfic,n);
    int rep;
    do{
        menu();
        scanf(" %d",&rep);
        switch (rep){
        case 1: // Affichage
        {
            printf("Affichage :\n");
            afficher_biblio(b);
            break;
        }
        case 2: // Insérer un livre
        {
            int num;
            char titre[256];
            char auteur[256];
            printf("Veuillez saisir le numéro, le titre et l'auteur de l'ouvrage.\n");
            if(scanf(" %d %s %s",&num,titre,auteur)==3){
                inserer_en_tete(b,num,titre,auteur);
                printf("Ajout fait.\n");
            }else{
                printf("Erreur format\n");
            }
            break;
        }
        case 3: // Recherche par numéro
        {
            int num;
            printf("Veuillez saisir le numéro de l'ouvrage:\n");
            if(scanf("%d",&num) == 1){
                int i = recherche_num(b,num);
                if(i == 1){
                    printf("l'ouvrage est trouvé\n");
                }else{
                    printf("l'ouvrage n'est pas trouvé");
                }
            }
            break;
        }
        case 4: // Recherche par titre
        {
            char titre[256];
            printf("Veuillez saisir le titre de l'ouvrage:\n");
            if(scanf("%s",titre)==1){
                int i = recherche_titre(b,titre);
                if(i == 1){
                    printf("l'ouvrage est trouvé\n");
                }else{
                    printf("l'ouvrage n'est pas trouvé");
                }
            }else{
                printf("Erreur lecture\n");
            }
            break;
        }
        case 5: // Livre de même auteur
        {
            char auteur[256];
            printf("Veuillez saisir l'auteur:\n");
            if(scanf("%s",auteur)==1){
                Biblio *a = livres_meme_auteur(b,auteur);
                printf("les ouvrages de l'auteur:\n");
                afficher_biblio(a);
            }else{
                printf("Erreur lecture\n");
            }
            break;
        }
        case 6: // Supprimer un livre
        {
            int num;
            char titre[256];
            char auteur[256];
            printf("Veuillez saisir le numéro, le titre et l'auteur de l'ouvrage.\n");
            if(scanf(" %d %s %s",&num,titre,auteur)==3){
                supprimer_livre(b,num,titre,auteur);
                printf("Supprime fait.\n");
            }else{
                printf("Erreur format\n");
            }
            break;
        }
        case 7: // Liste des exemplaires
        {
           	printf("Liste de tous les exemplaires\n");
            Livre *l = tous_exemplaire(b);
            while(l!=NULL){
            	afficher_livre(l);
                l = l->suiv;
            }
            liberer_livre(l);
        }
        }
    }while(rep != 0);
    printf("Merci et au revoir.\n");
    liberer_biblio(b);
    return 0;
} 

