#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Screen.hpp"
#include "WelcomeScreen.hpp"
#include <vector>


#define HAUTEUR_FENETRE 600
#define LARGEUR_FENETRE 800

class GamePlay
{
private:
    /* Attributs */

    sf::RenderWindow *fenetre;
    sf::Event event;
    sf::Clock clock;

    std::vector<Screen*> EcransDisponibles;

  
    
public:
    GamePlay();
    ~GamePlay();

    void WaitForExit();


};



#endif