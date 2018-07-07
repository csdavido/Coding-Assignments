all: dice

dice: main.o game.o die.o loadedDie.o
	g++ main.o game.o die.o loadedDie.o -o dice
	
main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

die.o: die.cpp
	g++ -c die.cpp

loadedDie.o: loadedDie.cpp
	g++ -c loadedDie.cpp
	
clean:
	rm -f dice *.o