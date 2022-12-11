#include "typedef.h"

ordonnanceur entree_processus(ordonnanceur A) {
    processus procX;
    printf("Veuillez donner une activité : \n nom:");
    scanf("%s",procX.str_nom);
    printf("priorité:\n");
    scanf("%d",&procX.priorite);
    printf("durée d'exécution:\n");
    scanf("%d",&procX.duree_exec);
    for (int i = 0; i < 20; ++i){
        if(A.proc[i].priorite==-1){
            A.proc[i]=procX;
            A.file++;
            printf("%d\n",A.file);
            return A;
        }
    }
    printf("La file est pleine\n");
    exit(EXIT_FAILURE);
}
