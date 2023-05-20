#include "../include/ChoseSkillMenu.hpp"
#include "../include/Screen.hpp"

void ChoseSkillMenu::ajouterBouton(){

    // on a besoin de boutons :
    // Play
    // Quit
    // 2 boutons choix : capteurs
    // 2 boutons choix : arme 1
    // 2 boutons choix : arme 2

     
    //Boutons skills : du joueur A, devant etre alignés selon y
    vector_buttons.push_back(new Bouton(1400, 900, 120, 80, "Play",  sf::Color(20,20,100,200),false));
    vector_buttons.push_back(new Bouton(1600, 900, 120, 80, "Quit",  sf::Color(100,20,20,200),false));

    int x_bouton = 350;
    int y_bouton = 70;

    sf::Color color_bouton(150,0,0,255);

    vector_buttons.push_back(new Bouton(450, 550, x_bouton, y_bouton, "Capteur 3D A", color_bouton,false));
    vector_buttons.push_back(new Bouton(950, 550, x_bouton, y_bouton, "Capteur distance A", color_bouton,false));
    vector_buttons.push_back(new Bouton(1450, 550, x_bouton, y_bouton, "Vitesse A",  color_bouton,false));

    //Boutons skills : du joueur B, devant etre alignés selon y

    vector_buttons.push_back(new Bouton(450, 770, x_bouton, y_bouton, "Capteur 3D B",  color_bouton,false));
    vector_buttons.push_back(new Bouton(950, 770, x_bouton, y_bouton, "Capteur distance B",  color_bouton,false));
    vector_buttons.push_back(new Bouton(1450, 770, x_bouton, y_bouton, "Vitesse B", color_bouton,false));

    //aucun skill
    nb_skills_A = 0;
    nb_skills_B = 0;





}





/**
 * @brief Constructeur par défaut
 * 
 */
ChoseSkillMenu::ChoseSkillMenu(){
   
    this->ScreenName = "Start";

    this->ajouterBouton();


    this->getTheMostLeftButton(); // On met le bouton le plus en haut a gauche a true

    // Chargement de l'image de fond
    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("../Assets/MenuSkill.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    fullBackground.setTexture(&backgroundTexture);
    fullBackground.setScale(1,1);


    this->ProchainScreen = "";
    this->Quit = false; // on ne quitte pas par defaut

    //skills des joueurs
    // On initialise tous a faux par defaut, le joueur pourra selectionner 2 parmi les 3 skills présents
    skills_joueurA["Capteur Ultrasons"] = false;
    skills_joueurA["Capteur 3D"] = false;
    skills_joueurA["Vitesse rapide"] = false;

    skills_joueurB["Capteur Ultrasons"] = false;
    skills_joueurB["Capteur 3D"] = false;
    skills_joueurB["Vitesse rapide"] = false;


    
    std::cout <<"fin du constructeur de chose skill menu"<<std::endl;




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

   

    // puis les boutons
    dessinerBoutons(window);

    // puis les boites de dialogue
    for (auto& talkbox : vector_talkbox){
        talkbox->AfficheTalkBox(window);
    }
   
}





/**
 * @brief Permet de gerer les evenements clavier pour le menu et les choix de skills
 * 
 */

void ChoseSkillMenu::handleEvent()
    
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        //on cherche le bouton acrif
        for (size_t i = 0; i < vector_buttons.size(); i++)
        {

            if (i==vector_buttons.size()-1){

                if (vector_buttons[i]->getIsActivated() == true){

                    vector_buttons[i]->setFlagActivated(false);
                    vector_buttons[0]->setFlagActivated(true);
                    break;
                }
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
        for (size_t i = vector_buttons.size()-1; i >= 0; i--)
        {
            if (i==0){
                if (vector_buttons[i]->getIsActivated() == true){

                    vector_buttons[i]->setFlagActivated(false);
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

                
                /*********** QUIT ********************************/

                if (bouton->getName() == "Quit")
                    this->Quit = true;


                /****************** SKILLS DU JOUEUR A ***************************/

                else if (bouton->getName() == "Capteur 3D A" && nb_skills_A<2){

                    skills_joueurA["Capteur 3D"] = true;
                    nb_skills_A++;
                }


                else if (bouton->getName()=="Capteur distance A" && nb_skills_A<2){
                    
                    skills_joueurA["Capteur Ultrasons"] = true;
                    nb_skills_A++;

                }

                else if (bouton->getName()=="Vitesse A" && nb_skills_A<2){
                    
                    skills_joueurA["Vitesse rapide"] = true;
                    nb_skills_A++;

                }


                /****************** SKILLS DU JOUEUR B ***************************/

               

                else if (bouton->getName() == "Capteur 3D B" && nb_skills_B<2){

                    skills_joueurB["Capteur 3D"] = true; // donner le skill au joueur A
                    nb_skills_B++;
                }

                else if (bouton->getName() == "Capteur distance B"  && nb_skills_B<2 ){

                    skills_joueurB["Capteur Ultrasons"] = true; // donner le skill au joueur A
                    nb_skills_B++;
                }

                else if (bouton->getName() == "Vitesse B"  && nb_skills_B<2){

                    skills_joueurB["Vitesse rapide"] = true; // donner le skill au joueur A
                    nb_skills_B++;
                }

                /******** Pour valider et changer de fenetre************************/

                else if (bouton->getName() == "Play" && nb_skills_A==2 && nb_skills_B==2){
                    this->ProchainScreen = bouton->getName(); // on donne le nom du nouveau screen via le nom du bouton donc ils doivent avoir le meme nom
                    AfficheInfosSkills();
                    break;
                }

                else{
                    std::cout<<"Vous n'avez pas choisi le bon nombre de skills"<<std::endl;
                    std::cout<<" Car vous avez choisi "<<nb_skills_A<<" skills pour le joueur A et "<<nb_skills_B<<" skills pour le joueur B"<<std::endl;

                    //alors on affiche une boite de dialogue
                    vector_talkbox.push_back(new Talkbox("2 skills par joueur !",100,830));


                }



                bouton->changeStateButton();
            }
        }
    }


  

}

    

void ChoseSkillMenu::AfficheInfosSkills(){
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"Pour le joueur A, l'état des skills est : "<<std::endl;
    for (auto& skill :skills_joueurA ){
        std::cout<<skill.first << " = " << skill.second <<std::endl;
    }

    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"Pour le joueur B, l'état des skills est : "<<std::endl;
    for (auto& skill :skills_joueurB ){
        std::cout<<skill.first << " = " << skill.second <<std::endl;
    }

    std::cout<<"------------------------------------------------"<<std::endl;
}




ChoseSkillMenu::~ChoseSkillMenu(){

    std::cout<<"Destruction de l'ecran de  choix "<<std::endl;
    if (this->vector_buttons.empty() == false){
        for (auto &bouton : vector_buttons)
        {
            delete bouton;
        }
    }

    for (auto &talkbox : vector_talkbox)
    {
        delete talkbox;
    }

   
}