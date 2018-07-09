#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "creature.hpp"

class HarryPotter : public Creature {
public:
	/**********************************
	** HarryPotter() -default constructor
	**********************************/
	HarryPotter();
	/*****************************
	** attack() -function
	** that calculates an attack
	** value based on a die roll
	*****************************/
	int attack();
	/*****************************
	** defend() -virtual function
	** that calculates a defence
	** value based on a die roll
	*****************************/
	int defend();
	////MUTATOR
	//void setStrength(int);
	//void setDied(bool);
	////ACCESSOR
	//int getArmor();
	//int getStrength();
	//string getType();
	//bool getDied();
private:
	bool died;
	int armor, strength;
	string type;
};
#endif