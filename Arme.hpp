#ifndef ARME_HPP
#define ARME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.hpp"
#include <iostream>
class Arme 
{
    private:

        //Savoir si l'arme est activée ou non
        bool isActivated;
        std::string _name;
        int nbMunitions;


        std::vector<Projectile*> munitions;



    
    public:

        Arme(std::string name);
        ~Arme();


        void addProjectile(int new_x, int new_y,float ang);
        void Tir(sf::RenderWindow* window, int taille_case);

        // retourne vrai si le vecteur de munitions est vide
        bool estVide(){
            
            return munitions.empty();}

      
            
        


        /**getters*/

        std::vector<Projectile*> getMunitions(){return this->munitions;}

};



#endif