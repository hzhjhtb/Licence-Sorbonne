#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_entiers.h"
#include <assert.h>

int main(void) {
	/* a completer. Exercice 4, question 1 */
	int *temp_1, *temp_2;
	int i;
	FILE *f;
	
	PListe pliste = malloc(sizeof(Liste));
  	pliste->dupliquer = dupliquer_int;
  	pliste->copier = copier_int;
  	pliste->detruire = detruire_int;
  	pliste->afficher = afficher_int;
  	pliste->comparer = comparer_int;
  	pliste->ecrire = ecrire_int;
  	pliste->lire = lire_int;
	
	for (i = 5; i >= 0; i--){
		temp_1 = malloc(sizeof(int));
		*temp_1 = i;
		inserer_debut(pliste, temp_1);
	}
	for (i = 11; i < 16; i++){
		temp_1 = malloc(sizeof(int));
		*temp_1 = i;
		inserer_fin(pliste, temp_1);
	}
	for (i = 6; i < 11; i++){
		temp_1 = malloc(sizeof(int));
		*temp_1 = i;
		inserer_place(pliste, temp_1);
	}
	
	*temp_1 = 100;
	PElement pel = pliste->elements;
	pliste->copier(temp_1, pel->data);	
	*temp_1 = *(int*)pliste->dupliquer(pel->data);
	assert(*temp_1 == 100);
	
	temp_2 = malloc(sizeof(int));
	*temp_2 = 200;
	assert(pliste->comparer(temp_1, temp_2) < 0);
	
	f = fopen("entier_entree.txt", "r");
	temp_1 = (int*)pliste->lire(f);
	fclose(f);
	assert(*temp_1 == 1000);
	
	f = fopen("entier_sortie.txt", "r");
	pliste->ecrire(temp_1, f);
	fclose(f);
	
	*temp_1 = 100;
	assert(*(int*)(chercher_liste(pliste, temp_1)->data) == *temp_1);
	assert(*(int*)(chercher_liste_triee(pliste, temp_1)->data) == *temp_1);
	ecrire_liste(pliste, "entier_sortie.txt");
	assert(lire_liste(pliste, "entier_entree.txt") == 1);
	ecrire_liste(pliste, "entier_sortie.txt");
	ajouter_liste(pliste, 1, temp_1);
	assert(*(int*)(extraire_en_tete(pliste) -> data) == *temp_1);
	afficher_liste(pliste);
	detruire_liste(pliste);
	
  	return 0;
}

























