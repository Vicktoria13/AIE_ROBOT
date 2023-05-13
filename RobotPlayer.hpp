#ifndef ROBOTPLAYER_HPP
#define ROBOTPLAYER_HPP

#include "EntiteAffichable.hpp"
#include "Ray.hpp"
#include "Arme.hpp"

#define PI 3.14159265
#define ANGLE_FOCAL PI/3
#define VARIATION_ANGLE 0.005
#define NB_RAYONS (int)((PI-2*ANGLE_FOCAL)/VARIATION_ANGLE) -120
//define pour le déplacement
#define  vitesse_angulaire 0.15
#define  vitesse_deplacement 15

#define nb_cases 15
//define pour l'affichage 3D
#define XX ((nb_cases+3)*60 ) // valeur en x ou commence l'affichage 3D : le premier slice

// -------- pour chaque slice
#define LARGEUR 9//(1920 - XX)/NB_RAYONS // largeur d'un slice :
#define HM (nb_cases)*60/2 // /2 pour que les 2 joueurs puissent entrer
#define CENTRE nb_cases*60/4

#define OFFSET_Y 15
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
    //int longueur_rayon[NB_RAYONS];
    std::vector<int> longueur_rayon;

    //arme
    Arme* _arme;



public:
    RobotPlayer(int x, int y, int max_x, int max_y, std::string name);
    ~RobotPlayer();

    void DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>* maze);
    int UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze);

    void KeyBoardEventARROW(std::array<std::array<int, 15>, 15>* maze);
    void KeyBoardEventZQSD(std::array<std::array<int, 15>, 15>* maze);


    void checkCollision(std::array<std::array<int, 15>, 15>* maze, sf::Vector2f* previous);

    
    /* getter */
    bool getADrapeau(){return this->ADrapeau;}

    void multi_rayon(std::array<std::array<int, 15>, 15>* maze,float rayon_centre,sf::RenderWindow* window);


    /*pour le 3D*/

    void draw3D_rect(sf::RenderWindow* window, int haut, int larg, int x) const;
    void draw3D(sf::RenderWindow* window) const;
};

#endif