#include "TourEnnemi.hpp"
#include <iostream>



/**
 * @brief Constructeur d'une Tour Ennemi:: Tour Ennemi. Valable a l'initialisation du jeu
 * 
 * @param x position x
 * @param y position y
 */
TourEnnemi::TourEnnemi() {

    std::cout << "Construction du tour ennemi" << std::endl;

    /* On charge la texture */
    if (!_texture.loadFromFile("Assets/TourEnnemie.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.5, 0.5);
   // _sprite.setPosition(360, 180);

    this->estPositionne = false; // par defaut, lorsque l'on crée une tour ennemi, elle n'est pas positionnée

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



int TourEnnemi::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze){
    return 0;
}

void TourEnnemi::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>* maze )
{
    window->draw(_sprite);
    DisplayTirs(window);
}