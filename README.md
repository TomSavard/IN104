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

Pour cette première tache, nous avons deux programmes:

        LE PROGRAMME main_bellman.c:
On stocke les données dans une __matrice d'adjacence__ puis on utilise la __méthode de Bellman Ford__ afin de trouver le chemin de plaisir maximal.

pour l'éxécuter:
1. se placer dans le dossier "programme_bellman"
2. make
3. ./main_bellman data.txt

        LE PROGRAMME main_dijkstra.c:
Ce programme propose le même principe que le précédent mais effectue un parcour de graphe de proche en proche pour le calcul du plaisir maximal. L'objectif étant de diminuer les temps de calculs. 

pour l'éxécuter:
1. se placer dans le dossier "programme_dijkstra"
2. make
3. ./main_dijkstra ../data.txt