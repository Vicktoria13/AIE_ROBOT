#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP


#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


class GameOverScreen : public Screen{

    private:

        sf::Text Title;
        sf::Font fontTitle;
        /* le fond d"'écran de l'accueil */

        sf::RectangleShape fullBackground;
        sf::Texture backgroundTexture;
    
    public:
        GameOverScreen();

        ~GameOverScreen();

        void drawScreens(sf::RenderWindow *window);

        void handleEvent();

        void ajouterBouton();
};
#endif