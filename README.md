# AieRobot


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


Ces paramètres peuvent être choisis au début par chaque joueur :


En effet, au démarrage, le jeu propose a chacun des 2 joueurs de personnaliser son robot avec différents skills :

#### Liste des skills possibles :

- capteur d'ultrasons, permettant au joueur d'élargir son point de vue par rapport a celui par défaut.

- Un choix d'armes : soit une arme qui tire des projectiles a 360° , mais de plus faible intensité, soit une arme qui tire dans
la direction choisie (donc il est plus dur de viser l'ennemi) mais qui impacte beaucoup plus la jauge de vie de l'autre joueur.
Ces armes sont respectivement : la tour et le bazooka.

- un moteur plus rapide : permet au robot d'aller legerement plus vite que l'ennemi.
