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
#ifndef ANT_HPP
#define ANT_HPP

enum Direction { UP, DOWN, LEFT, RIGHT };
enum State { RUNNING, STATIC };

class Ant {
public:
	//CONSTRUCTOR
	Ant();
	//MUTATOR AND ACCESSOR  X/Y
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	//MOVE ANT
	void moveLeft();
	void moveRight();
	//MUTATOR AND ACCESSOR STATE
	void setState(State);
	State getState();
private:
	int xCoord;
	int yCoord;
	Direction currentDirection;
	State currentState;
};
#endif
