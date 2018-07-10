all: p_drome

p_drome: main.o queue.o stack.o
	g++ main.o queue.o stack.o -o p_drome
	
main.o: main.cpp
	g++ -c main.cpp
	
queue.o: queue.cpp
	g++ -c queue.cpp

stack.o: stack.cpp
	g++ -c stack.cpp

clean:
	rm -f p_drome *.o