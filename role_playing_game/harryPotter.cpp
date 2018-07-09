#include "harryPotter.hpp"
/**********************************
** HarryPotter() -default constructor
**********************************/
HarryPotter::HarryPotter() : Creature(10, 0, "Harry") {
	armor = 0;
	strength = 10;
	type = "Harry";
	died = false;
}
/*****************************
** attack() -function
** that calculates an attack
** value based on a die roll
*****************************/
int HarryPotter::attack() {
	int harAttack = die->roll(2, 6);
	return harAttack;
}
/*****************************
** defend() -virtual function
** that calculates a defence
** value based on a die roll
*****************************/
int HarryPotter::defend() {
	int harDefend = die->roll(2, 6);
	return harDefend;
}
////MUTATOR
//void HarryPotter::setStrength(int s) {
//	this->strength = s;
//}
//void HarryPotter::setDied(bool d) {
//	this->died = d;
//}
////ACCESSOR
//int HarryPotter::getArmor() {
//	return armor;
//}
//int HarryPotter::getStrength() {
//	return strength;
//}
//string HarryPotter::getType() {
//	return type;
//}
//bool HarryPotter::getDied() {
//	return died;
//}