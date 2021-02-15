#include<stdio.h>
#include<stdlib.h> 
#include<time.h>

int V;

void allouematrice(int*** T,int n){
	*T = (int**)malloc(n*sizeof(int*)); // alloue d'un tableau de pointeur 
	for (int i=0; i<n; i++){
		(*T)[i] = (int*)malloc(n*sizeof(int)); // alloue de chaque tableau d'entier
	}
}

void desallouematrice(int** T, int n){
	for (int i=0; i<n; i++){
		free(T[i]); // désalloue de chaque tableau d'entier
	}
	free(T); // désalloue de le tableau de pointeur
}

void remplirmatrice(int** T, int n){
	V = n * n; // le maximum de les entiers aléatroires vaut le nombre des entiers
	srand(time(NULL));
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			T[i][j] = rand()%V;
		}
	}
}

void affichermatrice(int** T, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%d ", T[i][j]);
		}
		printf("\n");
	}
}

int est_different_1(int** T, int n){ // algo1
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				for (int h=0; h<n; h++){
					// si les valeurs dans positions differents sont equals
					if (((i != k) || (j != h)) && (T[i][j] == T[k][h])){
						return 1;
						// on quitte la foncition et retourne 1 qui représente Faux
					} 
				}
			}
		}
	}
	return 0; // sinon on retourne 0 qui représente True
}

int est_different_2(int** T, int n){ // algo2
	V = n * n;
	// tab est un tableau qui représente les nombres de apparition des valuers
	int tab[V]; 
	for (int i=0; i<V; i++){
		tab[i] = 0;
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (tab[T[i][j]] == 0){ 
				tab[T[i][j]]++;
			} else{ // si cette valeur est deja presente
				return 1; // c.a.d il y a deux valeurs equals dans la matrice
			}
		}
	}
	return 0;
}

void fcn2_5(){ // la comparaison des algorithmes dans Q2.5
	int** T;
	clock_t temps_initial;
	clock_t temps_final;
	double temps_cpu_1, temps_cpu_2;
	int n, res;
	FILE *F;

	F = fopen("Q2.5_sortie_vitesse.txt","w+");
	// on a besoin d'un fichier texte pour comparer les 2 algos avec gnuplot
	for (int n=1; n<=300; n++){
		allouematrice(&T, n);
		remplirmatrice(T, n);
		// on obtient le temps de calcul de algo1
		temps_initial = clock();
    	res = est_different_1(T, n);
		temps_final = clock();
		temps_cpu_1 = (double)(temps_final - temps_initial);
		/*printf("D'apres le algo1: ");
		if (res == 0){
			printf("Tous les elements sont differents\n"); 
		} else{
			printf("Il y a des elements equivalents\n");
		}*/
		// on obtient le temp de calcul de algo2
		temps_initial = clock();	
		res = est_different_2(T, n);
		temps_final = clock();
		temps_cpu_2 = (double)(temps_final - temps_initial);
		/*printf("D'apres le algo2: ");
		if (res == 0){
			printf("Tous les elements sont differents\n"); 
		} else{
			printf("Il y a des elements equivalents\n");
		}*/
		// Tous les résultats sont dans le ficher
		fprintf(F, "%d %f %f\n", n, temps_cpu_1, temps_cpu_2);
		desallouematrice(T, n);
	}
	
	fclose(F);
}

void initialmatrice(int** T3, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			T3[i][j] = 0;
		}
	}
}

void produit_matrice_1(int** T1, int** T2, int** T3, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				T3[i][j] += (T1[i][k]) * (T2[k][j]);  
			}
		}
	}
}

void remplirmatrice_triangulaire_sup(int** T, int n){
	V = n * n; // le maximum de les entiers aléatroires vaut le nombre des entiers
	srand(time(NULL));
	for (int i=0; i<n; i++){
		for (int j=i; j<n; j++){ // j allant de i à n-1
			T[i][j] = rand()%V;
		}
	}
}

void remplirmatrice_triangulaire_inf(int** T, int n){
	V = n * n; // le maximum de les entiers aléatroires vaut le nombre des entiers
	srand(time(NULL));
	for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++){ // j allant de 0 à i
			T[i][j] = rand()%V;
		}
	}
}

void produit_matrice_2(int** T1, int** T2, int** T3, int n){
	int max;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (i<=j) max = j; else max = i;
			for (int k=max; k<n; k++){
				T3[i][j] += (T1[i][k]) * (T2[k][j]);  
			}
		}
	}
}


void fcn2_6(){ // la comparaison des algorithmes dans Q2.6
	int **T1, **T2, **T3;
	clock_t temps_initial;
	clock_t temps_final;
	double temps_cpu_1, temps_cpu_2;
	int n;
	FILE *F;

	F = fopen("Q2.6_sortie_vitesse.txt","w+");
	// on a besoin d'un fichier texte pour comparer les 2 algos avec gnuplot
	for (int n=1; n<=100; n++){
		allouematrice(&T1, n);
		remplirmatrice_triangulaire_sup(T1, n);
		allouematrice(&T2, n);
		remplirmatrice_triangulaire_inf(T2, n);
		allouematrice(&T3, n);
		// on obtient le temps de calcul de algo1
		initialmatrice(T3, n);
		temps_initial = clock();
    	produit_matrice_1(T1, T2, T3, n);
		temps_final = clock();
		temps_cpu_1 = (double)(temps_final - temps_initial);
		// on obtient le temp de calcul de algo2
		initialmatrice(T3, n);
		temps_initial = clock();
    	produit_matrice_2(T1, T2, T3, n);
		temps_final = clock();
		temps_cpu_2 = (double)(temps_final - temps_initial);
		// Tous les résultats sont dans le ficher
		fprintf(F, "%d %f %f\n", n, temps_cpu_1, temps_cpu_2);
		desallouematrice(T1, n);
		desallouematrice(T2, n);
		desallouematrice(T3, n);
	}
	
	fclose(F);
}

int main(){
	fcn2_5(); 
	
	fcn2_6();
	
	return 0;
}
















