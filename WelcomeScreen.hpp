#ifndef WEELCOMESCREEN_HPP
#define WEELCOMESCREEN_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


class WelcomeScreen : public Screen{

    private:


        sf::Text Title;
        sf::Font fontTitle;
        /* le fond d"'écran de l'accueil */

        sf::RectangleShape fullBackground;
        sf::Texture backgroundTexture;


        /*liste de Boutons a afficher : polymorphisme */
        

        

        


    public:

        WelcomeScreen();
      

        ~WelcomeScreen();

        void drawScreens(sf::RenderWindow* window);

        void handleEvent();

        
        void ajouterBouton();



        // getters






        


     
};
#endif