#ifndef DRAPPEAU_HPP
#define DRAPPEAU_HPP

#include "EntiteAffichable.hpp"

class Drapeau : public EntiteAffichable
{
protected:
    bool isCollected;
    std::string nomProprietaire;


public:
    Drapeau(std::string nameOwner);
    ~Drapeau();

    /*Methodes a redefinir */

    void DisplayEntite(sf::RenderWindow* window, std::array<std::array<int, 15>, 15>* maze);
    int UpdateEvent(std::string NameIfPlayer,std::array<std::array<int, 15>, 15>* maze) ;


};




#endif