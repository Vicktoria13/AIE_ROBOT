#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP


#include "Screen.hpp"
#include "WelcomeScreen.hpp"
#include "ChoseSkillMenu.hpp"
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

  
    //std::vector<Screen*> EcransDisponibles;

    std::map<std::string,Screen*> MapEcransDisponibles;
    Screen* EcranActuel;

  
    
public:
    GamePlay();
    ~GamePlay();

    void Ajout_Ecran( std::string name, Screen* ecran);

    void DisplayCurrentScreen();

    void Run();

    void WaitForExit();

    void ChangerFenetreCourante(std::string name);

    int CheckFenetreChanges();




};



#endif