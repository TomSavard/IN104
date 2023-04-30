#ifndef LOAD_H
#define LOAD_H

//il ne veut pas include matrice.h
typedef struct{
    int nbr_croisements;
    int nbr_pistes;
    int** matrice;
}data_t;

data_t load(FILE *fichier);

#endif