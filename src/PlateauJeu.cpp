#include "../include/PlateauJeu.hpp"



/**
 * @brief ajoute un bouton dans la map des boutons
 * 
 */
void PlateauJeu::ajouterBouton(){
  
}



PlateauJeu::PlateauJeu(std::map<std::string, bool>* skills_joueurA,std::map<std::string, bool>* skills_joueurB){

   labyrinthe = {{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,4,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,2,0,0,0,0,0,1,1,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,1,1,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
    {1,0,1,0,0,0,1,1,1,1,1,0,0,0,1},
    {1,0,1,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,2,0,0,0,0,1,0,0,0,2,0,0,0,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,1,1,0,0,0,1,0,0,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,3,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
   }};
   

    // 4 : drapeau du joueur B (doit etre ramassé par le joueur A)
    // 3 : drapeau du joueur A (doit etre ramassé par le joueur B)
    // 2 : tour ennemi
    // 1 : mur
    // 0 : chemin libre

   

    //ajouterBouton();
    //getTheMostLeftButton();


    this->ScreenName = "Play";
    this->ProchainScreen = "";
    this->Quit = false; // on ne quitte pas par defaut


    // liste des entités affichables : JoueurA en bas a gauche, JoueurB en haut a droite
    characters["JoueurA"] = new RobotPlayer(200,750,"JoueurA",skills_joueurA);
    characters["JoueurB"] = new RobotPlayer(700,100,"JoueurB",skills_joueurB);

    characters["EnnemiA"] = new TourEnnemi();
    characters["EnnemiB"] = new TourEnnemi();
    characters["EnnemiC"] = new TourEnnemi();

    characters["DrapeauJoueurA"] = new Drapeau();
    characters["DrapeauJoueurB"] = new Drapeau();


    // Le masque de vision
    this->count_frames = 0;

  
    float rayon_par_defaut = 30.0;
    float rayon_joueurA, rayon_joueurB;

    if (skills_joueurA->at("Capteur Ultrasons") == true){
        rayon_joueurA = 2*rayon_par_defaut;
    }
    else{
        rayon_joueurA = rayon_par_defaut;
    }

    if (skills_joueurB->at("Capteur Ultrasons") == true){
        rayon_joueurB = 2*rayon_par_defaut;
    }
    else{
        rayon_joueurB = rayon_par_defaut;
    }
    
    this->masque2D = new Masque(rayon_joueurA,rayon_joueurB,characters.at("JoueurA")->getPositionX(),characters.at("JoueurA")->getPositionY(),
    characters.at("JoueurB")->getPositionX(),characters.at("JoueurB")->getPositionY());

    //texture lumiere
    
    if (!_textureLight.loadFromFile("../Assets/light.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }


    _spriteLight.setTexture(_textureLight);
    _spriteLight.setScale(0.5,0.5);

    //position en bas
    _spriteLight.setPosition(850,750);


    // fond
    fullBackground.setSize(sf::Vector2f(1920,1080));
    if (!backgroundTexture.loadFromFile("../Assets/Playground.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }
    fullBackground.setTexture(&backgroundTexture);

    //boites de dialogue
    vector_talkbox.push_back(new Talkbox("Lumiere dans l'arene !", 100, 850)); // 1ere position



}








/**
 * @brief Dessine le labyrinthe 2D  et tous les elements statiques lors du jeu (Tour + lab)
 * 
 * @param window 
 */


void PlateauJeu::DrawLabyrinthe(sf::RenderWindow* window) {

    int dec = 10; // permet le redecalage a cause du fait que le sprite n'est pas centré

    FondBlanc(window);
    sf::Texture textureWALL;
    if (!textureWALL.loadFromFile("../Assets/stone.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    sf::Texture textureFREE;
    if (!textureFREE.loadFromFile("../Assets/free.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    int pas =4;// si le pas est trop faible, alors on ne voit pas le quadrillage lors du resize
    for (int i = 0; i < nb_cases; i++){
        for (int j = 0; j < nb_cases; j++){
            
            // allocation statique
            sf::RectangleShape rectangle(sf::Vector2f(case_size-pas, case_size-pas));
            rectangle.setPosition(j*case_size, i*case_size);

            
            
            // on place les murs
            if (labyrinthe[i][j] == 1){
                // noir
                //rectangle.setFillColor(sf::Color::Black);
                rectangle.setTexture(&textureWALL);

              
            }

            // on place les chemins
            else if (labyrinthe[i][j] == 0){ 
                rectangle.setFillColor(sf::Color::White);  
            }

            // on place les tours
            else if (labyrinthe[i][j] == 2){
                rectangle.setFillColor(sf::Color(150, 50, 150, 128));  

                if (!characters.empty())
                {
                    if (characters.at("EnnemiA")->estPositionne == false)
                    {
                        characters.at("EnnemiA")->setPositionX_Y(j * case_size - dec, i * case_size);
                    }

                    else if (characters.at("EnnemiB")->estPositionne == false)
                    {
                        characters.at("EnnemiB")->setPositionX_Y(j * case_size - dec, i * case_size);
                    }

                    else if (characters.at("EnnemiC")->estPositionne == false)
                    {
                        characters.at("EnnemiC")->setPositionX_Y(j * case_size - dec, i * case_size);
                    }
                }
            }

            // on place les drapeaux
            else if (labyrinthe[i][j] == 3){

                //rectangle.setFillColor(sf::Color(0, 200, 200, 100));

                if (!characters.empty()){

                    if (characters.at("DrapeauJoueurA")->estPositionne == false){
                        characters.at("DrapeauJoueurA")->setPositionX_Y(j*case_size + dec, i*case_size);
                    }

                 
                }
            }

            else if (labyrinthe[i][j] == 4){


                if (!characters.empty()){

                    if (characters.at("DrapeauJoueurB")->estPositionne == false){
                        characters.at("DrapeauJoueurB")->setPositionX_Y(j*case_size + dec, i*case_size);
                    }

                 
                }
            }

             window->draw(rectangle);
        }
           
        }
    }




/**
 * @brief Rempli la fenêtre de blanc
 * 
 * @param window 
 */
void PlateauJeu::FondBlanc(sf::RenderWindow* window) const{

    //2D
    window->clear(sf::Color::Black);
    window->draw(fullBackground);

   //3D

    sf::Vector2f dimensions((LARGEUR)*NB_RAYONS  ,CENTRE);

    sf::RectangleShape rect1(dimensions);
    sf::RectangleShape rect2(dimensions);

    //------position
    rect1.setPosition(XX,0);
    rect2.setPosition(XX,CENTRE);

    //on fait une bordure
    sf::RectangleShape bordure(sf::Vector2f(dimensions.x,dimensions.y * 2));
    bordure.setPosition(XX,0);
    bordure.setFillColor(sf::Color::Transparent);
    bordure.setOutlineColor(sf::Color::Red);
    bordure.setOutlineThickness(6);


    //------couleur pour le ray cast : joueur 1 en haut

    rect1.setFillColor(sf::Color(135,206,235,255));
    rect2.setFillColor(sf::Color(20,89,128,255));

    window->draw(rect1);
    window->draw(rect2);
    window->draw(bordure);



    // -------------------------pour le joueur B

    rect2.setFillColor(sf::Color(150,206,235,255));
    rect1.setFillColor(sf::Color(20,89,128,255));

    //------position
    rect1.setPosition(XX,3*CENTRE + OFFSET_Y);
    rect2.setPosition(XX,2*CENTRE+ OFFSET_Y);

    bordure.setPosition(XX,2*CENTRE+ OFFSET_Y);
    bordure.setFillColor(sf::Color::Transparent);
    bordure.setOutlineColor(sf::Color::Blue);
    bordure.setOutlineThickness(6);


 

    window->draw(rect1);
    window->draw(rect2);
    window->draw(bordure);
}




/**
 * @brief Permet de dessiner chaque entité du jeu
 * 
 * @param window 
 */
void PlateauJeu::drawCharacters(sf::RenderWindow* window) {
    for (auto& perso : characters){
        perso.second->DisplayEntite(window,&labyrinthe);
    }
}




/**
 * @brief Permet de dessiner chaque entité du jeu
 * 
 * @param window fenêtre de rendu
 
 */

void PlateauJeu::drawScreens(sf::RenderWindow* window){
  


    //window->clear();
    
    DrawLabyrinthe(window);
    dessinerBoutons(window);
    drawCharacters(window);
    

    // le masque; : met les positions central des joeurs dans le centre des masques
    
    masque2D->setPlayer1(characters.at("JoueurA")->getPositionXSpriteCenter(),characters.at("JoueurA")->getPositionYSpriteCenter());
    masque2D->setPlayer2(characters.at("JoueurB")->getPositionXSpriteCenter(), characters.at("JoueurB")->getPositionYSpriteCenter());



    
    // on affiche la lumiere 20 frames avant le temps d'avertir le joueur
    if (count_frames>=SEUIL_FRAME-20){
        
        window->draw(_spriteLight);
        vector_talkbox[0]->setAffiche(true);
        vector_talkbox[0]->AfficheTalkBox(window);
        
    }

    // Si on est dans l'intervalle d'eveil, on efface donc le masque
    if (count_frames>=SEUIL_FRAME && count_frames < SEUIL_FRAME+TEMPS_EVEIL){

        // on efface une premiere fois 
         masque2D->eraseMasque();
         
         

    }
    
    //le reste du temps, on affiche le masque
    else if (count_frames != SEUIL_FRAME  ){
        masque2D->updateMasque();
        masque2D->dessineMasque(window);
        vector_talkbox[0]->setAffiche(false);
        
        
        
        
    }

    count_frames++;
    
    if (count_frames == SEUIL_FRAME+TEMPS_EVEIL){
            count_frames = 0;}
    

    //
    for (auto& talkbox : vector_talkbox){
        talkbox->AfficheTalkBox(window);
    }
    

}


/**
 * @brief gere les evenements clavier
 * 
 */
void PlateauJeu::handleEvent(){

      
    /* Personnages */

    if (!characters.empty()){

            int val_checkA = characters.at("JoueurA")->UpdateEvent("JoueurA", &labyrinthe);
            int val_checkB = characters.at("JoueurB")->UpdateEvent("JoueurB", &labyrinthe);

            // A a trouvé le drapeau de B OU B est mort : A a gagné
            if (val_checkA == 1 || val_checkB == 2)
            {
             this->ProchainScreen = "GameOver_B_Lost";
            }

            // B a trouvé le drapeau de A OU A est mort : B a gagné            
            else if (val_checkA==2 || val_checkB==1){
                // plus de vie pour un des joueurs
                this->ProchainScreen = "GameOver_A_Lost";
            }
    }


    
}


/**
 * @brief Destructeur
 * 
 */
PlateauJeu::~PlateauJeu(){

    std::cout<<"Destruction du plateau de jeu"<<std::endl;
    for (auto& perso : characters){
        delete perso.second;
        std::cout<<"Destruction du personnage "<<perso.first<<std::endl;
    }
    characters.clear();

    for (auto& bouton : vector_buttons){
        delete bouton;
    }

    delete masque2D;
}