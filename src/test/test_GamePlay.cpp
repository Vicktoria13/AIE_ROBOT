#define CATCH_CONFIG_MAIN

#include "../../include/GamePlay.hpp"
#include "../../include/catch.hpp"
#include <iostream>


TEST_CASE("GamePlay", "[GamePlay]"){

    
    GamePlay gamePlay;
    SECTION("Test appui sur entrée"){
        REQUIRE(gamePlay.CheckFenetreChanges() == 0);
    }

    


}
