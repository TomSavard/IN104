#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"
#include "utils.h"



float glouton(data_t data){
    float** adjacence=make_adjacence(data);

    int* statut=calloc(data.nbr_ville,sizeof(int)); // tableau de statut : 0 on n'est pas encore passé, 1 on est déjà passé.
    statut[0]=1; //on débute à la ville 0 (les numéros sont ceux de l'ordre des villes dans le .txt)
    int* predecesseur=malloc(sizeof(int)*data.nbr_ville);
    for (int i=0; i<data.nbr_ville;i++){
        predecesseur[i]=-1;}

    int pos=0; //on part de la ville 0
    for (int k=1; k<data.nbr_ville; k++){ // on a n-1 villes à visiter
        float min=-1;
        int imin=-1;
        for (int i=1; i<data.nbr_ville; i++){
            if (statut[i]==0){
                if (min==-1){
                    imin=i;
                    min=adjacence[pos][i];
                }
                else if (adjacence[pos][i]<=min){
                    min=adjacence[pos][i];
                    imin=i;
                }
            }
        }
        predecesseur[imin]=pos;
        pos=imin;
        statut[pos]=1;
    }
    predecesseur[0]=pos;

free(statut);
//affiche_list(predecesseur,data.nbr_ville);


//récupération de la distance à partir de la matrice d'adjacence et des predecesseur

float distance=0;
pos=0;
for (int i=0; i<data.nbr_ville;i++){
    distance+=adjacence[pos][predecesseur[pos]];
    pos=predecesseur[pos];
}

free(predecesseur);
free(adjacence);
return distance;
}
