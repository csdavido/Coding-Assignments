#ifndef DIE_HPP
#define DIE_HPP

class Die {
public:
	/********************
	** Die() -constructor
	*********************/
	Die();
	/**********************************************
	** roll() -function that simulates a
	** die roll. Selects a random integer within
	** the range of the number of sides of the die
	**********************************************/
	int roll(int, int);
private:
	int numSides;
	int numDie;
};
#endif