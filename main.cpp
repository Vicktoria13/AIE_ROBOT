#include "GamePlay.hpp"
#include "WelcomeScreen.hpp"
#include <iostream>

int main()
{
    GamePlay* partie = new GamePlay();

    partie->Run();

    delete partie;

    return 0;
}