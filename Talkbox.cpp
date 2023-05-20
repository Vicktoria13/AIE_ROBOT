#include "include/Talkbox.hpp"

/**
 * @brief Constructeur d'une nouvelle boite de dialogue
 * 
 * @param text texte
 * @param pos_x position x
 * @param pos_y position y
 */
Talkbox::Talkbox(std::string text, int pos_x, int pos_y){
    
    if (!_texture.loadFromFile("Assets/Talk.png"))
    {
        std::cout << "Error loading talkbox texture" << std::endl;
    }

    _talkbox.setTexture(_texture);
    _talkbox.setPosition(pos_x,pos_y);
    _talkbox.setScale(2,2);

    // texte : il doit etre centré dans la boite de dialogue
    _text.setString(text);
    if(!_font.loadFromFile("Assets/arcade.ttf")){
        throw("ERROR FONT LOAD");}


    _text.setFont(_font);

    _text.setPosition(pos_x+85,pos_y+50);
    _text.setCharacterSize(25);
    _text.setFillColor(sf::Color::White);


}


/**
 * @brief Affichage de la boite de dialogue
 * 
 * @param window fenetre de rendu
 */

void Talkbox::AfficheTalkBox(sf::RenderWindow* window){

    window->draw(_talkbox);
    window->draw(_text);
   
}

/**
 * 
 * @brief Destruction de la boite de dialogue
 * 
 */
Talkbox::~Talkbox(){
    std::cout<<"destruction de la talkbox"<<std::endl;
}


