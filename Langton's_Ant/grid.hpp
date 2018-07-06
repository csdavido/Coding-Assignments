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
#ifndef GRID_HPP
#define GRID_HPP

#include "ant.hpp"

enum Status { ON, OFF };

class Grid {
public:
	//CONSTRUCTOR
	Grid();
	//CREATE GRID
	void createGrid(int **, int, int);
	//INITIALIZE
	void initGrid(int **, int, int);
	//DISPLAY
	void display(int **, int, int, Ant *);
	//SET Status
	void setStatus(int **, int, int);
	//update color
	void updateStatus(int**, Ant *);
	//MOVE
	void move(int **, int, int, Ant *);
	//CLEAN
	void clean(int **, int);
	//CHECK BOUNDS
	void checkBounds(int, int, Ant *);
private:
	Status currentStatus;
	Ant *gridAnt;
};
#endif

