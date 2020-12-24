#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define NB_FILS 3

void fils(int i, int nb, int synchro_1[NB_FILS][2], int synchro_2[NB_FILS][2]){
	int lu;
	if (i < nb){
		if (fork() == 0){
			fils(i+1, nb, synchro_1, synchro_2);
			printf("je sui fils %d\n", i);
			sleep(rand()%11+5);
			
			close(synchro_1[i][0]);
			write(synchro_1[i][1], &lu, sizeof(int));
			close(synchro_1[i][1]);
			
			close(synchro_2[i][1]);
			read(synchro_2[i][0], &lu, sizeof(int));
			close(synchro_2[i][0]);
			
			printf("fils %d se termine\n", i);
			
			exit(EXIT_SUCCESS);
		}
	}
} 

int main(int argc, char **argv){
	int synchro_1[NB_FILS][2], synchro_2[NB_FILS][2];
	int lu;
	for (int i = 0; i < NB_FILS; i++) pipe(synchro_1[i]);
	for (int i = 0; i < NB_FILS; i++) pipe(synchro_2[i]);
	srand(getpid());
	
	printf("On commence !\n");
	fils(0, NB_FILS, synchro_1, synchro_2);
	for (int i = 0; i < NB_FILS; i++){
		close(synchro_1[i][1]);
		read(synchro_1[i][0], &lu, sizeof(int));
		close(synchro_1[i][0]);
		printf("fils %d atteint la barrière de synchronisation!\n", i);
	}
	for (int i = 0; i < NB_FILS; i++){
		close(synchro_2[i][0]);
		write(synchro_2[i][1], &lu, sizeof(int));
		close(synchro_2[i][1]);
	}
	
	exit(EXIT_SUCCESS);
}

