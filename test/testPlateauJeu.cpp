#include "catch.hpp"
#include "../include/PlateauJeu.hpp"


TEST_CASE("Test ChoseSkillMenu", "[ChoseSkillMenu]")
{
    SECTION("Test construction et initialisation")
    {
        PlateauJeu game;
        REQUIRE(game.skills_joueurA.size() == 3);
        REQUIRE(game.skills_joueurB.size() == 3);
        REQUIRE(game.getSkillA() == 0);
        REQUIRE(game.getSkillB() == 0);
    }

    SECTION("Test ajout de bouton")
    {
        PlateauJeu menu;
        menu.ajouterBouton();
        REQUIRE(menu.getVectorBoutons().size() == 7);
    }

}