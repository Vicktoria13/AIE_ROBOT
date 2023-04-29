#ifndef RAY_HPP
#define RAY_HPP

#include <SFML/Graphics.hpp>
class Ray
{
    private:
        float pos_x;
        float pos_y;
        float angle_horizontal;
    public:
        Ray(int x, int y, int angle);
        ~Ray();
        float getPosX() const{ return pos_x;}
        float getPosY() const{ return pos_y;}
        float getAngle() const{ return angle_horizontal;}
        
        int rayon_unitaire(float alpha, std::array<std::array<int, 15>, 15> maze, sf::RenderWindow* window,int taille_case);

        /*setters*/
        void setPosX(int x){this->pos_x = x;}
        void setPosY(int y){this->pos_y = y;}
        void setAngle(int angle){this->angle_horizontal = angle;}

        void update(float posX, float posY);

};


#endif //