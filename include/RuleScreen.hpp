#ifndef RULESCREEN_HPP
#define RULESCREEN_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


/**
 * @brief Permet d'afficher les règles du jeu
 * 
 */
class RuleScreen : public Screen{

    private:

        sf::RectangleShape fullBackground;
        sf::Texture backgroundTexture;
    
    public:
        RuleScreen();
        ~RuleScreen();

        void drawScreens(sf::RenderWindow *window);

        void handleEvent();

        void ajouterBouton();
};
#endif