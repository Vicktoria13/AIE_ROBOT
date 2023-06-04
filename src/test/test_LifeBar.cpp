#define CATCH_CONFIG_MAIN

#include "../../include/LifeBar.hpp"
#include "../../include/catch.hpp"
#include <iostream>


TEST_CASE("LifeBar", "[LifeBar]"){

    
    LifeBar lifeBar("JoueurA");
    SECTION("Test appui sur entrée"){
        REQUIRE(lifeBar.getValue() == MAX_LIFE);
        lifeBar.Lost();
        REQUIRE(lifeBar.getValue() == MAX_LIFE-1);
        for (int i = 0; i < MAX_LIFE-1; i++)
        {
            lifeBar.Lost();
        }
        REQUIRE(lifeBar.getValue() == 0);
        REQUIRE(lifeBar.getNoLife() == true);
    }

    
}
