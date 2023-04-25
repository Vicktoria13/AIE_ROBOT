//g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system
//g++ test1.cpp -o test1 -lsfml-graphics -lsfml-window -lsfml-system



#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Chargement des textures et création du sprite
    sf::Texture texbonhomme;
    texbonhomme.loadFromFile("robotPlayer.png");
    sf::Sprite sprite(texbonhomme);
    // On redimensionne le sprite pour le rendre 5 fois plus petit
    sprite.scale(0.2, 0.2);
    sprite.setPosition(0, 0);

    sf::Texture texrock;
    texrock.loadFromFile("block.png");
    sf::Sprite sprite2(texrock);
    sprite2.scale(0.1, 0.1);
    sprite2.setPosition(400, 300);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Gestion des mouvements
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            sprite.move(0, -0.2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.move(0, 0.2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            sprite.move(-0.2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.move(0.2, 0);
        }

        //On gère les collisions contre le bord de la fenêtre
        if (sprite.getPosition().x < 0)
        {
            sprite.setPosition(0, sprite.getPosition().y);
        }
        if (sprite.getPosition().x > 800 - sprite.getGlobalBounds().width)
        {
            sprite.setPosition(800 - sprite.getGlobalBounds().width, sprite.getPosition().y);
        }
        if (sprite.getPosition().y < 0)
        {
            sprite.setPosition(sprite.getPosition().x, 0);
        }
        if (sprite.getPosition().y > 600 - sprite.getGlobalBounds().height)
        {
            sprite.setPosition(sprite.getPosition().x, 600 - sprite.getGlobalBounds().height);
        }

        //On gère les collisions entre les deux sprites : le sprite bonhomme doit s'arrêter quand il touche le sprite rock, et ce de tous les côtés
        if (sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds()))
        {
            if (sprite.getPosition().x < sprite2.getPosition().x)
            {
                sprite.setPosition(sprite2.getPosition().x - sprite.getGlobalBounds().width, sprite.getPosition().y);
            }
            if (sprite.getPosition().x > sprite2.getPosition().x)
            {
                sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, sprite.getPosition().y);
            }
            if (sprite.getPosition().y < sprite2.getPosition().y)
            {
                sprite.setPosition(sprite.getPosition().x, sprite2.getPosition().y - sprite.getGlobalBounds().height);
            }
            if (sprite.getPosition().y > sprite2.getPosition().y)
            {
                sprite.setPosition(sprite.getPosition().x, sprite2.getPosition().y + sprite2.getGlobalBounds().height);
            }
        }
        


        // Effacement de la fenêtre
        window.clear();

        // Affichage du sprite
        window.draw(sprite);
        window.draw(sprite2);

        // Actualisation de la fenêtre
        window.display();
    }

    return 0;
}