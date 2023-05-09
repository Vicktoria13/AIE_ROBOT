#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#define RAYON_PROJECTILE 15

#include <SFML/Graphics.hpp>
class Projectile
{

    private:
  
    float angle_shot;

    sf::CircleShape _projectile;
    sf::Texture _texture;

    public:

        Projectile(int x, int y, float ang);
        ~Projectile();

        int Shot( sf::RenderWindow* window, int taille_case);

        /* getters */
        int getPosX(){return _projectile.getPosition().x;}
        int getPosY(){return _projectile.getPosition().y;}

};
#endif