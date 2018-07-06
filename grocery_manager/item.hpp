/*********************************************************************
** Program name: cart
** Author: David Rider
** Date: 2/3/2017
** Description: CS 162 Project 2: This program is a shopping list. It
** allows the user to display the shopping list, enter new items, and
** delete selected items. The program prevents the user from entering
** duplicate items.
*********************************************************************/
#include <iostream>
#include <string> 

#ifndef ITEM_HPP
#define ITEM_HPP

using std::string;

class Item {
public:
	//DEFAULT CONSTRUCTOR
	Item();
	//OVERLOADED CONSTRUCTOR
	Item(string, string, int, double);
	//ACCESSOR FUNCTIONS
	string getName();
	string getUnit();
	int getQuantity();
	double getPrice();
	double getTotal();
private:
	string name;
	string unit;
	int quantity;
	double price;
};
#endif 