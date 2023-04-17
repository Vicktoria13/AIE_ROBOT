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

Bouton::Bouton(float x, float y, float width, float height, std::string text, sf::Color couleurBouton) 
    {

    std::cout << "creation d'un nouveau Bouton constructeur 1 : nom = " << text << std::endl;
    /* fond du bouton*/

    this->pos_x = x;
    this->pos_y = y;
    this-> width = width;
    this->height = height;

    
    // on charge une police
    
    if (!this->police.loadFromFile("ccwild.ttf"))
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

    this->isActivated = false;

    // couleur si je passe la souris : gris
    this->couleurMouseOn = sf::Color(100, 100, 100, 100);

}




/**
 * @brief Permet de dessiner un bouton au centre dans la fenêtre
 * 
 * @param window  fenêtre dans laquelle on dessine : par référence
 */

void Bouton::drawButton(sf::RenderWindow& window){
    window.draw(formeBouton);
    window.draw(this->texteBouton);
}



void Bouton::HasBeenPressed(){
    this->isActivated = true;
}


bool Bouton::getIsActivated() const{
    return this->isActivated;
}



/**
 * @brief Permet d'afficher les infos du bouton
 * 
 */
void Bouton::AfficheInfos() const{
    std::cout << "pos_x : " << this->pos_x << std::endl;
    std::cout << "pos_y : " << this->pos_y << std::endl;
    std::cout << "width : " << this->width << std::endl;
    std::cout << "height : " << this->height << std::endl;
    std::cout << "isActivated : " << this->isActivated << std::endl;

}


/**
 * @brief Permet de savoir si la souris est sur le bouton
 * 
 * @param x coordonnée x de la souris
 * @param y coordonnée y de la souris
 */
void Bouton::MouseAction(int x, int y){

    if (this->formeBouton.getGlobalBounds().contains(x,y)){
        this->HasBeenPressed();
        // On change la couleur du bouton
        this->formeBouton.setFillColor(this->couleurMouseOn);
    }

    else {
        // on garde la couleur originelle
        this->formeBouton.setFillColor(this->couleurBouton);

    }
}


/**
 * @brief detruit le  Bouton
 * 
 */
Bouton::~Bouton()
{
    std::cout << "Destruction d'un bouton" << std::endl;
}
