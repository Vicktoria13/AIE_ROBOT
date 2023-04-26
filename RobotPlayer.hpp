#ifndef ROBOTPLAYER_HPP
#define ROBOTPLAYER_HPP

#include "EntiteAffichable.hpp"




/**
 * @brief Classe représentant un robot joueur
 * derivera de EntiteAffichable
 * 
 */


class RobotPlayer : public EntiteAffichable
{
private:

    int jaugeVie;
    int nb_munitions;

    int nb_pixels_deplacement;

    int limite_deplacement_x;
    int limite_deplacement_y;

    bool ADrapeau ;


public:
    RobotPlayer(int x, int y, int max_x, int max_y);
    ~RobotPlayer();

    void DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15> );
    void UpdateEvent(std::string NameIfPlayer);

    void KeyBoardEventARROW();
    void KeyBoardEventZQSD();

    void CheckPosition();
};

#endif