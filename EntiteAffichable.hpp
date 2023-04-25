#ifndef ENTITEAFFICHABLE_HPP
#define CHOSESKILLMENU_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief classe abstraite
 * 
 */

class EntiteAffichable
{
protected:
    sf::Sprite _sprite;
    sf::Texture _texture;
    
    int positionX;
    int positionY;

    
public:


    virtual void DisplayEntite(sf::RenderWindow* window) = 0;
    

};


#endif