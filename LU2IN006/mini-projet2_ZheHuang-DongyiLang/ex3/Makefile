all : tmp

tmp : tmp.o biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o
	gcc -ggdb -Wall -g -o tmp tmp.o biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o

tmp.o : tmp.c entreeSortieH.h biblioH.h biblioLC.h entreeSortieLC.h
	gcc -Wall -g -c tmp.c

biblioH.o : biblioH.c biblioH.h 
	gcc -Wall -g -c biblioH.c

entreeSortieH.o : entreeSortieH.c entreeSortieH.h
	gcc -Wall -g -c entreeSortieH.c

biblioLC.o : biblioLC.c biblioLC.h 
	gcc -Wall -g -c biblioLC.c

entreeSortieLC.o : entreeSortieLC.c entreeSortieLC.h
	gcc -Wall -g -c entreeSortieLC.c

clean :
	rm -f *.o main