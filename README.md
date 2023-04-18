Le programme main_bellman.c:

dans ce programme on récupère les données du fichier data.txt pour les mettre dans une matrice d'adjacence
puis le programme utilise la méthode de parcourt de graphe de bellman ford (merci wikipédia) adaptée pour trouver le plus long chemin

il retourne respectivement:
-nombre de pistes
-nombre de croisements
-matrice d'adjacence du graphe
-la configuration associée selon la valeur du bonheur

pour l'éxécuter:

gcc main_bellman.c
./a.out data.txt