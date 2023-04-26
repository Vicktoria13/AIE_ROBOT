#include "TourEnnemi.hpp"
#include <iostream>



/**
 * @brief Constructeur d'une Tour Ennemi:: Tour Ennemi object
 * 
 * @param x position x
 * @param y position y
 */
TourEnnemi::TourEnnemi(int x, int y) {

    std::cout << "Construction du tour ennemi" << std::endl;

    /* On charge la texture */
    if (!_texture.loadFromFile("TourEnnemie.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.5, 0.5);
    _sprite.setPosition(x, y);


}


/**
 * @brief Destructeur
 * 
 */
TourEnnemi::~TourEnnemi()
{
    std::cout << "Destruction du tour ennemi" << std::endl;
}


void TourEnnemi::DisplayTirs(sf::RenderWindow* window)
{
    //window->draw(_sprite);
}



void TourEnnemi::UpdateEvent(std::string NameIfPlayer){

}

void TourEnnemi::DisplayEntite(sf::RenderWindow* window)
{
    window->draw(_sprite);
    DisplayTirs(window);
}