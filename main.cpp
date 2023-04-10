#include "SFMLRenderer.hpp"
#include "PlateauJeu.hpp"
#include <iostream>

int main(int argc, char* argv[]){

    // On crée un renderer via alloc dynamique
    SFMLRenderer render;
    
    // On crée un plateau de jeu
    PlateauJeu plateau;
    plateau.afficherPlateau(render);

    return 0;


}

