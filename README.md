## Bienvenue sur Aie Robot !


## But du jeu

Le jeu est le suivant :

C'est un jeu a 2 joueurs, chaque joueur étant représenté par un robot. Le but, inspiré du simple jeu Capture the Flag ! est donc de recupérer le drapeau
ennemi avant l'ennemi. Un joueur perd si le second joueur remplit l'objectif avant lui et/ou meurt car n'a plus de points de vie.
 
Le jeu se déroule dans une carte 2D vu du dessus. Les robots sont controlables en direction via les touches du clavier.

Ainsi, leur but est de naviguer dans une carte 2D jusqu'au drapeau ennemi et le toucher, tout cela en évitant les obstacles et ennemis :

- Les "murs", qui se dressent sur leur chemins

- des robots aimants : si le joueur est pris dans leur champ magnétique, alors ils sont bloqués pendant un certain temps.


## Choix des options de chaque robot

Au démarrage du jeu, chaque joueur doit selectionner 2 options (= skills). Il a le choix entre :

- Capteur Ultrasons : cette option permet au robot de se doter d'un capteur a ultrasons , lui permettant donc d'avoir une plus grande
vision du plateau 2D.

- Capteur profondeur : cette option permet de donner au robot un capteur de type caméra 3D, lui permettant donc en plus de la vue 2D, d'obtenir une visualisation de la piste en profondeur.

- Vitesse rapide : Cette option donne au robot des moteurs puissants, lui permettant de se déplacer plus vite par rapport a son ennemi.


## Aide aux joueurs

De manière périodique, une lampe ponctuelle s'allumera de manière brève, laissant ainsi l'occasion aux deux joueurs de visulaiser le temps d'un court instant, ou se situe le drapeau ennemi !


## Controle du jeu

Chaque joueur maitrise 4 touches du clavier pour se déplacer dans l'environnement.

- les fleches directionnelles
- Les touches ZQSD

ainsi, les touches lattérales permettent de déplacer le champ de vision de chaque robot. Les touches du haut et bas, permettent respectivement d'avancer ou reculer selon la direction centrale du champ de vision.


## Installation et Mise en place du jeu Aie Robot !

Il est nécessaire d'installer la bibliothèque SFML , via la commande :
```sudo apt install```

