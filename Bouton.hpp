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



    /* visuel du texte*/
    sf::Text texteBouton;
    sf :: Color couleurTexte;
    

    /* couleur du fond du bouton */
    sf :: Color couleurBouton;


public:
    /* Constructeur */

    Bouton();
   Bouton(float pos_x, float pos_y, float width, float height, std::string texte,  sf::Color couleurTexte,sf::Color couleurBouton);

    /* Destructeur */
    ~Bouton();

   
    void HasBeenPressed();
    bool getIsActivated() const;
};




#endif