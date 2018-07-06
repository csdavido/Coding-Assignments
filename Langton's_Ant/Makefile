all: simulate

simulate: main.o grid.o ant.o menu.o
	g++ main.o grid.o ant.o menu.o -o simulate

main.o: main.cpp
	g++ -c main.cpp

grid.o: grid.cpp
	g++ -c grid.cpp

ant.o: ant.cpp
	g++ -c ant.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm -f calculate *.o