#include "../include/LifeBar.hpp"
#include <iostream>
LifeBar::LifeBar(std::string NameJoueur)
{
    this->value = MAX_LIFE;

    
    if (NameJoueur=="JoueurA"){
        begin_x = 50;
        begin_y = 950;

        color_bar = sf::Color(255,0,0,128);

    }

    else {

       
        begin_x = 500;
        begin_y = 950;

        color_bar = sf::Color(0,0,255,128);
    }

    

    

    // on dessine le cadre
    this->_lifeBar.setSize(sf::Vector2f(LIFE_BAR_WIDTH, LIFE_BAR_HEIGHT)); // 100x10
    this->_lifeBar.setFillColor(sf::Color::Transparent);

    if (NameJoueur=="JoueurA")
        this->_lifeBar.setOutlineColor(sf::Color::Blue);
    else
        this->_lifeBar.setOutlineColor(sf::Color::Red);


    this->_lifeBar.setOutlineThickness(2);
    this->_lifeBar.setPosition(begin_x, begin_y);
    
    NoLife = false;
   
}




/**
 * @brief Dessine la barre de vie
 * Le but est d''avvoir un cadre avec des rectangles de taille fine qui disparaisse
 * 
 * @param window 
 */
void LifeBar::drawLifeBar(sf::RenderWindow* window)
{
    
    //on definit la taille de chaque rectangle
    float width = LIFE_BAR_WIDTH / MAX_LIFE;
    int height = LIFE_BAR_HEIGHT;


    //on rempli la barre de vie avec des rectangles
    for (int i = 0; i < this->value; i++)
    {
        sf::RectangleShape rectangle(sf::Vector2f(10, height));
        rectangle.setFillColor(color_bar);
        rectangle.setPosition(begin_x + i * width, begin_y);

        window->draw(rectangle);
    }

    
}
/**
 * @brief Décrémente la vie de la barre de vie
 * et verifie que le joueur n'est pas mort
 * @return NoLife mis a vrai si le joueur n'a plus de vie
 *          false sinon
 * 
 */
void LifeBar::Lost(){
    this->value--;
    if (this->value==0){
        this->NoLife = true;
    }
}
LifeBar::~LifeBar()
{
}