#include "GamePlay.hpp"
#include <iostream>


GamePlay::GamePlay() 
{
    /* on cree la fenetre de jeu !*/
    fenetre = new sf::RenderWindow(sf::VideoMode(1920,1080), "Aie Robot!");
    fenetre->setFramerateLimit(20);

    /* on ajoute les ecrans disponibles */
    this->EcransDisponibles.push_back(new WelcomeScreen());


    std::cout<< " il y a " << EcransDisponibles.size()<< " ecrans dispo" << std::endl;
  
   
    
   
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
    this->fenetre->clear(sf::Color::Black);
    // on affiche l'ecran voulu
    EcransDisponibles[index]->drawScreens((this->fenetre));
    this->fenetre->display();
    
}


void GamePlay::WaitForExit(){

    while (this->fenetre->isOpen())
    {
        sf::Event event;
        
        while (this->fenetre->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->fenetre->close();
        }
        
       
    }
}

void GamePlay::Run()
{
    // on affiche l'ecran d'accueil
    this->Affichage_Ecran(0);
    WaitForExit();
    
}
