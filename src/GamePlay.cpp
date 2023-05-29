#include "../include/GamePlay.hpp"

#include <iostream>




/**
 * @brief Constructeur d'une partie de jeu
 * 
 */
GamePlay::GamePlay() 
{
    /* on cree la fenetre de jeu !*/
    fenetre = new sf::RenderWindow(sf::VideoMode(1920,1080), "Aîe Robot Game");
    fenetre->setFramerateLimit(80);

    /* Ajout des ecrans*/

    /* Ecran d'accueil */
    Ajout_Ecran("Accueil",new WelcomeScreen());

    /* Ecran Menu Choix Skills*/
    ChoseSkillMenu* ecran_choix = new ChoseSkillMenu();
    this->menu_skills = ecran_choix;

    Ajout_Ecran("Start", ecran_choix);

    //Ecran d'infos
    Ajout_Ecran("Ready",new RuleScreen());

    /* Ecran Game Over */
    //Ajout_Ecran("GameOver",new GameOverScreen());



    // on met l'ecran d'accueil comme ecran actuel
    // ecran actuel est un pointeur vers un ecran  : Screen* EcranActuel
    EcranActuel = MapEcransDisponibles["Accueil"];

  
   
   
}


/**
 * @brief Destructeur d'une partie de jeu
 * 
 */
GamePlay::~GamePlay()
{
    delete fenetre;
    for (auto it = MapEcransDisponibles.begin(); it != MapEcransDisponibles.end(); ++it)
    {
        if(it->second != nullptr)
            std::cout << "delete " << it->first << std::endl;
            delete it->second;
    }
    
    MapEcransDisponibles.clear();


    
}


/**
 * @brief 
 * 
 * @param name 
 * @param ecran 
 */
void GamePlay::Ajout_Ecran(std::string name, Screen *ecran)
{
    //EcransDisponibles.push_back(ecran);
    this->MapEcransDisponibles[name] = ecran;
    
}





/**
 * @brief Regarde si sa fenetre actuel demande un changement d'ecran
 * Si oui, alors on change d'ecran ou on quitte le jeu
 * 
 */
int GamePlay::CheckFenetreChanges(){

    // si le joueur a clique sur le bouton quitter de l'ecran actuel
    if(EcranActuel->getQuit()){
        this->fenetre->close();
        return -1;
    }

    else { // on change d'ecran

        std::string newScreenName = EcranActuel->getProchainScreen();

        if (newScreenName != "" && MapEcransDisponibles.empty() == false)
        {

            if (newScreenName == "Play")
            {
                Ajout_Ecran(newScreenName,new PlateauJeu(&(menu_skills->skills_joueurA), &(menu_skills->skills_joueurB)));
                this->EcranActuel = MapEcransDisponibles[newScreenName];

            }

            else if (newScreenName=="GameOver_B_Lost"){
                Ajout_Ecran(newScreenName,new GameOverScreen("A"));
                this->EcranActuel = MapEcransDisponibles[newScreenName];
            }

            else if (newScreenName=="GameOver_A_Lost"){
                Ajout_Ecran(newScreenName,new GameOverScreen("B"));
                this->EcranActuel = MapEcransDisponibles[newScreenName];
            }

           
            else if (MapEcransDisponibles.find(newScreenName) == MapEcransDisponibles.end())
            {
                throw std::runtime_error("Ecran non trouve");
            }


                        

            else { 
                this->EcranActuel = MapEcransDisponibles[newScreenName];
            }
            

            return 1;
        }
    }

    return 0; // pas de changement d'ecran
}



/*
int GamePlay::WaitForExit(){
    
    while (this->fenetre->isOpen())
    {
        sf::Event event;
        
        while (this->fenetre->waitEvent(event))
        {
            if (event.type == sf::Event::Closed){
                return -1;}

            else if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Escape){
                    return -1;
                }

        



        /* update + affichage a faire pour chaque fenetre dès qu'une touche
        est pressé

                fenetre->clear();

                EcranActuel->handleEvent();

                CheckFenetreChanges();

                DisplayCurrentScreen();
                std::cout<<"rafraichissement"<<std::endl;

                fenetre->display();

                WaitPeriod();
        }
    }
    }

    return 0;
}
*/

void GamePlay::WaitForExit(){
    while (this->fenetre->isOpen())
    {
        sf::Event event;
        
        while (this->fenetre->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->fenetre->close();

        }



        
        fenetre->clear(sf::Color(120,128,20,200));

        WaitPeriod();

        EcranActuel->handleEvent();


        CheckFenetreChanges();

        DisplayCurrentScreen();

        fenetre->display();

        //WaitPeriod();

    }
}



/**
 * @brief Affiche l'écran actuel
 * 
 */
void GamePlay::DisplayCurrentScreen(){
    if (EcranActuel != nullptr){
    EcranActuel->drawScreens((this->fenetre));
    }

    else{
        throw std::runtime_error("EcranActuel est null");
    }
}


void GamePlay::Run()
{
    // on affiche l'ecran d'accueil
    WaitForExit();
    
}


/**
 * @brief Attend un certain temps avant de passer a l'ecran suivant
 * quand on est sur l'ecran d'accueil ou le menu de jeu
 * car sinon, l'appui sur une touche est pris en compte 2 fois
 * 
 */
void GamePlay::WaitPeriod() const
{
    if (EcranActuel != nullptr)
    {
       if (EcranActuel->getScreenName() == "Accueil" || EcranActuel->getScreenName() == "Start" || EcranActuel->getScreenName() == "Ready" ){
       
           sf::sleep(sf::seconds(0.11f));
        }
       
    }
   
}