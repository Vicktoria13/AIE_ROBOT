#include "RobotPlayer.hpp"
#include <iostream>


// void DisplayEntite(sf::RenderWindow* window) doit être définie dans RobotPlayer.cpp


RobotPlayer::RobotPlayer(int x, int y, int max_x, int max_y)
{
    std::cout << "Construction du robot joueur" << std::endl;

    this->jaugeVie = 100;
    this->nb_munitions = 10;
    this->nb_pixels_deplacement = 10;

    this->positionX = x;
    this->positionY = y;

    this->limite_deplacement_x = max_x;
    this->limite_deplacement_y = max_y;

    /* On charge la texture */
    if (!_texture.loadFromFile("robotPlayer.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.2, 0.2);
    _sprite.setPosition(x, y);

    this->ADrapeau = false;
    this->estPositionne=true;

    

}


/**
 * @brief Gere les evenements clavier et modifie les attributs du robot en consequence
 * 
 */

void RobotPlayer::KeyBoardEventARROW(){
    // joueur A

    /*********DEPLACEMENT******************************/

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

    CheckPosition();
}


/**
 * @brief Permet un controlle via les touches ZQSD
 * 
 */
void RobotPlayer::KeyBoardEventZQSD(){
    // joueur B

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

    CheckPosition();
    /*********TIR******************************/

}

/**
 * @brief Verifie si le robot est dans les limites du labyrinthe
 * 
 */

void RobotPlayer::CheckPosition(){
    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    
    if (this->_sprite.getPosition().x < 0){
        this->_sprite.setPosition(0, this->_sprite.getPosition().y);
    }

    if (this->_sprite.getPosition().x > this->limite_deplacement_x){
        this->_sprite.setPosition(this->limite_deplacement_x, this->_sprite.getPosition().y);
    }

    if (this->_sprite.getPosition().y < 0){
        this->_sprite.setPosition(this->_sprite.getPosition().x, 0);
    }

    if (this->_sprite.getPosition().y > this->limite_deplacement_y){
        this->_sprite.setPosition(this->_sprite.getPosition().x, this->limite_deplacement_y);
    }
}


/**
 * @brief Met a jour les attributs du robot en fonction des evenements
 * 
 * @param NameIfPlayer pour distinguer les joueurs et donc les evenements clavier
 */
void RobotPlayer::UpdateEvent(std::string NameIfPlayer){
    if (NameIfPlayer =="JoueurA"){
        KeyBoardEventZQSD();
    }
    else if (NameIfPlayer =="JoueurB"){
        KeyBoardEventARROW();
}
}


RobotPlayer::~RobotPlayer()
{
    std::cout << "Destruction du robot joueur" << std::endl;
}



void RobotPlayer::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15> )
{
    window->draw(_sprite);
}