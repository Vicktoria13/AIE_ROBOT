#include "GamePlay.hpp"
#include <iostream>


GamePlay::GamePlay() 
{
    /* on cree la fenetre de jeu !*/
    fenetre = new sf::RenderWindow(sf::VideoMode(1920,1080), "Aie Robot!");
    fenetre->setFramerateLimit(20);

    /* on ajoute les ecrans disponibles */
    //this->EcransDisponibles.push_back(new WelcomeScreen());

    Ajout_Ecran("Accueil",new WelcomeScreen());





    std::cout<< " il y a " << MapEcransDisponibles.size()<< " ecrans dispo" << std::endl;
  
   
   
}



GamePlay::~GamePlay()
{
    delete fenetre;
    delete MapEcransDisponibles["Accueil"];
    
}


void GamePlay::Ajout_Ecran(std::string name, Screen *ecran)
{
    //EcransDisponibles.push_back(ecran);
    this->MapEcransDisponibles[name] = ecran;
}

void GamePlay::Affichage_Ecran(std::string name)
{
    this->fenetre->clear(sf::Color::Black);
    // on affiche l'ecran voulu
    MapEcransDisponibles[name]->drawScreens((this->fenetre));
    
    
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

        fenetre->clear();
        Affichage_Ecran("Accueil");
        fenetre->display();
        

        
       
    }
}


/**
 * @brief Affiche l'écran actuel
 * 
 */
void GamePlay::DisplayCurrentScreen(){
    this->fenetre->clear(sf::Color::Black);
    EcranActuel->drawScreens((this->fenetre));
}


void GamePlay::Run()
{
    // on affiche l'ecran d'accueil
    WaitForExit();
    
}
