#include "../include/LifeBar.hpp"

LifeBar::LifeBar(std::string NameJoueur)
{
    this->value = MAX_LIFE;

    if (NameJoueur=="JoueurA"){

        if (!this->_textureLifeBar.loadFromFile("../Assets/heartLife.png"))
            throw "ERROR LIFE BAR LOAD";

        begin_x = 50;
        begin_y = 950;

        this->_spriteLifeBar.scale(0.15, 0.15);
    }

    else {
        if (!this->_textureLifeBar.loadFromFile("../Assets/Diamond.png"))
            throw "ERROR LIFE BAR LOAD";

        begin_x = 500;
        begin_y = 950;

        this->_spriteLifeBar.scale(0.35, 0.35);
    }

    this->_spriteLifeBar.setTexture(this->_textureLifeBar);

    this->_lifeBar.setSize(sf::Vector2f(_spriteLifeBar.getGlobalBounds().width * MAX_LIFE + 20, _spriteLifeBar.getGlobalBounds().height+20));
    

    NoLife = false;
   
}



void LifeBar::drawLifeBar(sf::RenderWindow* window)
{

    // on dessine le cadre

    this->_lifeBar.setFillColor(sf::Color::Transparent);
    this->_lifeBar.setOutlineColor(sf::Color::Red);
    this->_lifeBar.setOutlineThickness(2);
    this->_lifeBar.setPosition(begin_x, begin_y);

    window->draw(this->_lifeBar);

    for (int i = 0; i < this->value; i++)
    {
        this->_spriteLifeBar.setPosition(begin_x + i * 40, begin_y);
        window->draw(this->_spriteLifeBar);
    }
}


void LifeBar::Lost(){
    this->value--;
    if (this->value==0){
        this->NoLife = true;
    }
}
LifeBar::~LifeBar()
{
}