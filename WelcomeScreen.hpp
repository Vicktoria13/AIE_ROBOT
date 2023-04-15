#ifndef WEELCOMESCREEN_HPP
#define WEELCOMESCREEN_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>


class WelcomeScreen : public Screen{

    private:
        /* le fond d"'écran de l'accueil */
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;

        /* Pour lancer le jeu*/
        Bouton PlayBouton;

        /* Pour quitter le jeu */
        Bouton QuitBouton;


    public:

        WelcomeScreen();
        WelcomeScreen(float pos_x_1, float pos_y_1, float width_1, float height_1, 
                 std::string textePlay,  sf::Color PlayColor,sf::Color ColorTextPlay,

                float pos_x_2, float pos_y_2, float width_2, float height_2,
                std::string texteQuit,  sf::Color QuitColor,sf::Color ColorTextQuit);


        ~WelcomeScreen();

        void draw(sf::RenderWindow& window);

        void handleEvent(const sf::Event& event);

};
#endif