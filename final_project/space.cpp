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
#include "space.hpp"
//CONSTRUCTOR
Space::Space() {
	hasBaby = false;
	hasItem = false;
	roomName = " ";
}
//MUTATOR
void Space::setLeft(Space* left) {
	this->left = left;
}
void Space::setUp(Space* up) {
	this->up = up;
}
void Space::setRight(Space* right) {
	this->right = right;
}
void Space::setDown(Space* down) {
	this->down = down;
}
void Space::setItem(Item* item) {
	if (item == NULL) {
		hasItem = false;
	}
	else {
		this->item = item;
		hasItem = true;
	}
}
void Space::setRoomName(string roomName) {
	this->roomName = roomName;
}
void Space::setBaby() {
	hasBaby = true;
}
//ACCESSOR
Space* Space::getLeft() {
	return left;
}
Space* Space::getUp() {
	return up;
}
Space* Space::getRight() {
	return right;
}
Space* Space::getDown() {
	return down;
}
Item* Space::getItem() {
	return item;
}
bool Space::getItemStatus() {
	return hasItem;
}
string Space::getRoomName() {
	return roomName;
}
bool Space::getBaby() {
	return hasBaby;
}