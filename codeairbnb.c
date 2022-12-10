#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "fonctionsreutilisees.h"
#define filename "airbnb_donnees_propre.csv"



int main(){
    int a;
    logement tab[nbrLignes()];
    
    LogementATester();
    copyTableau();
    shuffle(tab, nbrLignes());
    triinsertion(tab);
    a=moyennePrix(tab, 100);
    printf("Le prix estimé est: %d", a);
    return 0;
}
        
