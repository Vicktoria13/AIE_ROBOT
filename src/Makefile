#pour compiler : make
#pour nettoyer : make vclean

CPP=g++
LD=g++ -g

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES=main test_ray test_masque test_bouton test_GamePlay test_RobotPlayer test_WelcomeScreen test_LifeBar test_Talkbox


all: $(EXES)

main: main.o GamePlay.o WelcomeScreen.o Bouton.o ChoseSkillMenu.o PlateauJeu.o Screen.o RobotPlayer.o TourEnnemi.o Drapeau.o Masque.o GameOverScreen.o Ray.o Talkbox.o LifeBar.o RuleScreen.o
	$(LD) $(LDFLAGS) main.o GamePlay.o  WelcomeScreen.o Bouton.o ChoseSkillMenu.o  Screen.o PlateauJeu.o RobotPlayer.o TourEnnemi.o Drapeau.o Masque.o GameOverScreen.o Ray.o Talkbox.o  LifeBar.o RuleScreen.o -o main $(LIBS)


###################### TESTS ######################

########
test_RobotPlayer: test_RobotPlayer.o RobotPlayer.o  Ray.o  LifeBar.o 
	$(LD) $(LDFLAGS) test_RobotPlayer.o RobotPlayer.o   Ray.o  LifeBar.o -o test_RobotPlayer $(LIBS)

test_RobotPlayer.o: test/test_RobotPlayer.cpp ../include/RobotPlayer.hpp ../include/catch.hpp
	$(CPP) $(CPPFLAGS) -c test/test_RobotPlayer.cpp

########
test_GamePlay: test_GamePlay.o GamePlay.o WelcomeScreen.o Bouton.o ChoseSkillMenu.o PlateauJeu.o Screen.o RobotPlayer.o TourEnnemi.o Drapeau.o Masque.o GameOverScreen.o Ray.o Talkbox.o LifeBar.o RuleScreen.o
	$(LD) $(LDFLAGS) test_GamePlay.o GamePlay.o WelcomeScreen.o Bouton.o ChoseSkillMenu.o PlateauJeu.o Screen.o RobotPlayer.o TourEnnemi.o Drapeau.o Masque.o GameOverScreen.o Ray.o Talkbox.o LifeBar.o RuleScreen.o -o test_GamePlay $(LIBS)

test_GamePlay.o: test/test_GamePlay.cpp ../include/GamePlay.hpp ../include/catch.hpp
	$(CPP) $(CPPFLAGS) -c test/test_GamePlay.cpp 

########
test_ray: test_ray.o Ray.o
	$(LD) $(LDFLAGS) test_ray.o Ray.o -o test_ray $(LIBS)

test_ray.o: test/test_ray.cpp ../include/Ray.hpp
	$(CPP) $(CPPFLAGS) -c test/test_ray.cpp


########
test_masque: test_masque.o Masque.o
	$(LD) $(LDFLAGS) test_masque.o Masque.o -o test_masque $(LIBS)

test_masque.o: test/test_masque.cpp ../include/Masque.hpp
	$(CPP) $(CPPFLAGS) -c test/test_masque.cpp


########
test_bouton: test_bouton.o Bouton.o
	$(LD) $(LDFLAGS) test_bouton.o Bouton.o -o test_bouton $(LIBS)

test_bouton.o: test/test_bouton.cpp ../include/Bouton.hpp
	$(CPP) $(CPPFLAGS) -c test/test_bouton.cpp

########
test_WelcomeScreen : test_WelcomeScreen.o WelcomeScreen.o Bouton.o Screen.o Talkbox.o
	$(LD) $(LDFLAGS) test_WelcomeScreen.o WelcomeScreen.o Bouton.o Screen.o Talkbox.o -o test_WelcomeScreen $(LIBS)

test_WelcomeScreen.o: test/test_WelcomeScreen.cpp ../include/WelcomeScreen.hpp
	$(CPP) $(CPPFLAGS) -c test/test_WelcomeScreen.cpp

########

test_LifeBar : test_LifeBar.o LifeBar.o
	$(LD) $(LDFLAGS) test_LifeBar.o LifeBar.o -o test_LifeBar $(LIBS)

test_LifeBar.o: test/test_LifeBar.cpp ../include/LifeBar.hpp
	$(CPP) $(CPPFLAGS) -c test/test_LifeBar.cpp


########
test_Talkbox : test_Talkbox.o Talkbox.o
	$(LD) $(LDFLAGS) test_Talkbox.o Talkbox.o -o test_Talkbox $(LIBS)

test_Talkbox.o: test/test_Talkbox.cpp ../include/Talkbox.hpp
	$(CPP) $(CPPFLAGS) -c test/test_Talkbox.cpp


	
###################### CLASSES ######################
main.o: main.cpp ../include/GamePlay.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

GamePlay.o: GamePlay.cpp ../include/GamePlay.hpp  ../include/Screen.hpp ../include/WelcomeScreen.hpp ../include/ChoseSkillMenu.hpp ../include/GameOverScreen.hpp  ../include/PlateauJeu.hpp ../include/RuleScreen.hpp
	$(CPP) $(CPPFLAGS) -c GamePlay.cpp

Screen.o: Screen.cpp ../include/Screen.hpp ../include/Bouton.hpp ../include/Bouton.hpp ../include/Talkbox.hpp 
	$(CPP) $(CPPFLAGS) -c Screen.cpp


WelcomeScreen.o : WelcomeScreen.cpp ../include/WelcomeScreen.hpp ../include/Bouton.hpp ../include/Screen.hpp
	$(CPP) $(CPPFLAGS) -c WelcomeScreen.cpp 

ChoseSkillMenu.o : ChoseSkillMenu.cpp ../include/ChoseSkillMenu.hpp ../include/Screen.hpp ../include/Bouton.hpp
	$(CPP) $(CPPFLAGS) -c ChoseSkillMenu.cpp

PlateauJeu.o : PlateauJeu.cpp ../include/PlateauJeu.hpp ../include/Screen.hpp  ../include/Bouton.hpp  ../include/RobotPlayer.hpp ../include/Drapeau.hpp ../include/TourEnnemi.hpp ../include/Masque.hpp 
	$(CPP) $(CPPFLAGS) -c PlateauJeu.cpp

RuleScreen.o : RuleScreen.cpp ../include/RuleScreen.hpp ../include/Bouton.hpp ../include/Screen.hpp
	$(CPP) $(CPPFLAGS) -c RuleScreen.cpp

GameOverScreen.o : GameOverScreen.cpp ../include/GameOverScreen.hpp ../include/Bouton.hpp ../include/Screen.hpp
	$(CPP) $(CPPFLAGS) -c GameOverScreen.cpp

Bouton.o : Bouton.cpp ../include/Bouton.hpp
	$(CPP) $(CPPFLAGS) -c Bouton.cpp

RobotPlayer.o : RobotPlayer.cpp ../include/RobotPlayer.hpp ../include/Ray.hpp ../include/EntiteAffichable.hpp ../include/LifeBar.hpp
	$(CPP) $(CPPFLAGS) -c RobotPlayer.cpp

TourEnnemi.o : TourEnnemi.cpp ../include/TourEnnemi.hpp ../include/EntiteAffichable.hpp
	$(CPP) $(CPPFLAGS) -c TourEnnemi.cpp

Drapeau.o : Drapeau.cpp ../include/Drapeau.hpp 
	$(CPP) $(CPPFLAGS) -c Drapeau.cpp

Masque.o : Masque.cpp ../include/Masque.hpp
	$(CPP) $(CPPFLAGS) -c Masque.cpp

Ray.o : Ray.cpp ../include/Ray.hpp
	$(CPP) $(CPPFLAGS) -c Ray.cpp


Talkbox.o : Talkbox.cpp ../include/Talkbox.hpp
	$(CPP) $(CPPFLAGS) -c Talkbox.cpp


LifeBar.o : LifeBar.cpp ../include/LifeBar.hpp
	$(CPP) $(CPPFLAGS) -c LifeBar.cpp

clean:
	rm -f *.o $(EXES)

vclean: clean
	rm -f $(EXES) 

# valgrind --leak-check=full --show-leak-kinds=all ./main 