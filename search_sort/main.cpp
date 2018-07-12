/*******************************************************************
** Program name: search
** Author: David Rider
** Date: 3/5/2017
** Description: CS 162 Lab 8: This program contains three functions.
** The first function performs a simple linear search. The second 
** sorts a file. The third performs a binary search.
*******************************************************************/
#include <iostream>
#include <string>
#include <limits>
#include "tools.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void menu();

int main() {
	menu();
	return 0;
}

void menu() {
	cout << "******************************************************" << endl;
	cout << "(1) Search for a target value." << endl;
	cout << "(2) Perform a value sort." << endl;
	cout << "(3) Perform a binary sort. (2 must be completed first)" << endl;
	cout << "******************************************************" << endl;
	cout << "Make a selection: ";
	int choice;
	while (!(cin >> choice) || choice < 1 || choice > 3) {
		cout << "Error. Invalid input, re-enter choice: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	int rValue;
	if (choice == 1) {
		cout << "Choose file to search: " << endl;
		cout << "beg.txt" << endl;
		cout << "mid.txt" << endl;
		cout << "end.txt" << endl;
		string uInput;
		cin >> uInput;
		rValue = search(uInput);
		if (rValue == -1) {
			cout << "Search unsuccessfull." << endl;
		}
		else {
			cout << "Search successfull." << endl;
		}
	}
	if (choice == 2) {
		cout << "Choose file to sort: " << endl;
		cout << "beg.txt" << endl;
		cout << "mid.txt" << endl;
		cout << "end.txt" << endl;
		string sInput;
		string sOutput;
		cin >> sInput;
		if (sInput == "beg.txt") {
			cout << "Enter new name for sorted file:";
			cin >> sOutput;
			cout << "Sorting and saving to new file..." << endl;
			sort(sInput, sOutput);
		}
		else if (sInput == "mid.txt") {
			cout << "Enter new name for sorted file:";
			cin >> sOutput;
			cout << "Sorting and saving to new file..." << endl;
			sort(sInput, sOutput);
		}
		else if (sInput == "end.txt") {
			cout << "Enter new name for sorted file:";
			cin >> sOutput;
			cout << "Sorting and saving to new file..." << endl;
			sort(sInput, sOutput);
		}
		else {
			cout << "File not found" << endl;
		}
	}
	if (choice == 3) {
		string newFile;
		int sValue;
		cout << "What file do you want to search?" << endl;
		cin >> newFile;
		cout << "Enter search value: " << endl;
		cin >> sValue;
		rValue = binarySearch(newFile, sValue);
		if (rValue == sValue) {
			cout << "Search was successful." << endl;
		}
		else {
			cout << "Number not found." << endl;
		}
	}
}