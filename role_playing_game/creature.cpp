#include "creature.hpp"

/*************************
** Default Constructor
*************************/
Creature::Creature(int strength, int armor, string type) {
	this->strength = strength;
	this->armor = armor;
	this->type = type;
}
/*************************
** Copy Constructor
*************************/
Creature::Creature(const Creature &obj) : strength(obj.strength), armor(obj.armor), type(obj.type) {

}
/*************************
** OVERLOADED OPERATOR
*************************/
Creature& Creature::operator=(const Creature &obj) {
	strength = obj.strength;
	armor = obj.armor;
	type = obj.type;
	return *this;
}
/*****************************
** attack() -virtual function
** that calculates an attack
** value based on a die roll
*****************************/
int Creature::attack() {
	return -1;
}
/*****************************
** defend() -virtual function
** that calculates a defence
** value based on a die roll
*****************************/
int Creature::defend() {
	return -1;
}
//MUTATOR
void Creature::setStrength(int s) {
	this->strength = s;
}
void Creature::setLife(bool d) {
	this->life = d;
}
//ACCESSOR
int Creature::getArmor() {
	return armor;
}
int Creature::getStrength() {
	return strength;
}
string Creature::getType() {
	return type;
}
bool Creature::getLife() {
	return life;
}