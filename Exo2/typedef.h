#ifndef HEADER_ORDONNANCEURS
#define HEADER_ORDONNANCEURS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> //sleep pour linux
//#include <windows.h>     //sleep pour windows

typedef struct processus{char str_nom[20];int priorite;int duree_exec;} processus;
typedef struct ordonnanceur{int file; processus proc[20];} ordonnanceur;

ordonnanceur entree_processus(ordonnanceur A);
ordonnanceur run(ordonnanceur A);
ordonnanceur step(ordonnanceur A);

#endif
