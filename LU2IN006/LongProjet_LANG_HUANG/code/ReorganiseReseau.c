#include "Graphe.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){
    FILE* f = fopen("00014_burma.cha", "r");
    Chaines* C = lectureChaines(f);
    fclose(f);
    Reseau* R = reconstitueReseauListe(C);

    /* Ex 7.1-7.3 
    Graphe* G = creerGraphe(R);
    int x = 5, y = 4;

    printf("le nomdre d'arete du chemin plus court de %d à %d est %d\n", x, y, Q2_shortest_BFS(G, x, y));
    printf("le chemin est:");
    ListeEntier* L = Q3_shortest_BFS(G, x, y);
    ListeEntier Lcour = *L;
    while(Lcour){
        printf(" %d", Lcour->u);
        Lcour = Lcour->suiv;
    }
    printf("\n");
    
    desalloue(L);
    free(L);
    libererGraphe(G); */
    

    /* Ex 7.4 */
    printf("%d\n", reorganiseReseau(R));

    libererReseau(R);
    libererChaines(C);
    return 0;
}