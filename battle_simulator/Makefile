all: prog

prog: lab5.o monster.o goblin.o troll.o dragon.o iceDragon.o fireDragon.o
	g++ lab5.o monster.o goblin.o troll.o dragon.o iceDragon.o fireDragon.o -o prog
	
lab5.o: lab5.cpp
	g++ -c lab5.cpp

monster.o: monster.cpp
	g++ -c monster.cpp

goblin.o: goblin.cpp
	g++ -c goblin.cpp

troll.o: troll.cpp
	g++ -c troll.cpp

dragon.o: dragon.cpp
	g++ -c dragon.cpp

iceDragon.o: iceDragon.cpp
	g++ -c iceDragon.cpp

fireDragon.o: fireDragon.cpp
	g++ -c fireDragon.cpp

clean:
	rm -f prog *.o