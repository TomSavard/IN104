#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"
#include "dijkstra.h"
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

/*print de la matrice d'adjacence 
int** adjacence=make_adjacence(data);
for (int i=0; i<data.nbr_croisements;i++){
    affiche_list(adjacence[i],data.nbr_croisements);
}*/

//résultat du parcours de graph
dijkstra(data);
printf("\n");
//end = clock();
//execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
//printf("Temps d'exécution : %lfs\n",execution_time);
return 0;
}
