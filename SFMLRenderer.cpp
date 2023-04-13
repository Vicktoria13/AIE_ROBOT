

#include "SFMLRenderer.hpp"
#include <iostream>


/**
 * @brief Initialise la fenêtre SFML en fond noir
 * 
 */
SFMLRenderer::SFMLRenderer()
{
    fenetre = new sf::RenderWindow(sf::VideoMode(800, 600), "Fenêtre SFML");
    fenetre->clear(sf::Color::Black);
}

SFMLRenderer::~SFMLRenderer()
{
    delete fenetre;
}


void SFMLRenderer::waitForExit()
{
    fenetre->display();
    
    std::cout << "Fermez la fenêtre pour continuer." <<  std::endl;
    
    while (fenetre->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (fenetre->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                fenetre->close(); // on sort de la boucle
        }
    }
}