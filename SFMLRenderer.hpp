#ifndef SFMLRENDERER_HPP
#define SFMLRENDERER_HPP

#include <SFML/Graphics.hpp>
#include "Renderer.hpp"


/**
 * @brief Classe SFMLRenderer
 * 
 */


class SFMLRenderer : public Renderer {

// attributs
private:
     sf::RenderWindow* fenetre;

public:
    SFMLRenderer();
    ~SFMLRenderer();
    
    void waitForExit();
    
    sf::RenderWindow& getWindow() {return *fenetre;};


};


#endif