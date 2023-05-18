#ifndef TALKBOX_HPP
#define TALKBOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Talkbox
{
private:
    
    sf::Sprite _talkbox;
    sf::Texture _texture;

    sf::Text _text;
    sf::Font _font;

public:
    Talkbox(std::string text, int pos_x, int pos_y);
    ~Talkbox();

    void AfficheTalkBox(sf::RenderWindow* window);
};



#endif