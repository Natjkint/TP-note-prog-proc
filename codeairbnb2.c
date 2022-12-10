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
    float distance[3];
} logement;


int triinsertion(logement tab[])
{ 
  int k;
  printf("Choisissez l'attribut de la distance pour trier:\n1.Accomodates\n2.Bedrooms\n3.Beds");
  scanf("%d", &k);
  int i, j, tmp;
  int SIZE = nbrLignes();
  for (i=1 ; i <= SIZE-1; i++) {
    j = i;
 
    while (j > 0 && tab[j-1].distance[k] > tab[j].distance[k]) {
      tmp = tab[j].distance[k];
      tab[j].distance[k] = tab[j-1].distance[k];
      tab[j-1].distance[k] = tmp;
 
      j--;
    }
  }
 
  printf("\n******** tableau triée par ordre croissant ********\n");
 
 
  return 0;
}

int main(){
    int a;
    
    LogementATester();
    copyTableau();
    //shuffle(tab[]);
    triinsertion(tab[]);
    //a=moyennePrix(tab[], 100);
    printf("Le prix estimé est: %d", a);
    return 0;
}
        
