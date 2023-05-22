// contient diverses fonctions pouvant servir
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"
#include "utils.h"

int list_max_index(int* liste,int taille){ // fct qui renvoie l'indice du max de la liste 
    int max=liste[0];
    int max_index=0;
    for (int i=1; i<taille;i++){
        if (liste[i]>max){
            max=liste[i];
            max_index=i;
        }
    }
return max_index;
}


void affiche_list(int* list, int taille){
    for(int i=0;i<taille;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}


int villes_restantes(int* statut,int taille){
    int compteur=0;
    for (int i=0;i<taille;i++){
        if (statut[i]==0){
            compteur+=1;
            }
    }
return compteur;
}
