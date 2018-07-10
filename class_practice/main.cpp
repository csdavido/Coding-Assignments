#include <iostream>
#include <string>
#include "person.hpp"
#include "address.hpp"

int main() {
	//Test 1 Default constructor
	std::cout << "*****TEST 1***** Creating p1 with default constructor\n";
	Person p1;
	std::cout << "\nDisplaying p1:\n\n";
	p1.displayPerson();
	std::cout << "\nExpected Output:\n\nName: John Doe\nAge: -1\nTelephone Number: -1\nAddress(es):\n";

	//Test 2 Constructor with aurguments
	std::cout << "\n\n*****TEST 2**** Creating p2 with arguments (\"Eric\", \"Ianni\", 31, 5555555)\n";
	Person p2("Eric", "Ianni", 31, 5555555);
	std::cout << "\nDisplaying p2:\n\n";
	p2.displayPerson();
	std::cout << "\nExpected Output:\n\nName: Eric Ianni\nAge: 31\nTelephone Number: 5555555\nAddress(es):\n";

	//Test 3 Copy Constructor
	std::cout << "\n\n*****TEST 3*****  Creating p3 using copy constructor and p2\n";
	Person p3(p2);
	std::cout << "\nDisplaying p3:\n\n";
	p3.displayPerson();
	std::cout << "\nExpected Output:\n\nName: Eric Ianni\nAge: 31\nTelephone Number: 5555555\nAddress(es):\n";

	//Test 4 Adding an Address
	std::cout << "\n\n*****TEST 4***** Adding addresses to p2\n";
	std::cout << "*****TEST 4a***** Creating a1 with default constructor\n";
	Address a1;
	std::cout << "*****TEST 4b***** Creating a2 with arguments (\"Home\", \"123\", \"Street Rd\", \"Springfield\", \"CO\", 12345)\n";
	Address a2("Home", "123", "Street Rd", "Springfield", "CO", 12345);
	std::cout << "*****TEST 4c***** Creating a3 using copy constructor and a2\n";
	Address a3(a2);
	std::cout << "Adding a1...";
	p2.addAddress(a1);
	std::cout << "a2...";
	p2.addAddress(a2);
	std::cout << "a3...";
	p2.addAddress(a3);
	std::cout << "done\n";
	std::cout << "Displaying p2:\n\n";
	p2.displayPerson();
	std::cout << "\nExpected Output:\n\nName: Eric Ianni\nAge: 31\nTelephone Number: 5555555\nAddress(es):\n";
	std::cout << "Label: NONE\nStreet: NONE NONE\nCity: NONE\nState: NONE\nZip: -1\n";
	std::cout << "Label: Home\nStreet: 123 Street Rd\nCity: Springfield\nState: CO\nZip: 12345\n";
	std::cout << "Label: Home\nStreet: 123 Street Rd\nCity: Springfield\nState: CO\nZip: 12345\n\n";

	//Test 5 Person assignment operator
	std::cout << "****TEST 5**** Using assignment operator: p1 = p2\n";
	p1 = p2;
	std::cout << "\nDisplaying p1\n\n";
	p1.displayPerson();
	std::cout << "\nExpected Output:\n\nName: Eric Ianni\nAge: 31\nTelephone Number: 5555555\nAddress(es):\n";
	std::cout << "Label: NONE\nStreet: NONE NONE\nCity: NONE\nState: NONE\nZip: -1\n";
	std::cout << "Label: Home\nStreet: 123 Street Rd\nCity: Springfield\nState: CO\nZip: 12345\n";
	std::cout << "Label: Home\nStreet: 123 Street Rd\nCity: Springfield\nState: CO\nZip: 12345\n\n";

	//Test 6 Person copy constructor when the person being copied has addresses
	std::cout << "****TEST 6***** Creating p4 by copying p2\n";
	Person p4(p2);
	std::cout << "\nDisplaying p4\n\n";
	p4.displayPerson();
	std::cout << "\nExpected Output:\n\nName: Eric Ianni\nAge: 31\nTelephone Number: 5555555\nAddress(es):\n";
	std::cout << "Label: NONE\nStreet: NONE NONE\nCity: NONE\nState: NONE\nZip: -1\n";
	std::cout << "Label: Home\nStreet: 123 Street Rd\nCity: Springfield\nState: CO\nZip: 12345\n";
	std::cout << "Label: Home\nStreet: 123 Street Rd\nCity: Springfield\nState: CO\nZip: 12345\n\n";
	system("PAUSE");
	return 0;
}
