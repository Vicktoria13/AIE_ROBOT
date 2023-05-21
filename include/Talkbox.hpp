#ifndef TALKBOX_HPP
#define TALKBOX_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Talkbox
{
protected:
    
    sf::Sprite _talkbox;
    sf::Texture _texture;

    sf::Text _text;
    sf::Font _font;

    bool Affiche;

public:
    Talkbox(std::string text, int pos_x, int pos_y);
    ~Talkbox();

    void AfficheTalkBox(sf::RenderWindow* window);

    /*getter*/
    void setAffiche(bool affiche) { this->Affiche = affiche; }

    /*getter*/
    bool getAffiche() { return this->Affiche; }

};



#endif