#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int synchro_1[2], synchro_2[2];
	int lu_1 = 0, lu_2 = 0, lu_3 = 0;
	
	pipe(synchro_1);
	pipe(synchro_2);
	int synchro_3 = open("synchro_3",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	lseek(synchro_3, 0, SEEK_SET);
	write(synchro_3, &lu_3, sizeof(int));	
	srand(getpid());
	write(synchro_1[1], &lu_1, sizeof(int));
	close(synchro_1[1]);
	
	if (fork() == 0){
		while(lu_3 == 0){
			close(synchro_1[1]);
			read(synchro_1[0], &lu_1, sizeof(int));
			
			printf("Coco\n");
			lseek(synchro_3, 0, SEEK_SET);
			read(synchro_3, &lu_3, sizeof(int));
			
			close(synchro_2[0]);
			write(synchro_2[1], &lu_2, sizeof(int));
			
			sleep(rand()%3+1);
		}
		close(synchro_1[0]);
		close(synchro_2[1]);
		printf("le fils Coco se termine\n");
		exit(EXIT_SUCCESS);
	}
	if (fork() == 0){
		while(lu_3 == 0){
			close(synchro_2[1]);
			read(synchro_2[0], &lu_2, sizeof(int));
			
			printf("Jaco\n");
			lseek(synchro_3, 0, SEEK_SET);
			read(synchro_3, &lu_3, sizeof(int));
			
			close(synchro_1[0]);
			write(synchro_1[1], &lu_1, sizeof(int));
			
			sleep(rand()%3+1);
		}
		close(synchro_2[0]);
		close(synchro_1[1]);
		printf("le fils Jaco se termine\n");
		exit(EXIT_SUCCESS);
	}
	
	for (int i = rand()%10+20; i >= 0; i--){
		sleep(1);
		lu_3++;
	}
	lseek(synchro_3, 0, SEEK_SET);
	write(synchro_3, &lu_3, sizeof(int));
	read(synchro_1[0], &lu_1, sizeof(int));
	close(synchro_1[0]);	
	
	for (int i = 0; i < 2; i++) wait(NULL);
	close(synchro_3);
	printf("le père se termine\n");
	exit(EXIT_SUCCESS);
}
