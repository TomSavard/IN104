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

int** make_adjacence(struct data_t data){ // permet de réorganiser les données sous la forme d'une matrice d'adjacence.
    int** adjacence=malloc(sizeof(int*)*data.nbr_croisements);

    for (int i=0; i<data.nbr_croisements; ++i) {  // on initialise la matrice avec des - inf pour les sommets non voisins (pour le moment 0 car bug sinon)
        adjacence[i]=malloc(sizeof(int)*data.nbr_croisements);
        for (int j=0; j<=data.nbr_croisements; ++j) {
        adjacence[i][j]=0;
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
/* c'est un vrai bazarre sans introduire de liste chainée 
int ExistChemin(int** adjacence,int nbr_croisements,int u, int v){
    int* visite=calloc(nbr_croisements,sizeof(int));
    int* file =malloc(sizeof(int)*nbr_croisements);

    while (test==0 && k<nbr_croisements){
        


    }
}
*/



int main ( int argc , char* argv [] ) {

    if (argc!=2){
        printf("Wrong number of argument\n");
        return (1);
    }


FILE *fichier = fopen (argv[1], "r") ;
struct data_t data=load(fichier); //récupère les données
int** adjacence=make_adjacence(data);


// Mise en place de l'algorithme de dijkstra
// On a un tableau de distance, un de prédécesseur et un de statut.
int* distance=malloc(sizeof(int)*data.nbr_croisements);
int* predecesseur=malloc(sizeof(int)*data.nbr_croisements);
int* statut=calloc(data.nbr_croisements,sizeof(int)); // 0 = non visité, 1 = voisin d'un visité mais reste à traiter, 2=visité 

for (int i=0; i<data.nbr_croisements; i++){
    distance[i]=-INFINITY;
    predecesseur[i]=-1;}
//On part du sommet 0
distance[0]=0;
statut[0]=1;
for (int i=0; i<data.nbr_croisements;i++){
    if (adjacence[0][i]!=0){
        distance[i]=adjacence[0][i];
        predecesseur[i]=0;
        statut[i]=1;}
}
statut[0]=2;

while(traitement_fini(statut,data.nbr_croisements)!=1){
// il faut résussir à récupérer 'indice du sommet non marqué ayant la plus grande distance 
    int k=1;
    for (int n=0; n<data.nbr_croisements;n++){
        if (statut[n]==1 && distance[n]>distance[k]){
            k=n;
        }
    }
    for (int j=0; j<data.nbr_croisements;j++){
        if (adjacence[k][j]!=0){
            if (distance[j]<distance[k]+adjacence[k][j]){
                distance[j]=distance[k]+adjacence[k][j];
                predecesseur[j]=k;
            }
            statut[j]=1;
        }
    }
    affiche_list(distance,data.nbr_croisements);
    affiche_list(predecesseur,data.nbr_croisements);
    affiche_list(statut,data.nbr_croisements);
    printf("\n");

    statut[k]=2;
}
}