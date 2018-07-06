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
#include <unistd.h>

#include "grid.hpp"
#include "ant.hpp"
#include "menu.hpp"

using std::cout;
using std::endl;
using std::cin;

int main() {
	//CREATE OBJECTS
	Grid newGrid;
	Ant *newAnt = new Ant();
	Menu newMenu;
	newMenu.gameMenu(newAnt);
	//ALLOCATE DYNAMIC ARRAY
	int **grid = new int*[newMenu.getRow()];
	//CREATE, INITIALIZE GRID
	newGrid.createGrid(grid, newMenu.getRow(), newMenu.getCol());
	newGrid.initGrid(grid, newMenu.getRow(), newMenu.getCol());
	newGrid.setStatus(grid, newMenu.getRow(), newMenu.getCol());
	//SIMULATION
	int counter = 0;
	while (newAnt->getState() != STATIC) {
		newGrid.display(grid, newMenu.getRow(), newMenu.getCol(), newAnt);
		cout << "X: " << newAnt->getX() << endl;
		cout << "Y: " << newAnt->getY() << endl;
		newGrid.move(grid, newMenu.getRow(), newMenu.getCol(), newAnt);
		if (newAnt->getState() == STATIC) {
			cout << "Out of bounds. Simulation terminated." << endl;
			cout << "Number of iterations: " << counter << endl;
			cout << "Press enter to exit the program: ";
			cin.ignore().get();
		}
		if (counter >= newMenu.getMoves()) {
			newAnt->setState(STATIC);
			cout << "Out of moves. Simulation terminated." << endl;
			cout << "Press enter to exit the program: ";
			cin.ignore().get();
		}
		usleep(newMenu.getSpeed());
		std::cout << "\033[2J\033[1;1H";
		counter ++;
	}
	//CLEAN
	newGrid.clean(grid, newMenu.getRow());
	delete newAnt;
	return 0;
}