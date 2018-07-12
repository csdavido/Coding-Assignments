all: search

search: main.o tools.o
	g++ main.o tools.o -o search
	
main.o: main.cpp
	g++ -c main.cpp
	
tools.o: tools.cpp
	g++ -c tools.cpp

clean:
	rm -f search *.o