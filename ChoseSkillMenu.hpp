#ifndef ChoseSkillMenu_HPP
#define ChoseSkillMenu_HPP


class ChoseSkillMenu
{
private:
    
    bool isPlay = false;
        /* le fond d"'écran de l'accueil */

    sf::RectangleShape fullBackground;
    sf::Texture backgroundTexture;

    std::map<std::string,Bouton*> MapBoutons;

    
public:
   
};



#endif