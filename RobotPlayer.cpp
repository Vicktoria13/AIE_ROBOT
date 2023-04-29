#include "RobotPlayer.hpp"
#include <math.h>
#include <iostream>


// void DisplayEntite(sf::RenderWindow* window) doit être définie dans RobotPlayer.cpp


RobotPlayer::RobotPlayer(int x, int y, int max_x, int max_y, std::string name)
{
    std::cout << "Construction du robot joueur" << std::endl;

    this->jaugeVie = 100;
    this->nb_munitions = 10;
    this->nb_pixels_deplacement = 12;

    this->positionX = x;
    this->positionY = y;

    this->limite_deplacement_x = max_x;
    this->limite_deplacement_y = max_y;

    /* On charge la texture */
    if (!_texture.loadFromFile("Assets/robotPlayer.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.13, 0.13);
    _sprite.setPosition(x, y);

    

    this->ADrapeau = false;
    this->estPositionne=true;

    this->_name = name;

    // pour le raycasting : on remplis std::vector<Ray*> rayons
    this->angle_actuel = 0;


    this->variation_angle = 0.001;


    this->angle = M_PI_2;
    for (int i = 0; i < 100; i++){
        Ray* ray = new Ray(_sprite.getPosition().x, _sprite.getPosition().y, angle);
        this->rayons.push_back(ray);
        angle = angle+ this->variation_angle;
    }

    

    

}



/**
 * @brief Check les collisions joueur-murs-tours
 * 
 * @param maze le labyrinthe 2D
 * @param previous les coordonnees precedentes du joueur avant de se deplacer
 */
void RobotPlayer::checkCollision(std::array<std::array<int, 15>, 15> maze, sf::Vector2f* previous){

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){

            // collision avec les elements statiques (murs + tours)
            if (maze[i][j]==1 || maze[i][j]==2 || maze[i][j]==3 || maze[i][j]==4){
                
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

                    if (maze[i][j]==3 && this->_name=="JoueurB"){
                        this->ADrapeau = true;
                        std::cout<<"Joueur B a ramasse le drapeau"<<std::endl;
                    }

                    else if (maze[i][j]==4 && this->_name=="JoueurA"){
                        this->ADrapeau = true;
                        std::cout<<"Joueur A a ramasse le drapeau"<<std::endl;
                    }

                    else if (maze[i][j]==2  || maze[i][j]==1){
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

void RobotPlayer::KeyBoardEventARROW(std::array<std::array<int, 15>, 15> maze){
    // joueur A
    /*********DEPLACEMENT******************************/

    sf::Vector2f previous;

    previous.x = this->_sprite.getPosition().x;
    previous.y = this->_sprite.getPosition().y;

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->_sprite.move(-nb_pixels_deplacement,0);
     }
     
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){       
        this->_sprite.move(nb_pixels_deplacement,0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){  
        this->_sprite.move(0,-nb_pixels_deplacement);      
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){        
        this->_sprite.move(0,nb_pixels_deplacement);     
    }

    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    checkCollision(maze, &previous);
}


/**
 * @brief Permet un controlle via les touches ZQSD
 * 
 */
void RobotPlayer::KeyBoardEventZQSD(std::array<std::array<int, 15>, 15> maze){
    // joueur B

    sf::Vector2f previous;

    previous.x = this->_sprite.getPosition().x;
    previous.y = this->_sprite.getPosition().y;

    /*********DEPLACEMENT******************************/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this->_sprite.move(-nb_pixels_deplacement,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->_sprite.move(nb_pixels_deplacement,0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        this->_sprite.move(0,-nb_pixels_deplacement);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->_sprite.move(0,nb_pixels_deplacement);

    }

    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    checkCollision(maze, &previous);
    /*********TIR******************************/

}



/**
 * @brief Met a jour les attributs du robot en fonction des evenements
 * 
 * @param NameIfPlayer pour distinguer les joueurs et donc les evenements clavier
 */
int RobotPlayer::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15> maze){

    if (this->ADrapeau == false){

        if (NameIfPlayer == "JoueurA")
        {
            KeyBoardEventZQSD(maze);
        }
        else if (NameIfPlayer == "JoueurB")
        {
            KeyBoardEventARROW(maze);
        }

        // On met a jour la position de chaque ray
        for (auto& ray : this->rayons)
        {
            // on met a jour la position du rayon, qui est la meme que celle du robot
            ray->update(this->_sprite.getPosition().x, this->_sprite.getPosition().y);
        }

        return 0;
    }


    // retourne 1 si un joueur a gagné
    return 1;
    
}



/**
 * @brief Destucteur du robot joueur
 * 
 */

RobotPlayer::~RobotPlayer()
{
    std::cout << "Destruction du robot joueur" << std::endl;
}



/**
 * @brief Affiche le robot joueur
 * 
 * @param window la fenetre de rendu
 * @param maze le labyrinthe 2D
 */
void RobotPlayer::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15> maze )
{
    int facteur_retrecicement =2 ;
    window->draw(_sprite);

    /*ray*/
    int nb_ray = 0;
    for (auto& traits : this->rayons)
    {
        traits->rayon_unitaire(traits->getAngle(),maze,window, 60);
        nb_ray++;
    }
    std::cout<<"nb ray : "<<nb_ray<<std::endl;

    // on trace un cercle autour de la position du sprite
    sf::CircleShape cercle(5);
    cercle.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
    cercle.setFillColor(sf::Color(255,0,0,128));

    window->draw(cercle);


    
    sf::RectangleShape spriteBound(sf::Vector2f(_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height));
    spriteBound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
    spriteBound.setFillColor(sf::Color(255,0,0,128));

    window->draw(spriteBound);

    /*

    sf::RectangleShape Cropped;
    Cropped.setSize(sf::Vector2f(_sprite.getGlobalBounds().width/facteur_retrecicement, _sprite.getGlobalBounds().height/facteur_retrecicement));
    // il faut le centrer, donc on prend la moitié de la taille du sprite
    Cropped.setPosition(_sprite.getPosition().x + _sprite.getGlobalBounds().width/4, _sprite.getPosition().y + _sprite.getGlobalBounds().height/4);
    Cropped.setFillColor(sf::Color(0,255,0,50));

    window->draw(Cropped);
    */

   
}