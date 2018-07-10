all: crybaby

crybaby: main.o game.o space.o player.o item.o bottle.o diaper.o blanket.o toy.o bedRoom.o passageWay.o commonRoom.o bedRoom1.o hall.o bedRoom2.o livingRoom.o stairs.o kitchen.o
	g++ main.o game.o space.o player.o item.o bottle.o diaper.o blanket.o toy.o bedRoom.o passageWay.o commonRoom.o bedRoom1.o hall.o bedRoom2.o livingRoom.o stairs.o kitchen.o -o crybaby
	
main.o: main.cpp
	g++ -c main.cpp

game.o: game.cpp
	g++ -c game.cpp

space.o: space.cpp
	g++ -c space.cpp

player.o: player.cpp
	g++ -c player.cpp

item.o: item.cpp
	g++ -c item.cpp

bottle.o: bottle.cpp
	g++ -c bottle.cpp

diaper.o: diaper.cpp
	g++ -c diaper.cpp

blanket.o: blanket.cpp
	g++ -c blanket.cpp

toy.o: toy.cpp
	g++ -c toy.cpp

bedRoom.o: bedRoom.cpp
	g++ -c bedRoom.cpp

passageWay.o: passageWay.cpp
	g++ -c passageWay.cpp

commonRoom.o: commonRoom.cpp
	g++ -c commonRoom.cpp

bedRoom1.o: bedRoom1.cpp
	g++ -c bedRoom1.cpp

hall.o: hall.cpp
	g++ -c hall.cpp

bedRoom2.o: bedRoom2.cpp
	g++ -c bedRoom2.cpp

livingRoom.o: livingRoom.cpp
	g++ -c livingRoom.cpp

stairs.o: stairs.cpp
	g++ -c stairs.cpp

kitchen.o: kitchen.cpp
	g++ -c kitchen.cpp

clean:
	rm -f crybaby *.o