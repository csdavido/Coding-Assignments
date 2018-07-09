#include "medusa.hpp"
/**********************************
** Medusa() -default constructor
**********************************/
Medusa::Medusa() : Creature(8, 3, "Medusa") {
	armor = 3;
	strength = 8;
	type = "Medusa";
}
/*****************************
** attack() -function
** that calculates an attack
** value based on a die roll
*****************************/
int Medusa::attack() {
	int mAttack = die->roll(2, 6);
	if (mAttack == 12) {
		mAttack = 1000;

	}
	return mAttack;
}
/*****************************
** defend() -virtual function
** that calculates a defence
** value based on a die roll
*****************************/
int Medusa::defend() {
	int mDefend = die->roll(1, 6);
	return mDefend;
}
////MUTATOR
//void Medusa::setStrength(int s) {
//	this->strength = s;
//}
////ACCESSOR
//int Medusa::getArmor() {
//	return armor;
//}
//int Medusa::getStrength() {
//	return strength;
//}
//string Medusa::getType() {
//	return type;
//}