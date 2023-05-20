# Projet Ski
Réalisé par __Alexandre Larry__ et __Tom Savard__ dans le cadre du cours IN104
## Description 
Ce projet réalisé en langage C étudie le parcours de graphe dans différentes situtations. Ici deux situations sont traitées.
## Partie 1 : À la recherche du plaisir
On prend en entrée un fichier .txt comportant :
* $n$ : le nombre de croisements 
* $m$ : le nombre de pistes 
* pour chaque piste un entier $x_i \in [0,n-1]$, un entier $y_i \in [0,n-1]$ et un entier $f_i \in \mathbb{Z}$. Cela signifie que la piste $i$ part du croisement $x_i$, arrive au croisement $y_i$ et vous procure un plaisir $f_i$

L'objectif est alors, en partant du croisement 0, de déterminer le plaisir maximal atteignable.

Pour cette première tache, nous avons deux programmes:

---
###            Le programme main_bellman.c:
On stocke les données dans une __matrice d'adjacence__ puis on utilise la __méthode de Bellman Ford__ afin de trouver le chemin de plaisir maximal.

pour l'éxécuter:
1. se placer dans le dossier "programme_bellman"
2. make
3. ./main_bellman data.txt

---
###            Le programme main_dijkstra.c:
Ce programme propose le même principe que le précédent mais effectue un parcour de graphe de proche en proche pour le calcul du plaisir maximal. L'objectif étant de diminuer les temps de calculs. 

pour l'éxécuter:
1. se placer dans le dossier "programme_dijkstra"
2. make
3. ./main_dijkstra ../data.txt

----------
## Partie 2 : Le voyageur de commerce
L'objectif est maintenant de passer une et unique fois par chaque sommet et de revenir à la position de départ en parcourant une distance minimale.

Fichier d'entrée : 
- sur la première ligne le nombre de sommets noté n
- sur les n lignes suivantes les coordonnées de chacune des villes

Hypothèses : 
- On étudie un graphe complet, c'est à dire qu'entre toutes les villes i et j il existe une route non orientée.
- On utilise la norme L2 pour calculer des distances

Solutions proposées :
Ici le problème n'est plus P mais NP-Complet. Il n'y a pas de solution "parfaite". Il faut donc trouver un compromis entre précision et temps de calculs.

Pour ce faire nous avons mis en place deux solutions simples permettant de comprendre les enjeux.

---
### Algorithme glouton

Cet algorithme fonctionne "sans mémoire" et recherche à chaque itération l'optimal local. Ceci permet d'avoir une réponse parfois juste mais qui risque d'être mauvaise dans certains cas. En revanche le temps de calculs est très faible.
Ainsi cette méthode favorise le temps de calculs à la précision.

---
### Algorithme brute force

À l'opposé de la méthode gloutonne se trouve la brute force. Ici on va calculs toutes les combinaisons imaginables afin de déterminer la solution optimale pour le voyageur.
Ainsi cette méthode favorise la précision au détriment du temps de calculs qui lui explose dès la dizaine de villes atteintes. 