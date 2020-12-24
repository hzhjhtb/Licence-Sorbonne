#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void fils(char *chaine){

	int fic=open("fichier",O_CREAT|O_APPEND|O_WRONLY,S_IRUSR|S_IWUSR);
	dup2(fic,1);
	close(fic);
	printf("%d a ecrit %s\n",getpid(),chaine);
	fflush(stdout);

	srand(getpid());
	int attente=rand()%4;
	fprintf(stderr,"%d attente de %d\n",getpid(),attente);
	sleep(attente);

	fic=open("copie",O_CREAT|O_APPEND|O_WRONLY,S_IRUSR|S_IWUSR);
	dup2(fic,1);
	close(fic);
	printf("%d a ecrit %s\n",getpid(),chaine);
}

int main(int argc,char **argv){
	int i,lu;
	pid_t pid;
	system("rm -f fichier copie");
	int synchro[argc-2][2];
	for (i = 0; i < argc-2; i++) pipe(synchro[i]);

	for(i=1;i<argc;i++){
		if((pid=fork())<0){
			printf("Erreur fork\n");
			exit(EXIT_FAILURE);
		}else if(pid==0){
			if (i == 1){
				fils(argv[i]);

				close(synchro[0][0]);
				write(synchro[0][1],&lu,sizeof(int));
				close(synchro[0][1]);
				
				exit(EXIT_SUCCESS);	
			}
			if ((i > 1) && (i < argc-1)){
				close(synchro[i-2][1]);
				read(synchro[i-2][0],&lu,sizeof(int));
				close(synchro[i-2][0]);
				
				fils(argv[i]);
				
				close(synchro[i-1][0]);
				write(synchro[i-1][1],&lu,sizeof(int));
				close(synchro[i-1][1]);	
				
				exit(EXIT_SUCCESS);
			}
			if (i == argc-1){
				close(synchro[i-2][1]);
				read(synchro[i-2][0],&lu,sizeof(int));
				close(synchro[i-2][0]);
				
				fils(argv[i]);
				
				exit(EXIT_SUCCESS);
			}
		}
	}
	exit(EXIT_SUCCESS);
}
