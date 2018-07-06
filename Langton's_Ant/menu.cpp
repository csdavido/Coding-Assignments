/*********************************************************************
** Program name: simulate (CS 162 Project 1)
** Author: David Rider
** Date: 1/22/2017
** Description: This program creates a simulation of Langton's Ant.
** It utilizes three classes, and it inludes a 2D matrix which is
** dynamically allocated. This program contains a menu which offers
** input validation and is responsible for collecting input data from
** the user.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <time.h>

#include "menu.hpp"
#include "ant.hpp"


using std::cout;
using std::cin;
using std::endl;

Menu::Menu() {
	row = 0;
	col = 0;
	x = 0;
	y = 0;
	speed = 0;
}
/*************************************************
** gameMenu- collects data from the user. 
** @param pointer to an Ant object
*************************************************/
void Menu::gameMenu(Ant *menuAnt) {
	cout << "*************************" << endl;
	cout << "*****LANGTON'S***ANT*****" << endl;
	cout << "*************************" << endl;
	cout << "**c*2017***David*Rider***" << endl;
	cout << "*************************" << endl;
	cout << "*********v.*1.0**********" << endl;
	cout << "*************************" << endl;
	cout << "Game Menu" << endl;
	cout << "*************************" << endl;
	getBoard();
	cout << "How many moves would you like to make?" << endl;
	cin >> moves;
	while (moves <= 0) {
		cout << "Please enter a positive integer." << endl;
		cout << "Re-enter moves: ";
		cin >> moves;
	}
	cout << "Choose your simulation speed." << endl;
	cout << "1. Super-slow, 2. Normal, 3. Super-sonic: ";
	int speedChoice;
	cin >> speedChoice;
	while (speedChoice != 1 && speedChoice != 2 && speedChoice != 3) {
		cout << "Invalid input. Please enter 1, 2, or 3: ";
		cin >> speedChoice;
	}
	if (speedChoice == 1) {
		speed = 1000000;
	}
	else if (speedChoice == 2) {
		speed = 1000;
	}
	else if (speedChoice == 3) {
		speed = 100;
	}
	cout << "1. Choose starting coordinates." << endl;
	cout << "2. Use random starting coordinates." << endl;
	cout << "3. Exit program." << endl;
	cout << "Enter 1, 2, or 3. To make a selection: ";
	int choice;
	char confirm;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "Error. Invalid input. Please enter 1, 2, or 3: ";
		cin >> choice;
	}
	if (choice == 1) {
		cout << "Are you sure you want to enter your own coordinates? Y/N: ";
		cin >> confirm;
		while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
			cout << "Error. Invalid input. Please enter Y/N: ";
			cin >> confirm;
		}
		if (confirm == 'y' || confirm == 'Y') {
			getUserCoord(menuAnt);
		}
		else if (confirm == 'n' || confirm == 'N') {
			cout << "Please re-enter your choice: ";
			cin >> choice;
		}
	}
	else if (choice == 2) {
		cout << "Are you sure you want to use random coordinates? Y/N: ";
		cin >> confirm;
		while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
			cout << "Error. Invalid input. Please enter Y/N: ";
			cin >> confirm;
		}
		if (confirm == 'y' || confirm == 'Y') {
			getRanCoord(menuAnt);
		}
		else if (confirm == 'n' || confirm == 'N') {
			cout << "Please re-enter your choice: ";
			cin >> choice;
		}
	}
	else {
		cout << "Exiting program." << endl;
		cout << "Press enter to exit the program: ";
		cin.ignore().get();
	}
}
/*************************************************
** createGrid- dynamically allocates memory for 2d
** array.
** @param pointer to 2D array
** @param int for value of row/col
*************************************************/
void Menu::getBoard() {
	cout << "Please choose the size of your simulation." << endl;
	cout << "Enter row size: ";
	cin >> row;
	cout << "Enter column size: ";
	cin >> col;
	if (col < 2 || row < 2) {
		cout << "Enter a higher number." << endl;
		cout << "Re-enter row: ";
		cin >> row;
		cout << "Re-enter col: ";
		cin >> col;
	}
}
/*************************************************
** getUserCoord- accepts starting coordinates from 
** the user.
** @param pointer to an Ant object
*************************************************/
void Menu::getUserCoord(Ant *menuAnt) {
	cout << "Enter X: ";
	cin >> x;
	cout << "Enter Y: ";
	cin >> y;
	if (x > row || y > col) {
		cout << "Invalid entry. Enter an integer lesser than row/col.";
		cout << "Re-enter X: ";
		cin >> x;
		cout << "Re-enter Y: ";
		cin >> y;
	}
	else if (x < 0 || y < 0) {
		cout << "Invalid entry. Enter an integer greater than 0.";
		cout << "Re-enter X: ";
		cin >> x;
		cout << "Re-enter Y: ";
		cin >> y;
	}
	menuAnt->setX(x);
	menuAnt->setY(y);
}
/*************************************************
** getRanCoord- generates random starting coord-
** inates for the user.
** @param pointer to an Ant object
*************************************************/
void Menu::getRanCoord(Ant *menuAnt) {
	cout << "Generating random coordinates..." << endl;
	int randX, randY;
	srand(time(0));
	randX = rand() % row + 1;
	randY = rand() % col + 1;
	menuAnt->setX(randX);
	menuAnt->setY(randY);
	cout << "X-Coordinate: " << randX << endl;
	cout << "Y-Coordinate: " << randY << endl;
}
//MUTATOR FUNCTIONS
void Menu::setRow(int r) {
	row = r;
}
void Menu::setCol(int c) {
	col = c;
}
void Menu::setMoves(int m) {
	moves = m;
}
void Menu::setSpeed(int s) {
	speed = s;
}
//ACCESSOR FUNCTIONS
int Menu::getRow() {
	return row;
}
int Menu::getCol() {
	return col;
}
int Menu::getMoves() {
	return moves;
}
int Menu::getSpeed() {
	return speed;
}