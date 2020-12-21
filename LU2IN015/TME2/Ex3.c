#include<stdio.h> // Ex3
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void multi_grep(int nb,char* argv[],char chaine[]){
	int i;
	int ret = 0;
	
	for(i = 0;i < nb;i++){
 		if (fork() == 0){
			printf("Je suis %d, fils de %d\n",getpid(),getppid());
			execl("/bin/grep","grep",chaine,argv[i+2],NULL);
		}

	}

	while(1){
		ret = wait(NULL);
		if (ret == -1){
			break;
		}
	}
}	

int main(int argc,char* argv[]){
	multi_grep(argc-2,argv,argv[1]);
	
	return 0;
}
