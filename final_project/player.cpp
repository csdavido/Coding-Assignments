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
#include <iostream>
#include "player.hpp"

using std::cout;
using std::endl;
//CONSTRUCOR
Player::Player() {
	currentLoc = NULL;
	bottle;
	diaper = false;
	blanket = false;
	toy = false;
	topElem = -1;
}
/****************************************
** push() -adds a value to the top of the
** stack and returns true if there is
** room or false if the stack is full
** @param -a pointer to an Item object
****************************************/
void Player::push(Item* newItem) {
	if (topElem >= 0) {
		cout << "You can only carry one thing!" << endl;
	}
	else {
		itemArray[++topElem] = newItem;
	}
}
/****************************************
** top() -returns the value at the top of
** the stack
****************************************/
Item* Player::top() {
	if (topElem < 0) {
		cout << "Inventory is empty!" << endl;
		return NULL;
	}
	else {
		return itemArray[topElem];
	}
}
/****************************************
** pop() -removes a value from the top of
** the stack
****************************************/
bool Player::pop() {
	if (topElem < 0) {
		return false;
	}
	else {
		itemArray[topElem--];
		return true;
	}
}
/****************************************
** display() -displays the items
****************************************/
void Player::display() {
	if (topElem == -1) {
		cout << "You aren't carrying anything." << endl;
	}
	else {
		cout << "You have the ";
		for (int i = 0; i <= topElem; i++) {
			cout << itemArray[i]->getName() << endl;
		}
	}
}
//MUTATOR
void Player::setCurrentLoc(Space* cLoc) {
	this->currentLoc = cLoc;
}
void Player::setBottle(Item* newBottle) {
	push(newBottle);
	bottle = true;
}
void Player::setDiaper(Item* newDiaper) {
	push(newDiaper);
	diaper = true;
}
void Player::setBlanket(Item* newBlanket) {
	push(newBlanket);
	blanket = true;
}
void Player::setToy(Item* newToy) {
	push(newToy);
	toy = true;
}
//ACCESSOR
Space* Player::getCurrentLoc() {
	return currentLoc;
}
bool Player::hasBottle() {
	return bottle;
}
bool Player::hasDiaper() {
	return diaper;
}
bool Player::hasBlanket() {
	return blanket;
}
bool Player::hasToy() {
	return toy;
}