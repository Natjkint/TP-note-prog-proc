#include "typedef.h"

int main(){
    ordonnanceur A;
    int reponse2 = 0;
    while (reponse2==0){
        printf("Voulez-vous ajouter un processus ? : (oui / non) \n");
        char str_reponse[3];
        scanf("%s", str_reponse);
        reponse2 = strcmp("oui",str_reponse);
        if (reponse2==0){
            A = entree_processus();
        }
    }
    
    run(A);
    return 0;
}