#include "typedef.h"

int main(){
    ordonnanceur A;         //Initialisation
    A.file=0;
    for (int i = 0; i < 20; ++i){
        A.proc[i].priorite=-1; A.proc[i].duree_exec=-1; memset(&A.proc[i].str_nom, 0, sizeof(A.proc->str_nom));
    }
    int reponse2 = 0;
    while (reponse2==0){
        printf("Voulez-vous ajouter un processus ? : (oui / non) \n");
        char str_reponse[20];
        scanf("%s", str_reponse);
        reponse2 = strcmp("oui",str_reponse);
        if (reponse2==0){
            A = entree_processus(A);
        }
    }
    run(A);
    printf("est-ce que ça execute ça?");
    if (A.file == 0){               //Dernier test
        exit(EXIT_SUCCESS);
    } else {exit(EXIT_FAILURE);}
}
