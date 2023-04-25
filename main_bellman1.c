#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>

/*pour charger le fichier d'entrée dans une liste*/
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

/*pour créer la matrice d'adjacence à partir de la liste crée*/
int** create_matrice_adj(int** matrice, int croisement, int piste){
    int** adj_matrice = malloc(sizeof(int*) * croisement);

    for(int i = 0; i < croisement+1; i++){
        adj_matrice[i] = calloc(croisement, sizeof(int));
    }
   
    for(int i = 0; i < piste; i++){
printf("\n");
        int u = matrice[i][0];
        int v = matrice[i][1];
        int w = matrice[i][2];

        adj_matrice[u][v] = w;
 
    }
    return adj_matrice;
    
}

/*algorithme de bellman ford pour trouver le plus long chemin*/

int bellman_ford(int** matrice_adj, int croisement) {

    /*allocation mémoire pour le tableau contenant les valeurs de bonheur*/
    int* distance = malloc(sizeof(int) * croisement);
    /*initialisation du tableau à - l'infini*/
    int valeur_bonheur = INT_MIN;

    for (int i = 0; i < croisement; i++) {
        distance[i] = INT_MIN;
    }

    /*choix du noeud source*/
    distance[0] = 0;
    
    /*parcourt les croisements du graphe et calcule la distance max de chaque croisement jusqu'au croisement source*/
    for (int i = 0; i < croisement - 1; i++) {
    for (int u = 0; u < croisement; u++) {
    for (int v = 0; v < croisement; v++) {
            if (matrice_adj[u][v] != 0 && distance[u] != INT_MIN && distance[v] < distance[u] + matrice_adj[u][v]) {
                distance[v] = distance[u] + matrice_adj[u][v];
    }
    }
    }
    }

    // Vérifier s'il y a un cycle à poids positif
    for (int u = 0; u < croisement; u++) {
    for (int v = 0; v < croisement; v++) {
            if (matrice_adj[u][v] != 0 && distance[u] != INT_MIN && distance[v] < distance[u] + matrice_adj[u][v]) {
                printf("SKY IS THE LIMIT\n");
                return -1;
    }
    }
    }

    // Trouver la valeur maximale de la distance
    for (int i = 0; i < croisement; i++) {
        if (distance[i] > valeur_bonheur) {
            valeur_bonheur = distance[i];
    }
    }

    free(distance);

    if (valeur_bonheur == INT_MIN || valeur_bonheur <= 0) {
        printf("Vous ne pouvez pas skier aujourd'hui :(\n");
        return 0;
    }
     else {
        printf("La valeur maximale de bonheur est de %d\n", valeur_bonheur);
        return valeur_bonheur;
    }
}



void affiche_matrice(int** matrice, int croisement,int piste){

    for (int j=0; j<=piste-1; ++j) {
               
        for (int i=0; i<=piste-1; ++i) {
          
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
    printf("\n");
    printf("nombre de pistes :%d\n",piste);
    printf("nombre de croisements :%d\n",croisement);
    printf("\n");
    //affiche_matrice(load(fichier),croisement, piste);

 
    int** matrice = load (fichier);
  
    int** matrice_adj = create_matrice_adj(matrice, croisement, piste);

    printf("matrice d'adjacence du graphe:\n");

    affiche_matrice(matrice_adj,croisement,piste);
    printf("\n");
    bellman_ford(matrice_adj,croisement);
    printf("\n");
    fclose (fichier) ;
    //free(matrice);
    
    return 0;
}