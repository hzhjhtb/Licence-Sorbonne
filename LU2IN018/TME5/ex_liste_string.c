#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_string.h"

int main(void) {
  	/* a completer. Exercice 5, question 2 */
  	FILE *f;
  	char *str_1;
  	
  	PListe pliste = malloc(sizeof(Liste));
  	pliste->afficher = afficher_str;
  	pliste->comparer = comparer_str;
  	pliste->copier = copier_str;
  	pliste->detruire = detruire_str;
  	pliste->dupliquer = dupliquer_str;
  	pliste->lire = lire_str;
  	pliste->ecrire = ecrire_str;
  	
  	char *str_2 = "Hello,World!\n";
	char *str_3 = (char *)pliste->dupliquer(&str_2);   	
  	assert(strcmp(str_3, str_2) == 0);
  	
  	f = fopen("string_entree.txt", "r");
  	str_1 = strdup((char *)(pliste->lire(f)));
  	fclose(f);
  	pliste->afficher(&str_1);
  	printf("\n");
  	
  	assert(pliste->comparer("a", "b") < 0);
  	assert(pliste->comparer("ab", "ab") == 0);
  	
  	pliste->copier(&str_1, &str_3);
  	assert(strcmp(str_1, str_3) == 0);
  	
 	f = fopen("string_sortie.txt", "w");
 	pliste->ecrire(&str_1, f);
 	fclose(f);
 	
 	pliste->detruire(pliste); 	
 	free(str_1);
 	free(str_3);
 	 	
  	return 0;
}
