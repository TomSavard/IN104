/*Tom SAVARD 11 avril*/
// Ce programme a pour objectif de parcourir le graph et de calculer le plaisir optimal 

// On a un plaisir pouvant être positif ou négatif. 
// Il faut être capable de détecter les cycles positifs ==> boucle infini

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct data{
    int nbr_croisements;
    int nbr_pistes;
    int** matrice;
};

struct data load(FILE *fichier){

    int croisement;
    int piste;
    int n;
    int read;
    struct data res;
    
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
    res.nbr_croisements=croisement;
    res.nbr_pistes=piste;
    res.matrice=matrice;

        
    return res;

}

void affiche_matrice(struct data donnée){

    for (int j=0; j<=donnée.nbr_pistes-1; ++j) {
               
        for (int i=0; i<=2; ++i) {
          
            printf("%d ",donnée.matrice[j][i]);
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
    affiche_matrice(load(fichier));
    fclose (fichier) ;
    //free(matrice);
    return 0;
}