#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#include "matrice.h"
#include "lecture.h"

//permet la lecture des données contenues dans les fichiers .txt

data_t load(FILE *fichier){

    int nbr_ville; 
    int pos_ville;
    int read; // variable tampons pour la lecture
    data_t data;
    
    read = fscanf (fichier, "%d", &nbr_ville) ;

    if (read != 1) {
      fclose (fichier) ;
      printf("erreur de lecture\n");
    }

  // on rentre dans une matrice les données du .txt
  // on a nbr_ville ville
  // pour chaque ville on a les coordonées x y
    int** matrice=malloc(sizeof(int*)*nbr_ville);
    
    for (int i=0; i<=nbr_ville-1; ++i) {

        matrice[i]=malloc(sizeof(int)*2);

        for (int j=0; j<2; ++j) {
        read = fscanf (fichier, "%d", &pos_ville) ;
        matrice[i][j]=pos_ville;
        }
    }
    data.nbr_ville=nbr_ville;
    data.matrice=matrice;
    return data;
}
