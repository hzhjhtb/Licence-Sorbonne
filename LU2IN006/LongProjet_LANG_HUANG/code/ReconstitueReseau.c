#include <stdio.h>
#include "Reseau.h"
#include "Chaine.h"
#include <string.h>
#include <stdlib.h>
#include "Hachage.h"
#include "ArbreQuat.h"

void menu(){
    printf("méthodes à choisir:\n1-liste\n2-table de hachage\n3-arbre\n0-sortir\n");
}

int main(int argc, char** argv){
    /*int l = strlen(argv[1]);
    if((argv[1][l-1] != 'a')||(argv[1][l-2] != 'h')||(argv[1][l-3] != 'c')||(argv[1][l-4] != '.')||(argc != 2)){
        printf("ficher de format incorrect");
        return 0;
    }*/
    FILE* f = fopen("00014_burma.cha", "r");
    Chaines* C = lectureChaines(f);
    fclose(f);
    int rep;
    do{
        menu();
        scanf(" %d",&rep);
        switch (rep){
        case 1:{
            Reseau* R = reconstitueReseauListe(C);
            FILE* F = fopen("test.txt", "w");
            ecrireReseau(R, F);
            fclose(F);
            afficheReseauSVG(R,"r");
            libererReseau(R);
            printf("Reconstitution fait.\n");
            break;
        }
        case 2:{
            Reseau* Rh = reconstitueReseauHachage(C,100);
            FILE* Fh = fopen("testh.txt", "w");
            ecrireReseau(Rh, Fh);
            fclose(Fh);
            afficheReseauSVG(Rh,"rh");
            libererReseau(Rh);
            printf("Reconstitution fait.\n");
            break;            
        }
        case 3:{
            Reseau* Ra = reconstitueReseauArbre(C);
            FILE* Fa = fopen("testa.txt", "w");
            ecrireReseau(Ra, Fa);
            fclose(Fa);
            afficheReseauSVG(Ra,"ra");
            libererReseau(Ra);
            printf("Reconstitution fait.\n");
            break;
        }
        }
    }while(rep != 0);
    libererChaines(C);
    return 0;
}