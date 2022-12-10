#ifndef HEADER_ORDONNANCEURS
#define HEADER_ORDONNANCEURS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct processus{char str_nom[20];int priorite;int duree_exec;} processus;
typedef struct ordonnanceur{int file[20]; processus proc[20];} ordonnanceur;

ordonnanceur entree_processus();
int run(ordonnanceur A);
int step(ordonnanceur A);

#endif