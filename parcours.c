/*Tom SAVARD 11 avril*/
// Ce programme a pour objectif de parcourir le graph et de calculer le plaisir optimal 

// On a un plaisir pouvant être positif ou négatif. 
// Il faut être capable de détecter les cycles positifs ==> boucle infini

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct data_t{
    int nbr_croisements;
    int nbr_pistes;
    int** matrice;
};

struct data_t load(FILE *fichier){

    int croisement;
    int piste;
    int n;
    int read;
    struct data_t res;
    
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

void affiche_data(struct data_t data){

    for (int j=0; j<=data.nbr_pistes-1; ++j) {
               
        for (int i=0; i<=2; ++i) {
          
            printf("%d ",data.matrice[j][i]);
        }
        printf("\n");    
    }
}


int** make_adjacence(FILE* fichier){ // permet de réorganiser les données sous matrice d'adjacence.

struct data_t data=load(fichier); //récupère les données

int** adjacence=malloc(sizeof(int*)*data.nbr_croisements);

for (int i=0; i<data.nbr_croisements; ++i) {  // on initialise la matrice avec des - inf pour les sommets non voisins 
    adjacence[i]=malloc(sizeof(int)*data.nbr_croisements);
    for (int j=0; j<=data.nbr_croisements; ++j) {
    adjacence[i][j]=0;
    }
}

for (int p=0; p<data.nbr_pistes; p++){ 
    adjacence[data.matrice[p][0]][data.matrice[p][1]]=data.matrice[p][2];
}

return adjacence;} 


int main ( int argc , char* argv [] ) {

    if (argc!=2){
        printf("Wrong number of argument\n");
        return (1);
    }
FILE *fichier = fopen (argv[1], "r") ;

int** adjacence=make_adjacence(fichier);
}