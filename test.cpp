#include <SFML/Graphics.hpp>

int main()
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ma fenêtre SFML");

    // Chargement de la texture du fond d'écran
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Accueil.jpg"))
    {
        // Erreur lors du chargement de la texture
        return 1;
    }

    // Création du sprite du fond d'écran
    sf::Sprite background(backgroundTexture);

    // Création du rectangle
    sf::RectangleShape rectangle(sf::Vector2f(200, 100));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOrigin(rectangle.getSize() / 2.0f);

    // Calcul de la position initiale du rectangle
    rectangle.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

    // Boucle principale
    while (window.isOpen())
    {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Effacement de la fenêtre
        window.clear();

        // Affichage du fond d'écran et du rectangle
        window.draw(background);
        window.draw(rectangle);

        // Affichage de la fenêtre
        window.display();
    }

    return 0;
}