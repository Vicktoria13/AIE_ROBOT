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
    bool isActivated;

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
    sf::Font police;
    

    /* couleur du fond du bouton */
    sf :: Color couleurBouton;
    sf::Color couleurMouseOn;


public:
    /* Constructeur */

    Bouton();
    
    //Bouton(float pos_x, float pos_y, float width, float height, 
    //             std::string texte, sf::Color couleurBouton);

    Bouton(float x, float y, float width, float height, std::string text, sf::Color couleurBouton);
    /* Destructeur */
    ~Bouton();

    /*rendu dessin d'un Bouton*/
    void drawButton(sf::RenderWindow& window);


    void AfficheInfos() const;
   
    void HasBeenPressed();
    bool getIsActivated() const;

    void MouseAction(int x, int y);

};




#endif