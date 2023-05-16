#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>
#include "matrice.h"
#include "lecture.h"
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
        printf("0\n");
        return 0;
    }
     else {
        printf("%d\n", valeur_bonheur);
        return valeur_bonheur;
    }
}
