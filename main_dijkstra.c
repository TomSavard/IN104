/*Tom SAVARD 11 avril*/
// Ce programme a pour objectif de parcourir le graph et de calculer le plaisir optimal 

// On a un plaisir pouvant être positif ou négatif. 
// Il faut être capable de détecter les cycles positifs ==> boucle infini
//18 avril : boucle infini à cause du cycle positif. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

struct data_t{ // definition d'une structure permettant de stocker les données en entrée des graphes
    int nbr_croisements;
    int nbr_pistes;
    int** matrice;
};

struct data_t load(FILE *fichier){ //permet la lecture des données contenues dans les fichiers .txt

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

// permet de réorganiser les données sous la forme d'une matrice d'adjacence.
int** make_adjacence(struct data_t data){
    int** adjacence=malloc(sizeof(int*)*data.nbr_croisements);

    for (int i=0; i<data.nbr_croisements; ++i) {  // on initialise la matrice avec des - inf pour les sommets non voisins
        adjacence[i]=malloc(sizeof(int)*data.nbr_croisements);
        for (int j=0; j<=data.nbr_croisements; ++j) {
        adjacence[i][j]=INT_MIN;
        }
    }
    for (int p=0; p<data.nbr_pistes; p++){ 
        adjacence[data.matrice[p][0]][data.matrice[p][1]]=data.matrice[p][2];
    }
    return adjacence;
} 


int list_max_index(int* liste,int taille){ // fct qui renvoie l'indice du max de la liste 
    int max=liste[0];
    int max_index=0;
    for (int i=1; i<taille;i++){
        if (liste[i]>max){
            max=liste[i];
            max_index=i;
        }
    }
return max_index;
}


int traitement_fini(int* statut,int taille){ //test si il ne reste pas de sommet à traiter cad voisin d'un visité mais pas encore visité
    for (int i=0;i<taille;i++){
        if (statut[i]==1){
            return 0;
        }
    }
    return 1;}


void affiche_list(int* list, int taille){
    for(int i=0;i<taille;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}

int dijkstra(struct data_t data){
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
            return 0;
        }
    }

    // Trouver la valeur maximale de la distance
    int valeur_bonheur=0;
    for (int i = 0; i < data.nbr_croisements; i++) {
        if (distance[i] > valeur_bonheur) {
            valeur_bonheur = distance[i];
    }
    }

    //on libère les espaces mémoires
    free(distance);
    free(predecesseur);
    free(statut);
    free(adjacence);

    //on retourne le bonheur maximum du jours

    if (valeur_bonheur == 0) {
        printf("Le ski c'est pas fait pour moi (plaisir négatif :( )\n");
        return 0;
    }
     else {
        printf("La valeur maximale de bonheur est de %d\n", valeur_bonheur);
        return valeur_bonheur;
    }
}



int main ( int argc , char* argv [] ) {

    if (argc!=2){
        printf("Wrong number of argument\n");
        return (1);
    }

// lecture et résupération des données
FILE *fichier = fopen (argv[1], "r") ;
struct data_t data=load(fichier);

/*print de la matrice d'adjacence 
int** adjacence=make_adjacence(data);
for (int i=0; i<data.nbr_croisements;i++){
    affiche_list(adjacence[i],data.nbr_croisements);
}*/

//résultat du parcours de graph
int bonheur=dijkstra(data);

return 0;
}