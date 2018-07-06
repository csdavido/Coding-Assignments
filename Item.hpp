//function declarations
#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H
//Define a class called Item that consists of a string called name, a double called price, and an int called quantity.
class Item {
public:
	//default constructor
	Item();
	//overload constructor
	Item(string, double, int);
	//destructor
	~Item();
	
// It should have get and set methods for each field (following the normal naming convention
//- getName, setName, getPrice, setPrice, getQuantity and setQuantity).
	string getName();
	double getPrice();
	int getQuantity;

	void setName(string name);
	void setPrice(double price);
	void setQuantity(int quantity);


private:
	string newName;
	double newPrice;
	int newQuantity;
};

#endif