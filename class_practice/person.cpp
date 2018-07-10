#include <iostream>
#include "person.hpp"

using std::cout;
using std::endl;

//DEFAULT CONSTRUCTOR
Person::Person() {
	firstName = "John";
	lastName = "Doe";
	age = -1;
	telNum = -1;
	numAddrs = 0;
}
//CONSTRUCTOR THAT TAKES ARGUMENTS
Person::Person(string firstName, string lastName, int age, int telNum) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->telNum = telNum;
}
//DESTRUCTOR
Person::~Person() {
	cout << "Destructor called." << endl;
	delete[] addressArray;
}
//COPY CONSTRUCTOR
Person::Person(const Person &perObj) {
	this->firstName = perObj.firstName;
	this->lastName = perObj.lastName;
	this->age = perObj.age;
	this->telNum = perObj.telNum;
	this->addressArray = perObj.addressArray;
}
//OVERLOAD ASSIGNMENT OPERATOR
Person& Person::operator=(const Person &rhs) {
	this->setFirstName(rhs.firstName);
	this->setLastName(rhs.lastName);
	this->setAge(rhs.age);
	this->setTelNum(rhs.telNum);
	return *this;
}
//MUTATORS
void Person::setFirstName(string newFName) {
	firstName = newFName;
}
void Person::setLastName(string newLName) {
	lastName = newLName;
}
void Person::setAge(int newAge) {
	age = newAge;
}
void Person::setTelNum(int newTelNum) {
	telNum = newTelNum;
}
void Person::setNumAddrs(int newNumAddrs) {
	numAddrs = newNumAddrs;
}
//ACCESSORS
string Person::getFirstName() {
	return firstName;
}
string Person::getLastName() {
	return lastName;
}
int Person::getAge() {
	return age;
}
int Person::getTelNum() {
	return telNum;
}
int Person::getNumAddrs() {
	return numAddrs;
}
//DISPLAY PERSON
void Person::displayPerson() {
	cout << "Name: " << getFirstName() << " " << getLastName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Telepone Number: " << getTelNum() << endl;
	cout << "Address(es):" << endl;
	cout << "Label: " << addressArray->getLabel() << endl;
	cout << "Street: " << addressArray->getStreetName() << endl;
	cout << "City: " << addressArray->getCity() << endl;
	cout << "State: " << addressArray->getState() << endl;
	cout << "Zip: " << addressArray->getZip() << endl;
}

//ADD ADDRESS
void Person::addAddress(Address &newAddrs) {
	for (int i = 0; i < 10; i++) {
		addressArray[i] = newAddrs;
		numAddrs++;
	}
}