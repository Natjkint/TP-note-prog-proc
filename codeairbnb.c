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
    float distance;
} logement;


 int carre(x){ // fonction qui donne le carré de x
return x*x;
 }

logement LogementATester(){ // Fonction afin d'entrer les spécificités du logement à tester afin d'en calculer le prix
    int a;                  // Price et distance ne sont donc pas remplis car ils sont calculés
    logement LogementX;
    printf("Entrer accomodates");
    scanf("%d", &a);
    LogementX.accommodates=a;
    printf("Entrer  bedrooms");
    scanf("%d", &a);
    LogementX.bedrooms=a;
    printf("Entrer bathrooms");
    scanf("%d", &a);
    LogementX.bathrooms=a;
    printf("Entrer beds");
    scanf("%d", &a);
    LogementX.beds=a;
    printf("Entrer minimum nights");
    scanf("%d", &a);
    LogementX.minimum_nights=a;
    printf("Entrer maximum nights");
    scanf("%d", &a);
    LogementX.maximum_nights=a;
    printf("Entrer number of reviews");
    scanf("%d", &a);
    LogementX.number_of_reviews=a;
    return LogementX;
}

int nbrLignes(){        // Fonction calculant le nombre de ligne dans le document fourni
    char buffer[1024];
    int nbLogements;
    FILE *fileStream;
    fileStream = fopen(filename, "r");
    while (fgets(buffer, 1024, fileStream)){
        nbLogements ++;
    }
    fclose(fileStream);
return nbLogements;
}


logement copyTableau(){      // Fonction copiant le tableau du document fourni afin de le manipuler
    char buffer[1024];
    int column;
    int numattr;
    logement tab[nbrLignes(filename)-1];
    FILE *fileStream;
    fileStream = fopen(filename, "r");
    for (int i=0; i<= nbrLignes(filename)-1; i++){
        fgets(buffer,1024, fileStream);
        char* value = strtok(buffer, ", ");
        column = 0;
        while (value) {         // Cette partie du code sert à remplir les différents champ du struct Logement
            switch (column)
            {
            case 0:
                tab[i].index=value;
                break;
            
            case 1:
                 tab[i].accommodates=value;
                 break;
            case 2:
                   tab[i].bedrooms=value;
                   break;
            case 3:
                   tab[i].bathrooms=value;
                   break;
            case 4:
                   tab[i].beds=value;
                   break;
            case 5:
                   tab[i].price=value;
                   break;
            case 6:
                   tab[i].minimum_nights=value;
                   break;
            case 7:
                   tab[i].maximum_nights=value;
                   break;
            case 8:
                   tab[i].number_of_reviews=value;
                   break;
             }

            value = strtok(NULL, ", ");
            column++;
            }   
            printf("Entrer le numéro de l'attribut afin de calculer la distance correspondante:\n");        // Cette partie remplit le champ "distance" selon le choix de l'attribut/champ
            printf("1. Accomodates\n2.Bedrooms\n3.Bathrooms\n4.Beds\n5.Minimum nights\n6.Maximum nights\n7.Number of reviews");
            scanf("%d", &numattr);
            switch(numattr) {
                case 1:
                tab[i].distance=sqrt(carre((tab[i].accommodates-LogementATester().accommodates)));
                break;
                case 2:
                tab[i].distance=sqrt(carre((tab[i].bedrooms-LogementATester().bedrooms)));
                break;
                case 3:
                tab[i].distance=sqrt(carre((tab[i].bathrooms-LogementATester().bathrooms)));
                break;
                case 4:
                tab[i].distance=sqrt(carre((tab[i].beds-LogementATester().beds)));
                break;
                case 5:
                tab[i].distance=sqrt(carre((tab[i].minimum_nights-LogementATester().minimum_nights)));
                break;
                case 6:
                tab[i].distance=sqrt(carre((tab[i].maximum_nights-LogementATester().maximum_nights)));
                break;
                case 7:
                tab[i].distance=sqrt(carre((tab[i].number_of_reviews-LogementATester().number_of_reviews)));
                break;
            }
         fclose(fileStream);
    }
}

void shuffle(logement tab[], int taille){
    srand(time(NULL));
    int random;
    logement temp;
    for (int i=0; i<taille, i++){
        random= rand()%taille;
        temp= tab[i];
        tab[i] = tab[random];
        tab[random] = temp;
    }
}

int triinsertion(logement tab[])
{ 
  int i, j, tmp;
  int SIZE = nbrLignes();
  for (i=1 ; i <= SIZE-1; i++) {
    j = i;
 
    while (j > 0 && tab[j-1].distance > tab[j].distance) {
      tmp = tab[j].distance;
      tab[j].distance = tab[j-1].distance;
      tab[j-1].distance = tmp;
 
      j--;
    }
  }
 
  printf("\n******** tableau triée par ordre croissant ********\n");
 
 
  return 0;
}
   

int moyennePrix(logement tab[], int k){
    int a=0;
    int estimated_price;
    for (int i=0, i<k, i++){
        a=a+tab[i].price;
    }
    
    estimated_price = a/k;
    return estimated_price;
   
    }


    
