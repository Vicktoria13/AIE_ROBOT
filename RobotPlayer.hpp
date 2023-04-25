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


public:
    RobotPlayer(int x, int y);
    ~RobotPlayer();

    void DisplayEntite(sf::RenderWindow* window);
};

#endif