/*********************************************************************
** Program name: Dice Wars
** Author: David Rider
** Date: 1/25/2017
** Description: CS 162 Lab 3: This program is a two-player dice-
** simulator. It allows each player to choose a regular die, or a
** loaded die pre-disposed to a higher roll. Additionally, the user
** may choose the number of sides of their respective die.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "loadedDie.hpp"

LoadedDie::LoadedDie(int sides) {
	numSides = sides;
}
/**********************************************
** roll() -simulates a die roll of a "loaded"
** die. Selects a random integer within
** the range of the number of sides of the die.
** If the roll value is less than half of the
** number of sides, then the value is added to
** half the number of sides and returned.
**********************************************/
int LoadedDie::roll() {
	int rollValue = rand() % numSides + 1;
	if (rollValue > (numSides / 2)) {
		return rollValue;
	}
	else {
		return rollValue + (numSides / 2);
	}
}