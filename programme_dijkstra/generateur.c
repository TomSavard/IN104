/*Tom Savard 4 avril 2023*/
// Ce fichier génère des graphes correspondant à l'étude et les enregistre sous le format txt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int plaisir_max=10;
int croisement_max=6;

int main(){

    // on stock les données dans un txt
    FILE *f;
    f = fopen("./data/test.txt", "w");
    if(f==NULL){
    printf("Erreur lors de l'ouverture d'un fichier\n");
    exit(1);}

    //on génère le nombre de croisement
    time_t t;
    t = time(NULL);
    srand(t);
    int n=2+rand()%croisement_max;//ici 2 croisements minimum

    // pour chaque croisement on génère un nombre de piste (avec nbr piste <= nbr croisement-1)
    int m=0;
    int nbr_piste[n];
    for (int xi=0; xi<n; xi++){
        int p=rand()%(n-1); //nbr de piste adjacente au croisement
        nbr_piste[xi]=p;
        m=m+p; 
    }
    fprintf(f,"%d %d\n",n,m);

    //puis on définit l'arrivée et le plaisir de chaque piste
    for(int xi=0; xi<n; xi++){
        int* existe=calloc(n,sizeof(int)); // vecteur pour l'existence de piste sur ce croisement
        for (int i=0; i<nbr_piste[xi]; i++){ //pour chaque piste partant de xi, on prend un croisement d'arriver yi et un plaisir fi
            existe[xi]=1; //une piste ne revient pas au même croisement
            int yi=rand()%(n);
            while (existe[yi]==1){
                yi=rand()%(n-1);}
            existe[yi]=1;
            int fi=2*(rand()%plaisir_max)-plaisir_max;
            fprintf(f,"%d %d %d\n",xi,yi,fi);
        }
    }
}