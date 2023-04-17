#include <SFML/Graphics.hpp>

void drawRectangle(sf::RenderWindow& window,  sf::RectangleShape& rectangle)
{
    rectangle.setFillColor(sf::Color::White);
    rectangle.setOutlineThickness(5);
    rectangle.setOutlineColor(sf::Color(139, 0, 0)); // Rouge foncé
    window.draw(rectangle);
}

int main()
{
    // Crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Exemple de rectangle");

    // Crée le rectangle
    sf::RectangleShape rectangle(sf::Vector2f(50, 100));
    rectangle.setPosition(300, 250);

    // Boucle principale
    while (window.isOpen())
    {
        // Gère les événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Dessine le rectangle
        window.clear();
        drawRectangle(window, rectangle);

        // Affiche le rendu à l'écran
        window.display();
    }

    return 0;
}
