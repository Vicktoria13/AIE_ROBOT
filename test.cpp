#include <SFML/Graphics.hpp>

int main()
{
    const int rows = 10;
    const int cols = 10;
    int maze[rows][cols] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                            {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
                            {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
                            {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    const int cellSize = 50;
    const int width = cols * cellSize;
    const int height = rows * cellSize;

    sf::RenderWindow window(sf::VideoMode(width, height), "Labyrinth");
    window.setFramerateLimit(60);

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

        window.clear();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                if (maze[i][j] == 0)
                {
                    cell.setFillColor(sf::Color::Black);
                }
                else
                {
                    cell.setFillColor(sf::Color::White);
                }
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}

// g++ test.cpp -o test -lsfml-graphics -lsfml-window -lsfml-system
