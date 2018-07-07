/*********************************************************************
** Program name: calculate (CS 162 Lab 1)
** Author: David Rider
** Date: 1/10/2017
** Description: This program creates a dynamically allocated 2D array
** based off of user input, accepts input to populate the 2D array,
** and calculates the determinant of the matrix.
*********************************************************************/
#include "determinant.hpp"
/*********************************************
** Calculates the determinant of a 2D array.
** @param a pointer to a 2D array
** @param an integer that represents the 
** dimensions of the array
** returns the calculated determinant integer
*********************************************/
int determinant(int **grid, int sizeInput) {
	int det;
	if (sizeInput == 2) {
		det = ((grid[0][0] * grid[1][1]) - (grid[0][1] * grid[1][0]));
	}
	else if (sizeInput == 3) {
		det = ((grid[0][0] * ((grid[1][1] * grid[2][2]) - (grid[1][2] * grid[2][1]))) -
			  (grid[0][1] * ((grid[1][0] * grid[2][2]) - (grid[1][2] * grid[2][0]))) +
			  (grid[0][2] * ((grid[1][0] * grid[2][1]) - (grid[1][1] * grid[2][0]))));
	}
	return det;
}