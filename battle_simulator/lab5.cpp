/*********************************************************************
** Program name: prog
** Author: David Rider
** Date: 2/18/2017
** Description: CS 162 Lab 5: This program is a battle simulator. It 
** contains a base monster class which all other classes inherit from.
** It also contains another class (dragon) which inherits from monster
** and acts as a parent class to two additional classes. lab5.cpp fills
** an array of pointers to monster objects with random elements of the
** child classes. 
*********************************************************************/
#include <iostream>
#include <cstdlib>

#include "monster.hpp"
#include "goblin.hpp"
#include "troll.hpp"
#include "dragon.hpp"
#include "iceDragon.hpp"
#include "fireDragon.hpp"


using std::cout;
using std::endl;

int main() {
	srand(1234);
	Monster **mPointers = new Monster*[100];

	for (int i = 0; i < 100; i++) {
		int ranAssign = rand() % 5 + 1;
		if (ranAssign == 1) {
			mPointers[i] = new Goblin;
		}
		else if (ranAssign == 2) {
			mPointers[i] = new Troll;
		}
		else if (ranAssign == 3) {
			mPointers[i] = new Dragon;
		}
		else if (ranAssign == 4) {
			mPointers[i] = new IceDragon;
		}
		else  {
			mPointers[i] = new FireDragon;
		}
	}
	for (int x = 0; x < 100; x++) {
		cout << "Type: " << mPointers[x]->getType() << endl;
		cout << "AP: " << mPointers[x]->attack() << endl;;
	}

	for (int y = 0; y < 100; y++) {
		delete mPointers[y];
	}
	delete[] mPointers;
	return 0;
}