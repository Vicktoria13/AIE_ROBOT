#define CATCH_CONFIG_MAIN

#include "../../include/catch.hpp"
#include "../../include/Bouton.hpp"
#include <iostream>


TEST_CASE( "Bouton", "[Bouton]"){

    Bouton bouton(5.0, 3.0, 100.0,80.0, "test", sf::Color::Red, true);


    SECTION("Test getters"){
        REQUIRE(bouton.getName() == "test");
        REQUIRE(bouton.getIsActivated() == true);
        REQUIRE(bouton.getIsPressed() == false);

        REQUIRE(bouton.getPosX() == Approx(5.0));
        REQUIRE(bouton.getPosY() == Approx(3.0));
    }
   
    SECTION("Test appui sur entrée"){
        REQUIRE(bouton.EnterPressed() == 1);
    }
}