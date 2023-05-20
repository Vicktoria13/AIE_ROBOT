#include "../include/Screen.hpp"


void Screen::getTheMostLeftButton(){
        int min_x = 100000;
        int min_y = 100000;
        Bouton *boutonHautGauche = nullptr;
        
        if (!vector_buttons.empty())
        {  

            for (auto &bouton : vector_buttons)
            {
                if (bouton->getPosX() < min_x && bouton->getPosY() < min_y)
                {
                    min_x = bouton->getPosX();
                    min_y = bouton->getPosY();
                    boutonHautGauche = bouton;
                }
            }
            boutonHautGauche->setFlagActivated(true);
        }
}

void Screen::dessinerBoutons(sf::RenderWindow* window){
        for (auto& bouton : vector_buttons)
        {

            if (bouton->getIsActivated() == true)
            {

                bouton->drawContoursBoutton(*window);
            }

            else if (bouton->getIsActivated() == false)
            {
                bouton->drawButton(*window);
            }
        }
    }
