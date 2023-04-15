#include "WelcomeScreen.hpp"
#include <iostream>
// classe dérivée de Screen
// donc possède une fenêtre déja
// pas besoin de la créer

// void draw(sf::RenderWindow& window);


/*
* Ici, les attribus de la classe WelcomeScreen sont des objets : 
* Utiliser donc la liste d'initialisation pour appeler les constructeurs des attributs
*/
WelcomeScreen::WelcomeScreen(float pos_x_1, float pos_y_1, float width_1, float height_1, 
                 std::string textePlay,  sf::Color PlayColor,sf::Color ColorTextPlay,

                float pos_x_2, float pos_y_2, float width_2, float height_2,
                std::string texteQuit,  sf::Color QuitColor,sf::Color ColorTextQuit): 
                
                PlayBouton(pos_x_1, pos_y_1, width_1, height_1, textePlay, PlayColor, ColorTextPlay), 
                QuitBouton(pos_x_2, pos_y_2, width_2, height_2, texteQuit, QuitColor, ColorTextQuit)


                 

{
    if (!backgroundTexture.loadFromFile("Accueil.png"))
    {
        // erreur...
        std::cout << "erreur" << std::endl;
    }

    this->backgroundSprite.setTexture(backgroundTexture);
}




