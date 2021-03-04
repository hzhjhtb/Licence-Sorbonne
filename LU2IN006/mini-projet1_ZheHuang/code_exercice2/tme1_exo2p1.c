#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

const static int V = 10; // V est le maximum de les entiers aléatroires

void allouetableau(int **T, int n){ 
	*T = (int*)malloc(n*sizeof(int)); // alloue d'un tableau d'entier 
}

void desallouetableau(int *T){
	free(T); // désalloue d'un tableau d'entier
}

void remplirtableau(int *T, int n){
	srand(time(NULL));
	for (int i=0; i<n; i++){
		T[i] = rand()%V; // un entier aléatroire entre 0 et V(non cpmpris)
	}
}

void affichertableau(int *T, int n){
	printf("[ ");	
	for (int i=0; i<n; i++){
		printf("%d ",T[i]);	
	}
	printf("]\n");
}

int somme_carre_difference_1(int *T, int n){ // algo1
	int res = 0;
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			res += (T[i] - T[j]) * (T[i] - T[j]);
		}	
	}
	
	return res;
}

int somme_carre_difference_2(int *T, int n){ // algo2
	int s1 = 0, s2 = 0;
	
	for (int i=0; i<n; i++){
		s1 += T[i];
	}
	s1 = s1 * s1 * (-2);
	for (int i=0; i<n; i++){
		s2 += (T[i]) * (T[i]); 
	}
	s2 = s2 * 2 * n;
	
	return s1 + s2;
}

int main(){
	int* T;
	clock_t temps_initial;
	clock_t temps_final;
	double temps_cpu_1, temps_cpu_2;
	int n, s;
	FILE *F;
	
	F = fopen("Q2.3_sortie_vitesse.txt","w+");
	// on a besoin d'un fichier texte pour comparer les 2 algos avec gnuplot
	for (int n=1; n<=300; n++){
		allouetableau(&T, n);
		remplirtableau(T, n);
		// on obtient le temps de calcul de algo1
		temps_initial = clock();
    	s = somme_carre_difference_1(T, n);
		temps_final = clock();
		temps_cpu_1 = (double)(temps_final - temps_initial);
		// on obtient le temp de calcul de algo2
		temps_initial = clock();	
		s = somme_carre_difference_2(T, n);
		temps_final = clock();
		temps_cpu_2 = (double)(temps_final - temps_initial);
		// Tous les résultats sont dans le ficher
		fprintf(F, "%d %f %f\n", n, temps_cpu_1, temps_cpu_2);
		desallouetableau(T);
	}
	
	fclose(F);
	return 0;
}





























