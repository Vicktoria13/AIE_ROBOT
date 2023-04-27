#include "RobotPlayer.hpp"
#include <iostream>


// void DisplayEntite(sf::RenderWindow* window) doit être définie dans RobotPlayer.cpp


RobotPlayer::RobotPlayer(int x, int y, int max_x, int max_y)
{
    std::cout << "Construction du robot joueur" << std::endl;

    this->jaugeVie = 100;
    this->nb_munitions = 10;
    this->nb_pixels_deplacement = 9;

    this->positionX = x;
    this->positionY = y;

    this->limite_deplacement_x = max_x;
    this->limite_deplacement_y = max_y;

    /* On charge la texture */
    if (!_texture.loadFromFile("robotPlayer.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(0.2, 0.2);
    _sprite.setPosition(x, y);

    this->ADrapeau = false;
    this->estPositionne=true;

    

}



/**
 * @brief Check les collisions joueur-murs-tours
 * 
 * @param maze le labyrinthe 2D
 * @param previous les coordonnees precedentes du joueur avant de se deplacer
 */
void RobotPlayer::checkCollision(std::array<std::array<int, 15>, 15> maze, sf::Vector2f* previous){

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){

            // collision avec les elements statiques (murs + tours)
            if (maze[i][j]==1 || maze[i][j]==2 ){
                int pas = 4;
                int case_size = 60;
                sf::RectangleShape rectangle(sf::Vector2f(case_size, case_size));
                rectangle.setPosition(j*case_size, i*case_size);

                // on cree un rectangle qui contient le sprite : si la hit box est trop petite, on la réduit
                 sf::RectangleShape spriteBound(sf::Vector2f(_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height));
                 spriteBound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);

                 sf::RectangleShape Cropped(sf::Vector2f(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2));
                 Cropped.setPosition(_sprite.getPosition().x + _sprite.getGlobalBounds().width / 4, _sprite.getPosition().y + _sprite.getGlobalBounds().height / 4);

                 // si intersection avec un mur qui existe
                 if (Cropped.getGlobalBounds().intersects(rectangle.getGlobalBounds()) ){
                     this->_sprite.setPosition(previous->x, previous->y);
                 
                }
            }
        }
     }


  
}




/**
 * @brief Gere les evenements clavier et modifie les attributs du robot en consequence
 * 
 */

void RobotPlayer::KeyBoardEventARROW(std::array<std::array<int, 15>, 15> maze){
    // joueur A
    /*********DEPLACEMENT******************************/

    sf::Vector2f previous;

    previous.x = this->_sprite.getPosition().x;
    previous.y = this->_sprite.getPosition().y;

     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->_sprite.move(-nb_pixels_deplacement,0);
     }
     
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){       
        this->_sprite.move(nb_pixels_deplacement,0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){  
        this->_sprite.move(0,-nb_pixels_deplacement);      
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){        
        this->_sprite.move(0,nb_pixels_deplacement);     
    }

    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    CheckPosition();
    checkCollision(maze, &previous);
}


/**
 * @brief Permet un controlle via les touches ZQSD
 * 
 */
void RobotPlayer::KeyBoardEventZQSD(std::array<std::array<int, 15>, 15> maze){
    // joueur B

    sf::Vector2f previous;

    previous.x = this->_sprite.getPosition().x;
    previous.y = this->_sprite.getPosition().y;

    /*********DEPLACEMENT******************************/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        this->_sprite.move(-nb_pixels_deplacement,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->_sprite.move(nb_pixels_deplacement,0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        this->_sprite.move(0,-nb_pixels_deplacement);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->_sprite.move(0,nb_pixels_deplacement);

    }

    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    CheckPosition();
    checkCollision(maze, &previous);
    /*********TIR******************************/

}

/**
 * @brief Verifie si le robot est dans les limites du labyrinthe
 * 
 */

void RobotPlayer::CheckPosition(){
    // si on atteint le bord de l'écran, on ne peut plus aller plus loin

    
    if (this->_sprite.getPosition().x < 0){
        this->_sprite.setPosition(0, this->_sprite.getPosition().y);
    }

    if (this->_sprite.getPosition().x > this->limite_deplacement_x){
        this->_sprite.setPosition(this->limite_deplacement_x, this->_sprite.getPosition().y);
    }

    if (this->_sprite.getPosition().y < 0){
        this->_sprite.setPosition(this->_sprite.getPosition().x, 0);
    }

    if (this->_sprite.getPosition().y > this->limite_deplacement_y){
        this->_sprite.setPosition(this->_sprite.getPosition().x, this->limite_deplacement_y);
    }
}


/**
 * @brief Met a jour les attributs du robot en fonction des evenements
 * 
 * @param NameIfPlayer pour distinguer les joueurs et donc les evenements clavier
 */
void RobotPlayer::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15> maze){
    if (NameIfPlayer =="JoueurA"){
        KeyBoardEventZQSD(maze);
    }
    else if (NameIfPlayer =="JoueurB"){
        KeyBoardEventARROW(maze);
}
}


RobotPlayer::~RobotPlayer()
{
    std::cout << "Destruction du robot joueur" << std::endl;
}



void RobotPlayer::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15> maze )
{
    int facteur_retrecicement =2 ;
    window->draw(_sprite);

    /* l'original */
    sf::RectangleShape spriteBound(sf::Vector2f(_sprite.getGlobalBounds().width, _sprite.getGlobalBounds().height));
    spriteBound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
    spriteBound.setFillColor(sf::Color(255,0,0,128));

    window->draw(spriteBound);

    sf::RectangleShape Cropped;
    Cropped.setSize(sf::Vector2f(_sprite.getGlobalBounds().width/facteur_retrecicement, _sprite.getGlobalBounds().height/facteur_retrecicement));
    // il faut le centrer, donc on prend la moitié de la taille du sprite
    Cropped.setPosition(_sprite.getPosition().x + _sprite.getGlobalBounds().width/4, _sprite.getPosition().y + _sprite.getGlobalBounds().height/4);
    Cropped.setFillColor(sf::Color(0,255,0,128));

    window->draw(Cropped);

   
}