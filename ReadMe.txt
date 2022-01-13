**************
Projet gogodro
**************

Louis Forestier & Clémentine Guillot

Arborescence
Tous les fichiers sont à la racine du projet (.hh, .cc, lexer, parser et les exemples).

Comment ça marche
-----------------
Compiler le projet avec "make".
Le projet utilise la bibliothèque Clmg-3.0.0.
Executer le projet, vous pouvez écrire vos propres fichiers ou utiliser ceux à votre disposition.
./gogodro < quadrilatere_croix.txt
Le projet utilise par défaut le drawer, le résultat sera sous forme d'image.
Si vous utiliser le printer, le résultat sera affiché dans la console sous forme d'instruction.

Pour passer du printer au drawer et inversement :
Dans parser.yy, fonction main (ligne 151). Si vous voulez le printer mettre en commentaire
les 2 ligne du drawer (lignes 155 et 156). Si vous voulez le drawer mettre en commentaire les 
lignes 157 et 158.

Il existe quatre fichiers de test :
- "quadrillage.txt", dessine une grille.
- "quadrilatere_croix.txt", dessine un quadrilatère avec une croix en son centre.
- "test_for_erreur.txt", fichier devant arrêter le programme car il y a une affectation sur la variable 
	d'itération de la boucle.
- "test_for_erreur_imbrique.txt", fichier davant arrêter le programme. Boucle imbriquée dans une autre
	affectation sur la première variable d'itération dans la deuxième boucle.

Grammaire
---------
Toutes les instructions doivent se terminer par un point virgule.

Le repère utilisé est sous forme (x,y), x vers la droite, y vers le bas. 
Les coordonnées initales sont (0,0) soit le coin supérieur gauche.

La première instruction est forcément la déclaration de la taille de l'image (même si utilisation du printer).
Exemple : taille x y ; 
x et y entiers, respectivement la largeur et la hauteur.

Autres instructions du programme :
poser : pose le crayon, ne prend aucun argument.
lever : lève le crayon, ne prend aucun argument.
bouger (x,y) : a un argument, la coordonnée du point d'arrivée. Déplace le crayon. Ecrit si le crayon est posé.
couleur enum_couleur : a un argument, une couleur (noir, blanc, bleu, jaune, rouge, vert, orange, violet).
ligne (x,y) (x,y) : a deux arguments, coordonnée de départ et coordonnée d'arrivée. Déplace le crayon. Ecrit toujours.
rectangle (x,y) l h : a trois arguments, coordonnée du point du coin supérieure gauche, la largeur (un entier), la hauteur (un entier).
point (x,y) : a un argument, les coordonnées du point. Déplace le crayon.

Il y a la possibilité de créer une variable et de lui affecter une valeur. 
On ne peut pas déclarer une variable sans lui donner une valeur.
Cela s'écrit sous la forme variable <- valeur.
Par exemple : i <- 2 + 3;

Les calculs :
On peut faire des calculs uniquement avec des entiers

	
Améliorations :
- Ajout de l'instruction Point qui prend en argument les coordonnées de celui-ci.
- Ajout de Taille pour lancer le drawer

Le drawer céer une image
=======
- Ajout de la taille de l'image au début du programme

