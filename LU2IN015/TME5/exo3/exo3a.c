#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void fils(char *chaine){
	int verrou=open("verrou",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	lseek(verrou,0,SEEK_SET);
	lockf(verrou,F_LOCK,0);
	
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

	lseek(verrou,0,SEEK_SET);
	lockf(verrou,F_ULOCK,0);
	close(verrou);
	
	exit(EXIT_SUCCESS);
}

int main(int argc,char **argv){

	int i;
	pid_t pid;
	system("rm -f fichier copie");

	for(i=1;i<argc;i++){
		if((pid=fork())<0){
			printf("Erreur fork\n");
			exit(EXIT_FAILURE);
		}else if(pid==0){
			fils(argv[i]);
		}
	}
	exit(EXIT_SUCCESS);
}
