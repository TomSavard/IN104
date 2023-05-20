#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"
#include "utils.h"



int main ( int argc , char* argv [] ) {

    if (argc!=2){
        printf("Wrong number of argument\n");
        return (1);
    }
    // clock_t start, end;
    // double execution_time;
    // start = clock();

// lecture et résupération des données
FILE *fichier = fopen (argv[1], "r") ;
data_t data=load(fichier);

// Ceci permet d'afficher la data d'entrée
for (int i=0; i<data.nbr_ville;i++){
    affiche_list(data.matrice[i],2);
}
printf("\n");

//print de la matrice d'adjacence 
float** adjacence=make_adjacence(data);
affiche_matrice(adjacence,data.nbr_ville);

free(adjacence);
// end = clock();
// execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
return 0;
}
