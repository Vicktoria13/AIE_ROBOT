#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    sf::Font font;
    if (!font.loadFromFile("ccwild.ttf"))
    {
        std::cout << "Error loading font\n";
        return 1;
    }

    sf::Text text1("Joueur 1", font, 60);
    text1.setFillColor(sf::Color::White);
    text1.setStyle(sf::Text::Bold);
    sf::FloatRect text1Bounds = text1.getLocalBounds();
    text1.setOrigin(text1Bounds.left + text1Bounds.width / 2.0f, text1Bounds.top + text1Bounds.height / 2.0f);
    text1.setPosition(window.getSize().x / 2.0f, window.getSize().y / 3.0f);

    sf::Text text2("Joueur 2", font, 60);
    text2.setFillColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold);
    sf::FloatRect text2Bounds = text2.getLocalBounds();
    text2.setOrigin(text2Bounds.left + text2Bounds.width / 2.0f, text2Bounds.top + text2Bounds.height / 2.0f);
    text2.setPosition(window.getSize().x / 2.0f, window.getSize().y / 3.0f * 2);

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

        window.clear(sf::Color::Black);
        window.draw(text1);
        window.draw(text2);
        window.display();
    }

    return 0;
}
