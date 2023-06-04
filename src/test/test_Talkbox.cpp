#define CATCH_CONFIG_MAIN

#include "../../include/Talkbox.hpp"
#include "../../include/catch.hpp"
#include <iostream>


TEST_CASE("Talkbox", "[Talkbox]"){

    
    Talkbox test_talkbox("test" , 51 ,100);
    SECTION("Talkbox"){
        REQUIRE(test_talkbox.getAffiche() == false);
    }

    
}
