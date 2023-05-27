#define CATCH_CONFIG_MAIN

#include "../include/catch.hpp"
#include "../include/RobotPlayer.hpp"
#include <iostream>



TEST_CASE( "Robot Player operations", "[Robot Player]"){

    std::map<std::string, bool>* test;
    RobotPlayer player(0,0,"player1",test);

    //Test du bool
    REQUIRE(player.getADrapeau() == false);
    


}