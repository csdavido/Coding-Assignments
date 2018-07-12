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
#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>

using std::string;

class Monster {
public:
	Monster();
	/****************************************************
	** attack() -virtual function that generates a random 
	** number between 0 and int strength. It adds up each
	** attack and returns the value.
	****************************************************/
	virtual int attack() = 0;
	//ACCESSOR FUNCTION
	virtual string getType() = 0;
private:
	int attacks, strength, total;
	string type;
};
#endif