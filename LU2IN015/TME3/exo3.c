#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
  	int fd;
  	char lu;
  	int i;
  	pid_t pid;

	printf("Le pere %d commence\n", getpid());
	
  	// on ouvert le "test.txt"
  	fd = open(argv[1], O_RDONLY);
  	if (fd == -1){
    	printf("%s n'existe pas\n", argv[1]);
    	exit(EXIT_FAILURE);
	}else{
		// le premier fils
    	pid = fork();
    	if (pid < 0){  
      		printf("fork error\n");
      		close(fd);
      		exit(EXIT_FAILURE);
    	}
    	if (pid > 0){ 
      		wait(NULL); // le père attent le permier fils
		}
		if (pid == 0){ // on est dans le fils 
        	printf("Le premier fils %d commence\n", getpid());
 			for (i = 0; i < 3;i++){
   				if ((read(fd, &lu, sizeof(char))) > 0){
     				printf("%d a lu %c\n", getpid(), lu);
   				}else{
     				printf("reading error\n");
     				close(fd);
     				exit(EXIT_FAILURE);
   				}
  			}
  			printf("Le fils %d se termine\n", getpid());
  			close(fd);
  			exit(EXIT_SUCCESS);
  		}
		
		// on est dans le père
    	if ((read(fd, &lu, sizeof(char))) > 0) {
      		printf("%d a lu %c\n", getpid(), lu);
    	}else{
      		printf("reading error\n");
      		close(fd);
      		exit(EXIT_FAILURE);
    	}
		
		// le second fils
		pid = fork(); 
    	if (pid < 0){
      		printf("fork error\n");
      		close(fd);
      		exit(EXIT_FAILURE);
    	}
      	if (pid > 0){ // le père attent le second fils 
      		wait(NULL);
      	}
      	if (pid == 0){ 
        	printf("Le second fils %d commence\n", getpid());
 			for (i = 0 ; i < 3 ; i++) {
   				if (read(fd, &lu, sizeof(char)) > 0) {
   					printf("%d a lu %c\n", getpid(), lu);
   				}else{
     				printf("reading error\n");
     				close(fd);
     				exit(EXIT_FAILURE);
    			}
   			}
   			printf("Le fils %d se termine\n", getpid());
   			close(fd);
   			exit(EXIT_SUCCESS);
      	}
	}
    
    close(fd); 
	
    // le troisième fils
    pid = fork();
    if (pid < 0){
      	printf("fork error\n");
      	exit(EXIT_FAILURE);
      	}	
    if (pid > 0){ // le père attent le troisième fils 
    	wait(NULL);
    }
    if (pid == 0){ 
        printf("Le troisieme fils %d commence\n", getpid());
        if ((fd = open(argv[1], O_RDONLY)) == -1){
   			printf("open failed\n");
   			close(fd);
   			exit(EXIT_FAILURE);
   		}else{
   			for (i = 0 ; i < 4 ; i++) {
     		if (read(fd, &lu, sizeof(char)) > 0) {
       			printf("%d a lu %c\n", getpid(), lu);
     		}else{
       			printf("reading error\n");
       			close(fd);
       			exit(EXIT_FAILURE);
     		}
   			}
   			printf("Le fils %d se termine\n", getpid());
   			close(fd);
   			exit(EXIT_SUCCESS);
 		}
    }
    
    printf("Le pere %d se termine\n", getpid());
    
    exit(EXIT_SUCCESS);
}
