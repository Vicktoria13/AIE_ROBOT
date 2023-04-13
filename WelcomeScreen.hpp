#ifndef WEELCOMESCREEN_HPP
#define WEELCOMESCREEN_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>
class WelcomeScreen : public Screen{

    private:

        bool isRunning;
        sf::Sprite background;
        sf::Texture backgroundTexture;
        Bouton PlayBouton;
        Bouton QuitBouton;


    public:


        WelcomeScreen();
        ~WelcomeScreen();

};
#endif