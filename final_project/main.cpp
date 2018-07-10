/*******************************************************************
** Program name: crybaby
** Author: David Rider
** Date: 3/19/2017
** Description: CS 162 Final Project: This program is a text-based
** game. The object is to get your baby to stop crying before your 
** partner gets home. There are 6 rooms, which inherit from 3 types
** of child classes of a parent space class. There are four items 
** which inherit from an item class. There is a player class that 
** contains the players data. There is a game class that controls
** and simulates the game. Selecting the correct object and bring-
** ing it to the baby wins the game. Failing to do so befor the 
** partner returns ends the game in a loss.
*******************************************************************/
#include <iostream>
#include <limits>
#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
//USER MENU
int menu();

int main() {
	Game newGame;
	bool quit = false;
	while (!quit) {
		int userChoice = menu();
		switch (userChoice) {
		case 1:
			cout << "Select difficulty: " << endl;
			cout << "(1) Amatuer Hour (Easy)" << endl;
			cout << "(2) New Parent (Medium)" << endl;
			cout << "(3) 8 kids and counting (Hard)" << endl;
			int dif;
			while (!(cin >> dif) || dif < 1 || dif > 3) {
				cout << "Error! Re-enter choice: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			std::cout << "\033[2J\033[1;1H";
			if (dif == 1) {
				newGame.setDiff(30);
			}
			else if (dif == 2) {
				newGame.setDiff(20);
			}
			else if (dif == 3) {
				newGame.setDiff(10);
			}
			newGame.play();
			break;
		case 2:
			newGame.welcome();
			break;
		case 3:
			quit = true;
			break;
		}
	}
	return 0;
}
//USER MENU
int menu() {
	cout << "**************CRY**BABY**************" << endl;
	cout << "(1) New Game" << endl;
	cout << "(2) View instructions" << endl;
	cout << "(3) Quit" << endl;
	int choice;
	while (!(cin >> choice) || choice != 1 && choice != 2 && choice != 3) {
		cout << "Error! Re-enter choice: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	std::cout << "\033[2J\033[1;1H";
	return choice;
}
