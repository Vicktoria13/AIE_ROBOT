#include "../include/RobotPlayer.hpp"
#include <math.h>
#include <iostream>




/**
 * @brief Constructeur du robot joueur
 * @param x position x
 * @param y position y

 * @param name nom robot
 */
RobotPlayer::RobotPlayer(int x, int y, std::string name,std::map<std::string, bool>* skills_joueur)
{
    std::cout << "Construction du robot joueur" << std::endl;

    //taille des skils
    this->positionX = x;
    this->positionY = y;


    /* On charge la texture */
    if (!_texture.loadFromFile("../Assets/robotPlayer.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.1, 0.1);
    _sprite.setPosition(x, y);

    

    this->ADrapeau = false;
    this->estPositionne=true;

    this->_name = name;

    // pour le raycasting : on remplis std::vector<Ray*> rayons
    this->angle_actuel = M_PI_2;
    this->variation_angle = 0.005;
    
    for (int i = 0; i < NB_RAYONS; i++){
        // les rayons 
        Ray* ray = new Ray(_sprite.getPosition().x, _sprite.getPosition().y, angle_actuel);
        this->rayons.push_back(ray);
        angle_actuel = angle_actuel+ this->variation_angle;

        // leurs longueurs
        this->longueur_rayon.push_back(0);
    }

    // on cree l'arme

    this->_arme = new Arme("bazooka");
   


   // facteur 2 pour le joueur rapide
   if (skills_joueur->at("Vitesse rapide") == true){
       this->vitesse_player = vitesse_deplacement;
   }

   else{
       this->vitesse_player = vitesse_deplacement/(2);
   }

   //capteur 3D pour la raycasting
   if (skills_joueur->at("Capteur 3D") == true){
       this->capteur3D = true;
   }

   else{
       this->capteur3D = false;
   }



    // lifeBAR

    this->_lifeBar = new LifeBar(this->_name);

    std::cout<<"fin construction robot joueur"<<std::endl;
  
}



/**
 * @brief Check les collisions joueur-murs-tours
 * 
 * @param maze le labyrinthe 2D
 * @param previous les coordonnees precedentes du joueur avant de se deplacer
 */
void RobotPlayer::checkCollision(std::array<std::array<int, 15>, 15>* maze, sf::Vector2f* previous){

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){

            // collision avec les elements statiques (murs + tours)
            if ((*maze)[i][j]==1 || (*maze)[i][j]==2 || (*maze)[i][j]==3 || (*maze)[i][j]==4){
                
                /* On cree le rectangle correspondant a un obstacle/Entite externe*/

                int case_size = 60;
                sf::RectangleShape rectangle(sf::Vector2f(case_size, case_size));
                rectangle.setPosition(j*case_size, i*case_size);


                // on cree un rectangle qui contient le sprite : si la hit box est trop petite, on la réduit

                 sf::RectangleShape spriteBound(sf::Vector2f(_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height));
                 spriteBound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);

                 sf::RectangleShape Cropped(sf::Vector2f(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2));
                 Cropped.setPosition(_sprite.getPosition().x + _sprite.getGlobalBounds().width / 4, _sprite.getPosition().y + _sprite.getGlobalBounds().height / 4);



                 if (Cropped.getGlobalBounds().intersects(rectangle.getGlobalBounds()) ){
                    // si c'est un drapeau, on le ramasse. Attention, on le ramasse qui si drapeau ennemi

                    if ((*maze)[i][j]==3 && this->_name=="JoueurB"){
                        this->ADrapeau = true;
                        std::cout<<"Joueur B a ramasse le drapeau"<<std::endl;
                    }

                    else if ((*maze)[i][j]==4 && this->_name=="JoueurA"){
                        this->ADrapeau = true;
                        std::cout<<"Joueur A a ramasse le drapeau"<<std::endl;
                    }

                    else if ((*maze)[i][j]==1){
                        this->_sprite.setPosition(previous->x, previous->y);
                    }

                    else if ((*maze)[i][j]==2){
                        // on perd une vie
                        this->_lifeBar->Lost();
                        this->_sprite.setPosition(previous->x, previous->y);
                    }
                 
                }
            }

            
        }
     }


  
}



/**
 * @brief Gere les evenements clavier et modifie les attributs du robot en consequence
 * 
 */

void RobotPlayer::KeyBoardEventARROW(std::array<std::array<int, 15>, 15>* maze){
    // joueur A
    /*********DEPLACEMENT******************************/

    sf::Vector2f previous;

    previous.x = this->_sprite.getPosition().x;
    previous.y = this->_sprite.getPosition().y;


    if (sf::Keyboard::isKeyPressed){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            this->angle_actuel = this->angle_actuel + vitesse_angulaire;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            this->angle_actuel = this->angle_actuel - vitesse_angulaire;
        }

        // on suit la direction du rayon central
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            this->_sprite.move(vitesse_player * cos(this->angle_actuel),
                               vitesse_player * sin(this->angle_actuel));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            this->_sprite.move(-vitesse_player * cos(this->angle_actuel),
                               -vitesse_player * sin(this->angle_actuel));
        }

        // si on atteint le bord de l'écran, on ne peut plus aller plus loin
        checkCollision(maze, &previous);

        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) ){
           this->_arme->addProjectile(this->_sprite.getPosition().x+this->_sprite.getGlobalBounds().width/2, 
                                       this->_sprite.getPosition().y+this->_sprite.getGlobalBounds().height/2, 
                                       this->angle_actuel);
        }
        
    }

     
}


/**
 * @brief Permet un controlle via les touches ZQSD
 * 
 */
void RobotPlayer::KeyBoardEventZQSD(std::array<std::array<int, 15>, 15>* maze){
    // joueur B

    sf::Vector2f previous;

    previous.x = this->_sprite.getPosition().x;
    previous.y = this->_sprite.getPosition().y;

    /*********DEPLACEMENT******************************/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->angle_actuel = this->angle_actuel + vitesse_angulaire;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->angle_actuel = this->angle_actuel - vitesse_angulaire;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->_sprite.move(vitesse_player * cos(this->angle_actuel),
                           vitesse_player * sin(this->angle_actuel));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->_sprite.move(-vitesse_player * cos(this->angle_actuel),
                           -vitesse_player * sin(this->angle_actuel));
    }

    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    checkCollision(maze, &previous);

    /*********TIR******************************/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ){
           this->_arme->addProjectile(this->_sprite.getPosition().x+this->_sprite.getGlobalBounds().width/2, 
                                       this->_sprite.getPosition().y+this->_sprite.getGlobalBounds().height/2, 
                                       this->angle_actuel);
        }

  

}



/**
 * @brief Met a jour les attributs du robot en fonction des evenements
 * 
 * @param NameIfPlayer pour distinguer les joueurs et donc les evenements clavier
 */
int RobotPlayer::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze){

    if (this->ADrapeau == false){

        if (NameIfPlayer == "JoueurA")
        {
            KeyBoardEventZQSD(maze);
        }
        else if (NameIfPlayer == "JoueurB")
        {
            KeyBoardEventARROW(maze);
        }

      

        return 0;
    }


    // retourne 1 si un joueur a gagné
    return 1;
    
}




/**
 * @brief Affiche les rayons du robot
 * 
 * @param maze le labyrinthe
 * @param rayon_centre le rayon central
 * @param window la fenetre de jeu
 */
void RobotPlayer::multi_rayon(std::array<std::array<int, 15>, 15>* maze,float rayon_centre,sf::RenderWindow* window)
{
    /*Affiche T rayon et met les distances dans D*/
    float alpha= rayon_centre - M_PI/2 + ANGLE_FOCAL;
    int i=0;
    sf::Color color;
    // choix de la couleur 
    if (this->_name == "JoueurA"){
        color.r=255;
        color.g=0;
        color.b=0;
        color.a=50;
    }

    else{
        color.r=0;
        color.g=0;
        color.b=255;
        color.a=50;
    }

    float fish=0;
    int val;

    // on vide le vecteur
    longueur_rayon.clear();


    for (auto& traits : this->rayons){
        // on update la position de chaque rayon
        traits->update(this->_sprite.getPosition().x+this->_sprite.getGlobalBounds().width/2, 
                        this->_sprite.getPosition().y+this->_sprite.getGlobalBounds().height/2);
        // on trace

        //longueur_rayon[i]=traits->rayon_unitaire(alpha,  maze, window, 60,color);
       //on push back
        val = traits->rayon_unitaire(alpha,  maze, window, 60,color);
        longueur_rayon.push_back(val);

        // contre l'effet fish eye
        fish = alpha - rayon_centre;
        if (fish < 0){
            fish += 2 * PI;
        }

        if (fish > 2 * PI){
            fish -= 2 * PI;
        }

        if (longueur_rayon[i] > 0){
            longueur_rayon[i] *= cos(fish);
            longueur_rayon[i]++;
        }

        i++;
        alpha = alpha +VARIATION_ANGLE;
    }
    //209 rayons
}



/**
 * @brief Affiche les projections de chaque rayons
 * 
 * @param window fenetre de rendu
 * @param haut hauteur du rectangle
 * @param larg largeur du rectangle
 * @param x coordonnee x du rectangle
 */
void RobotPlayer::draw3D_rect(sf::RenderWindow* window, int haut, int larg, int x, bool isAFlag) const{
    
    sf::RectangleShape rectangle(sf::Vector2f(larg+1, haut));

    if (this->_name=="JoueurA"){
        rectangle.setPosition(x + XX, CENTRE - haut / 2);
        if (isAFlag) {

            rectangle.setFillColor(sf::Color(100, 0, 0, 255));
        }
           
        else{
            rectangle.setFillColor(sf::Color(100, 149, 200, 255));
        }
        
    }

    else {
        rectangle.setPosition(x + XX, 3*CENTRE - haut / 2 +OFFSET_Y);

         if (isAFlag) {
            
            rectangle.setFillColor(sf::Color(100, 0, 0, 255));
        }
           
        else{
            rectangle.setFillColor(sf::Color(100, 50, 140 ,255));
        }

        
    }
    
    window->draw(rectangle);

}

/**
 * @brief dessine la fenetre de raycasting
 * 
 * @param window 
 */

void RobotPlayer::draw3D(sf::RenderWindow* window) const {

    if (capteur3D == true){
        int i;
        int hauteur = 0;
        int x = 0;

        bool FlagSeen;

        for (i = 0; i < NB_RAYONS; i++)
        {

            if (longueur_rayon[i] == -500)
            {
                FlagSeen = true;
                hauteur = HM - 300;
            }
            else if (longueur_rayon[i] != 0)
            {
                FlagSeen = false;

                hauteur = (int)(60 * HM) / (longueur_rayon[i]); // thales
                if (hauteur > HM)
                    hauteur = HM; // on ne peut pas dépasser la hauteur max

                x = i * LARGEUR;
            }
            x = i * LARGEUR;
            draw3D_rect(window, hauteur, LARGEUR, x - 1, FlagSeen);
        }
    }

}

/**
 * @brief Affiche le robot joueur + les rayons + les tirs + le rendu 3D
 * 
 * @param window la fenetre de rendu
 * @param maze le labyrinthe 2D
 */
void RobotPlayer::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>* maze )
{
    
    //window->clear();
    window->draw(_sprite);    
    multi_rayon(maze,angle_actuel,window);

    if(!_arme->estVide()){
        _arme->Tir(window,60);
   }


    draw3D(window);

    // on affiche la lifeBar

    this->_lifeBar->drawLifeBar(window);
   
}


/**
 * @brief Destucteur du robot joueur
 * 
 */

RobotPlayer::~RobotPlayer()
{
    for (auto& ray : this->rayons)
    {
        delete ray;
        
    } 
  
    longueur_rayon.clear();
    rayons.clear();
    if (_name == "JoueurB")
    {
        //delete _arme;
    }
    
    std::cout<<"fin destruction robot joueur"<<std::endl;
}

