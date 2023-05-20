#include "../include/RuleScreen.hpp"


void RuleScreen::ajouterBouton(){


    vector_buttons.push_back(new Bouton(1400, 900, 120, 80, "Play",  sf::Color(20,20,100,200),false));
    vector_buttons.push_back(new Bouton(1600, 900, 120, 80, "Quit",  sf::Color(100,20,20,200),false));
}

RuleScreen::RuleScreen(){
    this->ajouterBouton();
    getTheMostLeftButton();

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("../Assets/rules.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);

    // chaine vide par defaut
    this->ProchainScreen = "";
    this->ScreenName = "Ready";

    this->Quit = false; // on ne quitte pas par defaut


}

void RuleScreen::drawScreens(sf::RenderWindow* window){
    window->draw(fullBackground);
    dessinerBoutons(window);
    
}

void RuleScreen::handleEvent(){

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

RuleScreen::~RuleScreen(){
    for (auto& bouton : vector_buttons)
    {
        delete bouton;
    }
}