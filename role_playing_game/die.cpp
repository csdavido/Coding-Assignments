#include <cstdlib>
#include <ctime>
#include <iostream>
#include "die.hpp"
/**********************************************
** Die() -constructor that accepts an int value
** while setting a default value.
** @param -int sides- an int value which
** represents the sides of a die
**********************************************/
Die::Die() {
	srand(time(NULL));
}
/**********************************************
** roll() -function that simulates a
** die roll. Selects a random integer within
** the range of the number of sides of the die
**********************************************/
int Die::roll(int numDie, int numSides) {
	int rollValue = 0;
	for (int r = 0; r < numDie; r++) {
		int temp = (rand() % numSides) + 1;
		rollValue += temp;
	}
	return rollValue;
};