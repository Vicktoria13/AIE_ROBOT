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
    Ajout_Ecran("ChoixSkills",new ChoseSkillMenu());



    // on met l'ecran d'accueil comme ecran actuel
    EcranActuel = MapEcransDisponibles["Accueil"];


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
    std::cout << "Ajout de l'ecran " << name << std::endl;
}



/**
 * @brief change l'ecran actuel par celui dont le nom est passe en parametre
 * 
 * @param name nom de l'ecran a afficher
 */
void GamePlay::ChangerFenetreCourante(std::string name)
{
    EcranActuel = MapEcransDisponibles[name];
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
