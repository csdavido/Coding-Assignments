#include "bluemen.hpp"
/**********************************
** Bluemen() -default constructor
**********************************/
Bluemen::Bluemen() : Creature(12, 3, "Blue Men") {
	armor = 3;
	strength = 12;
	type = "Blue Men";
}
/*****************************
** attack() -function
** that calculates an attack
** value based on a die roll
*****************************/
int Bluemen::attack() {
	int bManAttack = die->roll(2, 10);
	return bManAttack;
}
/*****************************
** defend() -virtual function
** that calculates a defence
** value based on a die roll
*****************************/
int Bluemen::defend() {
	int bManDefend = 0;
	if (getStrength() > 8) {
		bManDefend = die->roll(3, 6);
	}
	else if (getStrength() <= 8 || getStrength() > 4) {
		bManDefend = die->roll(2, 6);
	}
	else if (getStrength() <= 4) {
		bManDefend = die->roll(1, 6);
	}
	return bManDefend;
}
////MUTATOR
//void Bluemen::setStrength(int s) {
//	this->strength = s;
//}
////ACCESSOR
//int Bluemen::getArmor() {
//	return armor;
//}
//int Bluemen::getStrength() {
//	return strength;
//}
//string Bluemen::getType() {
//	return type;
//}