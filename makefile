all: game

game: game.o
	g++ -Wall -o game game.o

game.o: game.h game.cpp
	g++ -Wall -g -c game.h game.cpp
