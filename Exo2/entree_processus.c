#include "typedef.h"

ordonnanceur entree_processus() { 
    processus procX;
    printf("Veuillez donner une activité : \n nom:");
    scanf("%s",procX.str_nom);
    printf("priorité:\n");
    scanf("%d",&procX.priorite);
    printf("durée d'exécution:\n");
    scanf("%d",&procX.duree_exec);
    ordonnanceur A;
    for (int i = 0; i < 20; ++i){
        if(A.file[i]==0){
            A.proc[i]=procX;
            return A;
        }
    }
}