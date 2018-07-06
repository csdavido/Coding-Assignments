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

#include "list.hpp"

using std::cout;
using std::endl;
//DEFAULT CONSTRUCTOR
List::List() {
	defaultSize = 4;
	items = 0;
	total = 0.0;
	itemArray = new Item[defaultSize];
}
/**************************************
** addItem() -adds an Item object to a
**            list array
** @param -Item object
***************************************/
void List::addItem(Item newItem) {
	if (items < defaultSize) {
		itemArray[items] = newItem;
		items++;
	} 
	else {
		Item* copyArray = new Item[defaultSize];
		for (int a = 0; a < defaultSize; a++) {
			copyArray[a] = itemArray[a];
		}
		defaultSize++;

		itemArray = new Item[defaultSize];

		for (int b = 0; b < items; b++) {
			itemArray[b] = copyArray[b];
		}

		delete[] copyArray;

		itemArray[items] = newItem;
		items++;
	}
}
/**************************************
** deleteItem() -removes an Item from a
**               list array
** @param -int -number representing an
**              item object
***************************************/
/* cboard.cprogramming.com/cplusplus-programming/132068-help-creating-dynamic-array-can-add-delete-elements.html*/
void List::deleteItem(int itemNumber) {
	Item* tempItem = new Item[items]; 
	for (int c = 0; c < itemNumber; c++) {
		tempItem[c] = itemArray[c];
	}
	for (int d = itemNumber + 1; d < items; d++) {
		tempItem[d - 1] = itemArray[d];
	} 
	items--;
	for (int e = 0; e < items; e++) {
		itemArray[e] = tempItem[e];
	}
	delete[] tempItem;
}
//ACCESSOR FUNCTION
int List::getItems() {
	return items;
}
/**************************************
** getTotal() -calculates the grand
total of item array.
***************************************/
double List::getTotal() {
	for (int f = 0; f < items; f++) {
		total += itemArray[f].getTotal();
	}
	return total;
}
/**************************************
** displayList() -displays the contents
**                of a list array
***************************************/
void List::displayList() {
	for (int g = 0; g < items; g++) {
		cout << "(" << g + 1 << ")" << endl;
		cout << "Item: " << itemArray[g].getName() << endl;
		cout << "Unit: " << itemArray[g].getUnit() << endl;
		cout << "Quantity: " << itemArray[g].getQuantity() << endl;
		cout << "Price: $" << itemArray[g].getPrice() << endl;
		cout << "---------------" << endl;
		cout << "Total: $" << itemArray[g].getTotal() << endl;
		cout << "===============" << endl;
	}
	
}
//OVERLOADED INEQUALITY OPERATOR
bool List::operator==(string n) {
	bool match = false;
	for (int h = 0; h < items; h++) {
		if (itemArray[h].getName() == n) {
			match = true;
		} 
	}
	return match;
}
/**************************************
** clean() -deletes item array
***************************************/
void List::clean() {
	delete[] itemArray;
}