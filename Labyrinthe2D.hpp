#ifndef LABYRINTHE2D_HPP
#define LABYRINTHE2D_HPP

#include <array>

// Taille du labyrinthe : 10x10
#define COLONNES 10
#define LIGNES 10

// Taille d'une case en pixels
#define CASE_SIZE 64

typedef std::array<std::array<int, COLONNES>, LIGNES > Matrice2D;

class Labyrinthe2D
{
private:
    Matrice2D Map2D;

public:

    // Constructeur : allocation statique
    Labyrinthe2D();
    
  
};



#endif