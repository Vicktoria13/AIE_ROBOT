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

const int TAILLE_LABYRINTHE = 15;



//define pour l'affichage 3D
#define XX (TAILLE_LABYRINTHE+1)*60
#define LARGEUR (1300 - XX)/NB_RAYONS
#define CENTRE TAILLE_LABYRINTHE*60/2
#define HM (TAILLE_LABYRINTHE)*60


class PlateauJeu: public Screen
{
private:
    int case_size = 60 ;

   
    std::array<std::array<int, TAILLE_LABYRINTHE>, TAILLE_LABYRINTHE> labyrinthe; 

    
    std::map<std::string,EntiteAffichable*> characters;


    Masque* masque2D;

public:
    PlateauJeu();
    ~PlateauJeu();

    void DrawLabyrinthe(sf::RenderWindow* window) ;
    
    void FondBlanc(sf::RenderWindow* window) const;

    void drawScreens(sf::RenderWindow* window);
    void drawCharacters(sf::RenderWindow* window) const;

    void Dessine_cadre(sf::RenderWindow* window) const;


    void handleEvent();
    void ajouterBouton();

    /*getter*/
    std::array<std::array<int, TAILLE_LABYRINTHE>, TAILLE_LABYRINTHE> getLabyrinthe() const{
        return this->labyrinthe;
    }


};



#endif