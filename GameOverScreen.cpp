#include "GameOverScreen.hpp"










/**
 * @brief Ajoute des boutons selon la poisiton et la taille. Ils sont mis a false par defaut
 * 
 */

void GameOverScreen::ajouterBouton(){


   vector_buttons.push_back(new Bouton(1650, 900, 150, 70, "Quit",  sf::Color(100,20,20,200),false));

        
}


GameOverScreen::GameOverScreen(){
    this->ajouterBouton();

    // On met le bouton le plus en haut a gauche a true
    getTheMostLeftButton();
   

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("Assets/win.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);

    // chaine vide par defaut
    this->ProchainScreen = "";
    this->ScreenName = "GameOver";

    this->Quit = false; // on ne quitte pas par defaut
}



void GameOverScreen::drawScreens(sf::RenderWindow* window){
    window->draw(fullBackground);
    dessinerBoutons(window);
    
}




void GameOverScreen::handleEvent(){

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        for (auto& bouton : vector_buttons)
        {
            // on recherche celui qui est pressé : si on le trouve, on renvoit 1
            if (bouton->EnterPressed()==1){
                // faire une fonction qui renvoie le nom du bouton pressé 
                if (bouton->getName() == "Quit")
                    // on quitte le jeu
                    this->Quit = true;
                else {
                    this->ProchainScreen = bouton->getName(); // on donne le nom du nouveau screen via le nom du bouton donc ils doivent avoir le meme nom
                }
            }
        }
    }
}

GameOverScreen::~GameOverScreen(){
    for (auto& bouton : vector_buttons)
    {
        delete bouton;
    }
}