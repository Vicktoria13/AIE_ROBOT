#include "PlateauJeu.hpp"



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
    characters["JoueurA"] = new RobotPlayer(100,700,case_size*(TAILLE_LABYRINTHE-1),case_size*(TAILLE_LABYRINTHE-1),"JoueurA");
    characters["JoueurB"] = new RobotPlayer(700,100,case_size*(TAILLE_LABYRINTHE-1),case_size*(TAILLE_LABYRINTHE-1),"JoueurB");

    characters["EnnemiA"] = new TourEnnemi();
    characters["EnnemiB"] = new TourEnnemi();
    characters["EnnemiC"] = new TourEnnemi();

    characters["DrapeauJoueurA"] = new Drapeau("DrapeauJoueurA");
    characters["DrapeauJoueurB"] = new Drapeau("DrapeauJoueurB");


    // Le masque de vision
    float rayon_par_defaut = 80.0;

    this->masque2D = new Masque(rayon_par_defaut,rayon_par_defaut,characters.at("JoueurA")->getPositionX(),characters.at("JoueurA")->getPositionY(),
    characters.at("JoueurB")->getPositionX(),characters.at("JoueurB")->getPositionY());


}





void PlateauJeu::Dessine_cadre(sf::RenderWindow* window) const {
    sf::RectangleShape rectangle(sf::Vector2f((LARGEUR+1)*T,(TAILLE_LABYRINTHE+1)*case_size));
    rectangle.setFillColor(sf::Color(255,0,120,128));
    rectangle.setPosition(XX,0);

    window->draw(rectangle);
}

/**
 * @brief Dessine le labyrinthe 2D  et tous les elements statiques lors du jeu (Tour + lab)
 * 
 * @param window 
 */


void PlateauJeu::DrawLabyrinthe(sf::RenderWindow* window) {

    int dec = 10; // permet le redecalage a cause du fait que le sprite n'est pas centré

    FondBlanc(window);
    sf::Texture texture;
    if (!texture.loadFromFile("Assets/block.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    for (int i = 0; i < TAILLE_LABYRINTHE; i++){
        for (int j = 0; j < TAILLE_LABYRINTHE; j++){
            int pas = 4; // si le pas est trop faible, alors on ne voit pas le quadrillage lors du resize
            
            // allocation statique
            sf::RectangleShape rectangle(sf::Vector2f(case_size-pas, case_size-pas));
            rectangle.setPosition(j*case_size, i*case_size);

            
            
            // on place les murs
            if (labyrinthe[i][j] == 1){
                // noir
                //rectangle.setFillColor(sf::Color::Black);
                rectangle.setTexture(&texture);

              
            }

            // on place les chemins
            else if (labyrinthe[i][j] == 0){ 
                rectangle.setFillColor(sf::Color::White);  
            }

            // on place les tours
            else if (labyrinthe[i][j] == 2){

                rectangle.setFillColor(sf::Color(0, 0, 255, 200));

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
    window->clear(sf::Color::Black);
}




void PlateauJeu::drawCharacters(sf::RenderWindow* window) const{
    for (auto& perso : characters){
        perso.second->DisplayEntite(window,labyrinthe);
    }
}



void PlateauJeu::drawScreens(sf::RenderWindow* window){
    
    DrawLabyrinthe(window);
    dessinerBoutons(window);
    drawCharacters(window);

    // le masque; : met les positions des joeurs dans le centre des masques
    masque2D->setPlayer1(characters.at("JoueurA")->getPositionXSprite(),characters.at("JoueurA")->getPositionYSprite());
    masque2D->setPlayer2(characters.at("JoueurB")->getPositionXSprite(), characters.at("JoueurB")->getPositionYSprite());

    //masque2D->updateMasque();
    //masque2D->dessineMasque(window);

    Dessine_cadre(window);

}


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

    if (characters["JoueurA"]->UpdateEvent("JoueurA", this->labyrinthe)==1 || characters["JoueurB"]->UpdateEvent("JoueurB",this->labyrinthe)==1){
        this->ProchainScreen = "GameOver";
    }
    
  
    
    }

    // on teste si un des joueurs a touché le flag adverse


    
    
}


PlateauJeu::~PlateauJeu(){
    std::cout<<"Destruction du plateau de jeu"<<std::endl;
    for (auto& perso : characters){
        delete perso.second;
        std::cout<<"Destruction du personnage "<<perso.first<<std::endl;
    }

    delete masque2D;
}