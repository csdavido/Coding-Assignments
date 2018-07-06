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
#include "ant.hpp"

#ifndef MENU_HPP
#define MENU_HPP

class Menu {
public:
	Menu();
	void gameMenu(Ant *);
	void getBoard();
	void getUserCoord(Ant *);
	void getRanCoord(Ant *);
	//MUTATOR
	void setRow(int);
	void setCol(int);
	void setMoves(int);
	void setSpeed(int);
	//ACCESSOR
	int getRow();
	int getCol();
	int getMoves();
	int getSpeed();
private:
	int row, col, x, y, moves, speed;
	Ant *menuAnt;
};

#endif