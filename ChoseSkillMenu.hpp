#ifndef ChoseSkillMenu_HPP
#define ChoseSkillMenu_HPP


class ChoseSkillMenu
{
private:
    
       bool isPlay = false;

        sf::Text Title;
        sf::Font fontTitle;
        /* le fond d"'écran de l'accueil */

        sf::RectangleShape fullBackground;
        sf::Texture backgroundTexture;


        /*liste de Boutons a afficher : polymorphisme */
        std::map<std::string,Bouton*> MapBoutons;

public:

    

    void ajoutBouton();
    void ajoutTexte();
    void drawScreens(sf::RenderWindow* window);

   
};



#endif