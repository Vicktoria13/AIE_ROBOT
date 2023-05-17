#include "GamePlay.hpp"
#include <iostream>


GamePlay::GamePlay() 
{
    /* on cree la fenetre de jeu !*/
    fenetre = new sf::RenderWindow(sf::VideoMode(1920,1080), "Aie Robot!");
    fenetre->setFramerateLimit(80);

    /* Ajout des ecrans*/

    /* Ecran d'accueil */
    std::cout<<"ajout ecran accueil"<<std::endl;
    Ajout_Ecran("Accueil",new WelcomeScreen());

    /* Ecran Menu Choix Skills*/
    std::cout<<"ajout ecran choix"<<std::endl;
    ChoseSkillMenu* ecran_choix = new ChoseSkillMenu();

    std::cout<<"ajout ecran play"<<std::endl;
    Ajout_Ecran("Start", ecran_choix);

    /* Ecran Plateau de jeu */
    std::cout<<"ajout ecran plateau"<<std::endl;
    Ajout_Ecran("Play",new PlateauJeu(&(ecran_choix->skills_joueurA), &(ecran_choix->skills_joueurB)));

    /* Ecran Game Over */
    Ajout_Ecran("GameOver",new GameOverScreen());



    // on met l'ecran d'accueil comme ecran actuel
    // ecran actuel est un pointeur vers un ecran  : Screen* EcranActuel
    EcranActuel = MapEcransDisponibles["Accueil"];

  
   
   
}



GamePlay::~GamePlay()
{
    delete fenetre;
    for (auto it = MapEcransDisponibles.begin(); it != MapEcransDisponibles.end(); ++it)
    {
        delete it->second;
    }
    
    MapEcransDisponibles.clear();
    
}


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

    else {
        std::string newScreenName = EcranActuel->getProchainScreen();

        if (newScreenName != "" && MapEcransDisponibles.empty() == false)
        {
            this->EcranActuel->setProchainScreen("");
            if (MapEcransDisponibles.find(newScreenName) == MapEcransDisponibles.end())
            {
                std::cout<<"Ecran non trouve : "<<newScreenName<<std::endl;
                throw std::runtime_error("Ecran non trouve");
            }
                        

            else {
                this->EcranActuel = MapEcransDisponibles[newScreenName];
                std::cout<<"changement d'ecran pour "<<newScreenName<<std::endl;
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
       if (EcranActuel->getScreenName() == "Accueil" || EcranActuel->getScreenName() == "Start" ){
       
           sf::sleep(sf::seconds(0.12f));
        }
       
    }
   
}