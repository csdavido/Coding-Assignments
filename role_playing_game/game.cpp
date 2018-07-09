#include <iostream>
#include "game.hpp"

using std::cout;
using std::endl;

Game::Game(Creature *creature1, Creature *creature2) {
	this->c1 = creature1;
	this->c2 = creature2;
	bool over = false;
}
string Game::fight() {
	while (over == false) {
		int total, total2;
		cout << c1->getType() << "    vs.   " << c2->getType() << endl;
		cout << "S: " << c1->getStrength() << "             S: " << c2->getStrength() << endl;
		cout << "***********************************" << endl;
		//OPPONENT 1 ATTACK
		total = (c1->attack() - c2->getArmor()) - c2->defend();
		if (c2->getType() == "Vampire") {
			int charm = rand() % 2 + 1;
			if (charm == 1) {
				cout << "Vampire used charm!" << endl;
				total = 0;
			}
		}
		if (total < 0) {
			total = 0;
		} 
		c2->setStrength(c2->getStrength() - total);
		if (c2->getType() == "Harry") {
			if (c2->getLife() == false && c2->getStrength() <= 0) {
				c2->setStrength(20);
				c2->setLife(true);
				cout << "Harry is revived!" << endl;
			}
		}
		cout << c1->getType() << " attacks! They do " << total << " damage!" << endl;
		if (c2->getStrength() <= 0) {
			return "Opponent 1 wins!";
			over = true;
		}
		//opponent 2
		total2 = (c2->attack() - c1->getArmor()) - c1->defend();
		if (c1->getType() == "Vampire") {
			int charm = rand() % 2 + 1;
			if (charm == 1) {
				cout << "Vampire used charm!" << endl;
				total2 = 0;
			}
		}
		if (total2 < 0) {
			total2 = 0;
		}
		c1->setStrength(c1->getStrength() - total2);
		if (c1->getType() == "Harry") {
			if (c1->getLife() == false && c1->getStrength() <= 0) {
				c1->setStrength(20);
				c1->setLife(true);
				cout << "Harry is revived!" << endl;
			}
		}
		cout << c2->getType() << " attacks! They do " << total2 << " damage!" << endl;
		if (c1->getStrength() <= 0) {
			return "Opponent 2 wins!";
			over = true;
		}
	}
}