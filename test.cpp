#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>

class Button {
public:
    sf::RectangleShape shape;
    bool isRunning;

    Button(sf::Vector2f size, sf::Vector2f position, sf::Color color) {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(color);
        isRunning = false;
    }

    void update(sf::RenderWindow& window) {
        window.draw(shape);
    }

    void changeColor(sf::Color color) {
        shape.setFillColor(color);
    }
};

class Game {
public:
    Game() {
        window.create(sf::VideoMode(800, 600), "Button Test");

        buttons["UP"] = Button(sf::Vector2f(100, 50), sf::Vector2f(350, 200), sf::Color::Red);
        buttons["DOWN"] = Button(sf::Vector2f(100, 50), sf::Vector2f(350, 300), sf::Color::Green);
        buttons["LEFT"] = Button(sf::Vector2f(100, 50), sf::Vector2f(250, 250), sf::Color::Blue);
        buttons["RIGHT"] = Button(sf::Vector2f(100, 50), sf::Vector2f(450, 250), sf::Color::Yellow);
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Up) {
                        buttons["UP"].changeColor(sf::Color::Magenta);
                        buttons["DOWN"].changeColor(sf::Color::Green);
                        buttons["LEFT"].changeColor(sf::Color::Blue);
                        buttons["RIGHT"].changeColor(sf::Color::Yellow);
                    }
                    else if (event.key.code == sf::Keyboard::Down) {
                        buttons["UP"].changeColor(sf::Color::Red);
                        buttons["DOWN"].changeColor(sf::Color::Cyan);
                        buttons["LEFT"].changeColor(sf::Color::Blue);
                        buttons["RIGHT"].changeColor(sf::Color::Yellow);
                    }
                    else if (event.key.code == sf::Keyboard::Left) {
                        buttons["UP"].changeColor(sf::Color::Red);
                        buttons["DOWN"].changeColor(sf::Color::Green);
                        buttons["LEFT"].changeColor(sf::Color::Cyan);
                        buttons["RIGHT"].changeColor(sf::Color::Yellow);
                    }
                    else if (event.key.code == sf::Keyboard::Right) {
                        buttons["UP"].changeColor(sf::Color::Red);
                        buttons["DOWN"].changeColor(sf::Color::Green);
                        buttons["LEFT"].changeColor(sf::Color::Blue);
                        buttons["RIGHT"].changeColor(sf::Color::Cyan);
                    }
                    break;
                }
            }

            window.clear();

            for (auto& button : buttons) {
                button.second.update(window);
            }

            window.display();
        }
    }

private:
    sf::RenderWindow window;
    std::map<std::string, Button> buttons;
};

int main() {
    Game game;
    game.run();
    return 0;
}
