#define CATCH_CONFIG_MAIN

#include "../../include/catch.hpp"
#include "../../include/RobotPlayer.hpp"
#include <iostream>



TEST_CASE( "Robot Player operations", "[Robot Player]"){

    std::map<std::string, bool>* test;
    *test = {{"Capteur 3D",true},
    {"Vitesse rapide",true},
    {"Capteur Ultrasons",false}
    };
    

    RobotPlayer player(10,70,"JoueurA",test);
   

    //Test du bool
    REQUIRE(player.getADrapeau() == false);
    //REQUIRE(player.UpdateEvent("player1",maze) == 0);
    


}