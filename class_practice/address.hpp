#include <string>

#ifndef ADDRESS_HPP
#define ADDRESS_HPP

using std::string;

class Address {
public:
	//DEFAULT CONSTRUCTOR
	Address();
	//CONSTRUCTOR THAT TAKES ARGUMENTS
	Address(string label, string houseNumber, string streetName, 
		    string city, string state, int zip);
	//COPY CONSTRUCTOR
	Address(const Address &addObj);
	//OVERLOADED ASSIGNMENT OPERATOR
	Address& operator=(const Address &rhs);
	//MUTATORS AND ACCESSORS
	void setLabel(string);
	void setHouseNumber(string);
	void setStreetName(string);
	void setCity(string);
	void setState(string);
	void setZip(int);

	string getLabel();
	string getHouseNumber();
	string getStreetName();
	string getCity();
	string getState();
	int getZip();
private:
	string label, houseNumber, streetName, city, state;
	int zip;
};
#endif 
