/*********************************************************************
** Program name: calculate (CS 162 Lab 1)
** Author: David Rider
** Date: 1/10/2017
** Description: This program creates a dynamically allocated 2D array
** based off of user input, accepts input to populate the 2D array, 
** and calculates the determinant of the matrix.
*********************************************************************/
#include <iostream>

#include "matrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
	//GET MATRIX SIZE FROM THE USER
	int size;
	cout << "Would you like a 2x2 matrix or 3x3?" << endl;
	cout << "Enter 2 or 3: ";
	cin >> size;
	while (size != 2 && size != 3) {
		cout << "Invalid input. Enter 2 or 3: ";
		cin >> size;
	}
	//DYNAMIC ALLOCATE 2D ARRAY
	int **matrixArray = new int*[size];
	for (int x = 0; x < size; x++) {
		matrixArray[x] = new int[size];
	}
	//POPULATE MATRIX
	readMatrix(matrixArray, size);
	//DISPLAY MATRIX ARRRAY
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			cout << "|" << matrixArray[a][b] << "|";
		}
		cout << endl;
	}
	//DISPLAY VALUE OF THE DETERMINANT
	cout << "Determinant: " << determinant(matrixArray, size) << endl;
	return 0;
}