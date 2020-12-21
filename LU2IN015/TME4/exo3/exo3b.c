#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>


void creer_baigneurs(int i,int nb){
	if (i < nb){
		if (fork() == 0){
			creer_baigneurs(i+1,nb);
			char identite[10];
			sprintf(identite,"%d",i);
			execl("./exo3a","exo3a",identite,NULL);
		}
	}	
}


int main(int argc,char *argv[]){
	if (argc != 4){
		exit(EXIT_FAILURE);
	}
	int nb_baigneurs = atoi(argv[1]);
	int nb_paniers   = atoi(argv[2]);
	int nb_cabines   = atoi(argv[3]);
	
	int paniers = open("./paniers",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	lseek(paniers,0,SEEK_SET);
	write(paniers,&nb_paniers,sizeof(int));
	int cabines = open("./cabines",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	lseek(cabines,0,SEEK_SET);
	write(cabines,&nb_cabines,sizeof(int));
	
	creer_baigneurs(0,nb_baigneurs);
	for(int i = 0; i < nb_baigneurs; i++) wait(NULL);
	
	close(paniers);
	close(cabines);
	
	exit(EXIT_SUCCESS);
}
