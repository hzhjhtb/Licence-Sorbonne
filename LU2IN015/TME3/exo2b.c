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
	extern int errno;
	
	// ouvert du tube nommée
	int fd = open(FIFO, O_RDONLY);
	if (fd == -1){
		printf("error1 = %d\n", errno);
		exit(1);
	}
	
	// lecture du tube
	int alea; 
	if (read(fd, &alea, sizeof(int)) == -1){
		printf("error2 = %d\n", errno);
		exit(1);
	}else{
		printf("2b a lu le nb : %d\n", alea);	
	}
	
	// fermeture du tube
	close(fd);
	
	return 0;
}
