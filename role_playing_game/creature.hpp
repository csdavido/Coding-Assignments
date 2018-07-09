#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <cstdlib>
#include <string>
#include "die.hpp"

using std::string;

class Creature {
public:
	/*************************
	** Default Constructor
	*************************/
	Creature(int strength = 0, int armor = 0, string type = " ");
	/*************************
	** Copy Constructor
	*************************/
	Creature(const Creature &obj);
	/*************************
	** OVERLOADED OPERATOR
	*************************/
	Creature& operator=(const Creature &obj);
	/*****************************
	** attack() -virtual function
	** that calculates an attack
	** value based on a die roll
	*****************************/
	virtual int attack() = 0;
	/*****************************
	** defend() -virtual function
	** that calculates a defence
	** value based on a die roll
	*****************************/
	virtual int defend() = 0;
	//MUTATOR
	void setStrength(int);
	void setLife(bool);
	//ACCESSOR
	int getArmor();
	int getStrength();
	string getType();
	bool getLife();
protected:
	Die *die;
	int armor, strength;
	string type;
	bool life;
};
#endif