#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>
#include "matrice.h"
#include "lecture.h"
#include "bellman.h"

int main ( int argc , char* argv [] ) {

    if (argc!=2){
        printf("Wrong number of argument\n");
        return (1);
    }

    FILE *fichier = fopen (argv[1], "r") ;
    
    int croisement;
    fscanf (fichier, "%d", &croisement) ;
    int piste;
    fscanf (fichier, "%d", &piste) ;

    fclose (fichier) ;
 
    fopen (argv[1], "r") ;

    /*Pour afficher le nombre de pistes & croisements*/
    /*
    printf("\n");
    printf("nombre de pistes :%d\n",piste);
    printf("nombre de croisements :%d\n",croisement);
    printf("\n");*/
    //affiche_matrice(load(fichier),croisement, piste);

 
    int** matrice = load (fichier);
  
    int** matrice_adj = create_matrice_adj(matrice, croisement, piste);
    /*Pour afficher la matrice d'adjacence*/
    //printf("matrice d'adjacence du graphe:\n");

    
    //affiche_matrice(matrice_adj,croisement,piste);
    printf("\n");
    bellman_ford(matrice_adj,croisement);
    printf("\n");
    fclose (fichier) ;
    //free(matrice);
    
    return 0;
}