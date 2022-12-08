#include <stdio.h>

typedef struct processus{char nom;int priorite;int duree_exec;} processus;
typedef struct ordonnanceur{int file[100];struct processus proc;} ordonnanceur;

processus entree_processus() { 
    processus procX;
    printf("Veuillez donner une activité : \n nom:");
    scanf("%s",procX.nom);
    printf("priorité:\n");
    scanf("%d",&procX.priorite);
    printf("durée d'exécution:\n");
    scanf("%d",&procX.duree_exec);
    return(procX);
}

ordonnanceur ajout_activite(){
    processus prog1=entree_processus();
    ordonnanceur A;
    int i=0;
    for(0;A.file[i]==NULL;i++);
    A.file[i]=i;
    A.proc=prog1;
    return(A);
}
