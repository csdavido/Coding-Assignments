all: cart

cart: main.o list.o item.o
	g++ main.o list.o item.o -o cart

main.o: main.cpp
	g++ -c main.cpp

list.o: list.cpp
	g++ -c list.cpp

item.o: item.cpp
	g++ -c item.cpp

clean:
	rm -f cart *.o