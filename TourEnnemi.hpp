#ifndef TOURENNEMI_HPP
#define TOURENNEMI_HPP

#include "EntiteAffichable.hpp"


class TourEnnemi : public EntiteAffichable


{
    private:

        
    public :

        TourEnnemi();
        ~TourEnnemi();

        void DisplayTirs(sf::RenderWindow* window);

        void DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>*  maze );
        int UpdateEvent( std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze);


        /*setter qui change le flag que si on a changé la position*/
        void setPositionX_Y(int x, int y){
            this->_sprite.setPosition(x, y);
            this->estPositionne = true;
        }
    
    

  

};

#endif