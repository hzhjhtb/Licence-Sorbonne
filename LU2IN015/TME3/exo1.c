#include<unistd.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	pid_t pid;
	int tube[2];
	srand(time(NULL));
	
	// création de la tude anonyme
	if (pipe(tube) != 0){ 
		printf("Erreur de création de la tube!\n");
		exit(EXIT_FAILURE);
	}
	// le premier fils
	if ((pid = fork()) == 0){
		int alea = rand()%(99-0+1);
		close(tube[0]);
		write(tube[1],&alea,sizeof(int));
		printf("Le fils 1 a ecrit le nb\n");
		close(tube[1]);
		exit(EXIT_SUCCESS);
	}
	// le second fils
	if ((pid = fork()) == 0){
		int alea;
		close(tube[1]);
		read(tube[0],&alea,sizeof(int));
		printf("Le fils 2 a lu le nb : %d\n",alea);
		close(tube[0]);
		exit(EXIT_SUCCESS);
	}
	
	exit(EXIT_SUCCESS);
}
