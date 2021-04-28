all : ReorganiseReseau main ReconstitueReseau ChaineMain

main : main.o Chaine.o Reseau.o Hachage.o ArbreQuat.o SVGwriter.o
	gcc -Wall -g -rdynamic -o main main.o Chaine.o Reseau.o Hachage.o ArbreQuat.o SVGwriter.o -lm

main.o : main.c
	gcc -Wall -g -c main.c

ReorganiseReseau : ReorganiseReseau.o Struct_File.o Graphe.o Chaine.o Reseau.o Hachage.o ArbreQuat.o SVGwriter.o
	gcc -Wall -g -rdynamic -o ReorganiseReseau ReorganiseReseau.o Struct_Liste.o Struct_File.o Graphe.o Chaine.o Reseau.o Hachage.o ArbreQuat.o SVGwriter.o -lm

ReorganiseReseau.o : ReorganiseReseau.c
	gcc -Wall -g -c ReorganiseReseau.c

Struct_File.o : Struct_File.c
	gcc -Wall -g -c Struct_File.c

Struct_Liste.o : Struct_Liste.c
	gcc -Wall -g -c Struct_Liste.c

Graphe.o : Graphe.c Graphe.h
	gcc -Wall -g -c Graphe.c

ReconstitueReseau : ReconstitueReseau.o Chaine.o Reseau.o Hachage.o ArbreQuat.o SVGwriter.o
	gcc -Wall -g -rdynamic -o ReconstitueReseau ReconstitueReseau.o Chaine.o Reseau.o Hachage.o ArbreQuat.o SVGwriter.o -lm

ReconstitueReseau.o : ReconstitueReseau.c
	gcc -Wall -g -c ReconstitueReseau.c

ArbreQuat.o : ArbreQuat.c ArbreQuat.h
	gcc -Wall -g -c ArbreQuat.c

Hachage.o : Hachage.c Hachage.h
	gcc -Wall -g -c Hachage.c

Reseau.o : Reseau.c Reseau.h
	gcc -Wall -g -c Reseau.c 

ChaineMain : ChaineMain.o Chaine.o SVGwriter.o
	gcc -Wall -g -rdynamic -o ChaineMain ChaineMain.o Chaine.o SVGwriter.o -lm

ChaineMain.o : ChaineMain.c Chaine.h
	gcc -Wall -g -c ChaineMain.c

Chaine.o : Chaine.c Chaine.h
	gcc -Wall -g -c Chaine.c -lm

SVGwriter.o : SVGwriter.c SVGwriter.h
	gcc -Wall -g -c SVGwriter.c

clean :
	rm -f *.o main