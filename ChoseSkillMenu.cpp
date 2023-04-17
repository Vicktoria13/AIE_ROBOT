#include "ChoseSkillMenu.hpp"

void ChoseSkillMenu::ajoutBouton(){
     // Bouton Plau en bleu
    MapBoutons["Play"] = new Bouton(400, 800, 200, 100, "Play",  sf::Color(20,20,100,200));

    // Bouton Quit en rouge
    MapBoutons["Quit"] = new Bouton(1300, 800, 200, 100, "Quit",  sf::Color(100,20,20,200));

    // Ajout du choix des skills

    std::cout << "Ajout des boutons skills" << std::endl;

}



