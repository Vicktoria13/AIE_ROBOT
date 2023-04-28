#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
    const int width = 720;
    const int height = 720;

    

    // Définition des cercles
    sf::CircleShape circle1(75.f);
    circle1.setPosition(100.f, 100.f);

    sf::CircleShape circle2(75.f);
    circle2.setPosition(350.f, 350.f);

   

    

	// Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(1800, 1800), "Image");
	window.setFramerateLimit(20);

	
	// mon fond
	sf::Texture _texture;
    if (!_texture.loadFromFile("MenuSkill.jpg"))
    {
        throw std::runtime_error("Erreur lors du chargement de l'image");
    }

	sf::Sprite _sprite(_texture);


	// Création de l'image
    sf::Image image;
    image.create(width, height, sf::Color::Transparent);

	// Affichage de l'image
    sf::Texture texture;
    texture.loadFromImage(image);
	sf::Sprite sprite(texture);
	int nbit = 0;

	 int deplacement = 30;
    while (window.isOpen())
    {
		nbit=0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			circle2.setPosition(circle2.getPosition().x - deplacement, circle2.getPosition().y);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			circle2.setPosition(circle2.getPosition().x + deplacement, circle2.getPosition().y);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{

			circle2.setPosition(circle2.getPosition().x, circle2.getPosition().y - deplacement);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			circle2.setPosition(circle2.getPosition().x, circle2.getPosition().y + deplacement);
		}

		//ZQSD

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			circle1.setPosition(circle1.getPosition().x, circle1.getPosition().y - deplacement);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			circle1.setPosition(circle1.getPosition().x, circle1.getPosition().y + deplacement);


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
			circle1.setPosition(circle1.getPosition().x - deplacement, circle1.getPosition().y);

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			circle1.setPosition(circle1.getPosition().x + deplacement, circle1.getPosition().y);
		}

	
		 // Itération sur chaque pixel de l'image
    for (int x = 1; x < width; x++)
    {
        for (int y = 3; y < height; y=y+3)
        {
            // Récupération de la couleur du pixel
            sf::Color color ;

            // Vérification si le pixel est dans un des cercles avec la distance euclidienne
            if (std::sqrt(std::pow(x - circle1.getPosition().x, 2) + std::pow(y - circle1.getPosition().y, 2)) < circle1.getRadius() ||
				std::sqrt(std::pow(x - circle2.getPosition().x, 2) + std::pow(y - circle2.getPosition().y, 2)) < circle2.getRadius())
            {
				image.setPixel(x, y, sf::Color::Transparent);
            }

			else{

				int distance1 = std::sqrt(std::pow(x - circle1.getPosition().x, 2) + std::pow(y - circle1.getPosition().y, 2));
				int distance2 = std::sqrt(std::pow(x - circle2.getPosition().x, 2) + std::pow(y - circle2.getPosition().y, 2));

				if (distance1 < distance2){
					// cerlce 1 est plus proche
					int dmax = 60;
					float alpha = (255/dmax)*(std::sqrt(std::pow(x - circle1.getPosition().x, 2) + std::pow(y - circle1.getPosition().y, 2)) - circle1.getRadius());

					if (alpha > 255){
						alpha = 255; // noir
						image.setPixel(x, y, sf::Color(0, 0, 0, alpha));
						image.setPixel(x, y-1, sf::Color(0, 0, 0, alpha));
						image.setPixel(x, y-2, sf::Color(0, 0, 0, alpha));

						

					}

					else {
						if (alpha < 0){
							alpha = 0;
							
						}
						image.setPixel(x, y, sf::Color(0, 0, 0, alpha));
					}
				}

				else{
					// cerlce 2 est plus proche
					int dmax = 60;
					float alpha = (255/dmax)*(std::sqrt(std::pow(x - circle2.getPosition().x, 2) + std::pow(y - circle2.getPosition().y, 2)) - circle2.getRadius());

					if (alpha > 255){
						alpha = 255;
						image.setPixel(x, y, sf::Color(0, 0, 0, alpha));
						image.setPixel(x, y-1, sf::Color(0, 0, 0, alpha));
						image.setPixel(x, y-2, sf::Color(0, 0, 0, alpha));

						
						}
					else{
						if (alpha < 0){
							alpha = 0;
						}
						image.setPixel(x, y, sf::Color(0, 0, 0, alpha));
					}
						
					
					

				}

				



				nbit++;
			}

            
        }
    }
		std::cout << nbit << std::endl;
		// on reload
	 	texture.loadFromImage(image);
    	sprite.setTexture(texture);

		window.clear(); // on efface le contenu de la fenêtre

		window.draw(_sprite); // on dessine le fond
        window.draw(sprite); // on dessine le sprite
        window.display(); // on affiche le rendu

    }

	
    return 0;
}
