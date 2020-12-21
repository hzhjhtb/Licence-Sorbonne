#include <stdio.h>
#include <stdlib.h>
#include "arbre_lexicographique.h"


int main(int argc, char **argv){
  	/* a completer. Exercice 4, question 4 */
	if(argc != 3){
      	fprintf(stderr, "Usage : main_abr mot nb_recherches\n");
      	exit(1);
    }
    
    char* mot = argv[1];
    int nbr = atoi(argv[2]);
    PNoeud dico = lire_dico("french_za");
    
	//afficher_dico(dico);
	int res;
    for (int i = 0; i < nbr; i++){
      	res = rechercher_mot(dico, mot);
    }
    if(res == 0){
    	printf("Le mot %s n'est pas trouve.\n",mot);
    }else{
    	printf("Le mot %s est trouve.\n",mot);
    }

    detruire_dico(dico);
    
  	return 0;
}
