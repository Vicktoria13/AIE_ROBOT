#include "WelcomeScreen.hpp"
#include "Screen.hpp"
#include <iostream>

// classe dérivée de Screen
// donc possède une fenêtre déja
// pas besoin de la créer

// void draw(sf::RenderWindow& window);


/**
 * @brief Ajoute des boutons selon la poisiton et la taille. Ils sont mis a false par defaut
 * 
 */

void WelcomeScreen::ajouterBouton(){

    vector_buttons.push_back(new Bouton(1450, 900, 150, 70, "Start",  sf::Color(100,20,20,200),false));
    vector_buttons.push_back(new Bouton(1650, 900, 150, 70, "Quit",  sf::Color(100,20,20,200),false));
    
}




WelcomeScreen::WelcomeScreen()
{
    this->ScreenName = "Accueil";
    
    this->ajouterBouton();

    // On met le bouton le plus en haut a gauche a true
    getTheMostLeftButton();
   

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("Assets/start.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);

    // chaine vide par defaut
    this->ProchainScreen = "";
    

    this->Quit = false; // on ne quitte pas par defaut


   
}






/**
 * @brief Dessine tous ses composants sur la fenêtre (ici, le fond d'écran et les boutons)
 * 
 * @param window passe par référence la fenêtre sur laquelle on dessine
 */


void WelcomeScreen::drawScreens(sf::RenderWindow* window){
               
                window->draw(fullBackground);
                dessinerBoutons(window);
        }





/**
 * @brief Gère les évènements clavier :
 * - flèche droite : on passe au bouton suivant
 * - flèche gauche : on passe au bouton précédent
 * - entrée : on lance le jeu ou on quitte
 * 
 */
void WelcomeScreen::handleEvent()
{
   

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



WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
    for (auto& bouton : vector_buttons)
    {
        delete bouton;
    }

    
    
}




