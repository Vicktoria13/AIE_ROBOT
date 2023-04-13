#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Screen.hpp"
#include <vector>
class GamePlay
{
private:
    /* Attributs */

    sf::RenderWindow fenetre;
    sf::Event event;
    sf::Clock clock;

    std::vector<Screen*> EcransDisponibles;
    
public:
    GamePlay(/* args */);
    ~GamePlay();
};



#endif