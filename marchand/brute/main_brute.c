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

// // Ceci permet d'afficher la data d'entrée
// for (int i=0; i<data.nbr_ville;i++){
//     affiche_list(data.matrice[i],2);
// }
// printf("\n");


float** adjacence=make_adjacence(data);
//print de la matrice d'adjacence 
// affiche_matrice(adjacence,data.nbr_ville);


int* statut=calloc(data.nbr_ville,sizeof(int)); // tableau de statut : 0 on n'est pas encore passé, 1 on est déjà passé.
statut[0]=1; //on débute à la ville 0 (les numéros sont ceux de l'ordre des villes dans le .txt)
int* predecesseur=malloc(sizeof(int)*data.nbr_ville);
for (int i=0; i<data.nbr_ville;i++){
    predecesseur[i]=-1;}
int pos=0; //on part de la ville 0

float distance=brute(data,statut,pos);



free(adjacence);
// end = clock();
// execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
return 0;
}
