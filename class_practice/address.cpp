#include "address.hpp"

//DEFAULT CONSTRUCTOR
Address::Address() {

}
//CONSTRUCTOR THAT TAKES ARGUMENTS
Address::Address(string label, string houseNumber, string streetName,
	string city, string state, int zip) {
	this->label = label;
	this->houseNumber = houseNumber;
	this->streetName = streetName;
	this->city = city;
	this->state = state;
	this->zip = zip;
}
//COPY CONSTRUCTOR
Address::Address(const Address &addObj) {

}
//OVERLOADED ASSIGNMENT OPERATOR
Address& Address::operator=(const Address &rhs) {
	this->setLabel(rhs.label);
	this->setHouseNumber(rhs.houseNumber);
	this->setStreetName(rhs.streetName);
	this->setCity(rhs.city);
	this->setState(rhs.state);
	this->setZip(rhs.zip);
	return *this;
}
//MUTATORS AND ACCESSORS
void Address::setLabel(string newLabel) {
	label = newLabel;
}
void Address::setHouseNumber(string newNum) {
	houseNumber = newNum;
}
void Address::setStreetName(string newName) {
	streetName = newName;
}
void Address::setCity(string newCity) {
	city = newCity;
}
void Address::setState(string newState) {
	state = newState;
}
void Address::setZip(int newZip) {
	zip = newZip;
}

string Address::getLabel() {
	return label;
}
string Address::getHouseNumber() {
	return houseNumber;
}
string Address::getStreetName() {
	return streetName;
}
string Address::getCity() {
	return city;
}
string Address::getState() {
	return state;
}
int Address::getZip() {
	return zip;
}