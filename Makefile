#pour compiler : make
#pour nettoyer : make vclean

CPP=g++
LD=g++


CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES= jeu

all: $(EXES)

jeu: main.o PlateauJeu.o SFMLRenderer.o 
	$(LD) $(LDFLAGS) main.o PlateauJeu.o SFMLRenderer.o -o jeu $(LIBS)


main.o : main.cpp SFMLRenderer.cpp PlateauJeu.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

PlateauJeu.o : PlateauJeu.cpp Labyrinthe2D.cpp
	$(CPP) $(CPPFLAGS) -c PlateauJeu.cpp

SFMLRenderer.o : SFMLRenderer.cpp
	$(CPP) $(CPPFLAGS) -c SFMLRenderer.cpp

Labyrinthe2D.o : Labyrinthe2D.cpp
	$(CPP) $(CPPFLAGS) -c Labyrinthe2D.cpp

clean:
	rm -f *.o $(EXES)

vclean: clean
	rm -f $(EXES)