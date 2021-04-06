all : ChaineMain

ChaineMain : ChaineMain.o Chaine.o
	gcc -Wall -o ChaineMain ChaineMain.o Chaine.o

ChaineMain.o : ChaineMain.c Chaine.h
	gcc -Wall -c ChaineMain.c

Chaine.o : Chaine.c Chaine.h
	gcc -Wall -c Chaine.c

clean :
	rm -f *.o main