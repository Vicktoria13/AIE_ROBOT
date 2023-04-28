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
    RobotPlayer(int x, int y, int max_x, int max_y, std::string name);
    ~RobotPlayer();

    void DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15> maze);
    void UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15> maze);

    void KeyBoardEventARROW(std::array<std::array<int, 15>, 15> maze);
    void KeyBoardEventZQSD(std::array<std::array<int, 15>, 15> maze);


    void checkCollision(std::array<std::array<int, 15>, 15> maze, sf::Vector2f* previous);

    /* getter */
    bool getADrapeau(){return this->ADrapeau;}
};

#endif