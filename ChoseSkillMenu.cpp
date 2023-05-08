#include "ChoseSkillMenu.hpp"
#include "Screen.hpp"

void ChoseSkillMenu::ajouterBouton(){

    // on a besoin de boutons :
    // Play
    // Quit
    // 2 boutons choix : capteurs
    // 2 boutons choix : arme 1
    // 2 boutons choix : arme 2

     // Bouton Plau en bleu
    MapBoutons["PlateauJeu"] = new Bouton(400, 800, 200, 100, "Valide",  sf::Color(20,20,100,200),false);

    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200),false);


}





/**
 * @brief Constructeur par défaut
 * 
 */
ChoseSkillMenu::ChoseSkillMenu(){

    this->ajouterBouton();

    this->getTheMostLeftButton();

    // Chargement de l'image de fond

    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("Assets/MenuSkill.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);

     // On ajoute le titre

    if(!this->fontTitle.loadFromFile("Assets/ccwild.ttf")){
        throw("ERROR FONT LOAD");}


    Title.setFont(fontTitle);
    Title.setPosition(380,80);
    Title.setCharacterSize(80);
    Title.setString("Choisissez vos skills !");

    this->ScreenName = "Play";
    this->ProchainScreen = "";
    this->Quit = false; // on ne quitte pas par defaut



} 

/**
 * @brief Dessine les boutons sur la fenetre
 * 
 * @param window 
 */
void ChoseSkillMenu::drawScreens(sf::RenderWindow* window){

    window->clear();    

    // d'abord le fond

    window->draw(fullBackground);

    // puis le titre
    window->draw(Title);

    // puis les boutons
    dessinerBoutons(window);
}






void ChoseSkillMenu::handleEvent()
    
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {   
        // Cas du play alors on prend le bouton a sa droite
        if (MapBoutons["PlateauJeu"]->getIsActivated() == true){

            MapBoutons["PlateauJeu"]->setFlagActivated(false);
            MapBoutons["Quit"]->setFlagActivated(true);

            std::cout<<"Bouton play activé"<<std::endl;
        }
        
    
        // sinon : on ne fait rien, car on ne peut pas aller plus loin a droite
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        // Cas du play alors on prend le bouton a sa droite
        if (MapBoutons["Quit"]->getIsActivated() == true){

            MapBoutons["Quit"]->setFlagActivated(false);
            MapBoutons["PlateauJeu"]->setFlagActivated(true);  
            
        }
        
        // sinon : on ne fait rien, car on ne peut pas aller plus loin a gauche
    }


    // on verifie si la touche entrée est appuyée
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        for (auto& bouton : MapBoutons)
        {
            // on recherche celui qui est activé : si on le trouve, on renvoit 1
            if (bouton.second->EnterPressed()==1){
                // faire une fonction qui renvoie le nom du bouton pressé 
                if (bouton.first == "Quit")
                    // on quitte le jeu
                    this->Quit = true;
                else {
                    this->Quit = false;
                    this->ProchainScreen = bouton.first; // on donne le nom du nouveau screen via le nom du bouton donc ils doivent avoir le meme nom
                }
            }
        }
    }
}



ChoseSkillMenu::~ChoseSkillMenu(){

    std::cout<<"Destruction de l'ecran de  choix "<<std::endl;
    for (auto& bouton : MapBoutons)
    {
        delete bouton.second;
    }
}