#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int compte_mots_chaine(char * c){
  int stat = 0;
  int cpt = 0;
  int i = 0;
  
  while(c[i] != '\0'){
    if(stat == 0){
      if(!isspace(c[i])){
        cpt++;
        stat = 1;
      }
    }else if(stat == 1){
      if(isspace(c[i])){
        stat = 0;
      }
    }
    i++;
  }
  
  return cpt;
}

char ** decompose_chaine(char * c){
  int cpt = 0;
  int i = -1;
  int j = 0;
  int stat = 0;
  char ** tb = malloc(sizeof(char *) * (compte_mots_chaine(c) + 1));
  int nb_mots = 0;
  int nb_chars = 0;

  /* allouer les chaines correspondant aux mots */
  while(c[cpt] != '\0'){
    if(stat == 0){
      if(!isspace(c[cpt])){
        stat = 1;
        nb_chars = 1;
      }
    } else if(stat == 1){
      if(isspace(c[cpt])){
        tb[nb_mots] = malloc(sizeof(char) * (nb_chars + 1));
        nb_chars = 0;
        nb_mots ++;
        stat = 0;
      } else if(!isspace(c[cpt])){
        nb_chars ++;
      }
    }
    cpt ++;
  }
  if(stat == 1){
    tb[nb_mots] = malloc(sizeof(char) * (nb_chars + 1));
    nb_mots ++;
  }

  stat = 0;
  cpt = 0;
  
  /* construire le tableau */
  while(c[cpt] != '\0'){
    if(stat == 0){
      if(!isspace(c[cpt])){
        stat = 1;
        i ++;
        j = 0;
        tb[i][j] = c[cpt];
        j ++;
      }
    } else if(stat == 1){
      if(isspace(c[cpt])){
        stat = 0;
      } else if(!isspace(c[cpt])){
        tb[i][j] = c[cpt];
        j ++;
      }
    }
    cpt ++;
  }
  tb[i+1] = NULL;
                                                                                                            

  return tb;
}

int compte_mots(char ** tb){
  char ** p = tb;
  int i = 0;

  while(p[i] != NULL){
    i++;
  }

  return i;
}

char * compose_chaine(char ** tb){
  char * chaine = NULL;
  int nb_mots = compte_mots(tb);
  int nb_chars = 0;
  int nb_chars_mot = 0;
  int i = 0;
  int j = 0;
  
  for(i; i < nb_mots; i ++){
    nb_chars += strlen(tb[i]);
  }
  nb_chars ++;
  chaine = malloc(sizeof(char) * (nb_chars + nb_mots -1));

  nb_chars = 0;
  for(i = 0; i < nb_mots; i ++){
    nb_chars_mot = strlen(tb[i]);
    for(j = 0; j < nb_chars_mot; j ++){
      chaine[nb_chars] = tb[i][j];
      nb_chars ++;
    }
    if(i != nb_mots - 1){
      chaine[nb_chars] = ' ';
      nb_chars ++;
    }
  }
  chaine[nb_chars] = '\0';
  
  return chaine;
}

void detruit_tab_mots(char ** tb){
  int nb_mots = compte_mots(tb);
  int i = 0;
  int j = 0;
  
  for(i; i < nb_mots; i ++){
    if (tb[i] != NULL) {
      for (j = i ; j < nb_mots ; j++) {
        if ((tb[j] == tb[i]) && (j != i)) {
          tb[j] == NULL;
        }
      }
      free(tb[i]);
      tb[i] = NULL;
    }
  }
  free(tb);
  tb = NULL;
}

void affiche_tab_mots(char ** tb){
  int i = 0;
  int t = compte_mots(tb);
  for(i; i < t ;i++){
    printf("%s\n", tb[i]);
  }
}

char ** reduit_tab_mots(char ** tb) {
  int taille = compte_mots(tb);
  int i = 0;
  int j = 0;
  char * p = NULL;
  
  for (i = 0 ; i < taille - 1 ; i++) {
    for (j = i + 1 ; j < taille ; j++) {
      if (strcmp(tb[i], tb[j]) == 0) {
        free(tb[j]);
        tb[j] = tb[i];
      }
    }
  }
  
  return tb;
}

int main(){
  char * c = "mot1 et mot2 et mot3";
  char ** tb = decompose_chaine(c);

  printf("- decompose_chaine() : \n");
  affiche_tab_mots(tb);
  printf("- compose_chaine() : \n");
  c = compose_chaine(tb);
  printf("%s\n", c);
  
  printf("- reduit_tab_mots() : \n");
  tb = reduit_tab_mots(tb);
  affiche_tab_mots(tb);
  
  free(c);
  c = NULL;
  detruit_tab_mots(tb);

  return 0;
}
