#include ENTITEAFFICHABLE_HPP
#include CHOSESKILLMENU_HPP


class EntiteAffichable
{
protected:
    std::string nom;
    sf::Sprite sprite;
    
    int positionX;
    int positionY;

    virtual DisplayEntite(sf::RenderWindow* window);
    

};


#endif