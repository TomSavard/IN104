#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int** load(FILE *fichier){

    int croisement;
    int piste;
    int n;
    int read;
    
    read = fscanf (fichier, "%d", &croisement) ;
    read = fscanf (fichier, "%d", &piste) ;

    if (read != 1) {
      fclose (fichier) ;
      printf("erreur de lecture\n");
    }

    int** matrice=malloc(sizeof(int*)*piste);
    
    for (int i=0; i<=piste-1; ++i) {

        matrice[i]=malloc(sizeof(int)*3);

        for (int j=0; j<=2; ++j) {
        read = fscanf (fichier, "%d", &n) ;
        matrice[i][j]=n;
        }
    }
        
    return matrice;

}

void affiche_matrice(int** matrice, int croisement,int piste){

    for (int j=0; j<=piste-1; ++j) {
               
        for (int i=0; i<=2; ++i) {
          
            printf("%d ",matrice[j][i]);
        }
        printf("\n");    
    }
}

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
    printf("nombre de pistes :%d\n",piste);
    printf("nombre de croisements :%d\n",croisement);
    affiche_matrice(load(fichier),croisement, piste);
    fclose (fichier) ;
    //free(matrice);
    return 0;
}