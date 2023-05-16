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
int** make_adjacence(data_t data){
    int** adj_matrice=malloc(sizeof(int*)*data.nbr_ville);

    for (int i=0; i<data.nbr_ville; ++i) {  // on initialise la matrice avec des - inf pour les sommets non voisins
        adj_matrice[i]=malloc(sizeof(int)*data.nbr_ville);
        for (int j=0; j<=data.nbr_ville; ++j) {
        adj_matrice[i][j]=0;
        }
    }
    for (int p=0; p<data.nbr_ville; p++){ 
        adj_matrice[data.matrice[p][0]][data.matrice[p][1]]=data.matrice[p][2];
    }
    return adj_matrice;
} 

// affichage de la matrice (piqué à Alexandre)
void affiche_matrice(int** matrice, int nbr_ville){

    for (int i=0; i<=nbr_ville-1; ++i) {
               
        for (int j=0; j<=nbr_ville-1; ++j) {
          
            printf("%d ",matrice[i][j]);
        }
        printf("\n");    
    }
}

