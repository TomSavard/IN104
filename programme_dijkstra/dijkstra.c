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


int traitement_fini(int* statut,int taille){ //test si il ne reste pas de sommet à traiter cad voisin d'un visité mais pas encore visité
    for (int i=0;i<taille;i++){
        if (statut[i]==1){
            return 0;
        }
    }
    return 1;}

int dijkstra(data_t data){
    //mise en place des tableaux pour l'algorithme 
    int** adjacence=make_adjacence(data);
    int* distance=malloc(sizeof(int)*data.nbr_croisements);
    int* predecesseur=malloc(sizeof(int)*data.nbr_croisements);
    int* statut=calloc(data.nbr_croisements,sizeof(int)); // 0 = non visité, 1 = voisin d'un visité mais reste à traiter, 2=visité 


    for (int i=0; i<data.nbr_croisements; i++){// initialisation du plaisir à -inf
        distance[i]=INT_MIN;
        predecesseur[i]=-1;}

    //On part du sommet 0
    distance[0]=0;
    statut[0]=1;

    // on ajoute ses voisins à la liste de traitement
    for (int i=0; i<data.nbr_croisements;i++){
        if (adjacence[0][i]!=INT_MIN){
            distance[i]=adjacence[0][i];
            predecesseur[i]=0;
            statut[i]=1;}
    }
    statut[0]=2; // 0 est traité

    /*
        printf("On traite le sommet 0\n");
        affiche_list(distance,data.nbr_croisements);
        affiche_list(predecesseur,data.nbr_croisements);
        affiche_list(statut,data.nbr_croisements);
        printf("\n");
    */

    int bugInf=data.nbr_croisements;
    int boucle=0;

    while(traitement_fini(statut,data.nbr_croisements)!=1){
        // il faut résussir à récupérer 'indice du sommet non marqué ayant le plus grand plaisir 
        int k=0;
        while (statut[k]!=1){
            k+=1;}

        for (int n=0; n<data.nbr_croisements;n++){
            if (statut[n]==1 && distance[n]>distance[k]){
                k=n;
            }
        }
        //printf("On traite le sommet %d\n",k);

        //on actualise les plaisirs
        for (int j=0; j<data.nbr_croisements;j++){
            if (adjacence[k][j]!=INT_MIN && distance[j]<distance[k]+adjacence[k][j]){
                distance[j]=distance[k]+adjacence[k][j];
                predecesseur[j]=k;
                statut[j]=1;
                }
        }
        /*affiche_list(distance,data.nbr_croisements);
        affiche_list(predecesseur,data.nbr_croisements);*/
        statut[k]=2; // fin du traitement du sommet k
        /*affiche_list(statut,data.nbr_croisements);
        printf("\n");*/
        boucle+=1;

        if (boucle==bugInf){
            printf("sky is the limit\n");
            //on libère les espaces mémoires
            free(distance);
            free(predecesseur);
            free(statut);
            free(adjacence);
            return 0;
        }
    }

    //Croisement d'arrivée
    int arrivée=list_max_index(distance,data.nbr_croisements);
    // Plaisir maximal
    int valeur_bonheur=distance[arrivée];
    //Récupération du chemin à suivre, on a les predecesseurs des croisements. Il faut donc remonter le chemin et non le descendre
    //int position=arrivée;
    // printf("Chemin à suivre : \n");
    // while (predecesseur[position]!=-1){
    //     printf("%d <-- ",position);
    //     position=predecesseur[position];
    // }
    // printf("0\n");

    //on libère les espaces mémoires
    free(distance);
    free(predecesseur);
    free(statut);
    free(adjacence);

    //on retourne le bonheur maximum du jours

    if (valeur_bonheur == 0) {
        //printf("Le ski c'est pas fait pour moi (plaisir négatif :( )\n");
        printf("0\n");
        return 0;
    }
     else {
        // printf("La valeur maximale de bonheur est de %d\n", valeur_bonheur);
        printf("%d\n", valeur_bonheur);
        return valeur_bonheur;
    }
}
