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
    this->backgroundSprite.setColor(sf::Color(255, 255, 255, 200));

    
}


/*
*L'ecran d'accueil par defaut a un bouton Play au centre et un background

*/
WelcomeScreen::WelcomeScreen()
{
    PlayBouton = Bouton(100, 100, 100, 100, "Play", sf::Color::Red, sf::Color::Green);

    if (!backgroundTexture.loadFromFile("Accueil.jpg"))
    {
        // erreur...
        std::cout << "erreur" << std::endl;
    }

    this->backgroundSprite.setTexture(backgroundTexture);
    this->backgroundSprite.setColor(sf::Color(255, 255, 255, 200));
    std::cout << "creation d'un nouveau WelcomeScreen" << std::endl;
}


/**
 * @brief Dessine tous ses composants sur la fenêtre (ici, le fond d'écran et les boutons)
 * 
 * @param window 
 */

void WelcomeScreen::draw(sf::RenderWindow& window)
{
    
    float scaleX = static_cast<float>(window.getSize().x) / static_cast<float>(backgroundTexture.getSize().x);
    float scaleY = static_cast<float>(window.getSize().y) / static_cast<float>(backgroundTexture.getSize().y);
    if (scaleX > scaleY)
    {
        backgroundSprite.setScale(scaleX, scaleX);
    }
    else
    {
        backgroundSprite.setScale(scaleY, scaleY);
    }

    // Centrage du sprite
    backgroundSprite.setPosition((window.getSize().x - backgroundSprite.getGlobalBounds().width) / 2,
                        (window.getSize().y - backgroundSprite.getGlobalBounds().height) / 2);



    // affichage
    window.clear(sf::Color::Black);
    window.draw(backgroundSprite);
    //PlayBouton.drawAtGivenPosition(window);
    window.display();
}


void WelcomeScreen::handleEvent(const sf::Event& event)
{
  
}

WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
}