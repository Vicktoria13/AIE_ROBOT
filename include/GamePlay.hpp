#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP


#include "Screen.hpp"
#include "WelcomeScreen.hpp"
#include "ChoseSkillMenu.hpp"
#include "PlateauJeu.hpp"
#include "RuleScreen.hpp"
#include "GameOverScreen.hpp"
#include <vector>


#define HAUTEUR_FENETRE 800
#define LARGEUR_FENETRE 600


/**
 * @brief classe qui gere l'interaction entre les differents ecrans
 *          et afiche chaque ecran
 * 
 */
class GamePlay
{
private:
    /* Attributs */

    sf::RenderWindow *fenetre;
    std::map<std::string,Screen*> MapEcransDisponibles;
    Screen* EcranActuel;
    /** Les skills de chaque player */

    ChoseSkillMenu* menu_skills;

  
    
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
