// Ce fichier contient les fonctions concernant les matrices
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"


// création de la matrice d'adjacence à partir des data
//il faut mettre la norme L2 pour calculer la matrice d'adjacence.
float** make_adjacence(data_t data){
    float** adj_matrice=malloc(sizeof(float*)*data.nbr_ville);

    for (int i=0; i<data.nbr_ville; ++i) {
        adj_matrice[i]=malloc(sizeof(float)*data.nbr_ville);
        for (int j=0; j<data.nbr_ville; ++j) {
            adj_matrice[i][j]=sqrt(pow(data.matrice[i][0]-data.matrice[j][0],2)+pow(data.matrice[i][1]-data.matrice[j][1],2));
        }
    }
    return adj_matrice;
} 

// affichage de la matrice (piqué à Alexandre)
void affiche_matrice(float** matrice, int nbr_ville){

    for (int i=0; i<=nbr_ville-1; ++i) {
               
        for (int j=0; j<=nbr_ville-1; ++j) {
          
            printf("%.0f ",matrice[i][j]);
        }
        printf("\n");    
    }
}

