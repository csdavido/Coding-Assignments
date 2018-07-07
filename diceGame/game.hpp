/*********************************************************************
** Program name: Dice Wars
** Author: David Rider
** Date: 1/25/2017
** Description: CS 162 Lab 3: This program is a two-player dice-
** simulator. It allows each player to choose a regular die, or a
** loaded die pre-disposed to a higher roll. Additionally, the user
** may choose the number of sides of their respective die.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "die.hpp"
#include "loadedDie.hpp"

class Game {
public:
	//CONSTRUCTOR
	Game();
	/**********************************************
	** menu() -collects data from the user and 
	** initiates the game simulation.
	**********************************************/
	void menu();
	/**********************************************
	** checkRound() -checks for winner of each 
	** round.
	** @param -int p1_roll -player 1's roll value
	** @param -int p2_roll -player 2's roll value
	**********************************************/
	void checkRound(int, int);
	//checkMatch() -checks for overall winner
	void checkMatch();
	/**********************************************
	** createDie() -creates a Die obecjt depending 
	** on user's input.
	** @param -int dieType -1 for regular die and
	** 2 for loaded die
	** @param -int sides -the number of sides
	**********************************************/
	Die* createDie(int, int);
	/**********************************************
	** deleteDie() -deallocates memory
	** @param -Die* -a pointer to a Die object
	**********************************************/
	void deleteDie(Die*);
private:
	int player_1_wins, player_2_wins;
	int player1, player2;
	int p1_sides, p2_sides;
	int p1_roll, p2_roll;
};
#endif