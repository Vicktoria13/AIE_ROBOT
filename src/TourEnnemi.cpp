#include "../include/TourEnnemi.hpp"
#include <iostream>



/**
 * @brief Constructeur d'une Tour Ennemi:: Tour Ennemi. Valable a l'initialisation du jeu
 * 
 * @param x position x
 * @param y position y
 */
TourEnnemi::TourEnnemi() {

    /* On charge la texture */
    if (!_texture.loadFromFile("../Assets/RobotEnnemi.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.3, 0.3);
   // _sprite.setPosition(360, 180);

    this->estPositionne = false; // par defaut, lorsque l'on crée une tour ennemi, elle n'est pas positionnée

}


/**
 * @brief Destructeur
 * 
 */
TourEnnemi::~TourEnnemi()
{
}





int TourEnnemi::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze){
    return 0;
}

void TourEnnemi::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>* maze )
{
    window->draw(_sprite);
    // halo
    sf::CircleShape halo(50);
    halo.setFillColor(sf::Color(100, 150, 50, 100));
    halo.setPosition(_sprite.getPosition().x , _sprite.getPosition().y );
    window->draw(halo);
}