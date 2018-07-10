#ifndef GAME_HPP
#define GAME_HPP

#include "space.hpp"
#include "bedRoom.hpp"
#include "bedRoom1.hpp"
#include "bedRoom2.hpp"
#include "passageWay.hpp"
#include "hall.hpp"
#include "stairs.hpp"
#include "commonRoom.hpp"
#include "livingRoom.hpp"
#include "kitchen.hpp"
#include "item.hpp"
#include "bottle.hpp"
#include "diaper.hpp"
#include "blanket.hpp"
#include "toy.hpp"
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
#include "player.hpp"

class Game {
public:
	//CONSTRUCTOR
	Game();
	/********************************
	** welcome() -gives instructions
	********************************/
	void welcome();
	/********************************
	** play() -simulates game
	********************************/
	void play();
	/********************************
	** displayGrid() -prints house
	********************************/
	void displayGrid();
	//MUTATOR
	void setDiff(int);
	//ACCSSOR
	int getDiff();
private:
	int difficulty;
};
#endif