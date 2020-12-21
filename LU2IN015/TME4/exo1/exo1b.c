#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc,char* args[]){
	pid_t pid;
	if ((pid = fork()) == 0){
		int verrou=open("verrou",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
		lseek(verrou,0,SEEK_SET);
		lockf(verrou,F_LOCK,0);
		
		execl("./exo1a","exo1a","exo1.txt",NULL);
		
		lseek(verrou,0,SEEK_SET);
		lockf(verrou,F_ULOCK,0);
		close(verrou);
	}else{
		int verrou=open("verrou",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
		lseek(verrou,0,SEEK_SET);
		lockf(verrou,F_LOCK,0);
		
		execl("./exo1a","exo1a","exo1.txt",NULL);
		
		lseek(verrou,0,SEEK_SET);
		lockf(verrou,F_ULOCK,0);
		close(verrou);
	}
	exit(EXIT_SUCCESS);
}
