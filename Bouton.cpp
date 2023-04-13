#include "Bouton.hpp"
#include <iostream>


/**
 * @brief Constructeur par défaut
 * 
 */
Bouton::Bouton()
{
    std::cout << "creation d'un nouveau Bouton" << std::endl;

    this->isActivated = false;
}


Bouton::Bouton(float pos_x, float pos_y, float width, float height, 
                 std::string texte, sf::Font police, sf::Color couleurBouton){


    //etat du bouton par défaut : non activé
    this->isActivated = false;

    // Rectangle :
    this->formeBouton = sf::RectangleShape(sf::Vector2f(width, height));

    // position du bouton
    this->formeBouton.setPosition(pos_x, pos_y);

    // couleur de fond du bouton
    this->formeBouton.setFillColor(couleurBouton);

    // police du texte
    this->police = police;

    // texte du bouton
    this->texteBouton = sf::Text(texte, this->police, 20);

    //couleur du texte
    this->texteBouton.setFillColor(sf::Color::Black);


}

/**
 * @brief Construct a new Bouton:: Pressed object
 * 
 */
void Bouton::Pressed(){
    this->isActivated = true;
}


bool Bouton::getIsActivated() const{
    return this->isActivated;
}

