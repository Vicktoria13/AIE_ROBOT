## Bienvenue sur Aie Robot !


## But du jeu

Le jeu est le suivant :

C'est un jeu a 2 joueurs, chaque joueur étant représenté par un robot. Le but, inspiré du simple jeu Capture the Flag ! est donc de recupérer le drapeau
ennemi, et de revenir a son point de départ, avant l'ennemi. Un joueur perd si le second joueur remplit l'objectif avant lui et/ou meurt car n'a plus de points de vie.
 
Le jeu se déroule dans une carte 2D vu du dessus. Les robots sont controlables en direction via les touches du clavier.

Ainsi, leur but est de naviguer dans une carte 2D jusqu'au drapeau ennemi, et revenir a leur point de départ, tout cela en évitant les obstacles et ennemis :

- Les "murs", qui se dressent sur leur chemins

- des robots aimants : si le joueur est pris dans leur champ magnétique, alors ils sont bloqués pendant un certain temps.

- Les projectiles ennemis, lancés par le joueur adverse.

Détail important : chaque joueur n'a qu'une vision partielle de l'environnement, définie par défaut dans le jeu. 

Chaque robot :

- peut se déplacer dans la carte dans les endroits possibles

- peut tirer sur son ennemi pour lui faire perdre des points de vie.

- n'a qu'une vision partielle de l'environnement