#ifndef WEELCOMESCREEN_HPP
#define WEELCOMESCREEN_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


class WelcomeScreen : public Screen{

    private:


   
        


    public:

        WelcomeScreen();
      

        ~WelcomeScreen();

        void drawScreens(sf::RenderWindow* window);

        void handleEvent();

        
        void ajouterBouton();



        


     
};
#endif
