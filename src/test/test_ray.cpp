#define CATCH_CONFIG_MAIN

#include "../../include/catch.hpp"
#include "../../include/Ray.hpp"
#include <iostream>


TEST_CASE( "Rayon", "[Ray]"){

    Ray ray(0,0,1.0);

    SECTION("Test getters"){
        REQUIRE(ray.getPosX() == Approx(0));
        REQUIRE(ray.getPosY() == Approx(0));
        REQUIRE(ray.getAngle() == Approx(1.0));
    }
   
}