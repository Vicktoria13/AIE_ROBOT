/**
 * @file Bouton.cpp
 * @author Victoria
 * @brief 
 * @version 0.1
 * @date 2023-04-17
 * 
 * @copyright 
 * 
 */

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
 * @brief Constructeur surcharge. La couleur du bouton est passée en paramètre, celle de la souris est fixée
 * 
 * @param x coordonnée x du bouton
 * @param y coordonnée y du bouton
 * @param width largeur du bouton
 * @param height hauteur du bouton
 * @param text contenu du bouton
 * @param couleurBouton  couleur du bouton
 */

Bouton::Bouton(float x, float y, float width, float height, std::string text, sf::Color couleurBouton,bool Activate) 
    {

    /* fond du bouton*/

    this->pos_x = x;
    this->pos_y = y;
    this-> width = width;
    this->height = height;

    
    // on charge une police
    
    if (!this->police.loadFromFile("Assets/ccwild.ttf"))
    {
        std::cout << "erreur chargement police" << std::endl;
    } 
    

    formeBouton.setPosition(pos_x, pos_y);
    formeBouton.setSize(sf::Vector2f(this->width,this->height));
    formeBouton.setFillColor(couleurBouton);


    /* Texte du bouton +*/

    this->texteBouton.setFont(this->police);
    this->texteBouton.setFillColor(sf::Color::White);
    this->texteBouton.setCharacterSize(30);
    this->texteBouton.setString(text);
    
    // on centre le texte dans le bouton
    texteBouton.setPosition(formeBouton.getPosition() + 
    sf::Vector2f((formeBouton.getSize().x - texteBouton.getGlobalBounds().width) / 2.f, 
    (formeBouton.getSize().y - texteBouton.getGlobalBounds().height) / 2.f));


    couleurBoutonActive = sf::Color(100, 100, 100, 100);

    
    this->isActivated = Activate;
    this->isPressed = false; // faux par defaut
}










bool Bouton::getIsActivated() const{
    return this->isActivated;
}









/**
 * @brief Permet de dessiner les contours du bouton sur une fenêtre
 * Cette fonction dessine le bouton ET son contour !!
 * 
 * @param window fenêtre sur laquelle on dessine
 */
void Bouton::drawContoursBoutton(sf::RenderWindow& window){
   this->formeBouton.setOutlineThickness(7);
   this->formeBouton.setOutlineColor(sf::Color::Red);


   formeBouton.setFillColor(couleurBoutonActive);

   window.draw(this->formeBouton);
   window.draw(this->texteBouton);
}


/**
 * @brief Permet de dessiner un bouton + son texte
 * 
 * @param window  fenêtre dans laquelle on dessine : par référence
 */

void Bouton::drawButton(sf::RenderWindow& window){
    // on n'oublie pas de remettre le contour a 0 !!
    
    this->formeBouton.setFillColor(couleurBouton);
    this->formeBouton.setOutlineThickness(0);

    window.draw(formeBouton);
    window.draw(this->texteBouton);
}




int Bouton::getPosX() const{
    return this->pos_x;
}

int Bouton::getPosY() const{
    return this->pos_y;
}

void Bouton::setFlagActivated(bool flag){
    this->isActivated = flag;
}


/* Permet de savoir si le bouton a été survolé */
bool Bouton::getIsPressed() const{
     return this->isPressed;
}


/* Permet de savoir si le bouton a été pressé*/
void Bouton::setIsPressed(bool newIsPressed){
    this->isPressed = newIsPressed;
}



/**
 * @brief Permet de presser un bouton qui est activé
 * 
 * @return 1 si le bouton a été pressé, 0 sinon 
 */
int Bouton::EnterPressed(){
    if (this->isActivated ==true){
        this->isPressed = true;

        return 1;   
    }
    return 0;
    
}


