#ifndef ENTITEAFFICHABLE_HPP
#define ENTITEAFFICHABLE_HPP

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

    /* Methodes abstraite qui doivent être redefinies dans les classes dérivées !!  */
    virtual void DisplayEntite(sf::RenderWindow* window) = 0;
    virtual void UpdateEvent(std::string NameIfPlayer) = 0;

    /*------------------------------------------------------------------------------*/

    // getter
    int getPositionX() const{
        return this->positionX;
    }

    int getPositionY() const{
        return this->positionY;
    }
    
    int getPositionXSprite() const{
        return this->_sprite.getPosition().x;
    }

    int getPositionYSprite() const{
        return this->_sprite.getPosition().y;
    }

};


#endif