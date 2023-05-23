#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"
#include "utils.h"

// L'objectif est pour un nombre de ville en entrée petit <12, de parcourir tout les chemins possibles et de prendre le plus court

// complexité en n!
// un algo récursif semble adapté

void brute(data_t data, int* statut, int pos){
    float** adjacence=make_adjacence(data);

    if (villes_restantes(statut,data.nbr_ville)==0){
        return 1;
    }
    else {
        for (int k=0; k<villes_restantes(statut,data.nbr_ville); k++){
            float* dist=malloc(sizeof(float)*villes_restantes(statut,data.nbr_ville));
            
        }
    }
    // il faut stocker n! valeur de distance puis prendre le min.
    //un tableau de cette taille semble compliqué à créer et manipuler
    // il faudrait couper des parties de l'arbre (ensemble des chemins possibles)
}

