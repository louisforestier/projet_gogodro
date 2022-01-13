# projet_gogodro

repère : coordonnée initale (0,0), x vers la droite, y vers le bas

poser : pose le crayon, ne prend aucun argument.
lever : lève le crayon, ne prend aucun argument.
bouger : a un argument, la coordonnée du point d'arrivée. Déplace le crayon. Ecrit si le crayon est posé.
couleur : a un argument, une couleur (noir, blanc, bleu, jaune, rouge, vert, orange, violet).
ligne : a deux arguments, coordonnée de départ et coordonnée d'arrivée. Déplace le crayon; Ecrit toujours.
rectangle : a trois arguments, coordonnée du point du coin supérieure gauche,la longueur (un entier), la largeur (un entier).

notation coordonnée : (x,y)

Pour passer du printer au drawer et inversement :
Dans parser.yy, fonction main (ligne 151). Si vous voulez le printer mettre en commentaire
les 2 ligne du drawer (lignes 155 et 156). Si vous voulez le drawer mettre en commentaire les 
lignes 157 et 158.

Il existe trois fichiers de test :
- "quadrillage.txt", dessine une grille.
- "quadrilatere_croix.txt", dessine un quadrilatère avec une croix en son centre.
- "test_for_erreur.txt", fichier devant arréter le programme car il y a une affectation sur la variable 
	d'itération de la boucle.
	
Améliorations :
- Ajout de l'instruction Point qui prend en argument les coordonnées de celui-ci.
- 