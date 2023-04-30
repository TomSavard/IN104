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

On sait appuyer sur la méthode de dijkstra que l'on a par la suite modifié pour s'adapter au problème.
Il retourne le plaisir maximal accessible ainsi que le chemin à suivre.

pour l'éxécuter:
- se placer dans le dossier "programme_dijkstra"
make
./main_dijkstra ../data.txt