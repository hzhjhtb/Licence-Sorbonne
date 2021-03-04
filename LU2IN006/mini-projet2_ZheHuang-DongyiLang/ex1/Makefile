all : main

main : main.o biblioLC.o entreeSortieLC.o
	gcc -ggdb -Wall -g -o main main.o biblioLC.o entreeSortieLC.o 

main.o : main.c entreeSortieLC.h biblioLC.h
	gcc -Wall -g -c main.c

biblioLC.o : biblioLC.c biblioLC.h 
	gcc -Wall -g -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h
	gcc -Wall -g -c entreeSortieLC.c

clean :
	rm -f *.o main