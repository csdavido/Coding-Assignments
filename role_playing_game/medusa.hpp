#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "creature.hpp"

class Medusa : public Creature {
public:
	/**********************************
	** Medusa() -default constructor
	**********************************/
	Medusa();
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
	////ACCESSOR
	//int getArmor();
	//int getStrength();
	//string getType();
private:
	int armor, strength;
	string type;
};
#endif