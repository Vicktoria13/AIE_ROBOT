#ifndef TOURENNEMI_HPP
#define TOURENNEMI_HPP

#include "EntiteAffichable.hpp"


class TourEnnemi : public EntiteAffichable

{
    public :

        TourEnnemi(int x, int y);
        ~TourEnnemi();

        void DisplayTirs(sf::RenderWindow* window);

        void DisplayEntite(sf::RenderWindow* window);
        void UpdateEvent( std::string NameIfPlayer);

  

};

#endif