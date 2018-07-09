#include <iostream>
#include <cstdlib>
#include <time.h>
#include "creature.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "vampire.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "game.hpp"

using std::cout;
using std::cin;
using std::endl;

void gameMenu();

int main() {
	gameMenu();

	return 0;
}
void gameMenu() {
	//PRINT MENU
	cout << "*****MENU*****" << endl;
	cout << "(1) Choose Fighters." << endl;
	cout << "(2) Print menu." << endl;
	cout << "(3) Exit the program." << endl;
	//GET USER CHOICE
	int choice;
	cin >> choice;
	//VALIDATE
	while (choice < 1 || choice > 3 || cin.fail()) {
		cout << "Error! Invalid entry." << endl;
		cout << "Re-enter choice: ";
		cin.clear();
		cin >> choice;
	}
	while (choice == 1) {
		//DISPLAY FIGHTERS
		cout << "(1) Barbarian" << endl;
		cout << "(2) Bluemen" << endl;
		cout << "(3) Vampire" << endl;
		cout << "(4) Medusa" << endl;
		cout << "(5) Harry Potter" << endl;
		cout << "*****************" << endl;
		//CHOOSE FIGHTERS
		cout << "Choose fighter 1: " << endl;
		int c1, c2;
		cin >> c1;
		while (c1 < 1 || c1 > 5 || cin.fail()) {
			cout << "Error! Invalid entry." << endl;
			cout << "Re-enter choice: ";
			cin.clear();
			cin >> c1;
		}
		cout << "Choose fighter 2: " << endl;
		cin >> c2;
		while (c2 < 1 || c2 > 5 || cin.fail()) {
			cout << "Error! Invalid entry." << endl;
			cout << "Re-enter choice: ";
			cin.clear();
			cin >> c2;
		}
		Creature *opp1;
		Creature *opp2;
		//ASSIGN CHOICE
		switch (c1) {
		case 1:
			opp1 = new Barbarian;
			break;
		case 2:
			opp1 = new Bluemen;
			break;
		case 3:
			opp1 = new Vampire;
			break;
		case 4:
			opp1 = new Medusa;
			break;
		case 5:
			opp1 = new HarryPotter;
			break;
		default:
			opp1 = new Barbarian;
			break;
		}
		switch (c2) {
		case 1:
			opp2 = new Barbarian;
			break;
		case 2:
			opp2 = new Bluemen;
			break;
		case 3:
			opp2 = new Vampire;
			break;
		case 4:
			opp2 = new Medusa;
			break;
		case 5:
			opp2 = new HarryPotter;
			break;
		default:
			opp2 = new Barbarian;
			break;
		}
		//RANDOMIZE 1ST PLAYER
		int firstPlayer = rand() % 10 + 1;
		if (firstPlayer % 2 == 0) {
			Game newGame(opp1, opp2);
			cout << newGame.fight() << endl;
		}
		else {
			Game newGame(opp2, opp1);
			cout << newGame.fight() << endl;
		}
		int next;
		cout << "(1) Play again" << endl;
		cout << "(2) Return to main menu" << endl;
		cout << "(3) Exit program" << endl;
		cout << "Make a selection: ";
		cin.clear();
		cin >> next;
		while (next < 1 || next > 3 || cin.fail()) {
			cout << "Error, invalid input. Re-enter selection: ";
			cin.clear();
			cin >> next;
		}
		if (next == 1) {
			choice = 1;
		}
		else if (next == 2) {
			choice = 2;
		}
		else {
			choice = 3;
		}
	}
	while (choice == 2) {
		gameMenu();
	}
	while (choice == 3) {
		break;
	}
}