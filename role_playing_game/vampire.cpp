#include "vampire.hpp"
/**********************************
** Vampire() -default constructor
**********************************/
Vampire::Vampire() : Creature(18, 1, "Vampire") {
	armor = 1;
	strength = 18;
	type = "Vampire";
}
/*****************************
** attack() -function
** that calculates an attack
** value based on a die roll
*****************************/
int Vampire::attack() {
	int vAttack = die->roll(1, 12);
	return vAttack;
}
/*****************************
** defend() -virtual function
** that calculates a defence
** value based on a die roll
*****************************/
int Vampire::defend() {
	int vDefend = die->roll(1, 6);
	return vDefend;
}
////MUTATOR
//void Vampire::setStrength(int s) {
//	this->strength = s;
//}
////ACCESSOR
//int Vampire::getArmor() {
//	return armor;
//}
//int Vampire::getStrength() {
//	return strength;
//}
//string Vampire::getType() {
//	return type;
//}