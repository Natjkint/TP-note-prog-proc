#ifndef fonctionsreutilisees
#define fonctionsreutilisees
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#define filename "airbnb_donnees_propre.csv"


typedef struct logement {
    int index;
    int accommodates;
    int bedrooms;
    int bathrooms;
    int beds;
    int price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    float distance[7];
} logement;

logement LogementATester();

int nbrLignes();

logement* copyTableau();

int carre(float x);

void shuffle(logement tab[], int taille);

int moyennePrix(logement tab[], int k);

int triinsertion(logement tab[]);

#endif
