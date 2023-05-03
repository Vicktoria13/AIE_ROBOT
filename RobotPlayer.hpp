#ifndef ROBOTPLAYER_HPP
#define ROBOTPLAYER_HPP

#include "EntiteAffichable.hpp"
#include "Ray.hpp"

#define PI 3.14159265
#define ANGLE_FOCAL PI/3
#define VARIATION_ANGLE 0.005
#define NB_RAYONS (int)((PI-2*ANGLE_FOCAL)/VARIATION_ANGLE)
//define pour le déplacement
#define  vitesse_angulaire 0.15
#define  vitesse_deplacement 10


//define pour l'affichage 3D
#define XX (15+1)*60  // valeur en x ou commence l'affichage 3D : le premier slice

// -------- pour chaque slice
#define LARGEUR (1300 - XX)/NB_RAYONS // largeur d'un slice : ici 1 pixel sur x
#define HM 400// hauteur max de chaque slice sur y
#define CENTRE 230//15*60/2 //

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

    //pour le raycasting
    std::vector<Ray*> rayons;
    float variation_angle ;
    float angle_actuel;

    // pour stocker les longueurs de chaque rayon
    int longueur_rayon[NB_RAYONS];

    //


public:
    RobotPlayer(int x, int y, int max_x, int max_y, std::string name);
    ~RobotPlayer();

    void DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15> maze);
    int UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15> maze);

    void KeyBoardEventARROW(std::array<std::array<int, 15>, 15> maze);
    void KeyBoardEventZQSD(std::array<std::array<int, 15>, 15> maze);


    void checkCollision(std::array<std::array<int, 15>, 15> maze, sf::Vector2f* previous);

    
    /* getter */
    bool getADrapeau(){return this->ADrapeau;}

    void multi_rayon(std::array<std::array<int, 15>, 15> maze,float rayon_centre,sf::RenderWindow* window);


    /*pour le 3D*/

    void draw3D_rect(sf::RenderWindow* window, int haut, int larg, int x, int ra) const;
    void draw3D(sf::RenderWindow* window, float angul) const;
};

#endif