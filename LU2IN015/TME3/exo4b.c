#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char* args[]){
	pid_t pid;
	if ((pid = fork()) == 0){
		execl("./exo4a","./exo4a","exo4.txt",NULL);
	}else{
		wait(NULL);
		execl("./exo4a","./exo4a","exo4.txt",NULL);
	}
	exit(EXIT_SUCCESS);
}
