/*Tom Savard 4 avril 2023*/
// Ce fichier génère des graphes correspondant à l'étude et les enregistre sous le format txt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int plaisir_max=10;
int croisement_max=6;
int main(){
    //on génère le nombre de croisement
    time_t t;
    t = time(NULL);
    srand(t);
    int n=rand()%croisement_max;
    printf("n=%d\n",n);

    int m=0;

    // pour chaque croisement on génère un nombre de piste (avec nbr piste <= nbr croisement-1)
    for (int xi=0; xi<n; xi++){
        int* existe=calloc(n,sizeof(int)); // vecteur pour l'existence de piste sur ce croisement
        int p=rand()%(n-1);//nbr de piste adjacente au croisement
        m=m+p;
        for (int i=0; i<p; i++){ //pour chaque piste partant de xi, on prend un croisement d'arriver yi et un plaisir fi
            existe[xi]=1; //une piste ne revient pas au même croisement
            int yi=rand()%(n);
            while (existe[yi]==1){
                yi=rand()%(n-1);}
            existe[yi]=1;
            int fi=rand()%plaisir_max;
            printf("xi=%d  yi=%d  fi=%d\n",xi,yi,fi);
    }}
    printf("m=%d\n",m);
}
