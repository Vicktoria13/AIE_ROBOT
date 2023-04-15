#include "GamePlay.hpp"
#include <iostream>


GamePlay::GamePlay() 
{
    /* on cree la fenetre de jeu !*/
    fenetre = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML works!");
    
    /* on ajoute les ecrans disponibles */
    Ajout_Ecran(new WelcomeScreen());

}



GamePlay::~GamePlay()
{
    delete fenetre;
    delete EcransDisponibles[0];
    
}


void GamePlay::Ajout_Ecran(Screen *ecran)
{
    EcransDisponibles.push_back(ecran);
}

void GamePlay::Affichage_Ecran(int index)
{
    
    EcransDisponibles[index]->draw(*fenetre);
    std::cout << "Affichage de l'ecran " << index << std::endl;
    
}


void GamePlay::WaitForExit(){


    while (this->fenetre->isOpen())
    {
        while (this->fenetre->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->fenetre->close();
        }

       
    }
}

void GamePlay::Run()
{
    Affichage_Ecran(0);
    WaitForExit();
    
}
