/*********************************************************************
** Program name: Dice Wars
** Author: David Rider
** Date: 1/25/2017
** Description: CS 162 Lab 3: This program is a two-player dice-
** simulator. It allows each player to choose a regular die, or a
** loaded die pre-disposed to a higher roll. Additionally, the user
** may choose the number of sides of their respective die.
*********************************************************************/
#include <iostream>
#include <unistd.h>
#include <string>

#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;
//CONSTRUCTOR
Game::Game() {
	player_1_wins = 0;
	player_2_wins = 0;
}
/**********************************************
** checkRound() -checks for winner of each
** round.
** @param -int p1_roll -player 1's roll value
** @param -int p2_roll -player 2's roll value
**********************************************/
void Game::menu() {
	//GET DIE TYPE AND NUMBER OF SIDES FROM PLAYER 1
	cout << "**************DICE**********WARS**************" << endl;
	cout << "Choose die type:" << endl;
	cout << "1. Regular Die" << endl;
	cout << "2. Loaded Die" << endl;
	cout << "Player 1, enter 1 or 2: ";
	cin >> player1;
	while (player1 != 1 && player1 != 2) {
		cout << "Invalid input. Please enter 1 or 2: ";
		cin >> player1;
	}
	cout << "Now enter the number of sides: ";
	cin >> p1_sides;
	while (p1_sides <= 4 || p1_sides > 121) {
		cout << "Error! Please choose an integer greater than 3 or larger than 120: ";
		cin >> p1_sides;
	}
	cout << "Player 1 setup complete!" << endl;
	usleep(10000);
	std::cout << "\033[2J\033[1;1H";
	//GET DIE TYPE AND NUMBER OF SIDES FROM PLAYER 2
	cout << "**************DICE**********WARS**************" << endl;
	cout << "Choose die type:" << endl;
	cout << "1. Regular Die" << endl;
	cout << "2. Loaded Die" << endl;
	cout << "Player 2, enter 1 or 2: ";
	cin >> player2;
	while (player2 != 1 && player2 != 2) {
		cout << "Invalid input. Please enter 1 or 2: ";
		cin >> player2;
	}
	cout << "Now enter the number of sides: ";
	cin >> p2_sides;
	while (p2_sides <= 4 || p2_sides > 121) {
		cout << "Error! Please choose an integer greater than 3 or larger than 120: ";
		cin >> p2_sides;
	}
	cout << "Player 2 setup complete!" << endl;
	usleep(10000);
	std::cout << "\033[2J\033[1;1H";
	//GET THE NUMBER OF ROUNDS FROM USER
	int rounds;
	cout << "**************DICE**********WARS**************" << endl;
	cout << "Input the amount of rounds: ";
	cin >> rounds;
	if (rounds <= 0) {
		cout << "Error! Please choose a positive integer: ";
		cin >> rounds;
	}
	cout << "Game set-up complete. Match is about to start!";
	usleep(10000);
	std::cout << "\033[2J\033[1;1H";
	cout << "**************DICE**********WARS**************" << endl;
	//CREATE DIE OBJECTS
	Die *player_1_die = createDie(player1, p1_sides);
	Die *player_2_die = createDie(player2, p2_sides);
	//GAME SIMULATION
	int counter = 0;
	while (counter < rounds) {
		p1_roll = player_1_die->roll();
		p2_roll = player_2_die->roll();
		cout << "**********ROUND " << counter + 1 << "**********" << endl;
		cout << "Player 1: " << p1_roll << endl;
		cout << "Player 2: " << p2_roll << endl;
		checkRound(p1_roll, p2_roll);
		usleep(1000000);
		counter++;
	}
	deleteDie(player_1_die);
	deleteDie(player_2_die);
}
/*********************************************
** checkRound() -checks for winner of each
** round.
** @param -int p1_roll -player 1's roll value
** @param -int p2_roll -player 2's roll value
**********************************************/
void Game::checkRound(int p1_roll, int p2_roll) {
	if (p1_roll > p2_roll) {
		player_1_wins++;
		cout << "Player 1 wins the round!" << endl;
	}
	else if (p2_roll > p1_roll) {
		player_2_wins++;
		cout << "Player 2 wins the round!" << endl;
	}
	else {
		cout << "This round is a tie!" << endl;
	}
}
//checkMatch() -checks for overall winner
void Game::checkMatch() {
	cout << "**************RESULTS**************" << endl;
	//CHECK AND DISPLAY OVERALL WINNER
	if (player_1_wins > player_2_wins) {
		cout << "Player 1 wins the match!" << endl;
	}
	else if (player_2_wins > player_1_wins) {
		cout << "Player 2 wins the match!" << endl;
	}
	else {
		cout << "This match is a tie!" << endl;
	}
	//DISPLAY FINAL SCORE
	cout << "Final Score" << endl;
	cout << "Player 1: " << player_1_wins << endl;
	cout << "Player 2: " << player_2_wins << endl;
	//DISPLAY THE DIE TYPE USED BY EACH USER
	std::string a, b;
	if (player1 == 1) {
		a = "Regular Die";
	}
	else if (player1 == 2) {
		a = "Loaded Die";
	}
	if (player2 == 1) {
		b = "Regular Die";
	}
	else if (player2 == 2) {
		b = "Loaded Die";
	}
	cout << "Die Types: " << endl;
	cout << "Player 1: " << a << endl;
	cout << "Player 2: " << b << endl;

}
/**********************************************
** createDie() -creates a Die obecjt depending
** on user's input.
** @param -int dieType -1 for regular die and
** 2 for loaded die
** @param -int sides -the number of sides
**********************************************/
Die* Game::createDie(int dieType, int sides) {
	if (dieType == 1) {
		return new Die(sides);
	}
	else if (dieType == 2) {
		return new LoadedDie(sides);
	}
}
/**********************************************
** deleteDie() -deallocates memory
** @param -Die* -a pointer to a Die object
**********************************************/
void Game::deleteDie(Die *diePointer) {
	delete diePointer;
}