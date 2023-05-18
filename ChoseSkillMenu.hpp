#ifndef ChoseSkillMenu_HPP
#define ChoseSkillMenu_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>
#include "Talkbox.hpp"



/**
 * @brief Ecran ou on pourra choisir les skills pour chaque joueur
 * 
 */

class ChoseSkillMenu: public Screen
{
private:
    

        sf::Text Title;
        sf::Font fontTitle;
        /* le fond d"'écran de l'accueil */

        sf::RectangleShape fullBackground;
        sf::Texture backgroundTexture;

        int nb_skills_A;
        int nb_skills_B;

        std::vector<Talkbox*> vector_talkbox;
  
        


      

public:
    //map de skill
        std::map<std::string, bool> skills_joueurA;
        std::map<std::string, bool> skills_joueurB;

    ChoseSkillMenu();
    ~ChoseSkillMenu();

    void ajouterBouton();
    void drawScreens(sf::RenderWindow* window);

    void handleEvent() ;    

    /*****infos******/
    void AfficheInfosSkills();

    
   
};



#endif