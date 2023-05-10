#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>
#include "Bouton.hpp"
#include <iostream>
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

   std::map<std::string,Bouton*> MapBoutons;


public:
// pas de constructeur car c'est une classe abstraite : pas d'inst
    
    /* destructeur virtuel pour eviter les fuites mémoires */
    virtual ~Screen()  {}


    /* methode virtuelle pure */
    virtual void drawScreens(sf::RenderWindow* window) = 0;

    /* methode virtuelle pure permet de gerer les evenements clavier dans chaque screen */
    virtual void handleEvent() = 0;

    virtual void ajouterBouton()=0;

    virtual void getTheMostLeftButton(){
        int min_x = 100000;
        int min_y = 100000;
        Bouton *boutonHautGauche = nullptr;
        for (auto &bouton : MapBoutons)
        {
            if (bouton.second->getPosX() <= min_x && bouton.second->getPosY() <= min_y)
            {
                min_x = bouton.second->getPosX();
                min_y = bouton.second->getPosY();
                boutonHautGauche = bouton.second;
            }
        }
        boutonHautGauche->setFlagActivated(true);
}

    void dessinerBoutons(sf::RenderWindow* window){
        for (auto& bouton : MapBoutons)
                {
                    
                    if (bouton.second->getIsActivated() == true ){
                        
                        bouton.second->drawContoursBoutton(*window);
                        
                    }

                    else if (bouton.second->getIsActivated() == false){
                        bouton.second->drawButton(*window);
                    }
                }
    }


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

    /* setters */
    void setProchainScreen(std::string ProchainScreen) {
        this->ProchainScreen = ProchainScreen;
    };
};




#endif