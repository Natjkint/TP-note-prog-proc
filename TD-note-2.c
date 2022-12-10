#include <stdio.h>

typedef struct processus{char nom;int priorite;int duree_exec;} processus;

int file_attente[][4];
/*
typedef struct ordonnanceur{file_attente} ordonnanceur;
*/

processus entree_processus(){
    processus procX;
    printf("Veuillez donner une activité : \n nom:");
    scanf("%s",procX.nom);
    printf("priorité:\n");
    scanf("%d",&procX.priorite);
    printf("durée d'exécution:\n");
    scanf("%d",&procX.duree_exec);
    return(procX);
}

void ajout_activite(int (*file_attente)[2]){
    processus prog1=entree_processus();
    for (unsigned i = 0; i < 100; ++i)          //il y aura pas plus de 100 éléments à la fois dans la file d'attente.
        if(file_attente[i][0]!=NULL){
            file_attente[i][0]=i;
            file_attente[i][1]=prog1.nom;
            file_attente[i][2]=prog1.priorite;
            file_attente[i][3]=prog1.duree_exec;
            return file_attente;
        }
}           

int step(int (*file_attente)[2]){
    for (unsigned i = 0; i < 100; ++i)
        if(file_attente[i][0]!=NULL){
            //"exec le processus"
            printf("Processus %s, de priorité %d, et de durée d'exécution %d", file_attente[i][1], file_attente[i][2], file_attente[i][3];);
            for (unsigned j = 0; j < 4; ++j)
                file_attente[i][j]=NULL;
            return 0;
        }
    printf("Il n'y a pas de processus en attente");
    return 10;
}

int run(int (*file_attente)[2]){
    int A=step(*file_attente);
    while (A!=10){
        A=step(*file_attente);
    }
    return 0;
}
