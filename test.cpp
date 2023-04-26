#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    // Définir la taille de la fenêtre
    const int windowWidth = 500;
    const int windowHeight = 500;

    // Définir la taille de la cellule du labyrinthe
    const int cellSize = 50;

    // Définir la grille du labyrinthe
    const int rows = 10;
    const int cols = 10;

    // Créer la fenêtre
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Labyrinthe");

    // Créer la matrice représentant le labyrinthe
    std::vector<std::vector<int>> maze(rows, std::vector<int>(cols, 1));

    // Dessiner les murs
    sf::RectangleShape wall(sf::Vector2f(cellSize, cellSize));
    wall.setFillColor(sf::Color::White);

    // Dessiner les chemins
    sf::RectangleShape path(sf::Vector2f(cellSize, cellSize));
    path.setFillColor(sf::Color::Black);

    // Boucle principale du programme
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

        // Effacer l'écran
        window.clear();

        // Dessiner le labyrinthe
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (maze[i][j] == 1)
                {
                    wall.setPosition(j * cellSize, i * cellSize);
                    window.draw(wall);
                }
                else
                {
                    path.setPosition(j * cellSize, i * cellSize);
                    window.draw(path);
                }
            }
        }

        // Dessiner un objet à la case (2, 3)
        sf::CircleShape object(20);
        object.setFillColor(sf::Color::Red);
        object.setPosition(3 * cellSize + cellSize/2 - object.getRadius(), 2 * cellSize + cellSize/2 - object.getRadius());
        window.draw(object);

        // Afficher la fenêtre
        window.display();
    }

    return 0;
}

// g++ test.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system
