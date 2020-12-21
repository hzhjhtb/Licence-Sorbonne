#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


void prise(int fd){
	int verrou=open("verrou",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	lseek(verrou,0,SEEK_SET);
	lockf(verrou,F_LOCK,0);
	
	int nb;
	lseek(fd,0,SEEK_SET);
	read(fd,&nb,sizeof(int));
	while (nb == 0){
		sleep(1);
		lseek(fd,0,SEEK_SET);
		read(fd,&nb,sizeof(int));
	}
	nb--;
	lseek(fd,0,SEEK_SET);
	write(fd,&nb,sizeof(int));
	
	lseek(verrou,0,SEEK_SET);
	lockf(verrou,F_ULOCK,0);
	close(verrou);
}

void liberation(int fd){
	int verrou=open("verrou",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
	lseek(verrou,0,SEEK_SET);
	lockf(verrou,F_LOCK,0);
	
	int nb;
	lseek(fd,0,SEEK_SET);
	read(fd,&nb,sizeof(int));
	nb++;
	lseek(fd,0,SEEK_SET);
	write(fd,&nb,sizeof(int));
	
	lseek(verrou,0,SEEK_SET);
	lockf(verrou,F_ULOCK,0);
	close(verrou);
}


int main(int argc,char *argv[]){
	if (argc != 2){
		exit(EXIT_FAILURE);
	}
	
	srand(getpid());
	int paniers = open("./paniers",O_RDWR,S_IRUSR|S_IWUSR);
	int cabines = open("./cabines",O_RDWR,S_IRUSR|S_IWUSR);
	int identite = atoi(argv[1]);
	
	printf("%d arrive a la piscine\n",identite);
	
	int nb_cabine,nb_panier;
	read(cabines,&nb_cabine,sizeof(int));
	read(paniers,&nb_panier,sizeof(int));
	while (nb_cabine <= 1 || nb_panier <= 0){
		sleep(1);
		lseek(cabines,0,SEEK_SET);
		read(cabines,&nb_cabine,sizeof(int));
		lseek(paniers,0,SEEK_SET);
		read(paniers,&nb_panier,sizeof(int));
	}
	
	prise(cabines);
	printf("%d prend une cabine\n",identite);
	prise(paniers);
	printf("%d prend un panier\n",identite);
	
	printf("%d se change\n",identite);
	
	liberation(cabines);
	printf("%d libere la cabine\n",identite);

	printf("%d se baigne\n",identite);
	for (int k = rand()%8+2; k >= 0; k--) sleep(1);
	
	prise(cabines);
	printf("%d prend une cabine\n",identite);
	
	printf("%d se change\n",identite);
	
	liberation(paniers);
	printf("%d libere le panier\n",identite);
	
	liberation(cabines);
	printf("%d libere la cabine\n",identite);
	
	printf("%d depart de la piscine\n",identite);
	
	close(paniers);
	close(cabines);
	
	exit(EXIT_SUCCESS);
}
