#ifndef WEELCOMESCREEN_HPP
#define WEELCOMESCREEN_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


class WelcomeScreen : public Screen{

    private:


      
        /* le fond d"'écran de l'accueil */

        sf::RectangleShape fullBackground;
        sf::Texture backgroundTexture;


    public:

        WelcomeScreen();
      

        ~WelcomeScreen();

        void drawScreens(sf::RenderWindow* window);

        void handleEvent();

        
        void ajouterBouton();



        


     
};
#endif
