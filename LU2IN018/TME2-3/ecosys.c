#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecosys.h"


/* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir = 0.01;//probabilité de changer de direction de deplacement
int gain_energie_proie = 6;
int gain_energie_predateur = 20;
float p_reproduce_proie = 0.4;
float p_reproduce_predateur = 0.5;
int temps_repousse_herbe = -15;
float p_manger = 0.9;


/* PARTIE 1*/
/* Fourni: Part 1, exercice 3, question 2 */
Animal *creer_animal(int x, int y, float energie) {
  	Animal *na = (Animal *)malloc(sizeof(Animal));
  	assert(na);
  	na->x = x;
  	na->y = y;
  	na->energie = energie;
  	na->dir[0] = rand() % 3 - 1;
  	na->dir[1] = rand() % 3 - 1;
  	na->suivant = NULL;
  	return na;
}


/* Fourni: Part 1, exercice 3, question 3 */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
	assert(animal);
	assert(!animal->suivant);
  	animal->suivant = liste;
  	return animal;
}

/* A faire. Part 1, exercice 5, question 1 */
void ajouter_animal(int x, int y,  float energie, Animal **liste_animal) {
  	assert((x >= 0) && (x < SIZE_X));
  	assert((y >= 0) && (y < SIZE_Y));
	// On crée un animal et l'ajoute en tete de la liste
	Animal *new_animal = creer_animal(x,y,energie); 
	*liste_animal = ajouter_en_tete_animal(*liste_animal,new_animal); 
	return ;
}

/* A Faire. Part 1, exercice 5, question 5 */
void enlever_animal(Animal **liste, Animal *animal) {
  	assert(*liste);
  	assert(animal);
	if (*liste == animal){// Si on veut enlever le premier animal dans la liste 
	 	*liste = (*liste)->suivant;
		free(animal); 
		return ;
	}else{// Si l'animal qu'on veut enlever est pas le premier 
		Animal *courant,*precedent;
		precedent = *liste; 
  		courant = (*liste)->suivant;
  		while (courant){// On commence de la deuxième animal
  			if (courant == animal){
  				precedent->suivant = courant->suivant;
  				free(animal);
  				return ;
  			}else{
  				precedent = courant;
  				courant = courant->suivant;
  			}	
  		}
	}
}

/* A Faire. Part 1, exercice 5, question 2 */
Animal *liberer_liste_animaux(Animal *liste) {
	Animal *nelt = NULL;
	while(liste){  // Si il reste des memoire pas liberés
		nelt = liste -> suivant; // nelt hérite l'animal prochain
		free(liste); 
		liste = nelt;
	}
  	return NULL;
}

/* Fourni: part 1, exercice 3, question 4 */
unsigned int compte_animal_rec(Animal *la) {
  	if (!la) return 0;
  	return 1 + compte_animal_rec(la->suivant);
}

/* Fourni: part 1, exercice 3, question 4 */
unsigned int compte_animal_it(Animal *la) {
  	int cpt = 0;
  	while (la) {
    	++cpt;
    	la = la->suivant;
  	}
  	return cpt;
}

/* On obtient un animal dans la listes par utiliser la fonction ci-dessous */
Animal *get_animal(Animal *la){  
	srand(time(NULL));
	unsigned int n = rand()%compte_animal_rec(la)+1;
	for (unsigned int i=1;i < n;i++){
		la = la->suivant;
	}
	return la;
}



/* Part 1. Exercice 4, question 1 */
void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
  	unsigned int i, j;
  	char ecosys[SIZE_X][SIZE_Y];
  	int nbpred=0,nbproie=0;
  	Animal *pa=NULL;

  	/* on initialise le tableau */
	/*A Completer*/
	for (i=0;i<SIZE_X;i++){
   		for (j=0;j<SIZE_Y;j++){
   			ecosys[i][j]=' ';
   		}
   	}


  	/* on ajoute les proies */
    /*A Completer*/
	pa = liste_proie;
    while (pa){
    	nbproie++;
    	assert(pa->x >= 0 && pa->x < SIZE_X && pa->y >= 0 && pa->y < SIZE_Y);
    	ecosys[pa->x][pa->y] = '*';
    	pa = pa->suivant;
    }

  	/* on ajoute les predateurs */
  	/*A Completer*/
	pa = liste_predateur;
  	while (pa){
  		nbpred++;
  		assert(pa->x >= 0 && pa->x <= SIZE_X && pa->y >= 0 && pa->y <= SIZE_Y);
  		if ((ecosys[pa->x][pa->y] == '@') || (ecosys[pa->x][pa->y] == '*')){
  			ecosys[pa->x][pa->y] = '@';
  		}else{
  			ecosys[pa->x][pa->y] = 'O';
  		}
  		pa = pa->suivant;
  	}

  	/* on affiche le tableau */
  	/*A Completer*/
	printf("Nb proies :%5d\tNb predateurs :%5d\n",nbproie,nbpred);
  	printf("+");
  	for (j=0;j<SIZE_Y;j++){
  		printf("-");
  	}
  	printf("+\n");
  	for (i=0;i<SIZE_X;i++){
  		printf("|");
  		for (j=0;j<SIZE_Y;j++){
  			putchar(ecosys[i][j]);
  		}
  		printf("|\n");
  	}
  	printf("+");
  	for (j=0;j<SIZE_Y;j++){
  		printf("-");
  	}
  	printf("+\n");	
}


void clear_screen() {
  	printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}


/* PARTIE 2*/
/* Part 2. Exercice 5, question 1 */
void bouger_animaux(Animal *la) {
    /*A Completer*/
    srand(time(NULL));
	while (la){
		if (rand()/RAND_MAX < p_ch_dir){// Si on changer la dircetion
			int a = la->dir[0];
			int b = la->dir[1];
			while ((a == la->dir[0]) && (b == la->dir[1])){
			// Si la direction ne change pas
				la->dir[0] = rand() % 3 - 1;
				la->dir[1] = rand() % 3 - 1;
			}
		}
		
		/* on fait les animaux bouger dans un espace torique */
		la->x = la->x - la->dir[0];// "en haut"
		if (la->x < 0){ la->x = la->x + SIZE_X; }
		if (la->x >= SIZE_X){ la->x = la->x - SIZE_X ; }
		assert(la->x >= 0 && la->x < SIZE_X);
		
		la->y = la->y + la->dir[1];// "à droite"
		if (la->y < 0){ la->y = la->y + SIZE_Y; }
		if (la->y >= SIZE_Y){ la->y = la->y - SIZE_Y ; }
		assert(la->y >= 0 && la->y < SIZE_Y);
		
		la = la->suivant;
	}   
}

/* Part 2. Exercice 5, question 3 */
void reproduce(Animal **liste_animal, float p_reproduce) {
	/*A Completer*/
	if (*liste_animal){
		Animal *ani;
		ani = *liste_animal;
	
		while (ani){
			if (rand()/RAND_MAX < p_reproduce){//Si on reproduit
				ajouter_animal(ani->x,ani->y,ani->energie/2,liste_animal);
				ani->energie = ani->energie / 2; 
			}
		
			ani = ani->suivant;
		}
	}	
}


/* Part 2. Exercice 7, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
    /*A Completer*/
    if (*liste_proie){
    	bouger_animaux(*liste_proie);// on fait les proies bouger
    	
    	Animal *ani;
    	ani = *liste_proie;
    	while (ani){
    		ani->energie -= 1;
    		if (monde[ani->x][ani->y] >= 0){// les proies mangent l'herbe
    			ani->energie += gain_energie_proie;
    			monde[ani->x][ani->y] = temps_repousse_herbe;
    		}
    		
    		if (ani->energie < 0){// on trouve le mort d'une proie
    			Animal *precedent;
    			precedent = ani;
    			ani = ani->suivant;
    			enlever_animal(liste_proie,precedent);
    		}else{   			
    			ani = ani->suivant;
    		}
    	}
    	 
    	/* reproduction des proies */
    	reproduce(liste_proie,p_reproduce_proie);	
    }
}
    
/* Part 2. Exercice 8, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
	/*A Completer*/
	while (l){
		if (l->x == x && l->y == y){
			return l;
		}
		l = l->suivant;
	}
	
  	return NULL;
} 

/* Part 2. Exercice 8, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
	/*A Completer*/
	if (*liste_predateur){
    	bouger_animaux(*liste_predateur);// on fait les predateurs bouger
    	
    	Animal *ani,*proie_ici;
    	ani = *liste_predateur;
    	while (ani){
    		ani->energie -= 1;
    		proie_ici = animal_en_XY(*liste_proie,ani->x,ani->y);
    		/*  les predateurs mangent les proies */
    		if ((proie_ici) && (rand()/RAND_MAX < p_manger)){
    			ani->energie += proie_ici->energie;
    			enlever_animal(liste_proie,proie_ici);
    		}
    		
    		if (ani->energie < 0){// on trouve le mort d'une predateur
    			Animal *precedent;
    			precedent = ani;
    			ani = ani->suivant;
    			enlever_animal(liste_predateur,precedent);
    		}else{   			
    			ani = ani->suivant;
    		}
    	}
    	
    	/* reproduction des predateurs */
		reproduce(liste_predateur,p_reproduce_predateur);
    }
}

/* Part 2. Exercice 6, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){
	/*A Completer*/
	for (int i = 0;i < SIZE_X;i++){
		for (int j = 0;j < SIZE_Y;j++){
			monde[i][j]++;
		}
	}	
}
