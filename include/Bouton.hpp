#ifndef BOUTON_HPP
#define BOUTON_HPP

/**
 * @brief Construit des boutons cliquables 
 * 
 */

#include <SFML/Graphics.hpp>

class Bouton
{
private:
    /*permet de savoir si le bouton et survolé !*/
    bool isActivated;

    /* Permet de savoir si un bouton a été selectionné via la touche Entrée*/
    bool isPressed;

    /* position dans l'écran */

    float pos_x;
    float pos_y;

    /* taille dans l'écran */
    float width;
    float height;


    /* forme rectangulaire */
    sf::RectangleShape formeBouton;

    /* visuel du texte*/
    sf::Text texteBouton;
    std::string name;

    sf::Font police;
    

    /* couleur du fond du bouton */
    sf :: Color couleurBouton;
    sf::Color couleurBoutonActive;



public:
    /* Constructeur */

    Bouton();
    
    //Bouton(float pos_x, float pos_y, float width, float height, 
    //             std::string texte, sf::Color couleurBouton);

    Bouton(float x, float y, float width, float height, std::string text, sf::Color couleurBouton,bool Activate);
    /* Destructeur */
    ~Bouton(){};

    int EnterPressed();
    
    /*rendu dessin d'un Bouton*/
    void drawButton(sf::RenderWindow& window);
    void drawContoursBoutton(sf::RenderWindow& window);

    void changeStateButton();
    

    //getters
    int getPosX() const;
    int getPosY() const;
    bool getIsPressed() const;
    bool getIsActivated() const;

    std::string getName() const{
        return this->name;
    }

    //setters

    void setFlagActivated(bool flag);
    void setIsPressed(bool newIsPressed);


    
    

};




#endif