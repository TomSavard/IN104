# Projet Ski
Réalisé par Alexandre Larry et Tom Savard
## Description 
Ce projet réalisé en langage C étudie le parcours de graphe dans différentes situtations. Ici deux situations sont traitées.
### Partie 1
On prend en entrée un fichier .txt comportant :
* $n$ : le nombre de croisements 
* $m$ : le nombre de pistes 
* pour chaque piste un entier $x_i \in [0,n-1]$, un entier $y_i \in [0,n-1]$ et un entier $f_i \in \mathbb{Z}$. Cela signifie que la piste $i$ part du croisement $x_i$, arrive au croisement $y_i$ et vous procure un plaisir $f_i$

L'objectif est alors, en partant du croisement 0, de déterminer le plaisir maximal atteignable.
        
        
        
        
        LE PROGRAMME main_bellman.c:

dans ce programme on récupère les données du fichier *.txt pour les mettre dans une matrice d'adjacence
puis le programme utilise la méthode de parcourt de graphe de bellman ford (merci wikipédia) adaptée pour trouver le plus long chemin

il retourne respectivement:
(-nombre de pistes
-nombre de croisements
-matrice d'adjacence du graphe)
-la configuration associée selon la valeur du bonheur

pour l'éxécuter:
-se placer dans le dossier "programme_bellman"
make
./main_bellman data.txt




        LE PROGRAMME main_dijkstra.c:

dans ce programme on récupère les données du fichier data.txt pour les mettre dans une matrice d'adjacence.

On s'est appuyé sur la méthode de dijkstra que l'on a par la suite modifié pour s'adapter au problème.
Il retourne le plaisir maximal accessible ainsi que le chemin à suivre.

pour l'éxécuter:
- se placer dans le dossier "programme_dijkstra"

make

./main_dijkstra ../data.txt