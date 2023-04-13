#include "GamePlay.hpp"
#include <iostream>



/**
 * @brief Construit une nouvelle partie
 * 
 */
GamePlay::GamePlay()
{
    // Intialisation d'une partie

    // on commence par créer la fenêtre
    std::cout << "creation de la partie !" << std::endl;
    this->fenetre = new sf::RenderWindow(sf::VideoMode(HAUTEUR_FENETRE, LARGEUR_FENETRE), "SFML works!",sf::Style::Resize);

}


GamePlay::~GamePlay()
{
    delete fenetre;
}

void GamePlay::WaitForExit(){
    while (this->fenetre->isOpen())
    {
        while (this->fenetre->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->fenetre->close();
        }

        this->fenetre->clear();
        this->fenetre->display();
    }
}