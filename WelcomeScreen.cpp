#include "WelcomeScreen.hpp"
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

    MapBoutons["Play"] = new Bouton(400, 800, 200, 100, "Play",  sf::Color(20,20,100,200),false);

    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200),false);

    
    // par defaut , le bouton a Gauche est entouré de rouge
    
    std::cout << "Ajout des boutons" << std::endl;
}



/*
* Ici, les attribus de la classe WelcomeScreen sont des objets : 
* Utiliser donc la liste d'initialisation pour appeler les constructeurs des attributs
*/

/*
*L'ecran d'accueil par defaut a un bouton Play au centre et un background

*/
WelcomeScreen::WelcomeScreen()
{

    this->ajouterBouton();

    // On met le bouton le plus en haut a gauche a true
    this->getTheMostLeftButton();
   

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("galaxy.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);

     // On ajoute le titre

    if(!this->fontTitle.loadFromFile("ccwild.ttf")){
        throw("ERROR FONT LOAD");}


    Title.setFont(fontTitle);
    Title.setPosition(380,80);
    Title.setCharacterSize(80);
    Title.setString("Welcome to Aie Robot");

    // chaine vide par defaut
    this->ProchainScreen = "";
    this->ScreenName = "WelcomeScreen";

    this->Quit = false; // on ne quitte pas par defaut


   
}






/**
 * @brief Dessine tous ses composants sur la fenêtre (ici, le fond d'écran et les boutons)
 * 
 * @param window passe par référence la fenêtre sur laquelle on dessine
 */


void WelcomeScreen::drawScreens(sf::RenderWindow* window){
               

                window->clear();
                // d'abord le fond

                window->draw(fullBackground);

                // puis le titre
                window->draw(Title);

                // puis les boutons
                for (auto& bouton : MapBoutons)
                {
                    
                    if (bouton.second->getIsActivated() == true ){
                        
                        bouton.second->drawContoursBoutton(*window);
                        
                    }

                    else if (bouton.second->getIsActivated() == false){
                        bouton.second->drawButton(*window);
                    }
                }

                

        }



/**
 * @brief Met le bouton le plus en haut a gauche a true.
 * Cela se traduit par le y et le x minimum parmi tous les boutons
 * 
 * @return Bouton* 
 */
void WelcomeScreen::getTheMostLeftButton(){
    int min_x = 100000;
    int min_y = 100000;
    Bouton* boutonHautGauche = nullptr;
    for (auto& bouton : MapBoutons)
    {
        if (bouton.second->getPosX() <= min_x && bouton.second->getPosY() <= min_y){
            min_x = bouton.second->getPosX();
            min_y = bouton.second->getPosY();
            boutonHautGauche = bouton.second;
        }
    }
    boutonHautGauche->setFlagActivated(true);

}


void WelcomeScreen::handleEvent()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        // Cas du play alors on prend le bouton a sa droite
        if (MapBoutons["Play"]->getIsActivated() == true){

            MapBoutons["Play"]->setFlagActivated(false);
            MapBoutons["Quit"]->setFlagActivated(true);
        }
        
    
        // sinon : on ne fait rien, car on ne peut pas aller plus loin a droite
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // Cas du play alors on prend le bouton a sa droite
        if (MapBoutons["Quit"]->getIsActivated() == true){

            MapBoutons["Quit"]->setFlagActivated(false);
            MapBoutons["Play"]->setFlagActivated(true);  }
        
        // sinon : on ne fait rien, car on ne peut pas aller plus loin a gauche
    }

    // on verifie si la touche entrée est appuyée
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        for (auto& bouton : MapBoutons)
        {
            // on recherche celui qui est activé : si on le trouve, on renvoit 1
            if (bouton.second->EnterPressed()==1){
                // faire une fonction qui renvoie le nom du bouton pressé 
                this->ProchainScreen = bouton.first; // on donne le nom du nouveau screen via le nom du bouton donc ils doivent avoir le meme nom
            }
            
        }
    }
}



WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
    for (auto& bouton : MapBoutons)
    {
        delete bouton.second;
    }
    
}




