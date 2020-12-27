#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "devel.h"

void *dupliquer_str(const void *src) {
	/* a completer. Exercice 5, question 1 */
  	char **isrc = (char **)src;
  	char *idst = strdup(*isrc);
  	if (idst == NULL) {
    	affiche_message("Erreur de strdup");
    	return NULL;
  	}
  	return (void *)idst;
}

void copier_str(const void *src, void *dst) {
  	/* a completer. Exercice 5, question 1 */
  	char **isrc = (char **)src;
  	char **idst = (char **)dst;
  	char *temp = strdup(*isrc);
  	*idst = temp;
}

void detruire_str(void *data) {
  	/* a completer. Exercice 5, question 1 */
  	free(data);
}

void afficher_str(const void *data) {
  	/* a completer. Exercice 5, question 1 */
  	char **idata=(char **)data;
  	printf("%s", *idata);
}

int comparer_str(const void *a, const void *b) {
  	/* a completer. Exercice 5, question 1 */
  	char *ia = (char *)a;
  	char *ib = (char *)b;
  	return strcmp(ia, ib);
}

int ecrire_str(const void *data, FILE *f) {
  	/* a completer. Exercice 5, question 1 */
  	char **idata=(char **)data;
  	return fprintf(f, "%s", *idata);
}

void * lire_str(FILE *f) {
  	/* a completer. Exercice 5, question 1 */
  	char *str = malloc(sizeof(char)*255);
  	if (str == NULL){
  		affiche_message("Erreur d'allocation.");
  		return NULL;
  	}
  	
  	int r = fscanf(f, "%[^\n]", str);
  	if (r<1) return NULL;
  	
  	char *res = strdup(str);
  	free(str);
	return (void *)res;
}
