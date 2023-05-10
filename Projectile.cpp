#include "Projectile.hpp"
#include <iostream>
#include <iostream>
#include <math.h>

/**
 * @brief Constructeur de Projectile
 * 
 * @param x position x
 * @param y position y
 * @param ang angle de tir
 */
Projectile::Projectile(int x, int y, float ang ): _projectile(){
   
    this->angle_shot = ang;

    this->_projectile.setPosition(x,y);
    this->_projectile.setRadius(RAYON_PROJECTILE);

    if (!this->_texture.loadFromFile("Assets/shot.png"))
    {
        std::cout << "Erreur lors du chargement de l'arme" << std::endl;
    }
    this->_projectile.setTexture(&this->_texture);

}


int Projectile::Shot( sf::RenderWindow* window, int taille_case){
    

    _projectile.move(20*cos(angle_shot),20*sin(angle_shot));
    if (_projectile.getPosition().y < 0 ){
        return -1;
    }
    window->draw(_projectile); // Dessine le cercle dans la fenêtre de rendu

    return 0;
    /*
    int nx = _projectile.getPosition().x;
    int ny = _projectile.getPosition().y;

    int Nx = (nx)/taille_case;
    int Ny = (ny)/taille_case;

    std::cout<<"avant le while"<<std::endl;

    
    while (Ny < 15 && Nx<15 && (*maze)[Ny][Nx] != 1 && (*maze)[Ny][Nx] != 2 && (*maze)[Ny][Nx] !=3 && (*maze)[Ny][Nx] !=4){
   

        _projectile.move(10*cos(angle_shot),10*sin(angle_shot));

        window->draw(_projectile); // Dessine le cercle dans la fenêtre de rendu

        nx = _projectile.getPosition().x;
        ny = _projectile.getPosition().y;
        std::cout<<"nx : "<<nx<<std::endl;

    }

*/

}

/**
 * @brief Destructeur de Projectile
 * 
 */
Projectile::~Projectile(){
}