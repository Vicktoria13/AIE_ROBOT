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

/*
Bouton::Bouton(float pos_x, float pos_y, float width, float height, 
                 std::string texte, sf::Color couleurBouton) : texteBouton(texte, sf::Font(), 20), couleurBouton(couleurBouton) {

    
    // ici on met les autres attributs , qui sont des types de bases
    this->isActivated = false;

    this->pos_x = pos_x;
    this->pos_y = pos_y;

}
*/

Bouton::Bouton(float x, float y, float width, float height, std::string text, sf::Color couleurBouton){

    /* fond du bouton*/
    formeBouton.setPosition(sf::Vector2f(x,y));
    formeBouton.setSize(sf::Vector2f(width,height));
    formeBouton.setFillColor(couleurBouton);



    /* Texte du bouton +*/
    texteBouton.setString(text);
    texteBouton.setFillColor(sf::Color::Black);
    texteBouton.setCharacterSize(30);
    texteBouton.setPosition(
        formeBouton.getPosition().x + (formeBouton.getGlobalBounds().width/2.f) - texteBouton.getGlobalBounds().width/2.f,
        formeBouton.getPosition().y + (formeBouton.getGlobalBounds().height/2.f) - texteBouton.getGlobalBounds().height/2.f);
    
    
    
}




/**
 * @brief Permet de dessiner un bouton au centre dans la fenêtre
 * 
 * @param window 
 */

void Bouton::drawButton(sf::RenderWindow& window){
    window.draw(formeBouton);
    window.draw(texteBouton);
}



void Bouton::HasBeenPressed(){
    this->isActivated = true;
}


bool Bouton::getIsActivated() const{
    return this->isActivated;
}


