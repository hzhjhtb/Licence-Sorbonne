#include "Chaine.h"
#include <stdlib.h>
#include "SVGwriter.h"

int main(int argc,char **argv){
    FILE* f = fopen("00014_burma.cha", "r");
    Chaines* c = lectureChaines(f);
    fclose(f);
    if(argc != 2){
        return 0;
    }
    FILE* F = fopen(argv[1], "w");
    ecrireChaines(c, F);
    printf("%f\n",longueurTotale(c));
    fclose(F);
    printf("%d\n",comptePointsTotal(c));
    return 0;
}