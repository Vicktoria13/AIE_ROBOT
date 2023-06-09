#include "../include/RuleScreen.hpp"


/**
 * @brief Ajoute les boutons de l'ecran
 * 
 */
void RuleScreen::ajouterBouton(){


    vector_buttons.push_back(new Bouton(1600, 900, 100, 70, "Play",  sf::Color(20,20,100,200),false));
    vector_buttons.push_back(new Bouton(1730, 900, 100, 70, "Quit",  sf::Color(100,20,20,200),false));
}


/**
 * @brief Constructeur par defaut de la classe RuleScreen
 * 
 */
RuleScreen::RuleScreen(){
    this->ajouterBouton();
    getTheMostLeftButton();

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("../Assets/rules.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);
    fullBackground.setScale(1,1);

    // chaine vide par defaut
    this->ProchainScreen = "";
    this->ScreenName = "Ready";

    this->Quit = false; // on ne quitte pas par defaut


}



/**
 * @brief Methode virtuelle pour dessiner l'ecran et ses boutons
 * 
 * @param window 
 */
void RuleScreen::drawScreens(sf::RenderWindow* window){
    window->draw(fullBackground);
    dessinerBoutons(window);
    
}


/**
 * @brief Gere les evenements de l'ecran clavier
 * 
 */
void RuleScreen::handleEvent(){

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        //on cherche le bouton acrif
        for (size_t i = 0; i < vector_buttons.size(); i++)
        {
            if (i==vector_buttons.size()-1){
                if (vector_buttons[i]->getIsActivated() == true){
                    vector_buttons[i]->setFlagActivated(false);
                    vector_buttons[0]->setFlagActivated(true);
                }
                break;
            }
            else{

                if (vector_buttons[i]->getIsActivated() == true){
             
                    vector_buttons[i]->setFlagActivated(false);
                    vector_buttons[i + 1]->setFlagActivated(true);
                    

                break;
            }
            }
        }
        
   
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        //on cherche le bouton acrif
        for (size_t i = vector_buttons.size()-1; i >= 0; i--)
        {
            if (i==0){
                if (vector_buttons[i]->getIsActivated() == true){

                    vector_buttons[0]->setFlagActivated(false);
                    vector_buttons[vector_buttons.size()-1]->setFlagActivated(true);
                    break;
                    
                }
                
            }
            else{

                if (vector_buttons[i]->getIsActivated() == true){
             
                    vector_buttons[i]->setFlagActivated(false);
                    vector_buttons[i - 1]->setFlagActivated(true);
                    

                break;
            }
            }
        }
        
   
    }

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
                    // soit "Play" soit "Quit"
                }
            }
        }
    }

}


/**
 * @brief Destructeur de la classe RuleScreen
 * 
 */
RuleScreen::~RuleScreen(){
    for (auto& bouton : vector_buttons)
    {
        delete bouton;
    }
}