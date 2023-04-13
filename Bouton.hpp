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

    /* visuel */
    sf::RectangleShape formeBouton;
    sf::Text texteBouton;
    sf::Font police;
    sf :: Color couleurBouton;
    sf :: Color couleurTexte;
    sf :: Color couleurBoutonActif;
    sf :: Color hoverBouton; // couleur quand on passe la souris dessus


public:
    /* Constructeur */
    Bouton();


    Bouton(float pos_x, float pos_y, float width, float height, 
                 std::string texte, sf::Font police, sf::Color couleurBouton);
    ~Bouton();

   
    void Pressed();
    bool getIsActivated() const;
};




#endif