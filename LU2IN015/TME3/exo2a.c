#include<time.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#define FIFO "./fifo"
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	srand(time(NULL));
	extern int errno;
	
	// création du tube nommée
	int fifo = mkfifo(FIFO, 0777);
	if (fifo == -1){
		printf("error1 = %d\n", errno);
		exit(1);
	}
	
	// ouvert du tube nommée
	int fd;
	fd = open(FIFO, O_WRONLY);
	if (fd == -1){
		printf("error2 = %d\n", errno);
		exit(1);
	}
	
	// on donne la valeur au tube
	int alea = rand()%100;
	if (write(fd, &alea, sizeof(int)) == -1){
		printf("error3 = %d\n", errno);
		exit(1);
	}else{
		printf("2a a ecrit le nb : %d\n", alea);
	}
	
	// on fait le fermeture
	close(fd);
	unlink(FIFO);

	return 0;	
}




