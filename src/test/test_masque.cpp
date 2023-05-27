#define CATCH_CONFIG_MAIN

#include "../../include/catch.hpp"
#include "../../include/Masque.hpp"
#include <iostream>


TEST_CASE( "Rayon", "[Ray]"){


    SECTION("Test getters"){
        Masque masque(10.0f, 15.0f, 100, 100, 200, 200);

        REQUIRE(masque.getPlayer1Radius() == 10.0f);
        REQUIRE(masque.getPlayer2Radius() == 15.0f);
        
    }
   
}