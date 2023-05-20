#ifndef LIFE_HPP
#define LIFE_HPP

#define MAX_LIFE 5
#define MIN_LIFE 0

#define LIFE_BAR_WIDTH 100
#define LIFE_BAR_HEIGHT 10

#include <SFML/Graphics.hpp>

class LifeBar
{
private:

    int value; // entre 0 et MAX_LIFE
    sf::Texture _textureLifeBar;
    sf::Sprite _spriteLifeBar;

    sf::RectangleShape _lifeBar;

    int begin_x;
    int begin_y;

    bool NoLife;
    

public:
    LifeBar(std::string NameJoueur);
    ~LifeBar();

    void drawLifeBar(sf::RenderWindow* window);

    /*setter*/

    void Lost();

    /*getter*/
    int getValue(){return this->value;}

    bool getNoLife(){return this->NoLife;}
};


#endif