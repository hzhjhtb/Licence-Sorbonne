#include<stdio.h> //Ex4
#include<stdlib.h> 
#include<unistd.h>
#include<sys/wait.h>
#define MAXFILS 2

void multi_grep(int nb,char* argv[],char chaine[]){
	int i;
	int ret = 0;

	
	if (nb <= MAXFILS){
		for(i = 0;i < nb;i++){
 			if (fork() == 0){
				printf("Je suis %d, fils de %d\n",getpid(),getppid());
				execl("/bin/grep","grep",chaine,argv[i+2],NULL);
			}

		}
	}else{
		for(i = 0;i < MAXFILS;i++){
 			if (fork() == 0){
				printf("Je suis %d, fils de %d\n",getpid(),getppid());
				execl("/bin/grep","grep",chaine,argv[i+2],NULL);
			}
		}	
		wait(NULL);

		while (i < nb){
			if (fork() == 0){
				printf("Je suis %d, fils de %d\n",getpid(),getppid());
				execl("/bin/grep","grep",chaine,argv[i+2],NULL);
			}
			i++;
			wait(NULL);
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
