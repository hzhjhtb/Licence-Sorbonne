#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Chaine.h"
#include "Reseau.h"
#include "Hachage.h"
#include "ArbreQuat.h"

Chaines* generationAleatoire(int nbChaines, int nbPointsChaine, int xmax, int ymax){
	// creer une chaine
	Chaines* Ch = (Chaines*)malloc(sizeof(Chaines));
	Ch->nbChaines = nbChaines;

	for(int i = 1; i <= nbChaines; i++){
		// creer cellchaine
		CellChaine* cellCh = (CellChaine*)malloc(sizeof(CellChaine));
		cellCh->numero = i;
		
		for(int j=0; j < nbPointsChaine; j++){
			// creer cellPoint
			CellPoint* p = (CellPoint*)malloc(sizeof(CellPoint));
			p->x = (double)(rand()%xmax);
			p->y = (double)(rand()%ymax);

			// inserer point
			p->suiv = cellCh->points;
			cellCh->points = p;
		}

		// inserer cellchaine
		cellCh->suiv = Ch->chaines;
		Ch->chaines = cellCh;
	}
	return Ch;
}	



int main(){
	srand(time(NULL));	
	FILE *F = fopen("sortie_vitesse.txt","w+");
	int n = 0;
	scanf("%d",&n);	
	printf("en processus de n= %d\n", n);
	Chaines* C = generationAleatoire(n, 100, 5000, 5000);	
	//clock_t temps_initial_1;
	//clock_t temps_final_1;
	clock_t temps_initial_2;
	clock_t temps_final_2;
	clock_t temps_initial_3;
	clock_t temps_final_3;
	//double temps_cpu1;
	double temps_cpu2;
	double temps_cpu3;
	
	/*temps_initial_1 = clock();
	Reseau* R1 = reconstitueReseauListe(C);
	temps_final_1 = clock();*/
		
	temps_initial_2 = clock();
	Reseau* R2 = reconstitueReseauHachage(C, 50000);
	temps_final_2 = clock();
		
	temps_initial_3=clock();
	Reseau* R3 = reconstitueReseauArbre(C);
	temps_final_3=clock();
	
	//temps_cpu1 = ((double)(temps_final_1 - temps_initial_1))/CLOCKS_PER_SEC;
	temps_cpu2 = ((double)(temps_final_2 - temps_initial_2))/CLOCKS_PER_SEC;
	temps_cpu3=((double)(temps_final_3 - temps_initial_3))/CLOCKS_PER_SEC;
	fprintf(F, "%d %f %f\n", n, temps_cpu2, temps_cpu3);

	libererChaines(C);
	libererReseau(R2);
	//libererReseau(R2);
	libererReseau(R3);
	fclose(F);
	return 0;
}

/*int main(){
	srand(time(NULL));
	FILE *F = fopen("sortie_vitesse.txt","w+");
	FILE* f = fopen("00014_burma.cha", "r");
    Chaines* C = lectureChaines(f);
    fclose(f);
	clock_t temps_initial_1;
	clock_t temps_final_1;
	clock_t temps_initial_2;
	clock_t temps_final_2;
	clock_t temps_initial_3;
	clock_t temps_final_3;
	double temps_cpu1;
	double temps_cpu2;
	double temps_cpu3;
	temps_initial_1 = clock();
	Reseau* R1 = reconstitueReseauListe(C);
	temps_final_1 = clock();

	temps_initial_2 = clock();
	Reseau* R2 = reconstitueReseauHachage(C, 100);
	temps_final_2 = clock();

	temps_initial_3=clock();
	Reseau* R3 = reconstitueReseauArbre(C);
	temps_final_3=clock();

	temps_cpu1 = ((double)(temps_final_1 - temps_initial_1))/CLOCKS_PER_SEC;
	temps_cpu2 = ((double)(temps_final_2 - temps_initial_2))/CLOCKS_PER_SEC;
	temps_cpu3=((double)(temps_final_3 - temps_initial_3))/CLOCKS_PER_SEC;
	fprintf(F,"%f %f %f\n",temps_cpu1,temps_cpu2,temps_cpu3);
	fclose(F);
	libererReseau(R1);
	libererReseau(R2);
	libererReseau(R3);
	libererChaines(C);
	return 0;
}*/
