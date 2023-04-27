#include <SFML/Graphics.hpp>

int main()
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jeu avec sprite et obstacle");

    // Chargement des textures
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png"))
    {
        return EXIT_FAILURE;
    }

    sf::Texture obstacleTexture;
    if (!obstacleTexture.loadFromFile("obstacle.png"))
    {
        return EXIT_FAILURE;
    }

    // Création des sprites
    sf::Sprite playerSprite(playerTexture);
    playerSprite.setPosition(50, 50);

    sf::Sprite obstacleSprite(obstacleTexture);
    obstacleSprite.setPosition(375, 275);

    // Boucle de jeu
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

        // Déplacement du personnage
        float speed = 5.0;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            playerSprite.move(-speed, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            playerSprite.move(speed, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerSprite.move(0, -speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerSprite.move(0, speed);
        }

        // Détection de la collision entre le joueur et l'obstacle
        if (playerSprite.getGlobalBounds().intersects(obstacleSprite.getGlobalBounds()))
        {
            // Calcul de la distance entre les deux sprites sur l'axe x et y
            float deltaX = playerSprite.getPosition().x - obstacleSprite.getPosition().x;
            float deltaY = playerSprite.getPosition().y - obstacleSprite.getPosition().y;

            // Empêchement du déplacement dans la direction de l'obstacle
            if (abs(deltaX) > abs(deltaY))
            {
                if (deltaX > 0)
                {
                    // Collision à droite de l'obstacle
                    playerSprite.setPosition(obstacleSprite.getPosition().x + obstacleSprite.getGlobalBounds().width, playerSprite.getPosition().y);
                }
                else
                {
                    // Collision à gauche de l'obstacle
                    playerSprite.setPosition(obstacleSprite.getPosition().x - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
                }
            }
            else
            {
                if (deltaY > 0)
                {
                    // Collision en dessous de l'obstacle
                    playerSprite.setPosition(playerSprite.getPosition().x, obstacleSprite.getPosition().y + obstacleSprite.getGlobalBounds().height);
                }
                else
                {
                    // Collision au dessus de l'obstacle
                    playerSprite.setPosition(playerSprite.getPosition().x, obstacleSprite.getPosition().y - playerSprite.getGlobalBounds().height);
                }
            }
        }

        // Affichage des sprites et de la fenêtre
        window.clear(sf::Color::White);
        window.draw(playerSprite);
        window.draw(obstacleSprite);

        window.display();
    }

    return EXIT_SUCCESS;
}

//g++ -c test.cpp -o test.o -lsfml-graphics -lsfml-window -lsfml-system
       
