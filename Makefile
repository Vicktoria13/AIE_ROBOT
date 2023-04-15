#pour compiler : make
#pour nettoyer : make vclean

CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES= main


all: $(EXES)

main: main.o GamePlay.o WelcomeScreen.o Bouton.o
	$(LD) $(LDFLAGS) main.o GamePlay.o  WelcomeScreen.o Bouton.o -o main $(LIBS)

main.o: main.cpp GamePlay.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

GamePlay.o: GamePlay.cpp GamePlay.hpp WelcomeScreen.hpp
	$(CPP) $(CPPFLAGS) -c GamePlay.cpp

WelcomeScreen.o : WelcomeScreen.cpp WelcomeScreen.hpp Bouton.hpp 
	$(CPP) $(CPPFLAGS) -c WelcomeScreen.cpp 

Bouton.o : Bouton.cpp Bouton.hpp
	$(CPP) $(CPPFLAGS) -c Bouton.cpp

clean:
	rm -f *.o $(EXES)

vclean: clean
	rm -f $(EXES)