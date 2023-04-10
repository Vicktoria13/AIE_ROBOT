#include "SFMLRenderer.hpp"
#include <iostream>


#define WIDTH 640
#define HEIGHT 640

SFMLRenderer::SFMLRenderer(){
    /**
     * @brief Constructeur d'un renderer via alloc dyn
     * 
     */
    this->fenetre_jeu = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Aie Robot !");
    this->fenetre_jeu->clear(sf::Color::White);
}



SFMLRenderer::~SFMLRenderer()
{
    delete fenetre_jeu;
}

void SFMLRenderer::waitExit(){
    /**
     * @brief Fonction qui attend la fermeture de la fenetre
     * @param aucun
     * @return aucun
     */ 

    this->fenetre_jeu->display();
        
    while (this->fenetre_jeu->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (this->fenetre_jeu->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                this->fenetre_jeu->close();
        }
    }

}

sf::RenderWindow& SFMLRenderer::getFenetreJeu(){
    /**
     * @brief Fonction qui retourne la fenetre SFML
     * @param aucun
     * @return fenetre_jeu
     */ 
    return *fenetre_jeu;
}