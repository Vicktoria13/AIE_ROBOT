#include <SFML/Graphics.hpp>
#include "Renderer.hpp"

/**
 * @brief Classe SFMLRenderer
 * @class SFMLRenderer
 * @author Victoria
 * 
 * 
 */


class SFMLRenderer : public Renderer{

    private:
        
        // Pointeur vers une fenetre SFML : alloc dynamique
        sf::RenderWindow* fenetre_jeu;


    public:

        // constructeur : alloc dynamique
        SFMLRenderer();

        // donc destructeur : free dynamique
        ~SFMLRenderer();
        void waitExit();

        //getter
        sf::RenderWindow& getFenetreJeu();
        
};