#include "GamePlay.hpp"
#include <iostream>


GamePlay::GamePlay() 
{
    /* on cree la fenetre de jeu !*/
    fenetre = new sf::RenderWindow(sf::VideoMode(1920,1080), "Aie Robot!");
    fenetre->setFramerateLimit(20);

    /* Ajout des ecrans*/

    /* Ecran d'accueil */
    Ajout_Ecran("Accueil",new WelcomeScreen());

    /* Ecran Menu Choix Skills*/
    Ajout_Ecran("Play",new ChoseSkillMenu());



    // on met l'ecran d'accueil comme ecran actuel
    EcranActuel = MapEcransDisponibles["Accueil"];


    std::cout<< " il y a " << MapEcransDisponibles.size()<< " ecrans dispo" << std::endl;
  
   
   
}



GamePlay::~GamePlay()
{
    delete fenetre;
    for (auto it = MapEcransDisponibles.begin(); it != MapEcransDisponibles.end(); ++it)
    {
        delete it->second;
    }
    
}


void GamePlay::Ajout_Ecran(std::string name, Screen *ecran)
{
    //EcransDisponibles.push_back(ecran);
    this->MapEcransDisponibles[name] = ecran;
    
}





/**
 * @brief Regarde si sa fenetre actuel demande un changement d'ecran
 * Si oui, alors on change d'ecran
 * 
 */
void GamePlay::CheckFenetreChanges(){
    std::string newScreenName = EcranActuel->getProchainScreen();
    if(newScreenName != ""){
        
        this->EcranActuel = MapEcransDisponibles[newScreenName];
    }
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



        /* update + affichage */
        
        fenetre->clear();
        EcranActuel->handleEvent();
        CheckFenetreChanges();
        DisplayCurrentScreen();
        fenetre->display();

    }
}




/**
 * @brief Affiche l'écran actuel
 * 
 */
void GamePlay::DisplayCurrentScreen(){
    EcranActuel->drawScreens((this->fenetre));
}


void GamePlay::Run()
{
    // on affiche l'ecran d'accueil
    WaitForExit();
    
}
