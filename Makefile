#pour compiler : make
#pour nettoyer : make vclean

CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
EXES= GamePlay


all: $(EXES)

GamePlay: main.o GamePlay.o Screen.o SFMLRenderer.o
	$(LD) $(LDFLAGS) main.o GamePlay.o Screen.o SFMLRenderer.o -o GamePlay $(LIBS)

main.o: main.cpp GamePlay.cpp Screen.cpp SFMLRenderer.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

GamePlay.o: GamePlay.cpp 
	$(CPP) $(CPPFLAGS) -c GamePlay.cpp

Screen.o: Screen.cpp
	$(CPP) $(CPPFLAGS) -c Screen.cpp

SFMLRenderer.o: SFMLRenderer.cpp
	$(CPP) $(CPPFLAGS) -c SFMLRenderer.cpp

clean:
	rm -f *.o $(EXES)

vclean: clean
	rm -f $(EXES)