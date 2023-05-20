#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP


#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


class GameOverScreen : public Screen{

    private:

    public:
        GameOverScreen();

        ~GameOverScreen();

        void drawScreens(sf::RenderWindow *window);

        void handleEvent();

        void ajouterBouton();
};
#endif