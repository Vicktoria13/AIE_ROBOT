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
    

        int nb_skills_A;
        int nb_skills_B;

        std::vector<Talkbox*> vector_talkbox;

        bool capteur3DA ;
        bool capteur3DB ;

        bool VitesserapideA ;
        bool VitesserapideB ;

        bool capteurUltrasonsA ;
        bool capteurUltrasonsB ;

    public:
        // map de skill
        std::map<std::string, bool> skills_joueurA;
        std::map<std::string, bool> skills_joueurB;

        ChoseSkillMenu();
        ~ChoseSkillMenu();

        void ajouterBouton();
        void drawScreens(sf::RenderWindow *window);

        void handleEvent();

        /*****infos******/
        void AfficheInfosSkills();

        /*****getters******/
        std::map<std::string, bool> getSkills_joueurA() { return this->skills_joueurA; }
        std::map<std::string, bool> getSkills_joueurB() { return this->skills_joueurB; }

    
   
};



#endif