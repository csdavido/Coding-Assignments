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

using std::cout;
using std::cin;
/*********************************************
** Populates a 2D array with user input
** @param a pointer to a 2D array
** @param an integer that represnts the 
** dimensions of the array
*********************************************/
void readMatrix(int **grid, int size) {
	int input;
	for (int j = 0; j < size; j++) {
		for (int k = 0; k < size; k++) {
			cout << "Enter number at (" << j << ", " << k << "): ";
			cin >> input;
			grid[j][k] = input;
		}
	}
}