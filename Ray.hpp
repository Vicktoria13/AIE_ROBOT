#ifndef RAY_HPP
#define RAY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
class Ray
{
    private:
        float pos_x;
        float pos_y;
        float angle_horizontal;

        
    public:
        Ray(int x, int y, float angle);
        ~Ray();
        float getPosX() const{ return pos_x;}
        float getPosY() const{ return pos_y;}

        float getAngle() const{ 
            std::cout.precision(5);
           
            return angle_horizontal;}
        
        int rayon_unitaire(float alpha, std::array<std::array<int, 15>, 15>* maze, sf::RenderWindow* window,int taille_case,sf::Color colorRayon);

        void affiche_info() const;

        /*setters*/
        void setPosX(int x){this->pos_x = x;}
        void setPosY(int y){this->pos_y = y;}
        void setAngle(float angle){this->angle_horizontal = angle;}

        void update(float posX, float posY);

};


#endif //