#ifndef ENTITEAFFICHABLE_HPP
#define ENTITEAFFICHABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief classe abstraite
 * 
 */

class EntiteAffichable
{
protected:

    
    sf::Sprite _sprite;
    sf::Texture _texture;

    std::string _name;
    
    int positionX;
    int positionY;

public:

    bool estPositionne;

    /* Methodes abstraite qui doivent être redefinies dans les classes dérivées !!  */
    virtual void DisplayEntite(sf::RenderWindow* window, std::array<std::array<int, 15>, 15>* maze)  = 0;
    virtual int UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze) = 0;

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
        // renvoie la position en haut  a gauchey du sprite
        return this->_sprite.getPosition().y;
    }

    // retourne la position cenrale du sprite en x
    int getPositionXSpriteCenter() const{
        return this->_sprite.getPosition().x + this->_sprite.getGlobalBounds().width/2;
    }

    // retourne la position cenrale du sprite en y
    int getPositionYSpriteCenter() const{
        return this->_sprite.getPosition().y + this->_sprite.getGlobalBounds().height/2;
    }

    sf::Sprite getSprite() {
        return this->_sprite;
    }

    /* setters */

    virtual void setPositionX_Y(int x, int y){
        this->_sprite.setPosition(x, y);
        this->estPositionne = true;
        
    
    }

    virtual ~EntiteAffichable(){
        std::cout<<"Destruction de l'entite affichable"<<std::endl;
    }
};


#endif