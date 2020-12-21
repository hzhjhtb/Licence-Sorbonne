#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int compte_mots_chaine(char *str){
	int state = 0;
	int i = 0;
	int cpt = 0;
	while (str[i] != '\0'){
		switch(state){
			case 0:
				if (isspace(str[i])==0){
					state = 1;
					cpt++;
					}
			break;
			case 1:
				if (isspace(str[i]) != 0) state=0;
			break;				
			}
		i++;			
		}
	return cpt;
	}

char compte_mots(char **ptab_mots){
	int i=0;
	char **p = ptab_mots;
	while(p[i] != NULL){
		i++;
	}
	return i;
}

void affiche_tab_mots(char ** ptab_mots){
  int t = compte_mots(ptab_mots);
  for(int i=0; i < t ;i++){
    printf("%s\n", ptab_mots[i]);
  }
}

char * compose_chaine(char ** ptab_mots){
  char * chaine = NULL;
  int nb_mots = compte_mots(ptab_mots);
  int nb_chars = 0;
  int nb_chars_mot = 0;
  for(int i=0; i < nb_mots; i ++){
    nb_chars += strlen(ptab_mots[i]);
  }
  nb_chars ++;
  chaine = malloc(sizeof(char) * (nb_chars + nb_mots -1));

  nb_chars = 0;
  for(int h = 0; h < nb_mots; h ++){
    nb_chars_mot = strlen(ptab_mots[h]);
    for(int j = 0; j < nb_chars_mot; j ++){
      chaine[nb_chars] = ptab_mots[h][j];
      nb_chars ++;
    }
    if(h != nb_mots - 1){
      chaine[nb_chars] = ' ';
      nb_chars ++;
    }
  }
  chaine[nb_chars] = '\0';
  
  return chaine;
}

void detruit_tab_mots(char **ptab_mots)
{

  /* Fonction vue en TD, exercice 2, question 5 */

  int i=0;

  if (ptab_mots)
    while(ptab_mots[i])
      free(ptab_mots[i++]);

  free(ptab_mots);
}

int main(){
	char *p="mot1 mot2";
	char *tab[]={"mot1","mot2","mot3",NULL};
	printf("%d\n",compte_mots_chaine(p));
	printf("%d\n",compte_mots(tab));
	p = compose_chaine(tab);
    printf("%s\n", p);
    free(p);
    detruit_tab_mots(tab);
	return 0;
}
