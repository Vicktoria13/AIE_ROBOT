#include "../include/Ray.hpp"
#include <math.h>
#include <iostream>


/**
 * @brief Constructeur d'un rayon unitaire
 * 
 * @param x position x du point de départ du rayon
 * @param y position y du point de départ du rayon
 * @param angle angle du rayon par rapport à l'horizontal
 */
Ray::Ray(int x, int y, float angle)
{
    this->pos_x = x;
    this->pos_y = y;
    this->angle_horizontal = angle;

  
}


/**
 * @brief Destructeur
 * 
 */
Ray::~Ray()
{
}


/**
 * @brief dessine un rayon unitaire sur la fenetre, partant de la position du robot
 * Dessine le rayon via ses attributs : une position et un angle
 * @param alpha angle du rayon
 * @param px position x du robot
 * @param py position y du robot
 * @param maze le labyrinthe du jeu
 * @param window la fenetre de rendu
 * @param taille_case la taille d'une case du labyrinthe
 */

int Ray::rayon_unitaire(float alpha,  std::array<std::array<int, 15>, 15>* maze, sf::RenderWindow* window, int taille_case,sf::Color colorRayon){
    
    int distance = 0;
    int nx = this->pos_x;
    int ny = this->pos_y;

    int Nx = (nx)/taille_case;
    int Ny = (ny)/taille_case;
    sf::CircleShape point(2.f); // Crée un cercle de rayon 2

    while (Ny < 15 && Nx<15 && (*maze)[Ny][Nx] != 1 && (*maze)[Ny][Nx] != 2 && (*maze)[Ny][Nx] !=3 && (*maze)[Ny][Nx] !=4){
        nx = this->pos_x + distance*cos(alpha);
        ny = this->pos_y + distance*sin(alpha);

        Nx = (nx)/taille_case;
        Ny = (ny)/taille_case;

        

        // tracé du point
        point.setFillColor(colorRayon); // Définit la couleur du cercle en blanc
        point.setPosition(nx, ny); // Positionne le cercle en (100, 100)

        window->draw(point); // Dessine le cercle dans la fenêtre de rendu
        distance =distance+ 1;

    }

    //si on a croisé un drapeau, on met la distance à -100

    if ((*maze)[Ny][Nx] ==3 || (*maze)[Ny][Nx] ==4){
        
        return -500;
    }

 
    return distance;
}

/**
 * @brief setter position x et y du rayon
 * 
 * @param posX position x du rayon
 * @param posY position y du rayon
 */
void Ray::update(float posX, float posY)
{
    this->pos_x = posX;
    this->pos_y = posY;
}


/**
 * @brief affiche les informations du rayon
 * 
 * 
 */
void Ray::affiche_info() const
{
    std::cout << "Angle du rayon par rapport a l'horizontal en radians: " << this->angle_horizontal << std::endl;
}