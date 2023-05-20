#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>
#include "bellman.h"
#include "lecture.h"


/*pour créer la matrice d'adjacence à partir de la liste crée*/
int** create_matrice_adj(int** matrice, int croisement, int piste){
    int** adj_matrice = malloc(sizeof(int*) * croisement);

    for(int i = 0; i < croisement+1; i++){
        adj_matrice[i] = calloc(croisement, sizeof(int));
    }
   
    for(int i = 0; i < piste; i++){

        int u = matrice[i][0];
        int v = matrice[i][1];
        int w = matrice[i][2];

        adj_matrice[u][v] = w;
 
    }
    return adj_matrice;
    
}

void affiche_matrice(int** matrice, int croisement){

    for (int j=0; j<=croisement-1; ++j) {
               
        for (int i=0; i<=croisement-1; ++i) {
          
            printf("%d ",matrice[j][i]);
        }
        printf("\n");    
    }
}
