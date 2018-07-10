/*******************************************************************
** Program name: crybaby
** Author: David Rider
** Date: 3/19/2017
** Description: CS 162 Final Project: This program is a text-based
** game. The object is to get your baby to stop crying before your
** partner gets home. There are 6 rooms, which inherit from 3 types
** of child classes of a parent space class. There are four items
** which inherit from an item class. There is a player class that
** contains the players data. There is a game class that controls
** and simulates the game. Selecting the correct object and bring-
** ing it to the baby wins the game. Failing to do so befor the
** partner returns ends the game in a loss.
*******************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "item.hpp"
#include "space.hpp"

class Player {
public:
	//CONSTRUCOR
	Player();
	/****************************************
	** push() -adds a value to the top of the
	** stack and returns true if there is
	** room or false if the stack is full
	** @param -a pointer to an Item object
	****************************************/
	void push(Item*);
	/****************************************
	** top() -returns the value at the top of
	** the stack
	****************************************/
	Item* top();
	/****************************************
	** pop() -removes a value from the top of
	** the stack
	****************************************/
	bool pop();
	/****************************************
	** display() -displays the items
	****************************************/
	void display();
	//MUTATOR
	void setCurrentLoc(Space*);
	void setBottle(Item*);
	void setDiaper(Item*);
	void setBlanket(Item*);
	void setToy(Item*);
	//ACCESSOR
	Space* getCurrentLoc();
	bool hasBottle();
	bool hasDiaper();
	bool hasBlanket();
	bool hasToy();
private:
	Space* currentLoc;
	bool bottle;
	bool diaper;
	bool blanket;
	bool toy;
	int topElem;
	Item* itemArray[3];
};
#endif