#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
class Screen
{
private:
   
public:
// pas de constructeur car c'est une classe abstraite : pas d'inst

    /* destructeur virtuel pour eviter les fuites mémoires */
    virtual ~Screen() {}


    /* methode virtuelle pure */
    virtual void draw(sf::RenderWindow& window) = 0;

    /* methode virtuelle pure */
    virtual void handleEvent(const sf::Event& event) = 0;
};




#endif