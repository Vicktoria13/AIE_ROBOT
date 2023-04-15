#include "WelcomeScreen.hpp"
#include <iostream>
// classe dérivée de Screen
// donc possède une fenêtre déja
// pas besoin de la créer

// void draw(sf::RenderWindow& window);



void WelcomeScreen::ajouterBouton(){

    MapBoutons["Play"] = new Bouton(500, 500, 200, 100, "Play", sf::Color::Green);
    MapBoutons["Quit"] = new Bouton(800, 500, 200, 100, "Quit", sf::Color::Green);
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

    // on applique la texture au rectangle
    
    fullBackground.setTexture(&backgroundTexture);

   
}






/**
 * @brief Dessine tous ses composants sur la fenêtre (ici, le fond d'écran et les boutons)
 * 
 * @param window passe par référence la fenêtre sur laquelle on dessine
 */


void WelcomeScreen::drawScreens(sf::RenderWindow* window){
                std::cout << "dans la fonction draw :Dessin de l'ecran d'accueil" << std::endl;
                std::cout <<window<<std::endl;

                window->clear(sf::Color::Red);
                // d'abord le fond
                window->draw(fullBackground);

                // puis les boutons
                for (auto& bouton : MapBoutons)
                {
                    bouton.second->draw(*window);
                }



        }

void WelcomeScreen::handleEvent(const sf::Event& event)
{
  
}

WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
    
}