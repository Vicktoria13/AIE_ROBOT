#include "Bouton.hpp"
#include <iostream>




/**
 * @brief Constructeur par défaut
 * Chaque objet Ecran contiendra une liste de boutons
 * 
 */



/**
 * Pour les constructeurs de Bouton : Les attribus de bouton sont eux meme des 
 * objets de la classe sf::Text, sf::Font, sf::Color
 * Faire his->texteBouton = sf::Text(texte, sf::Font(), 20);
 * est une mauvaise idée car
 * 
 * Il faut appeler directement leur propre constructeur via liste d'initialisation
 * Le but est d'appeler les consstructeurs des attributs qui sont des objets + dse types de bases
 * 
 * 
 * Synthaxe 
 * NomClase(liste parametres) 
 * : attribut1(mettre les parama), 
 *   attribut2(mettre les parama),
 * ...
 *   attributN(mettre les parama)
 * { // autres instructions}
 * 
 * voir https://youtu.be/otlZtRPeYDk
 */


Bouton::Bouton()
{
    std::cout << "creation d'un nouveau Bouton" << std::endl;

    this->isActivated = false;
}



/**
 * @brief Permet d'initialiser un bouton a une pose donnée
 */


Bouton::Bouton(float pos_x, float pos_y, float width, float height, 
                 std::string texte,  sf::Color couleurTexte,sf::Color couleurBouton) : texteBouton(texte, sf::Font(), 20), couleurTexte(couleurTexte), couleurBouton(couleurBouton) {

    
    // ici on met les autres attributs , qui sont des types de bases
    this->isActivated = false;

    this->pos_x = pos_x;
    this->pos_y = pos_y;

}


/**
 * @brief Permet de dessiner un bouton au centre dans la fenêtre
 * 
 * @param window 
 */
void Bouton::drawCenter(sf::RenderWindow& window){

    // cree une forme rectangulaire de bouton
    sf::RectangleShape MonBouton(sf::Vector2f(this->width, this->height));
    MonBouton.setFillColor(this->couleurBouton);

    sf::FloatRect windowBounds = window.getView().getViewport();

    // Centrer le bouton sur la fenêtre
    MonBouton.setPosition(windowBounds.left + windowBounds.width/2.0f - MonBouton.getSize().x/2.0f, 
                               windowBounds.top + windowBounds.height/2.0f - MonBouton.getSize().y/2.0f);

    window.draw(MonBouton);
    //window.draw(this->texteBouton);
}



void Bouton::drawAtGivenPosition(sf::RenderWindow& window){

    // cree une forme rectangulaire de bouton
    sf::RectangleShape MonBouton(sf::Vector2f(this->width, this->height));
    MonBouton.setFillColor(this->couleurBouton);

    // Centrer le bouton sur la fenêtre
    MonBouton.setPosition(this->pos_x, this->pos_y);
    window.draw(MonBouton);
}
/**
 * @brief Construct a new Bouton:: Pressed object
 * 
 */

void Bouton::HasBeenPressed(){
    this->isActivated = true;
}


bool Bouton::getIsActivated() const{
    return this->isActivated;
}


