/**********************************************************************
** Program name: p_drome
** Author: David Rider
** Date: 3/11/2017
** Description: This program has two functionalities. First it simulates 
** a queue buffer. It uses user-provided percentage values to randomly 
** input a number in the buffer. The program displays the length of the 
** queue in each round and the average length of the queue over all 
** rounds. The program also alows the user to inter string input which
** will be returned as a palindrome.
**********************************************************************/
#include <iostream>
#include <limits>
#include <string>
#include "queue.hpp"
#include "stack.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;

void menu();

int main() {
	menu();
	return 0;
}

void menu() {
	//CREATE OBJECTS
	Queue newQueue;
	Stack newStack;
	//MENU
	cout << "***********************" << endl;
	cout << "(1) Buffer function" << endl;
	cout << "(2) Palindrone function" << endl;
	cout << "***********************" << endl;
	//GET USER CHOICE AND VALIDATE
	int choice;
	while (!(cin >> choice) || choice != 1 && choice != 2) {
		cout << "Error! Invalid input. Re-enter choice: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "***********************" << endl;
	//BUFFER FUNCTION
	if (choice == 1) {
		//GET PERCENTAGE 1 AND VALIDATE
		cout << "Enter a number (1 - 100) for percentage #1: ";
		int per1;
		while (!(cin >> per1) || per1 < 0 && per1 > 100) {
			cout << "Error! Invalid input. Re-enter choice: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		//GET PERCENTAGE 1 AND VALIDATE
		cout << "Enter a number (1 - 100) for percentage #2: ";
		int per2;
		while (!(cin >> per2) || per2 < 0 && per2 > 100) {
			cout << "Error! Invalid input. Re-enter choice: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Enter simulation rounds (1-1000): ";
		int r;
		while (!(cin >> r) || r < 1 && r > 1000) {
			cout << "Error! Invalid input. Re-enter choice: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		//CALL FUNCTION
		newQueue.simBuff(per1, per2, r);
	}
	else {
		//CALL PALINDRONE FUNCTION
		cout << "Enter a string to recieve it's palindrome: ";
		//GET USER INPUT
		string sInput;
		cin >> sInput;
		//CALL FUNCTION
		cout << "Palindrome: " << newStack.palindrome(sInput) << endl;
	}
}