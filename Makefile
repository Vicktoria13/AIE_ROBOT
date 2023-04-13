#pour compiler : make
#pour nettoyer : make vclean

CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES= GamePlay


all: $(EXES)

GamePlay: main.o GamePlay.o WelcomeScreen.o Bouton.o
	$(LD) $(LDFLAGS) main.o GamePlay.o   -o GamePlay $(LIBS)

main.o: main.cpp GamePlay.cpp 
	$(CPP) $(CPPFLAGS) -c main.cpp

GamePlay.o: GamePlay.cpp 
	$(CPP) $(CPPFLAGS) -c GamePlay.cpp

WelcomeScreen.o : WelcomeScreen.cpp
	$(CPP) $(CPPFLAGS) -c WelcomeScreen.cpp

Bouton.o : Bouton.cpp
	$(CPP) $(CPPFLAGS) -c Bouton.cpp

clean:
	rm -f *.o $(EXES)

vclean: clean
	rm -f $(EXES)