#ifndef tme1_exo2p2
#define tme1_exo2p2

extern int V;

void allouematrice(int*** T,int n);
void desallouematrice(int** T, int n);
void remplirmatrice(int** T, int n);
void affichermatrice(int** T, int n);

int est_different_1(int** T, int n);
int est_different_2(int** T, int n);
void fcn2_5();

void initialmatrice(int** T3, int n);
void produit_matrice_1(int** T1, int** T2, int** T3, int n);

void remplirmatrice_triangulaire_sup(int** T, int n);
void remplirmatrice_triangulaire_inf(int** T, int n);
void produit_matrice_2(int** T1, int** T2, int** T3, int n);
void fcn2_6();

#endif
