#include "GameOverScreen.hpp"










/**
 * @brief Ajoute des boutons selon la poisiton et la taille. Ils sont mis a false par defaut
 * 
 */

void GameOverScreen::ajouterBouton(){


    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200),false);

        
}


GameOverScreen::GameOverScreen(){
    this->ajouterBouton();

    // On met le bouton le plus en haut a gauche a true
    getTheMostLeftButton();
   

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("Assets/GameOver.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);

     // On ajoute le titre

    if(!this->fontTitle.loadFromFile("Assets/ccwild.ttf")){
        throw("ERROR FONT LOAD");}


    Title.setFont(fontTitle);
    Title.setPosition(380,80);
    Title.setCharacterSize(80);
    Title.setString("Final");

    // chaine vide par defaut
    this->ProchainScreen = "";
    this->ScreenName = "GameOver";

    this->Quit = false; // on ne quitte pas par defaut
}



void GameOverScreen::drawScreens(sf::RenderWindow* window){
    window->draw(fullBackground);
    window->draw(Title);
    for (auto& bouton : MapBoutons)
    {
        bouton.second->drawContoursBoutton(*window);
    }
}

void GameOverScreen::handleEvent(){
    
}

GameOverScreen::~GameOverScreen(){
    for (auto& bouton : MapBoutons)
    {
        delete bouton.second;
    }
    MapBoutons.clear();
}