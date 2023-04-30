// Ce fichier contient les fonctions concernant les matrices
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"


// création de la matrice d'adjacence à partir des data
int** make_adjacence(data_t data){
    int** adj_matrice=malloc(sizeof(int*)*data.nbr_croisements);

    for (int i=0; i<data.nbr_croisements; ++i) {  // on initialise la matrice avec des - inf pour les sommets non voisins
        adj_matrice[i]=malloc(sizeof(int)*data.nbr_croisements);
        for (int j=0; j<=data.nbr_croisements; ++j) {
        adj_matrice[i][j]=INT_MIN;
        }
    }
    for (int p=0; p<data.nbr_pistes; p++){ 
        adj_matrice[data.matrice[p][0]][data.matrice[p][1]]=data.matrice[p][2];
    }
    return adj_matrice;
} 

// affichage de la matrice (piqué à Alexandre)
void affiche_matrice(int** matrice, int croisement){

    for (int j=0; j<=croisement-1; ++j) {
               
        for (int i=0; i<=croisement-1; ++i) {
          
            printf("%d ",matrice[j][i]);
        }
        printf("\n");    
    }
}

