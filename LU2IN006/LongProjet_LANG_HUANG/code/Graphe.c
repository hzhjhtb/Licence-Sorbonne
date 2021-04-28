#include "Graphe.h"


Graphe* creerGraphe(Reseau* r){
    // on crée un pointeur vers notre Graphe R 
    Graphe* G = (Graphe*)malloc(sizeof(Graphe));
    G->gamma = r->gamma;
    G->nbsom = r->nbNoeuds;
    G->nbcommod = 0;
    
    // on crée un tableau de pointeurs sur sommets
    Sommet** T_som = (Sommet**)malloc((G->nbsom + 1)*sizeof(Sommet*));
    // on parcout les noeuds du Reseau r
    CellNoeud* ncour = r->noeuds;
    while(ncour){
        // on crée un sommet
        Sommet* s = (Sommet*)malloc(sizeof(Sommet));
        s->num = ncour->nd->num;
        s->x = ncour->nd->x;
        s->y = ncour->nd->y;
        // on crée L_voisin
        Cellule_arete* L_voisin = NULL;
        // on parcout les voisins de ncour
        CellNoeud* voisins = ncour->nd->voisins;
        while(voisins){
            if (ncour->nd->num < voisins->nd->num){ // premiere fois on le cree
                // on crée et ajoute l'arete dans L_voisin
                Cellule_arete* arete = (Cellule_arete*)malloc(sizeof(Cellule_arete));
                Arete* a = (Arete*)malloc(sizeof(Arete));; 
                a->u = ncour->nd->num;
                a->v = voisins->nd->num;
                arete->a = a;
                arete->suiv = L_voisin;
                L_voisin = arete;         
            }
            voisins = voisins->suiv;
        }
        // on donne L_voisin à Sommet s à la fin
        s->L_voisin = L_voisin;
        // on donne ce Sommet s à le tableau T_som
        T_som[s->num] = s;
        ncour = ncour->suiv;
    }
    //on complète les voisins
    ncour = r->noeuds;
    while(ncour){
        // on parcout les voisins de ncour
        CellNoeud* voisins = ncour->nd->voisins;
        while(voisins){
            if (ncour->nd->num > voisins->nd->num){ // deuxieme fois on le cherche
                Cellule_arete* arete = (Cellule_arete*)malloc(sizeof(Cellule_arete));
                Cellule_arete* v = T_som[voisins->nd->num]->L_voisin;
                while(v){
                    if (voisins->nd->num == v->a->u && ncour->nd->num == v->a->v){
                        arete->a = v->a;
                        arete->suiv = T_som[ncour->nd->num]->L_voisin;
                        T_som[ncour->nd->num]->L_voisin = arete;
                        break;
                    }
                    v = v->suiv;
                }         
            }
            voisins = voisins->suiv;
        }
        ncour = ncour->suiv;
    }
    // on donne ce tableau à notre Graphe R
    G->T_som = T_som;

    // on parcout les commodites du Reseau r pour obtenir le nombre de commodites nbcommod
    CellCommodite* ccour = r->commodites;
    while(ccour){
        G->nbcommod++;
        ccour = ccour->suiv;
    }
    // on crée un tableau des commodites
    Commod* T_commod = (Commod*)malloc((G->nbcommod)*sizeof(Commod));
    // on parcout les commodites du Reseau r pour les donner à le tableau T_commod
    int cpt = 0;
    ccour = r->commodites;
    while(ccour){
        cpt++;
        // on creé un Commod et l'ajoute dans le tableau
        T_commod[cpt].e1 = ccour->extrA->num;
        T_commod[cpt].e2 = ccour->extrB->num;
        ccour = ccour->suiv;
    }
    // on donne ce tableau à notre Graphe R
    G->T_commod = T_commod;

    return G;
}


void libererGraphe(Graphe* G){
    for (int i = 1; i <= G->nbsom; i++){
        Sommet* s = G->T_som[i];
        Cellule_arete* voisins = s->L_voisin;
        while(voisins){
            if (voisins->a->u == s->num){
                free(voisins->a);
            }
            Cellule_arete* courant = voisins;
            voisins = voisins->suiv;
            free(courant);
        }
        free(s);
    }
    free(G->T_som);
    free(G->T_commod);
    free(G);
}


int Q2_shortest_BFS(Graphe *G, int x, int y){ 
    int res = G->nbsom;

    int* visit = (int*)malloc((G->nbsom + 1) * sizeof(int));  // la liste de Sommet visité et non_visité
	int* D = (int*)malloc((G->nbsom + 1) * sizeof(int));      // le tableau d'arité du largeur 
	for (int i = 1; i <= G->nbsom; i++){ 
    	visit[i] = 0;
    	D[i] = 0;
    }
	visit[x] = 1;
	D[x] = 0;
    
    S_file* F = (S_file*)malloc(sizeof(S_file));        // File F est la bordure
	Init_file(F);
	enfile(F, x);

	while (!(estFileVide(F))){
		int u = defile(F);

		Cellule_arete* ccour = G->T_som[u]->L_voisin;
		while (ccour){
            int v;
            if (u == ccour->a->u) v = ccour->a->v;
            if (u == ccour->a->v) v = ccour->a->u;

			if (visit[v] == 0){ 
				visit[v] = 1;
				enfile(F, v);
				D[v] = D[u] + 1;
			}

			if (v == y && D[v] < res && D[v] > 0) res = D[v];
			
            ccour = ccour->suiv; 
		}
	} 

    free(visit);
    free(D);
    free(F);

	return res;
}


ListeEntier* Q3_shortest_BFS(Graphe *G, int x, int y){
    int res = G->nbsom;

    int* prec = (int*)malloc((G->nbsom + 1) * sizeof(int));   // la liste de sommet precedent du sommet
    int* visit = (int*)malloc((G->nbsom + 1) * sizeof(int));  // la liste de sommet visité et non_visité
	int* D = (int*)malloc((G->nbsom + 1) * sizeof(int));      // le tableau d'arité du largeur 
	for (int i = 1; i <= G->nbsom; i++){ 
    	visit[i] = 0;
    	D[i] = 0;
        prec[i] = 0;
    }
	visit[x] = 1;
	D[x] = 0;
    prec[x] = -1;
    
    S_file* F = (S_file*)malloc(sizeof(S_file));        // File F est la bordure
	Init_file(F);
	enfile(F, x);

	while (!(estFileVide(F))){
		int u = defile(F);

		Cellule_arete* ccour = G->T_som[u]->L_voisin;
		while (ccour){
            int v;
            if (u == ccour->a->u) v = ccour->a->v;
            if (u == ccour->a->v) v = ccour->a->u;

			if (visit[v] == 0){ 
				visit[v] = 1;
				enfile(F, v);
				D[v] = D[u] + 1;
                prec[v] = u;
			}

			if (v == y && D[v] < res && D[v] > 0) res = D[v];
            ccour = ccour->suiv; 
		}
	} 

    free(visit);
    free(D);
    free(F);

    ListeEntier* L = (ListeEntier*)malloc(sizeof(ListeEntier)); 
    Init_Liste(L);
    ajoute_en_tete(L, y); 
    for (int i = res - 1; i >= 0; i--){
        ajoute_en_tete(L, prec[(*L)->u]);
    }

    free(prec);
	return L;
}


int reorganiseReseau(Reseau* r){
    /* on crée le graphe correspondant au réseau */
    Graphe* G = creerGraphe(r);

    /* on crée un matrice sommet-sommet pour compter le nombre de chaines passant par chaque arete */
    int tab[G->nbsom][G->nbsom];

    /* on calcule la plus courte chaine pour chqaue commodité */
    for (int i = 0; i < G->nbcommod; i++){
        ListeEntier* L = Q3_shortest_BFS(G, G->T_commod[i].e1, G->T_commod[i].e2);
        int u, v;

        ListeEntier Lcour = *L;
        v = Lcour->u;
        Lcour = Lcour->suiv;
        while(Lcour){
            u = v;
            v = Lcour->u;
            tab[u][v]++;
            Lcour = Lcour->suiv;
        }

        desalloue(L);
        free(L);
    }
    
    /* on retourne le res: vrai si gamma est garantie, false sinon */
    for (int i = 0; i < G->nbcommod; i++){
        for (int j = 0; i < G->nbcommod; i++){
            if (tab[i][j] >= G->gamma){
                libererGraphe(G);
                return 0;
            }
        }
    }

    libererGraphe(G);
    return 1;
}