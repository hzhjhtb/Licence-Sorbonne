#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioH.h"
#include "entreeSortieH.h"
#include "biblioLC.h"
#include "entreeSortieLC.h"




int main(){
	clock_t temps_initial;
	clock_t temps_final;
	clock_t temps_initial1;
	clock_t temps_final1;
	double temps_cpu;
	double temps_cpu1;
	
    // Q3.1 + Q3.2
    /*FILE *F = fopen("sortie_vitesse.txt","w+");
    Biblio *b2 = charger_n_entreesLC("GdeBiblio.txt",10000);
	BiblioH *b1 = charger_n_entreesH("GdeBiblio.txt",10000);
	
	for(int n=0;n<10000;n++){	
		// livre present
		int m = n;
		// livre absent
		//int m = -n;
		
		// on obtient les 3 instants
		temps_initial = clock();
		recherche_numH(b1,m);
		temps_final = clock();
		temps_initial1 = clock();
		recherche_numLC(b2,m);
		temps_final1 = clock();
		// le temps de calcul de manière table hachage
		temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;
		// le temps de calcul de manière liste chainee
		temps_cpu1 = ((double)(temps_final1 - temps_initial1))/CLOCKS_PER_SEC;
		fprintf(F,"%d %f %f\n",n,temps_cpu,temps_cpu1);	
	}
	liberer_biblioLC(b2);
	liberer_biblioH(b1);
	fclose(F);
	return 0;
	*/
	
	
	// Q3.3 + Q3.4
    FILE *F = fopen("sortie_vitesse.txt","w+");
	for(int n=1000;n<1100;n++){	
		Biblio *b2 = charger_n_entreesLC("GdeBiblio.txt",n);
		BiblioH *b1 = charger_n_entreesH("GdeBiblio.txt",n);
		
		// on obtient les 3 instants
		temps_initial = clock();
		LivreH* l1 = tous_exemplaireH(b1);
		temps_final = clock();
		temps_initial1 = clock();
		Livre* l2 = tous_exemplaireLC(b2);
		temps_final1 = clock();
		// le temps de calcul de manière table hachage
		temps_cpu = ((double)(temps_final - temps_initial))/CLOCKS_PER_SEC;
		// le temps de calcul de manière liste chainee
		temps_cpu1 = ((double)(temps_final1 - temps_initial1))/CLOCKS_PER_SEC;
		fprintf(F,"%d %f %f\n",n,temps_cpu,temps_cpu1);	
		
		liberer_biblioLC(b2);
		liberer_biblioH(b1);
	}
	fclose(F);
	return 0;
}
