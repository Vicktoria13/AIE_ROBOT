#include <SFML/Graphics.hpp>

int main()
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fenêtre SFML");

    // Chargement de l'image
    sf::Texture texture;
    if (!texture.loadFromFile("Accueil.jpg"))
    {
        // Gestion de l'erreur si le chargement de l'image échoue
        return EXIT_FAILURE;
    }

    // Création du sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255, 255, 255, 200));

    // Redimensionnement du sprite pour qu'il soit proportionnel à la fenêtre
    float scaleX = static_cast<float>(window.getSize().x) / static_cast<float>(texture.getSize().x);
    float scaleY = static_cast<float>(window.getSize().y) / static_cast<float>(texture.getSize().y);
    if (scaleX > scaleY)
    {
        sprite.setScale(scaleX, scaleX);
    }
    else
    {
        sprite.setScale(scaleY, scaleY);
    }

    // Centrage du sprite
    sprite.setPosition((window.getSize().x - sprite.getGlobalBounds().width) / 2,
                        (window.getSize().y - sprite.getGlobalBounds().height) / 2);

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

        // Affichage du fond d'écran
        window.clear(sf::Color::White);
        window.draw(sprite);

        // Actualisation de la fenêtre
        window.display();
    }

    return EXIT_SUCCESS;
}
