#ifndef ARMESOLO_HPP
#define ARMESOLO_HPP

#include <SFML/Graphics.hpp>
#include "EntiteAffichable.hpp"

class ArmeSolo : public EntiteAffichable{

    private :
        int nb_munitions;

        int pos_x;
        int pos_y;
        int angle;

        sf::Texture projectileTexture;

    public:
        ArmeSolo();
        ~ArmeSolo();

        void DisplayEntite(sf::RenderWindow* window, std::array<std::array<int, 15>, 15>* maze) ;
        int UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze);
};



#endif