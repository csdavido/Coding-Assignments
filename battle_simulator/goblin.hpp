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
#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "monster.hpp"

class Goblin : public Monster {
public:
	//DEFAULT CONSTRUCTOR
	Goblin();
	/****************************************************
	** attack() -virtual function that generates a random
	** number between 0 and int strength. It adds up each
	** attack and returns the value.
	****************************************************/
	int attack();
	//ACCESSOR FUNCTION
	string getType();
private:
	int attacks, strength, total;
	string type;
};
#endif