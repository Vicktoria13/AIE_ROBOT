#include "../include/Drapeau.hpp"
#include <iostream>

Drapeau::Drapeau()
{

    std::cout << "Construction du d'un drapeau" << std::endl;

    /* On charge la texture */
    if (!_texture.loadFromFile("../Assets/flag.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(1, 1);

    this->estPositionne = false; // par defaut, lorsque l'on crée une tour ennemi, elle n'est pas positionnée
    this->isCollected = false; // par defaut, le drapeau n'est pas collecté encore


}

Drapeau::~Drapeau()
{
    std::cout << "Destruction du drapeau" << std::endl;
}


int Drapeau::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze){
    return 0;
}

void Drapeau::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>* maze )
{
    if (this->isCollected == false){
         window->draw(_sprite);}
}