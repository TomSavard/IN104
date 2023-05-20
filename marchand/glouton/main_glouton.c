#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"
#include "utils.h"
#include "glouton.h"


int main ( int argc , char* argv [] ) {

    if (argc!=2){
        printf("Wrong number of argument\n");
        return (1);
    }
    clock_t start, end;
    double execution_time;
    start = clock();

// lecture et récupération des données
FILE *fichier = fopen (argv[1], "r") ;
data_t data=load(fichier);

float distance=glouton(data);

//print de la matrice d'adjacence 
// float** adjacence=make_adjacence(data);
// affiche_matrice(adjacence,data.nbr_ville);
// free(adjacence);
end = clock();
execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
printf("%f\n",distance);
printf("Temps d'exécution : %f\n",execution_time);
return 0;
}
