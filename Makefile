#pour compiler : make
#pour nettoyer : make vclean

CPP=g++
LD=g++ -g

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES= main


all: $(EXES)

main: main.o GamePlay.o WelcomeScreen.o Bouton.o ChoseSkillMenu.o PlateauJeu.o Screen.o RobotPlayer.o TourEnnemi.o Drapeau.o Masque.o GameOverScreen.o 
	$(LD) $(LDFLAGS) main.o GamePlay.o  WelcomeScreen.o Bouton.o ChoseSkillMenu.o  PlateauJeu.o RobotPlayer.o TourEnnemi.o Drapeau.o Masque.o GameOverScreen.o  -o main $(LIBS)

main.o: main.cpp GamePlay.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

GamePlay.o: GamePlay.cpp GamePlay.hpp WelcomeScreen.hpp
	$(CPP) $(CPPFLAGS) -c GamePlay.cpp

Screen.o: Screen.cpp Screen.hpp Bouton.hpp
	$(CPP) $(CPPFLAGS) -c Screen.cpp


WelcomeScreen.o : WelcomeScreen.cpp WelcomeScreen.hpp Bouton.hpp Screen.o
	$(CPP) $(CPPFLAGS) -c WelcomeScreen.cpp 

ChoseSkillMenu.o : ChoseSkillMenu.cpp ChoseSkillMenu.hpp Bouton.hpp 
	$(CPP) $(CPPFLAGS) -c ChoseSkillMenu.cpp

PlateauJeu.o : PlateauJeu.cpp PlateauJeu.hpp 
	$(CPP) $(CPPFLAGS) -c PlateauJeu.cpp

GameOverScreen.o : GameOverScreen.cpp GameOverScreen.hpp 
	$(CPP) $(CPPFLAGS) -c GameOverScreen.cpp

Bouton.o : Bouton.cpp Bouton.hpp
	$(CPP) $(CPPFLAGS) -c Bouton.cpp

RobotPlayer.o : RobotPlayer.cpp RobotPlayer.hpp
	$(CPP) $(CPPFLAGS) -c RobotPlayer.cpp

TourEnnemi.o : TourEnnemi.cpp TourEnnemi.hpp
	$(CPP) $(CPPFLAGS) -c TourEnnemi.cpp

Drapeau.o : Drapeau.cpp Drapeau.hpp
	$(CPP) $(CPPFLAGS) -c Drapeau.cpp

Masque.o : Masque.cpp Masque.hpp
	$(CPP) $(CPPFLAGS) -c Masque.cpp
clean:
	rm -f *.o $(EXES)

vclean: clean
	rm -f $(EXES)

# valgrind --leak-check=full --show-leak-kinds=all ./main 