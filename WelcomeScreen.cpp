#include "WelcomeScreen.hpp"
#include <iostream>
// classe dérivée de Screen
// donc possède une fenêtre déja
// pas besoin de la créer

// void draw(sf::RenderWindow& window);



void WelcomeScreen::ajouterBouton(){

    // Bouton Plau en bleu : par défaut, il est mis a true car il est le plus a gauche.
    // Un bouton est true sera est entouré de rouge
    MapBoutons["Play"] = new Bouton(400, 800, 200, 100, "Play",  sf::Color(20,20,100,200),true);

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
    std::cout<<"Creation de l'ecran d'accueil"<<std::endl;
    //Ajout des boutons a la liste de boutons : Play et Quit
    this->ajouterBouton();

   
    // Chargement de l'image de fond

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("Accueil.jpg"))
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

                // puis les boutons
                for (auto& bouton : MapBoutons)
                {
                    
                    if (bouton.second->getIsActivated() == true ){
                        bouton.second->drawContoursBoutton(*window);
                    }
                    bouton.second->drawButton(*window);
                    
                }

                // puis le titre
                window->draw(Title);

        }



/**
 * @brief Parmi toute la liste de Bouton, recupere le bouton le plus a gauche
 * Le plus a gauche se reduit a trouver le minimum de la position x
 * 
 * @return Bouton* 
 */
Bouton* WelcomeScreen::getTheLeftButton(){
    int min_x = 100000;
    Bouton* theLeftButton = nullptr;
    for (auto& bouton : MapBoutons)
    {
        if (bouton.second->getPosX() < min_x){
            min_x = bouton.second->getPosX();
            theLeftButton = bouton.second;
        }
    }

    return theLeftButton;
}

/**
 * @brief Permettra de gerer les evenements clavier : 
 * Si les touches <- ou -> sont appuyées, on change de bouton, ce qui change sa couleur et l'entoure
 * 
 */

void WelcomeScreen::handleEvent()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        
    }
}




WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
    
}


