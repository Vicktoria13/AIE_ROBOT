#include "../include/Masque.hpp"
#include <math.h>


/**
 * @brief Constructeur du masque
 * 
 * @param r1 rayon du joueur 1
 * @param r2 rayon du joueur 2
 * @param x1 position x du joueur 1
 * @param y1 position y du joueur 1
 * @param x2 position x du joueur 2
 * @param y2 position y du joueur 2
 */
Masque::Masque(float r1, float r2, int x1, int y1, int x2, int y2):player1(r1), player2(r2)
{
    player1.setPosition(x1, y1);
    player2.setPosition(x2, y2);

    this->_imageMasque.create(860, 860, sf::Color(50, 50, 50, 200));



}

void Masque::eraseMasque(){
    this->_imageMasque.create(860, 860, sf::Color::Transparent);
    this->_textureMasque.loadFromImage(_imageMasque);
    this->_spriteMasque.setTexture(_textureMasque);
}



void Masque::updateMasque(){


    	 // Itération sur chaque pixel de l'image
    this->_imageMasque.create(860, 860, sf::Color(10, 20, 20, 255));
    int rayon1 = player1.getRadius();
    int rayon2 = player2.getRadius();

    int x1 = player1.getPosition().x;
    int y1 = player1.getPosition().y;

    int x2 = player2.getPosition().x;
    int y2 = player2.getPosition().y;

    // on itere sur tous les pixels se situant dans un cercle de rayon rayon1 et rayon2 autour des joueurs
    
    for (int x = x1 - rayon1; x < x1 + rayon1; x=x+2)
    {
        for (int y = y1- rayon1 ;y < y1+rayon1; y=y+2)
        {
          _imageMasque.setPixel(x, y, sf::Color::Transparent);
            
    }
    }

    for (int x = x2 - rayon2; x < player2.getPosition().x + rayon2; x=x+2)
    {
        for (int y = y2- rayon2 ;y < player2.getPosition().y +rayon2; y=y+2)
        {
            if (std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2)) < rayon2)
            {
                _imageMasque.setPixel(x, y, sf::Color::Transparent);
                
         }

           
        }
    }
    

    this->_textureMasque.loadFromImage(_imageMasque);
    this->_spriteMasque.setTexture(_textureMasque);


}


/**
 * @brief Dessine le masque sur la fenêtre, centré sur le joueur
 * 
 * @param window 
 */
void Masque::dessineMasque(sf::RenderWindow* window) const
{
    
    window->draw(_spriteMasque);
}



/**
 * @brief Destructeur du masque
 * 
 */
Masque::~Masque()
{
    std::cout << "Destruction du masque" << std::endl;
   

    
}


/**
 * @brief Permet de modifier le rayon du joueur 
 * 
 * @param r rayon du joueur
 */
void Masque::setPlayer1Radius(float r)
{
    player1.setRadius(r);
}



/**
 * @brief Permet de modifier le rayon du joueur 2
 * 
 * @param r rayon du joueur 2
 */
void Masque::setPlayer2Radius(float r)
{
    player2.setRadius(r);
}


/**
 * @brief Permet de modifier la position du joueur 1
 * 
 * @param x position x du joueur 1
 * @param y position y du joueur 1
 */
void Masque::setPlayer1(int x, int y)
{
    player1.setPosition( x,  y);
}


/**
 * @brief Permet de modifier la position du joueur 2
 * 
 * @param x position x du joueur 2
 * @param y position y du joueur 2
 */
void Masque::setPlayer2(int x, int y)
{
    player2.setPosition( x,  y);
}

