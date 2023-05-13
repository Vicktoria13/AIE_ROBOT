#include "PlateauJeu.hpp"



/**
 * @brief ajoute un bouton dans la map des boutons
 * 
 */
void PlateauJeu::ajouterBouton(){
    // en bas a droite
    MapBoutons["Quit"] = new Bouton(1500, 900, 100, 80, "Quit",  sf::Color(20,20,100,200),false);
    MapBoutons["Break"] = new Bouton(1700, 900, 100, 80, "Pause",  sf::Color(20,20,100,200),false);
}



PlateauJeu::PlateauJeu(){
    /*
    labyrinthe = {{
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,1},
        {1,0,0,0,0,1,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    }};
    */

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


    this->ScreenName = "Valide";
    this->ProchainScreen = "";
    this->Quit = false; // on ne quitte pas par defaut


    // liste des entités affichables : JoueurA en bas a gauche, JoueurB en haut a droite
    characters["JoueurA"] = new RobotPlayer(100,700,case_size*(nb_cases-1),case_size*(nb_cases-1),"JoueurA");
    characters["JoueurB"] = new RobotPlayer(700,100,case_size*(nb_cases-1),case_size*(nb_cases-1),"JoueurB");

    characters["EnnemiA"] = new TourEnnemi();
    characters["EnnemiB"] = new TourEnnemi();
    characters["EnnemiC"] = new TourEnnemi();

    characters["DrapeauJoueurA"] = new Drapeau("DrapeauJoueurA");
    characters["DrapeauJoueurB"] = new Drapeau("DrapeauJoueurB");


    // Le masque de vision
    this->count_frames = 0;
    float rayon_par_defaut = 35.0;

    this->masque2D = new Masque(rayon_par_defaut,rayon_par_defaut,characters.at("JoueurA")->getPositionX(),characters.at("JoueurA")->getPositionY(),
    characters.at("JoueurB")->getPositionX(),characters.at("JoueurB")->getPositionY());

    //texture lumiere
    
    if (!_textureLight.loadFromFile("Assets/light.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }


    _spriteLight.setTexture(_textureLight);
    _spriteLight.setScale(0.5,0.5);

    //position en bas
    _spriteLight.setPosition(850,800);


   



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
    if (!textureWALL.loadFromFile("Assets/stone.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    sf::Texture textureFREE;
    if (!textureFREE.loadFromFile("Assets/free.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }


    for (int i = 0; i < nb_cases; i++){
        for (int j = 0; j < nb_cases; j++){
            int pas = 4; // si le pas est trop faible, alors on ne voit pas le quadrillage lors du resize
            
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
                rectangle.setFillColor(sf::Color(200, 255, 255, 200));  

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

   //3D

    sf::Vector2f dimensions((LARGEUR)*NB_RAYONS  ,CENTRE);

    sf::RectangleShape rect1(dimensions);
    sf::RectangleShape rect2(dimensions);

    //------position
    rect1.setPosition(XX,0);
    rect2.setPosition(XX,CENTRE);


    //------couleur pour le ray cast : joueur 1 en haut

    rect1.setFillColor(sf::Color(135,206,235,255));
    rect2.setFillColor(sf::Color(0,128,128,255));

    window->draw(rect1);
    window->draw(rect2);



    // -------------------------pour le joueur B

    rect1.setFillColor(sf::Color(140,50,235,255));
    rect2.setFillColor(sf::Color(150,120,100,255));

    //------position
    rect1.setPosition(XX,3*CENTRE + OFFSET_Y);
    rect2.setPosition(XX,2*CENTRE+ OFFSET_Y);

    //------couleur pour le ray cast : joueur 1 en haut

 

    window->draw(rect1);
    window->draw(rect2);
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
  


    window->clear();
    DrawLabyrinthe(window);
    dessinerBoutons(window);
    drawCharacters(window);
    

    // le masque; : met les positions central des joeurs dans le centre des masques
    
    masque2D->setPlayer1(characters.at("JoueurA")->getPositionXSpriteCenter(),characters.at("JoueurA")->getPositionYSpriteCenter());
    masque2D->setPlayer2(characters.at("JoueurB")->getPositionXSpriteCenter(), characters.at("JoueurB")->getPositionYSpriteCenter());

    /*if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    
        masque2D->updateMasque();
        masque2D->dessineMasque(window);
    }
    */

    
    if (count_frames>=SEUIL_FRAME-15){
        
        window->draw(_spriteLight);
    }
    if (count_frames>=SEUIL_FRAME && count_frames < SEUIL_FRAME+TEMPS_EVEIL){

        // on efface une premiere fois 
         masque2D->eraseMasque();

    }
    
    else if (count_frames != SEUIL_FRAME  ){
        masque2D->updateMasque();
        masque2D->dessineMasque(window);
        
    }

    count_frames++;
    
    if (count_frames == SEUIL_FRAME+TEMPS_EVEIL){
            count_frames = 0;}
    

    

}


/**
 * @brief gere les evenements clavier
 * 
 */
void PlateauJeu::handleEvent(){


    /* Boutons */

    if (!MapBoutons.empty()){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            // Cas du play alors on prend le bouton a sa droite
            if (MapBoutons["Break"]->getIsActivated() == true)
            {

                MapBoutons["Break"]->setFlagActivated(false);
                MapBoutons["Quit"]->setFlagActivated(true);

                std::cout << "Bouton play activé" << std::endl;
            }

            // sinon : on ne fait rien, car on ne peut pas aller plus loin a droite
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // Cas du play alors on prend le bouton a sa droite
            if (MapBoutons["Quit"]->getIsActivated() == true)
            {

                MapBoutons["Quit"]->setFlagActivated(false);
                MapBoutons["Break"]->setFlagActivated(true);
            }

            // sinon : on ne fait rien, car on ne peut pas aller plus loin a gauche
        }

        // on verifie si la touche entrée est appuyée
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            for (auto &bouton : MapBoutons)
            {
                // on recherche celui qui est activé : si on le trouve, on renvoit 1
                if (bouton.second->EnterPressed() == 1)
                {
                    // faire une fonction qui renvoie le nom du bouton pressé
                    if (bouton.first == "Quit")
                        // on quitte le jeu
                        this->Quit = true;
                    else
                    {
                        this->Quit = false;
                        this->ProchainScreen = bouton.first; // on donne le nom du nouveau screen via le nom du bouton donc ils doivent avoir le meme nom
                    }
                }
            }
        }


    }


    /* Personnages */

    if (!characters.empty()){

    if (characters["JoueurA"]->UpdateEvent("JoueurA", &labyrinthe)==1 || characters["JoueurB"]->UpdateEvent("JoueurB",&labyrinthe)==1){
        this->ProchainScreen = "GameOver";
    }
    
  
    
    }

    // on teste si un des joueurs a touché le flag adverse


    
    
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

    for (auto& bouton : MapBoutons){
        delete bouton.second;
    }

    delete masque2D;
}