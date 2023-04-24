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
   
    ajouterBouton();
    getTheMostLeftButton();

    this->ScreenName = "Valide";
    this->ProchainScreen = "";
    this->Quit = false; // on ne quitte pas par defaut
}



/**
 * @brief Dessine le labyrinthe 2D ! 
 * 
 * @param window 
 */


void PlateauJeu::DrawLabyrinthe(sf::RenderWindow* window) const{

    FondBlanc(window);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            int pas = 1;
            sf::RectangleShape rectangle(sf::Vector2f(case_size-pas, case_size-pas));
            rectangle.setPosition(j*case_size, i*case_size);

            if (labyrinthe[i][j] == 1){
                // noir
                rectangle.setFillColor(sf::Color::Black);
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





void PlateauJeu::drawScreens(sf::RenderWindow* window){
    
    DrawLabyrinthe(window);

    dessinerBoutons(window);
}


void PlateauJeu::handleEvent(){
    // rien a faire
}