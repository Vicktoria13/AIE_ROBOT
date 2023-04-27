//g++ main.cpp -lsfml-graphics -lsfml-window -lsfml-system




#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Chargement des textures et création du sprite
    sf::Texture texbonhomme;
    texbonhomme.loadFromFile("robotPlayer.png");
    sf::Sprite sprite(texbonhomme);
    // On redimensionne le sprite pour le rendre 5 fois plus petit
    sprite.scale(0.5, 0.5);
    sprite.setPosition(0, 0);

    sf::Texture texrock;
    texrock.loadFromFile("TourEnnemie.png");
    sf::Sprite sprite2(texrock);
    sprite2.scale(1, 1);
    sprite2.setPosition(400, 300);

    sf::Vector2f previous;
    



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

        previous.x = sprite.getPosition().x;
        previous.y = sprite.getPosition().y;

        // Gestion des mouvements
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 0.2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + 0.2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            sprite.setPosition(sprite.getPosition().x - 0.2, sprite.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sprite.setPosition(sprite.getPosition().x + 0.2, sprite.getPosition().y);
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

                //sprite2 : rock
                //sprite : bonhomme

            // collision par la gauche
            if (sprite.getPosition().x < sprite2.getPosition().x)
            {
                sprite.setPosition(previous.x ,previous.y);
            }

            // collision par la droite
            if (sprite.getPosition().x > sprite2.getPosition().x)
            {
                //sprite.setPosition(sprite2.getPosition().x + sprite2.getGlobalBounds().width, sprite.getPosition().y);
               sprite.setPosition(previous.x ,previous.y);
            }
            if (sprite.getPosition().y < sprite2.getPosition().y)
            {
                sprite.setPosition(previous.x ,previous.y);
            }
            if (sprite.getPosition().y > sprite2.getPosition().y)
            {
                sprite.setPosition(previous.x ,previous.y);
            }
        }

        sf::RectangleShape boundingPerso(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    boundingPerso.setPosition(sprite.getPosition().x, sprite.getPosition().y);
    boundingPerso.setFillColor(sf::Color(255, 0, 0, 128));

    sf::RectangleShape boundingRock(sf::Vector2f(sprite2.getGlobalBounds().width, sprite2.getGlobalBounds().height));
    boundingRock.setPosition(sprite2.getPosition().x, sprite2.getPosition().y);
    boundingRock.setFillColor(sf::Color(0, 0, 255, 128));
        


        // Effacement de la fenêtre
        window.clear();

        // Affichage du sprite
        window.draw(sprite);
        window.draw(sprite2);

        window.draw(boundingPerso);
        window.draw(boundingRock);

        // Actualisation de la fenêtre
        window.display();
    }

    return 0;
}