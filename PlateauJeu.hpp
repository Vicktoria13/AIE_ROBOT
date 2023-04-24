#ifndef PLATEAUJEU_HPP
#define PLATEAUJEU_HPP

#include "Screen.hpp"
#include "Bouton.hpp"
#include <iostream>
#include <vector>

class PlateauJeu: public Screen
{
private:
    int case_size = 100 ;
    std::array<std::array<int, 10>, 10> labyrinthe; 

public:
    PlateauJeu();

    void DrawLabyrinthe(sf::RenderWindow* window) const;
    void FondBlanc(sf::RenderWindow* window) const;

    void drawScreens(sf::RenderWindow* window);
    void handleEvent();
    void ajouterBouton();

};



#endif