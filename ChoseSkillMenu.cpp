#include "ChoseSkillMenu.hpp"

void ChoseSkillMenu::ajoutBouton(){
     // Bouton Plau en bleu
    MapBoutons["Play"] = new Bouton(400, 800, 200, 100, "Play",  sf::Color(20,20,100,200),false);

    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200),false);

    // Ajout du choix des skills

    std::cout << "Ajout des boutons skills" << std::endl;

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
    if (!backgroundTexture.loadFromFile("lab.jpg"))
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


void ChoseSkillMenu::drawScreens(sf::RenderWindow& window){
    window.draw(this->fullBackground);
    window.draw(this->Title);

}



