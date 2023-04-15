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
 * @brief Construct a new Bouton:: Bouton object
 * 
 * @param pos_x position x du bouton
 * @param pos_y position y du bouton
 * @param width  largeur du bouton
 * @param height h hauteur du bouton
 * @param texte  texte du bouton
 * @param couleurBouton  couleur de fond du bouton
 */


Bouton::Bouton(float pos_x, float pos_y, float width, float height, 
                 std::string texte,  sf::Color couleurTexte,sf::Color couleurBouton) : texteBouton(texte, sf::Font(), 20), couleurTexte(couleurTexte), couleurBouton(couleurBouton) {

    
    // ici on met les autres attributs , qui sont des types de bases
    this->isActivated = false;

    this->pos_x = pos_x;
    this->pos_y = pos_y;

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


