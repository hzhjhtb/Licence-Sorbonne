#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"


#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 40000
#define ENERGIE 10.0

int main(void) {
	/* Part 2. Exercice 6, question 1 */
	/* on initialisère ce tableau à 2 dim à 0 dans toutes les cases */
	int monde[SIZE_X][SIZE_Y];
	for (int i = 0;i < SIZE_X;i++){
		for (int j = 0;j < SIZE_Y;j++){
			monde[i][j] = 0;
		}
	}
	
	
	/* Part 2. Exercice 7, question 2 */
	/* Part 2. Exercice 8, question 3 */
	/* Part 2. Exercice 9, question 1 */
	int x,y,i;
	float energie;
	Animal *liste_proie = NULL;
	Animal *liste_predateur = NULL;
 	
	/*  on crée les proies et les predateurs */
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
	  
	/* on fait la simulation pas à pas de temps */
	FILE* f = fopen("Evol_Pop.txt","w"); // on ouvrit le ficher
	
	i = 0;
	afficher_ecosys(liste_proie,liste_predateur);
	while (i < 500 && liste_proie){
		/* mise à jour */
		rafraichir_proies(&liste_proie,monde);
		rafraichir_predateurs(&liste_predateur,&liste_proie);
		rafraichir_monde(monde);
		i++;
		/* affichage */
		usleep(T_WAIT);
		afficher_ecosys(liste_proie,liste_predateur);
		/* on trace le graphe */
		x = compte_animal_it(liste_proie);  // ici x est le nombre de poires
		y = compte_animal_it(liste_predateur);// et y est le nombre de predateurs
		fprintf(f,"%d %d %d\n",i,x,y);
	}
	
	fclose(f);  // fermeture
 
	/* on libère la memoire */
	liberer_liste_animaux(liste_proie);
	liberer_liste_animaux(liste_predateur);
	
  	return 0;
}
