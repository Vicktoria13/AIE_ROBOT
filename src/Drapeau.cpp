#include "../include/Drapeau.hpp"
#include <iostream>

Drapeau::Drapeau()
{

    /* On charge la texture */
    if (!_texture.loadFromFile("../Assets/flag.png"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

    /* on l'associe au sprite*/
    _sprite.setTexture(_texture);
    _sprite.scale(1, 1);

    this->estPositionne = false; // par defaut, lorsque l'on crée une tour ennemi, elle n'est pas positionnée
    this->isCollected = false; // par defaut, le drapeau n'est pas collecté encore


}


/**
 * @brief Destructeur de la classe Drapeau
 * 
 */
Drapeau::~Drapeau()
{

}


/**
 * @brief update si l'on veut faire bouger le drapeau eventuellement avec un bonus
 * 
 * @param NameIfPlayer nom du joueur qui a le drapeau
 * @param maze labyrinthe
 * @return int 
 */
int Drapeau::UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze){
    return 0;
}


/**
 * @brief affiche le drapeau que si il n'est pas collecté
 * 
 * @param window fenetre de rendu
 * @param maze labirynthe de jeu
 */
void Drapeau::DisplayEntite(sf::RenderWindow* window,std::array<std::array<int, 15>, 15>* maze )
{
    if (this->isCollected == false){
         window->draw(_sprite);}
}