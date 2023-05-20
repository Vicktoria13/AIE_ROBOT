#include "../include/Arme.hpp"
#include <iostream>

Arme::Arme(std::string name) 
{
    
    this->_name = name;
    this->isActivated = true;
    this->nbMunitions = 10;

    //on s'assure que le tableau des projectiles est vide
    munitions.clear();
    
}

Arme::~Arme()
{
    std::cout <<"destruction des "<<this->munitions.size()<<" projectiles ..."<<std::endl;
    if (this->munitions.size() != 0)
    {
        
        for (size_t i = 0; i < this->munitions.size(); i++){
            delete munitions[i];

            
        }
    }

    
    
    munitions.clear();
}



/**
 * @brief Permet d'ajouter des projectiles dans le vecteur de projectiles
 * 
 * @param new_x position x du projectile
 * @param new_y position y du projectile
 * @param ang angle de tir
 */
void Arme::addProjectile(int new_x, int new_y,float ang){
   this->munitions.push_back(new Projectile(new_x,new_y,ang));
}



/**
 * @brief permet de tirer avec l'arme, jusqu'a ce que le projectile touche un mur ou sorte de la fenetre
 * 
 * @param window fenetre de rendu
 * @param taille_case taille d'une case
 */
void Arme::Tir(sf::RenderWindow* window, int taille_case){
    for (size_t i = 0; i < munitions.size(); i++)
    {
        if (munitions[i]->Shot( window, taille_case)==-1)
        {
            this->munitions.erase(this->munitions.begin() + i);
        }
      
    }
    
    /*
    for (auto& munition : this->munitions)
    {
        std::cout<<"fonctioon Tir"<<std::endl;
        munition->Shot(maze, window, taille_case);
    }*/
}