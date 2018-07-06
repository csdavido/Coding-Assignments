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
using std::cin;
using std::endl;

int main() {
	//CREATE LIST OBJECT
	List newList;
	//DISPLAY INITIAL MENU OPTIONS
	cout << "Make a selection." << endl;
	cout << "===============" << endl;
	cout << "1. Display List." << endl;
	cout << "2. Add new item." << endl;
	cout << "3. Delete item." << endl;
	cout << "4. Display Menu." << endl;
	cout << "5. Exit program." << endl;
	cout << "===============" << endl;
	//INPUT AND VALIDATE USER CHOICE
	int choice;
	cin >> choice;
	while (choice <= 0 || choice > 5 || cin.fail()) {
		cout << "Error. Re-enter choice." << endl;
		cin.clear();
		cin.ignore();
		cin >> choice;
	}
	/**************************************
	** SIMULATION LOOP
	** It will exit when the user selects 5
	***************************************/
	while (choice != 5) {
		//VALIDATE
		while (choice == 3 && newList.getItems() == 0) {
				cout << "Error. Add items first to delete." << endl;
				choice = 4;
		}
		while (choice == 1 && newList.getItems() == 0) {
			cout << "No items on list." << endl;
			choice = 4;
		}
		//DISPLAY LIST
		while (choice == 1) {
			newList.displayList();
			cout << "***************" << endl;
			cout << "Grand Total: $" << newList.getTotal() << endl;
			choice = 4;
		}
		//ADD NEW ITEM
		while (choice == 2) {
			//IPUT MEMBERS
			string inputName, inputUnit;
			int inputQuantity;
			double inputPrice;
			cout << "===============" << endl;
			cout << "Add a new item." << endl;
			cout << "===============" << endl;
			cout << "Item name: " << endl;
			cin.clear();
			cin.ignore();
			getline(cin >> std::ws, inputName);
			cout << "Unit type: " << endl;
			cin.clear();
			getline(cin >> std::ws, inputUnit);
			cout << "Quantity: " << endl;
			cin.clear();
			cin >> inputQuantity;
			//VALIDATE
			while (inputQuantity <= 0 || cin.fail()) {
				cout << "Error. Enter a positive number: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> inputQuantity;
			}
			cout << "Price: " << endl;
			cin >> inputPrice;
			//VALIDATE
			while (inputPrice <= 0.0 || cin.fail()) {
				cout << "Error. Enter a positive number: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> inputPrice;
			}
			//CREATE ITEM OBJECT
			Item newItem(inputName, inputUnit, inputQuantity, inputPrice);
			//CHECK FOR DUPLICATE
			if (newList == inputName) {
				cout << "Error. Duplicate item." << endl;
				choice = 4;
			}
			//IF NO DUPLICATE, ADD ITEM TO LIST
			else {
				newList.addItem(newItem);
			}

			cout << "***************" << endl;
			choice = 4;
		}
		//DELETE ITEM
		while (choice == 3) {
			int deleteNum;
			newList.displayList();
			cout << "Enter number of item to be deleted." << endl;
			cin >> deleteNum;
			//VALIDATE
			while (deleteNum < 1 || deleteNum > newList.getItems() || cin.fail()) {
				cout << "Error. Enter the number of the item you wish to delete: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> deleteNum;
			}
			cout << "Deleting..." << endl;
			newList.deleteItem(deleteNum - 1);
			cout << "***************" << endl;
			choice = 4;
		}
		//RE-PRINT MENU
		while (choice == 4) {
				cout << endl;
				cout << "Make a selection." << endl;
				cout << "1. Display List." << endl;
				cout << "2. Add new item." << endl;
				cout << "3. Delete item." << endl;
				cout << "4. Display Menu." << endl;
				cout << "5. Exit program." << endl;
				cin >> choice;
				while (choice <= 0 || choice > 5 || cin.fail()) {
					cout << "Error. Re-enter choice." << endl;
					cin.clear();
					cin.ignore(100, '\n');
					cin >> choice;
				}
			}
		//EXIT PROGRAM AND CALL FUNCTION TO DEALLOCATE
		while (choice == 5) {
			newList.clean();
			return 0;
		}
	}
	return 0;
}