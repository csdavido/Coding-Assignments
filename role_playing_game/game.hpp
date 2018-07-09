#ifndef GAME_HPP
#define GAME_HPP
#include "creature.hpp"
class Game {
public:
	//CONSTRUCTOR
	Game(Creature *creature1, Creature *creature2);
	string fight();
private:
	Creature *c1;
	Creature *c2;
	bool over;
};
#endif