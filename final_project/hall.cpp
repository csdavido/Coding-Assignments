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
#include "hall.hpp"
//CONSTRUCTOR
Hall::Hall() {
	roomName = "hall";
}
/******************************
** displayInfo() -virtual func-
** tion that displays data
** about the room
******************************/
void Hall::displayInfo() {
	cout << "This is the hall. It leads to your bedroom and the baby's nursery." << endl;
	cout << "There is a large book shelf with lots of things in it." << endl;
}