#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief 
 * 
 * @warning Attention : il faut que le nom des boutons destinés a changer de page, soit le nom de la page a aller visiter !!
 */
class Screen
{
protected:
    /*Attributs permettant de connaitre le nom de la prochaine fenetre a aller visiter */
   std::string ProchainScreen;
   std::string ScreenName;

   bool Quit;


public:
// pas de constructeur car c'est une classe abstraite : pas d'inst
    
    /* destructeur virtuel pour eviter les fuites mémoires */
    virtual ~Screen()  {}


    /* methode virtuelle pure */
    virtual void drawScreens(sf::RenderWindow* window) = 0;

    /* methode virtuelle pure permet de gerer les evenements clavier dans chaque screen */
    virtual void handleEvent() = 0;

    /* getters */
    std::string getProchainScreen() const {
        return ProchainScreen;
    };

    std::string getScreenName() const {
        return ScreenName;
    };

    bool getQuit() const {
        return Quit;
    };

};




#endif