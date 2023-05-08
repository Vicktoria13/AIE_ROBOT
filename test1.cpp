//g++ -o test1 test1.cpp -lsfml-graphics -lsfml-window -lsfml-system




#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    const int nb_cases = 10; // par exemple
std::array<std::array<int, nb_cases>, nb_cases> *labyrinthe = new std::array<std::array<int, nb_cases>, nb_cases>();

// Initialisation de chaque case du tableau
for(int i = 0; i < nb_cases; i++) {
    for(int j = 0; j < nb_cases; j++) {
        (*labyrinthe)[i][j] = 0; // ou une autre valeur initiale
    }
}

// initialisation avec accolades


//affichage
for(int i = 0; i < nb_cases; i++) {
    for(int j = 0; j < nb_cases; j++) {
        std::cout << (*labyrinthe)[i][j] << " ";
    }
    std::cout << std::endl;
}

return 0;
}