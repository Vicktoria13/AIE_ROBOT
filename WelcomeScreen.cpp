#include "WelcomeScreen.hpp"


// classe dérivée de Screen
// donc possède une fenêtre déja
// pas besoin de la créer
WelcomeScreen::WelcomeScreen()
{   


    // a l'initialisation , isRunning est vrai
    this->isRunning = true;
    this->backgroundTexture = sf::Texture();

    if (!this->backgroundTexture.loadFromFile("Accueil.jpg")){
        std::cout << "Erreur lors du chargement de l'image" << std::endl;
    }

    this->background = sf::Sprite(this->backgroundTexture);


    // on initialise les boutons
    


}