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

#ifndef LIST_HPP
#define LIST_HPP

class List {
public:
	//DEFAULT CONSTRUCTOR
	List();
	/**************************************
	** addItem() -adds an Item object to a
	**            list array
	** @param -Item object
	***************************************/
	void addItem(Item);
	/**************************************
	** deleteItem() -removes an Item from a
	**               list array
	** @param -int -number representing an
	**              item object
	***************************************/
	void deleteItem(int);
	//ACCESSOR FUNCTION
	int getItems();
	/**************************************
	** getTotal() -calculates the grand
	               total of item array.
	***************************************/
	double getTotal();
	/**************************************
	** displayList() -displays the contents
	**                of a list array
	***************************************/
	void displayList();
	//OVERLOADED INEQUALITY OPERATOR
	bool operator==(string);
	/**************************************
	** clean() -deletes item array
	***************************************/
	void clean();
private:
	int defaultSize, items;
	double total;
	Item *itemArray;
};
#endif 