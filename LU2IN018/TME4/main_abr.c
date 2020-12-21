#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "abr.h"

int main(int argc, char **argv){
	/* a completer. Exercice 3, question 1 */
	if (argc != 3){
		fprintf(stderr,"Usage : main_abr mot nb_recherches\n");
		exit(EXIT_FAILURE);
	}
	
	char* mot = argv[1];
	int nbr = atoi(argv[2]);
	Nd_mot* abr = Lm2abr(lire_dico_Lmot("french_za"));
	Nd_mot* pn;
	
	for (int i = 0; i < nbr; i++){
		pn = chercher_Nd_mot(abr, mot);
	}
	
	if (pn == NULL){
		printf("Le mot %s n'est pas trouvé\n",mot);
	}else{
		printf("Le mot %s est trouver\n",mot);
	}
	
	detruire_abr_mot(abr);
	
  	exit(EXIT_SUCCESS);
}
