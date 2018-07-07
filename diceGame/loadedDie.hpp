/*********************************************************************
** Program name: Dice Wars
** Author: David Rider
** Date: 1/25/2017
** Description: CS 162 Lab 3: This program is a two-player dice-
** simulator. It allows each player to choose a regular die, or a
** loaded die pre-disposed to a higher roll. Additionally, the user
** may choose the number of sides of their respective die.
*********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "die.hpp"

class LoadedDie : public Die {
public:
	/**********************************************
	** LoadedDie() -constructor that accepts an int
	** value while setting a default value.
	** @param -int sides- an int value which
	** represents the sides of a die
	**********************************************/
	LoadedDie(int numSides = 4);
	/**********************************************
	** roll() -simulates a die roll of a "loaded"
	** die. Selects a random integer within
	** the range of the number of sides of the die.
	** If the roll value is less than half of the 
	** number of sides, then the value is added to 
	** half the number of sides and returned.
	**********************************************/
	int roll();
private:
	int numSides;
};
#endif 