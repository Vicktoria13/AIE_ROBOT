#include "RobotPlayer.hpp"
#include <iostream>


// void DisplayEntite(sf::RenderWindow* window) doit être définie dans RobotPlayer.cpp


RobotPlayer::RobotPlayer(int x, int y)
{
    std::cout << "Construction du robot joueur" << std::endl;

    this->jaugeVie = 100;
    this->nb_munitions = 10;
    this->nb_pixels_deplacement = 10;

    this->positionX = x;
    this->positionY = y;

    /* On charge la texture */
    if (!_texture.loadFromFile("robotPlayer.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.2, 0.2);
    _sprite.setPosition(x, y);

    

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
    std::cout<<"ZQSD"<<std::endl;
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

void RobotPlayer::CheckPosition(){
    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    if (this->_sprite.getPosition().x < 0){
        this->_sprite.setPosition(0, this->_sprite.getPosition().y);
    }

    if (this->_sprite.getPosition().x > 800){
        this->_sprite.setPosition(800, this->_sprite.getPosition().y);
    }

    if (this->_sprite.getPosition().y < 0){
        this->_sprite.setPosition(this->_sprite.getPosition().x, 0);
    }

    if (this->_sprite.getPosition().y > 600){
        this->_sprite.setPosition(this->_sprite.getPosition().x, 600);
    }
}

RobotPlayer::~RobotPlayer()
{
    std::cout << "Destruction du robot joueur" << std::endl;
}



void RobotPlayer::DisplayEntite(sf::RenderWindow* window)
{
    window->draw(_sprite);
}