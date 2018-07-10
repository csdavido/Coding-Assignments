#include "address.hpp"
#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

class Person {
public:
	//DEFAULT CONSTRUCTOR
	Person();
	//CONSTRUCTOR THAT TAKES ARGUMENTS
	Person(string firstName, string lastName, int age, int telNum);
	//DESTRUCTOR
	~Person();
	//COPY CONSTRUCTOR
	Person(const Person &perObj);
	//OVERLOAD ASSIGNMENT OPERATOR
	Person& operator=(const Person &rhs);
	//MUTATORS AND ACCESSORS
	void setFirstName(string);
	void setLastName(string);
	void setAge(int);
	void setTelNum(int);
	void setNumAddrs(int);

	string getFirstName();
	string getLastName();
	int getAge();
	int getTelNum();
	int getNumAddrs();
	//DISPLAY PERSON
	void displayPerson();
	//ADD ADDRESS
	void addAddress(Address &newAddrs);
private:
	string firstName, lastName;
	int age, telNum, numAddrs;
	Address* addressArray = new Address[10];
};
#endif
