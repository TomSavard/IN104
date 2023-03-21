# Un jour au ski 

## Introduction 

L'objectif de ce projet d'IN104 est de mettre en application une grande partie des concepts que vous avez pu voir au cours de l'année. 
Le projet devra être réalisé en binome.

Le sujet se décompose en plusieurs parties, le rendu minimum attendu correspond aux briques notées obligatoires. Parmi les briques optionnelles vous pouvez choisir lesquelles vous souhaitez réalisées. 

En cas de problème de compréhension ou de code, n'hésitez pas à venir me voir au début de chaque séance où à m'envoyer un mail à marine.saintmezard@gmail.com en mettant [IN104] en objet. 

Le code doit-être écrit en C. Un seul projet doit être rendu par binôme. 

## Problème 

### Enoncé 
Après une dure semaine de partiels, vous partez en vacances bien méritées ! Vous voici arrivés dans une station de ski. C’est votre dernier jour, vous avez déjà testé toutes les pistes et vous savez quel plaisir chaque piste vous procure.

Vous disposez donc d’une carte avec l’ensemble des pistes et un entier qui représente le plaisir généré lorsque vous dévalez cette piste. Ce chiffre peut-être négatif si cette piste est ennuyeuse.

Les croisements des pistes sont numérotés et vous partez de celui qui parte le numéro 0.

Votre objectif est de déterminer le meilleur itinéraire possible pour la journée. Bien sur rien ne vous interdit de passer plusieurs fois sur la même piste et donc de ressentir un plaisir infini. Vous pouvez aussi décider que la meilleure solution est de ne pas skier !

Alors quel itinéraire empruntez vous ?

### Données d'entrées 
Les données d'entrées comprennent les informations suivantes : 
* $n$ : le nombre de croisements 
* $m$ : le nombre de pistes 
* pour chaque piste un entier $x_i \in [0,n-1]$, un entier $y_i \in [0,n-1]$ et un entier $f_i \in \mathbb{Z}$. Cela signifie que la piste $i$ part du croisement $x_i$, arrive au croisement $y_i$ et vous procure un plaisir $f_i$

### Sortie attendue

Vous afficherez la quantité maximale de plaisir que vous pouvez prendre. 
Si jamais cette quantité est infinie vous afficherez : "SKY IS THE LIMIT". 

### Exemples 
Exemple d'entrée
```
4 6 
0 1 -10 
1 2 5
2 3 -2 
3 4 -7
4 3 -2
```
Cela correspond au schéma suivant : 
![](https://markdown.data-ensta.fr/uploads/upload_c2aa1f2afbaaba4168f0a74c9717c44c.jpg)


Sortie attendue : 
```
SKY IS THE LIMIT 
```
En effet, le cycle 1,2,3 procure un plaisir de 6 points. Puisqu'on peut répéter ce cycle autant de fois qu'on le désire, il n'y a aucune limite au plaisir ! 

## Contraintes et critères d'évaluation

### Git 

**VOUS DEVEZ UTILISER GIT**, tout au long de votre projet. 

La première séance sera dédiée à la création d'un projet git. 
Un tutoriel est disponible dans le répertoire du projet. Prenez le temps de le suivre et de créer correctement votre projet. 
Les bonnes pratiques seront rappelées pendant la première séance, il est important de les suivre pour éviter des problèmes par la suite. 
La bonne utilisation de git et le caractère régulier des commits seront pris en compte pour l'évaluation. 

### Lisibilité du code 

Une attention particulière sera portée à la lisibilité du code. 
Votre code doit être lisible et facilement compréhensible par n'importe qui. 

Les bonnes pratiques seront rappelées pendant la première séance, il est important de les suivre. 
Quelques conseils : 
* donner des noms clairs à vos variables et vos fonctions 
* séparer le code en différents modules et créer à chaque fois un fichier .h
* séparer chaque module en fonction 
* commenter rapidement ce que fait chaque fonction 

### Tests unitaires 

Afin de s'assurer que votre code fonctionne correctement, il vous est demandé d'implémenter des tests unitaires. 
Le fonctionnement et les bonnes pratiques seront rappelés. 

### Performances du code 

La performance de votre code, en terme de temps d'exécution et d'utilisation de la mémoire sera un critère important. 

**Prenez le temps de comparer le temps d'exécution de vos différentes implémentations. Un graphique montrant l'évolution en commentant les différentes améliorations pendant la soutenance orale sera grandement valorisé.**
