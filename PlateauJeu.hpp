#ifndef PLATEAUJEU_HPP
#define PLATEAUJEU_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include "RobotPlayer.hpp"
#include "TourEnnemi.hpp"
#include "Drapeau.hpp"

#include "Masque.hpp"
#include <iostream>
#include <vector>







class PlateauJeu: public Screen
{
private:
    int case_size = 60 ;

   //pointeur
   std::array<std::array<int, nb_cases>, nb_cases> labyrinthe; 

    
    std::map<std::string,EntiteAffichable*> characters;



    Masque* masque2D;

public:
    PlateauJeu();
    ~PlateauJeu();

    void DrawLabyrinthe(sf::RenderWindow* window) ;
    
    void FondBlanc(sf::RenderWindow* window) const;

    void drawScreens(sf::RenderWindow* window);
    void drawCharacters(sf::RenderWindow* window) ;



    void handleEvent();
    void ajouterBouton();

    

    /* raycasting 3D*/

    

};



#endif