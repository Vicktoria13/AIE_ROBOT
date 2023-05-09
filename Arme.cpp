#include "Arme.hpp"
#include <iostream>

Arme::Arme(std::string name) : munitions()
{
    
    this->_name = name;
    this->isActivated = true;
    this->nbMunitions = 10;

    if (this->munitions.empty())
    {
        std::cout << "Le vecteur de munitions est vide" << std::endl;
    }
    else
    {
        std::cout << "Le vecteur de munitions n'est pas vide" << std::endl;
    }

    

    
}

Arme::~Arme()
{
    std::cout << "Arme détruite" << std::endl;
    for (auto& munition : this->munitions)
    {
        delete munition;
    }
    munitions.clear();
}




void Arme::addProjectile(int new_x, int new_y,float ang){
   this->munitions.push_back(new Projectile(new_x,new_y,ang));
}

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