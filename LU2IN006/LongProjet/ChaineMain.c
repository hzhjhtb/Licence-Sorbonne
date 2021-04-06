#include "Chaine.h"
#include <stdlib.h>

int main(){
    FILE* f = fopen("00014_burma.cha", "r");
    Chaines* c = lectureChaines(f);
    FILE* F = fopen("ecrire.txt", "w");
    ecrireChaines(c, F);
    
    return 0;
}