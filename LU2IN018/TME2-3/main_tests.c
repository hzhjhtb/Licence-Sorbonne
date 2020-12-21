#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"


#define NB_PROIES 20
#define NB_PREDATEURS 20
#define ENERGIE 10.0


 
   
int main(void) {
	/* A Completer. Exercice 5, question 3 */
	Animal *liste_proie = NULL;
	Animal *liste_predateur = NULL;
	int x,y;
	float energie;	
	unsigned int i;
	
	/* on genère les listes des proies ou prédateurs  */
	srand(time(NULL));
	for (i = 0;i < NB_PROIES;i++){
		x = rand() % SIZE_X;
		y = rand() % SIZE_Y;
		energie = ENERGIE;
		ajouter_animal(x,y,energie,&liste_proie); 
	}
	for (i = 0;i < NB_PREDATEURS;i++){
		x = rand() % SIZE_X;
		y = rand() % SIZE_Y;
		energie = ENERGIE;
		ajouter_animal(x,y,energie,&liste_predateur); 
	}
	/* affichage */
	afficher_ecosys(liste_proie,liste_predateur);
	
	/* on enlève quelques quelques proies et quelques prédateurs */
	unsigned int nb_suppression;
	printf("le nombre de suppression de les proies:");
	scanf("%u",&nb_suppression);
	for (i = 1;i <= nb_suppression;i++){
		enlever_animal(&liste_proie,get_animal(liste_proie));
		assert(compte_animal_rec(liste_proie) + i == NB_PROIES);
	}
	printf("le nombre de suppression de les prédateurs:");
	scanf("%u",&nb_suppression);
	for (i = 1;i <= nb_suppression;i++){
		enlever_animal(&liste_predateur,get_animal(liste_predateur));
		assert(compte_animal_it(liste_predateur) + i == NB_PREDATEURS);
	}
	/* affichage après le suppression */
	afficher_ecosys(liste_proie,liste_predateur);
	
	/* on fait les animaux bouger */ 
	bouger_animaux(liste_proie);
	bouger_animaux(liste_predateur);
	/* affichage après le déménagement  */
	printf("=====On fait les animaux bouger!=====\n");
	afficher_ecosys(liste_proie,liste_predateur);
	
	/* on fait les reproduction */
	reproduce(&liste_proie,1.0);
	reproduce(&liste_predateur,1.0);
	/* affichage après la reproducetion */
	printf("=====On fait la reproduction par le taux à 1!=====\n");
	afficher_ecosys(liste_proie,liste_predateur);
	
	/* on libère la memoire */
	liberer_liste_animaux(liste_proie);
	liberer_liste_animaux(liste_predateur);
	
  	return 0;
}
