#include<stdio.h> // Ex1
#include<stdlib.h>
#include<unistd.h>

void creer_chaine(int i,int nb){
	if (i<nb){
		if (fork() == 0){
			printf("je suis %d, le fils de %d\n",getpid(),getppid());
			creer_chaine(i+1,nb);
		}
	}else{
		if (fork() == 0){
			printf("je suis %d, le N+1 fils de %d\n",getpid(),getppid());
		}
	}
}
int main(int argc,char* argv[]){
	int pid = getpid();
	
	creer_chaine(0,atoi(argv[1]));
	                                  
	return 0;
}
