/*********************************************************************
** Program name: Dice Wars
** Author: David Rider
** Date: 1/25/2017
** Description: CS 162 Lab 3: This program is a two-player dice-
** simulator. It allows each player to choose a regular die, or a
** loaded die pre-disposed to a higher roll. Additionally, the user
** may choose the number of sides of their respective die.
*********************************************************************/
#include <cstdlib>
#include "die.hpp"
/**********************************************
** Die() -constructor that accepts an int value
** while setting a default value.
** @param -int sides- an int value which
** represents the sides of a die
**********************************************/
Die::Die(int sides) {
	numSides = sides;
}
/**********************************************
** roll() -virtual function that simulates a
** die roll. Selects a random integer within
** the range of the number of sides of the die
**********************************************/
int Die::roll() {
	int rollValue = rand() % numSides + 1;
	return rollValue;
};