#include "RobotPlayer.hpp"
#include <iostream>


// void DisplayEntite(sf::RenderWindow* window) doit être définie dans RobotPlayer.cpp


RobotPlayer::RobotPlayer(int x, int y)
{
    std::cout << "Construction du robot joueur" << std::endl;

    this->jaugeVie = 100;
    this->nb_munitions = 10;

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

RobotPlayer::~RobotPlayer()
{
    std::cout << "Destruction du robot joueur" << std::endl;
}



void RobotPlayer::DisplayEntite(sf::RenderWindow* window)
{
    window->draw(_sprite);
}