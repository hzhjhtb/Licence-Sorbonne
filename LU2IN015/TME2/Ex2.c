#include<stdio.h> // Ex2
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
	int a,b,status;
	
	if (fork() == 0){
		printf("a : ");
		scanf("%d",&a);
		printf("b : ");
		scanf("%d",&b);
		
		if (a+b > 10){
			exit(EXIT_SUCCESS);	
		}else{
			exit(EXIT_FAILURE);
		}
	}
	
	wait(&status);
	if (WEXITSTATUS(status) == 0){
		printf("a+b > 10\n");
	}else{
		printf("a+b <= 10\n");
	}			
	
	return 0;
}
