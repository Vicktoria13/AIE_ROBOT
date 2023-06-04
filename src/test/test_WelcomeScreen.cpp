#define CATCH_CONFIG_MAIN

#include "../../include/catch.hpp"
#include "../../include/WelcomeScreen.hpp"
#include <iostream>



TEST_CASE( "WelcomeScreen operations", "[WelcomeScreen]"){

    WelcomeScreen* welcomeScreen_test = new WelcomeScreen();

    REQUIRE(welcomeScreen_test->getScreenName() == "Accueil");

    //verifie l'état des boutons
    REQUIRE(welcomeScreen_test->getvector_buttons()[0]->getIsActivated() == true);
    REQUIRE(welcomeScreen_test->getvector_buttons()[1]->getIsActivated() == false);

    


}