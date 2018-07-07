calculate: main.o matrix.o determinant.o
	g++ main.o matrix.o determinant.o -o calculate

main.o: main.cpp
	g++ -c main.cpp

matrix.o: matrix.cpp
	g++ -c matrix.cpp

determinant.o: determinant.cpp
	g++ -c determinant.cpp

clean:
	rm -f calculate *.o