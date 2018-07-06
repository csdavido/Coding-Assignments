/*********************************************************************
** Program name: simulate (CS 162 Project 1)
** Author: David Rider
** Date: 1/22/2017
** Description: This program creates a simulation of Langton's Ant.
** It utilizes three classes, and it inludes a 2D matrix which is
** dynamically allocated. This program contains a menu which offers
** input validation and is responsible for collecting input data from
** the user.
*********************************************************************/
#include <iostream>

#include "grid.hpp"

using std::cout;
using std::cin;
using std::endl;
/******************
**CONSTRUCTOR
*******************/
Grid::Grid() {

}
/*************************************************
** createGrid- dynamically allocates memory for 2d
** array.
** @param pointer to 2D array
** @param int for value of row/col
*************************************************/
void Grid::createGrid(int **grid, int r, int c) {
	for (int i = 0; i < r; i++) {
		grid[i] = new int[c];
	};
}
/*************************************************
** initGrid- initializes 2D array to a value of 0.
** @param pointer to 2D array
** @param int for value of row/col
*************************************************/
void Grid::initGrid(int **grid, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int g = 0; g < col; g++) {
			grid[i][g] = 0;
		}
	}
}
/*************************************************
** display- displays 2D array. 
** @param pointer to 2D array
** @param int for value of row/col
*************************************************/
void Grid::display(int **grid, int row, int col, Ant *gridAnt) {
	for (int d = 0; d < row; d++) {
		cout << "-";
		for (int p = 0; p < col; p++) {
			if (p == gridAnt->getY() && d == gridAnt->getX()) {
				cout << "*-";
			}
			else if (grid[d][p] == OFF) {
				cout << " -";
			}
			else if (grid[d][p] == ON) {
				cout << "X-";
			}
		}
		cout << "\n";
	};
}
/*************************************************
** setStatus- sets the integer value of a cell to 
** an ENUM value.
** of the 2D array.
** @param pointer to 2D array
** @param int for value of row/col
*************************************************/
void Grid::setStatus(int **grid, int row, int col) {
	for (int d = 0; d < row; d++) {
		for (int p = 0; p < col; p++) {
			if (grid[d][p] == 0) {
				grid[d][p] = OFF;
			}
			else if (grid[d][p] == 1) {
				grid[d][p] = ON;
			}
		}
	};
}
/*************************************************
** updateStatus- changes the color of individual 
** cells of the 2D array.
** @param pointer to 2D array
** @param int for value of row/col
** @param pointer to an Ant object
*************************************************/
void Grid::updateStatus(int **grid, Ant *gridAnt) {
	if (grid[gridAnt->getX()][gridAnt->getY()] == 1) {
		grid[gridAnt->getX()][gridAnt->getY()] = 0;
	}
	else if (grid[gridAnt->getX()][gridAnt->getY()] == 0) {
		grid[gridAnt->getX()][gridAnt->getY()] = 1;
	}
}
/*************************************************
** move- moves the Ant's location accross the grid
** according to the algoritm of Lanton's Ant.
** @param pointer to 2D array
** @param int for value of row/col
** @param pointer to an Ant object
*************************************************/
void Grid::move(int **grid, int row, int col, Ant *gridAnt) {
	if (grid[gridAnt->getX()][gridAnt->getY()] == OFF) {
		gridAnt->moveRight();
		updateStatus(grid, gridAnt);
	}
	else if (grid[gridAnt->getX()][gridAnt->getY()] == ON) {
		gridAnt->moveLeft();
		updateStatus(grid, gridAnt);
	}
	checkBounds(row, col, gridAnt);
}
/*************************************************
** clean- de-allocates memory of 2D array
** @param pointer to 2D array
** @param int for value of row
*************************************************/
void Grid::clean(int **grid, int row) {
	for (int c = 0; c < row; c++) {
		delete[] grid[c];
	}
	delete[] grid;
}
/*************************************************
** checkBounds- checks if ant has reached the 
** boundary of the grid and terminates the program
** if so.
** @param pointer to 2D array
** @param int for value of row/col
** @param a pointer to an Ant object
*************************************************/
void Grid::checkBounds(int row, int col, Ant *gridAnt) {
	if (gridAnt->getX() <= 0 || gridAnt->getY() <= 0) {
		gridAnt->setState(STATIC);
	}
	else if (gridAnt->getX() >= row || gridAnt->getY() >= col) {
		gridAnt->setState(STATIC);
	}
	else {
		gridAnt->setState(RUNNING);
	}
}