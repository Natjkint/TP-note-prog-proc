#include "typedef.h"


int step(ordonnanceur A){
    for (int i = 0; i < 20; ++i){
        if(A.file[i]!=0){
            //"execute le processus"
            printf("Processus %s, de priorité %d, et de durée d'exécution %d", A.proc[i].str_nom, A.proc[i].priorite, A.proc[i].duree_exec);
            printf("On attend %ds, le temps que le processus s'exécute !",A.proc[i].duree_exec);
            sleep(A.proc[i].duree_exec);
            A.file[i]=0;    //A.str_nom[20][i]=NULL;A.priorite[i]=0;A.duree_exec[i]=0;
            return 0;
        }
    }
    printf("Il n'y a pas de processus en attente");
    return 10;
}