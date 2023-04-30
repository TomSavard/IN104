#ifndef MATRICE_H
#define MATRICE_H

// sytructure pour le stockage des données
typedef struct{
    int nbr_croisements;
    int nbr_pistes;
    int** matrice;
}data_t;

int** make_adjacence(data_t data);

void affiche_matrice(int** matrice, int croisement,int piste);

#endif