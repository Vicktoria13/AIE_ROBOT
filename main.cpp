#include "include/GamePlay.hpp"
#include "include/WelcomeScreen.hpp"
#include <iostream>
#include "SFML/Audio.hpp"
int main()
{

    sf::Music music;

    if(!music.openFromFile("Music/Apocalypse.wav"))
        throw "ERROR MUSIC LOAD";

    music.setLoop(true);
    music.setVolume(50);
    music.play();


    GamePlay partie;

    partie.Run();


    return 0;
}
