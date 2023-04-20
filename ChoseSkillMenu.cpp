#include "ChoseSkillMenu.hpp"

void ChoseSkillMenu::ajoutBouton(){

    // on a besoin de boutons :
    // Play
    // Quit
    // 2 boutons choix : capteurs
    // 2 boutons choix : arme 1
    // 2 boutons choix : arme 2

     // Bouton Plau en bleu
    MapBoutons["Valide"] = new Bouton(400, 800, 200, 100, "Valide",  sf::Color(20,20,100,200),false);

    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200),false);



}

/**
 * @brief Constructeur par défaut
 * 
 */
ChoseSkillMenu::ChoseSkillMenu(){

    std::cout<<"Creation de l'ecran de  choix "<<std::endl;

    this->ajoutBouton();

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
    Title.setString("Choisissez vos skills !");



} 


void ChoseSkillMenu::drawScreens(sf::RenderWindow* window){

    window->clear();
    
    window->draw(this->fullBackground);
    window->draw(this->Title);

}



void ChoseSkillMenu::handleEvent(){
    std::cout<<"handleEvent de l'ecran de  choix "<<std::endl;
    
}



ChoseSkillMenu::~ChoseSkillMenu(){

    std::cout<<"Destruction de l'ecran de  choix "<<std::endl;
}