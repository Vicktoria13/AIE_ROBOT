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
    std::cout<<"Creation de l'ecran d'accueil"<<std::endl;
    //Ajout des boutons a la liste de boutons : Play et Quit
    this->ajouterBouton();

    // On met le bouton le plus en haut a gauche a true
    this->getTheMostLeftButton();
   
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

                // puis le titre
                

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

/**
 * @brief Met le bouton a gauche du bouton actif a true, et le bouton actif a false
 * le bouton a gauche se traduit par un x plus petit.
 * 
 */
void WelcomeScreen::getLeftButton(Bouton *boutonActif){
    
    for (auto& bouton : MapBoutons)
    {
        if (bouton.second->getPosX() <= boutonActif->getPosX()){
            bouton.second->setFlagActivated(false);
            boutonActif->setFlagActivated(true);
        }
    }
}



/**
 * @brief Permettra de gerer les evenements clavier : 
 * Si les touches <- ou -> sont appuyées, on change de bouton, ce qui change sa couleur et l'entoure
 * 
 */

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
            MapBoutons["Play"]->setFlagActivated(true);
        }
        
        // sinon : on ne fait rien, car on ne peut pas aller plus loin a gauche
}
}



WelcomeScreen::~WelcomeScreen()
{   
    std::cout << "Destruction de l'ecran d'accueil" << std::endl;
    
}




