#include "WelcomeScreen.hpp"
#include <iostream>
// classe dérivée de Screen
// donc possède une fenêtre déja
// pas besoin de la créer

// void draw(sf::RenderWindow& window);



void WelcomeScreen::ajouterBouton(){

    // Bouton Plau en bleu
    MapBoutons["Play"] = new Bouton(400, 800, 200, 100, "Play",  sf::Color(20,20,100,200));

    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200));
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
                    bouton.second->drawButton(*window);
                }

                // puis le titre
                window->draw(Title);

        }

void WelcomeScreen::handleEvent()
{

}

WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
    
}