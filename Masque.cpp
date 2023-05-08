#include "Masque.hpp"
#include <math.h>


/**
 * @brief Constructeur du masque
 * 
 * @param r1 rayon du joueur 1
 * @param r2 rayon du joueur 2
 * @param x1 position x du joueur 1
 * @param y1 position y du joueur 1
 * @param x2 position x du joueur 2
 * @param y2 position y du joueur 2
 */
Masque::Masque(float r1, float r2, int x1, int y1, int x2, int y2)
{
    player1.setRadius(r1);
    player1.setPosition(x1, y1);

    player2.setRadius(r2);
    player2.setPosition(x2, y2);

    this->_imageMasque.create(860, 860, sf::Color(30, 30, 30, 255));
    this->_textureMasque.loadFromImage(_imageMasque);
    this->_spriteMasque.setTexture(_textureMasque);


}



void Masque::updateMasque(){

//Au lieu de tout update, on n'update qu'autour de la position des joueurs
/*
for (int x = player1.getPosition().x - player1.getRadius(); x < player1.getPosition().x + player1.getRadius(); x++)
{
    for (int y = player1.getPosition().y - player1.getRadius(); y < player1.getPosition().y + player1.getRadius(); y++)
    {

    }
}
*/
    	 // Itération sur chaque pixel de l'image

    int nb= 0;
    float alpha = 0;


 
    int rayon1 = player1.getRadius();
    int rayon2 = player2.getRadius();

    int x1 = player1.getPosition().x;
    int y1 = player1.getPosition().y;

    int x2 = player2.getPosition().x;
    int y2 = player2.getPosition().y;

    

    for (int x = x1 - 4*rayon1; x < player1.getPosition().x + rayon1; x=x+2)
    {
        for (int y = y2- 4*rayon1 ;y < player1.getPosition().y +rayon1; y=y+2)
        {
            nb++;
            if (std::sqrt(std::pow(x - x1, 2) + std::pow(y - y1, 2)) < rayon1 || std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2)) < rayon2)
            {
                _imageMasque.setPixel(x, y, sf::Color::Transparent);
                _imageMasque.setPixel(x, y-1, sf::Color::Transparent);

         }

            else{

                int dmax = 60; float alpha ;

				int distance1 = std::sqrt(std::pow(x - x1, 2) + std::pow(y - y1, 2));

			
				alpha = (255/dmax)*(std::sqrt(std::pow(x - x1 ,2) + std::pow(y - y1, 2)) - rayon1);
                

               

                if (alpha > 255){
                    alpha = 255; // noir    
                }

                else if (alpha < 0){
                    alpha = 0;
                }
                    // Transparence
                 _imageMasque.setPixel(x, y, sf::Color(30, 30, 30, alpha));     
                  _imageMasque.setPixel(x, y-1, sf::Color(30, 30, 30, alpha));     
            }
        }
    }


    // pour le joueur 2
    for (int x = x2 - 4*rayon2; x < player2.getPosition().x + rayon2; x=x+2)
    {
        for (int y = y2- 4*rayon2 ;y < player2.getPosition().y +rayon2; y=y+2)
        {
            if (std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2)) < rayon2 ){
            
                _imageMasque.setPixel(x, y, sf::Color::Transparent);
                _imageMasque.setPixel(x, y-1, sf::Color::Transparent);
            }

            else{

                int dmax = 60; float alpha ;
                alpha = (255/dmax)*(std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2)) - rayon2);
                 if (alpha > 255){
                    alpha = 255; // noir    
                }

                else if (alpha < 0){
                    alpha = 0;
                }
                    // Transparence
                 _imageMasque.setPixel(x, y, sf::Color(30, 30, 30, alpha));     
            }
            
        }
    }




/*
    
    for (int x = 65; x < 830; x=x+5)
    {
        for (int y = 65; y < 830; y=y+5)
        {
        
    
            // Récupération de la couleur du pixel
             nb++;
            // Vérification si le pixel est dans un des cercles avec la distance euclidienne
            if (std::sqrt(std::pow(x -x1, 2) + std::pow(y - y1, 2)) < rayon1 ||
				std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2)) < rayon2)
            {
				_imageMasque.setPixel(x, y, sf::Color::Transparent);
                _imageMasque.setPixel(x, y - 1, sf::Color::Transparent);
                _imageMasque.setPixel(x, y - 2, sf::Color::Transparent);
                _imageMasque.setPixel(x, y - 3, sf::Color::Transparent);
                _imageMasque.setPixel(x, y - 4, sf::Color::Transparent);
                _imageMasque.setPixel(x, y - 5, sf::Color::Transparent);

                 _imageMasque.setPixel(x - 1, y, sf::Color::Transparent);
                _imageMasque.setPixel(x - 1, y-1, sf::Color::Transparent);
                _imageMasque.setPixel(x - 1, y-2, sf::Color::Transparent);
                _imageMasque.setPixel(x - 1, y-3, sf::Color::Transparent);
                _imageMasque.setPixel(x - 1, y-4, sf::Color::Transparent);

                _imageMasque.setPixel(x - 2, y, sf::Color::Transparent);
                _imageMasque.setPixel(x - 2, y-1, sf::Color::Transparent);
                _imageMasque.setPixel(x - 2, y-2, sf::Color::Transparent);
                _imageMasque.setPixel(x - 2, y-3, sf::Color::Transparent);
                _imageMasque.setPixel(x - 2, y-4, sf::Color::Transparent);
                _imageMasque.setPixel(x - 2, y-5, sf::Color::Transparent);

               
                

            }

			else{

                int dmax = 60; float alpha ;

				int distance1 = std::sqrt(std::pow(x - x1, 2) + std::pow(y - y1, 2));
				int distance2 = std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2));

				if (distance1 < distance2){
					// cerlce 1 est plus proche
					
					alpha = (255/dmax)*(std::sqrt(std::pow(x - x1, 2) + std::pow(y - y1, 2)) - rayon1);
                }

                else{

                    alpha = (255/dmax)*(std::sqrt(std::pow(x - x2, 2) + std::pow(y - y2, 2)) - rayon2);
                }

                if (alpha > 255)
                {
                    alpha = 255; // noir
                     
                }

                else if (alpha < 0){
                    alpha = 0;
                }
                    // Transparence
                 _imageMasque.setPixel(x, y, sf::Color(0, 0, 0, alpha));
                 
                 _imageMasque.setPixel(x, y - 1, sf::Color(0, 0, 0, alpha));
                 _imageMasque.setPixel(x, y - 2, sf::Color(0, 0, 0, alpha));
                 _imageMasque.setPixel(x, y - 3, sf::Color(0, 0, 0, alpha));
                 _imageMasque.setPixel(x, y - 4, sf::Color(0, 0, 0, alpha));
                 _imageMasque.setPixel(x, y - 5, sf::Color(0, 0, 0, alpha));

                
                 _imageMasque.setPixel(x - 1, y, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 1, y-1, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 1, y-2, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 1, y-3, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 1, y-4, sf::Color(0, 0, 0, alpha));

                _imageMasque.setPixel(x - 2, y, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 2, y-1, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 2, y-2, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 2, y-3, sf::Color(0, 0, 0, alpha));
                _imageMasque.setPixel(x - 2, y-4, sf::Color(0, 0, 0, alpha));
                
          

          
            }
            
        }

            
        }
        */
    

    this->_textureMasque.loadFromImage(_imageMasque);
    this->_spriteMasque.setTexture(_textureMasque);

    //std::cout<<"nb de pixels  : "<<nb<<std::endl;

}


void Masque::dessineMasque(sf::RenderWindow* window) const
{
    
    window->draw(_spriteMasque);
}

/**
 * @brief Destructeur du masque
 * 
 */
Masque::~Masque()
{
    std::cout << "Destruction du masque" << std::endl;
   

    
}



void Masque::setPlayer1(int x, int y)
{
    player1.setPosition( x,  y);
}

void Masque::setPlayer2(int x, int y)
{
    player2.setPosition( x,  y);
}

