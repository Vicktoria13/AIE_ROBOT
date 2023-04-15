#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP


#include "Screen.hpp"
#include "WelcomeScreen.hpp"
#include <vector>
#include <memory>


#define HAUTEUR_FENETRE 800
#define LARGEUR_FENETRE 600



class GamePlay
{
private:
    /* Attributs */

    sf::RenderWindow *fenetre;
    sf::Event event;
    sf::Clock clock;

  
    //std::shared_ptr<Screen> EcransDisponibles;
    std::vector<Screen*> EcransDisponibles;
    //std::vector<std::unique_ptr<Screen>> EcransDisponibles;

  
    
public:
    GamePlay();
    ~GamePlay();

    void Ajout_Ecran( Screen* ecran);

    void Affichage_Ecran(int index);

    void Run();

    void WaitForExit();



};



#endif