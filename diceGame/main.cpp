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

#include "game.hpp"

int main() {
	//CREATE GAME OBJECT
	Game diceWars;
	//CALL MENU FUNCTION TO COLLECT USER DATA AND SIMUMALTE GAME
	diceWars.menu();
	//CHECK FOR OVERALL WINNER AND DISPLAY RESULTS
	diceWars.checkMatch();
	return 0;
}