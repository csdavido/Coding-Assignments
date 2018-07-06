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
/***************************
** CONSTRUCTOR
***************************/
Ant::Ant() {
	currentDirection = UP;
	currentState = RUNNING;
}
//MUTATOR FUNCTIONS
void Ant::setX(int x) {
	xCoord = x;
}
void Ant::setY(int y) {
	yCoord = y;
}
void Ant::setState(State inputState) {
	currentState = inputState;
}
//ACCESSOR FUNTIONS
int Ant::getX() {
	return xCoord;
}
int Ant::getY() {
	return yCoord;
}
State Ant::getState() {
	return currentState;
}
/*************************************************
** moveLeft- moves ant to the left and changes 
** ant's direction.
*************************************************/
void Ant::moveLeft() {
	switch (currentDirection) {
	case UP:
		currentDirection = LEFT;
		xCoord -= 1;
		break;
	case LEFT:
		currentDirection = DOWN;
		yCoord += 1;
		break;
	case DOWN:
		currentDirection = RIGHT;
		xCoord += 1;
		break;
	case RIGHT:
		currentDirection = UP;
		yCoord -= 1;
		break;
	};
}
/*************************************************
** moveRight- moves ant to the right and changes
** ant's direction
*************************************************/
void Ant::moveRight() {
	switch (currentDirection) {
	case UP:
		currentDirection = RIGHT;
		xCoord += 1;
		break;
	case LEFT:
		currentDirection = UP;
		yCoord -= 1;
		break;
	case DOWN:
		currentDirection = LEFT;
		xCoord -= 1;
		break;
	case RIGHT:
		currentDirection = DOWN;
		yCoord += 1;
		break;
	};
}