#ifndef MASQUE_HPP
#define MASQUE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>




class Masque
{
private:

    sf::CircleShape player1;
    sf::CircleShape player2;

    sf::Texture _textureMasque;
    sf::Sprite _spriteMasque;
    sf::Image _imageMasque;



public:
    Masque(float r1, float r2, int x1, int y1, int x2, int y2);
    ~Masque();

    void dessineMasque(sf::RenderWindow* window) const;

    void updateMasque();

    void eraseMasque();

    /*setters */
    void setPlayer1(int x, int y);
    void setPlayer2(int x, int y);

    
};




#endif