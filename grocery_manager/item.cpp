/*********************************************************************
** Program name: cart
** Author: David Rider
** Date: 2/3/2017
** Description: CS 162 Project 2: This program is a shopping list. It
** allows the user to display the shopping list, enter new items, and
** delete selected items. The program prevents the user from entering
** duplicate items.
*********************************************************************/
#include "item.hpp"

//DEFAULT CONSTRUCTOR
Item::Item() {
	name = " ";
	unit = " ";
	quantity = 0;
	price = 0.0;
}
//OVERLOADED CONSTRUCTOR
Item::Item(string itemName, string itemUnit, int itemQuantity, double itemPrice) {
	this->name = itemName;
	this->unit = itemUnit;
	this->quantity = itemQuantity;
	this->price = itemPrice;
}
//ACCESSOR FUNCTIONS
string Item::getName() {
	return name;
}
string Item::getUnit() {
	return unit;
}
int Item::getQuantity() {
	return quantity;
}
double Item::getPrice() {
	return price;
}
double Item::getTotal() {
	return quantity * price;
}