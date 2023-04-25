#include "PlateauJeu.hpp"



void PlateauJeu::ajouterBouton(){
    // en bas a droite
    MapBoutons["Quit"] = new Bouton(1500, 900, 100, 80, "Quit",  sf::Color(20,20,100,200),false);
    MapBoutons["Break"] = new Bouton(1700, 900, 100, 80, "Pause",  sf::Color(20,20,100,200),false);
}



PlateauJeu::PlateauJeu(){
    
    labyrinthe = {{
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    }};
   
    //ajouterBouton();
    //getTheMostLeftButton();

    this->ScreenName = "Valide";
    this->ProchainScreen = "";
    this->Quit = false; // on ne quitte pas par defaut


    // liste des entités affichables
    characters["JoueurA"] = new RobotPlayer(100,100);
    characters["JoueurB"] = new RobotPlayer(500,500);
}






/**
 * @brief Dessine le labyrinthe 2D ! 
 * 
 * @param window 
 */


void PlateauJeu::DrawLabyrinthe(sf::RenderWindow* window) const{

    FondBlanc(window);
    sf::Texture texture;
    if (!texture.loadFromFile("block.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    int taille = 10;
    for (int i = 0; i < taille; i++){
        for (int j = 0; j < taille; j++){
            int pas = 4; // si le pas est trop faible, alors on ne voit pas le quadrillage lors du resize
            
            sf::RectangleShape rectangle(sf::Vector2f(case_size-pas, case_size-pas));
            rectangle.setPosition(j*case_size, i*case_size);
            std::cout<< "rectange position : " << j*case_size << " " << i*case_size << std::endl;

            if (labyrinthe[i][j] == 1){
                // noir
                //rectangle.setFillColor(sf::Color::Black);
                rectangle.setTexture(&texture);
            }
            else{
                // blanc
                rectangle.setFillColor(sf::Color::White);             
            }
            window->draw(rectangle);
        }
    }


}

/**
 * @brief Rempli la fenêtre de blanc
 * 
 * @param window 
 */
void PlateauJeu::FondBlanc(sf::RenderWindow* window) const{
    window->clear(sf::Color::Black);
}




void PlateauJeu::drawCharacters(sf::RenderWindow* window) const{
    for (auto& perso : characters){
        perso.second->DisplayEntite(window);
    }
}



void PlateauJeu::drawScreens(sf::RenderWindow* window){
    
    DrawLabyrinthe(window);
    dessinerBoutons(window);
    drawCharacters(window);
}


void PlateauJeu::handleEvent(){


    /* Boutons */

    if (!MapBoutons.empty()){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // Cas du play alors on prend le bouton a sa droite
            if (MapBoutons["Break"]->getIsActivated() == true)
            {

                MapBoutons["Break"]->setFlagActivated(false);
                MapBoutons["Quit"]->setFlagActivated(true);

                std::cout << "Bouton play activé" << std::endl;
            }

            // sinon : on ne fait rien, car on ne peut pas aller plus loin a droite
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // Cas du play alors on prend le bouton a sa droite
            if (MapBoutons["Quit"]->getIsActivated() == true)
            {

                MapBoutons["Quit"]->setFlagActivated(false);
                MapBoutons["Break"]->setFlagActivated(true);
            }

            // sinon : on ne fait rien, car on ne peut pas aller plus loin a gauche
        }

        // on verifie si la touche entrée est appuyée
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            for (auto &bouton : MapBoutons)
            {
                // on recherche celui qui est activé : si on le trouve, on renvoit 1
                if (bouton.second->EnterPressed() == 1)
                {
                    // faire une fonction qui renvoie le nom du bouton pressé
                    if (bouton.first == "Quit")
                        // on quitte le jeu
                        this->Quit = true;
                    else
                    {
                        this->Quit = false;
                        this->ProchainScreen = bouton.first; // on donne le nom du nouveau screen via le nom du bouton donc ils doivent avoir le meme nom
                    }
                }
            }
        }
    }
    
}


PlateauJeu::~PlateauJeu(){
    std::cout<<"Destruction du plateau de jeu"<<std::endl;
    for (auto& perso : characters){
        delete perso.second;
        std::cout<<"Destruction du personnage "<<perso.first<<std::endl;
    }
}