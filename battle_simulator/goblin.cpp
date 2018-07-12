/*********************************************************************
** Program name: prog
** Author: David Rider
** Date: 2/18/2017
** Description: CS 162 Lab 5: This program is a battle simulator. It
** contains a base monster class which all other classes inherit from.
** It also contains another class (dragon) which inherits from monster
** and acts as a parent class to two additional classes. lab5.cpp fills
** an array of pointers to monster objects with random elements of the
** child classes.
*********************************************************************/
#include <cstdlib>
#include "goblin.hpp"

//DEFAULT CONSTRUCTOR
Goblin::Goblin() : Monster() {
	attacks = 1;
	strength = 30;
	type = "Goblin";
	total = 0;
}
/****************************************************
** attack() -virtual function that generates a random
** number between 0 and int strength. It adds up each
** attack and returns the value.
****************************************************/
int Goblin::attack() {
	for (int i = 0; i < attacks; i++) {
		total += rand() % strength + 1;
	}
	int dAttack = rand() % 10 + 1;
	if (dAttack == 1) {
		total *= 2;
	}
	return total;
}
//ACCESSOR FUNCTION
string Goblin::getType() {
	return type;
}