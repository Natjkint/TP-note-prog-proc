#include "typedef.h"


ordonnanceur step(ordonnanceur A){
    if (A.file == 0){
        printf("Il n'y a pas de processus en attente");
        return A;
    }
    else{
        for (int i = 0; i < 20; ++i){
            if (A.proc[i].duree_exec != -1){
                //"execute le processus"
                printf("Processus %s, de priorité %d, et de durée d'exécution %d\n", A.proc[i].str_nom, A.proc[i].priorite, A.proc[i].duree_exec);

                printf("On attend %ds, le temps que le processus s'exécute !\n",A.proc[i].duree_exec);
                sleep(A.proc[i].duree_exec);

                A.proc[i].priorite=-1; A.proc[i].duree_exec=-1; memset(&A.proc[i].str_nom, 0, sizeof(A.proc->str_nom)); 
                A.file--;       //On reset l'entrée du processus aux valeurs initiales.
                return A;
            }
        }
    }
    exit(EXIT_FAILURE);
}
