// contient diverses fonctions pouvant servir


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


void affiche_list(int* list, int taille){
    for(int i=0;i<taille;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
}
