#include "barbarian.hpp"
/**********************************
** Barbarian() -default constructor
**********************************/
Barbarian::Barbarian() : Creature(12, 0, "Barbarian") {
	armor = 0;
	strength = 12;
	type = "Barbarian";
}
/*****************************
** attack() -function
** that calculates an attack
** value based on a die roll
*****************************/
int Barbarian::attack() {
	int bAttack = die->roll(2, 6);
	return bAttack;
}
/*****************************
** defend() -virtual function
** that calculates a defence
** value based on a die roll
*****************************/
int Barbarian::defend() {
	int dAttack = die->roll(2, 6);
	return dAttack;
}
////MUTATOR
//void Barbarian::setStrength(int s) {
//	this->strength = s;
//}
////ACCESSOR
//int Barbarian::getArmor() {
//	return armor;
//}
//int Barbarian::getStrength() {
//	return strength;
//}
//string Barbarian::getType() {
//	return type;
//}