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
    virtual void drawScreens(sf::RenderWindow* window) = 0;

    /* methode virtuelle pure permet de gerer les evenements clavier dans chaque screen */
    virtual void handleEvent() = 0;


};




#endif