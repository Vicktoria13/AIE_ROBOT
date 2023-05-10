#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP


#include "Screen.hpp"
#include "WelcomeScreen.hpp"
#include "ChoseSkillMenu.hpp"
#include "PlateauJeu.hpp"
#include "GameOverScreen.hpp"
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

  
    std::vector<Screen*> EcransDisponibles;

    std::map<std::string,Screen*> MapEcransDisponibles;
    Screen* EcranActuel;
    // ptr unique pour ecran actuel
    //std::unique_ptr<Screen> EcranActuel;

  
    
public:
    GamePlay();
    ~GamePlay();

    void Ajout_Ecran( std::string name, Screen* ecran);

    void DisplayCurrentScreen();

    void Run();

    //int WaitForExit();*
    void WaitForExit();

    void ChangerFenetreCourante(std::string name);

    int CheckFenetreChanges();

    void WaitPeriod() const;



};



#endif