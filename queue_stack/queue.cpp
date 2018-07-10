/**********************************************************************
** Program name: p_drome
** Author: David Rider
** Date: 3/11/2017
** Description: This program has two functionalities. First it simulates
** a queue buffer. It uses user-provided percentage values to randomly
** input a number in the buffer. The program displays the length of the
** queue in each round and the average length of the queue over all
** rounds. The program also alows the user to inter string input which
** will be returned as a palindrome.
**********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "queue.hpp"

using std::cout;
using std::endl;
//DEFAULT CONSTRUCTOR
Queue::Queue() {
	srand(time(NULL));
	addChance = 0;
	remChance = 0;
	total = 0;
	avgLength = 0.0;
	rem = 0;
	add = 0;
}
/****************************
** genRand() -generates a
** random
****************************/
int Queue::genRand() {
	int num = rand() % 100;
	return num;
}
/****************************
** genBuff() -simulates a
** buffer
** @param -chance of value
** put into the queue
** @param -chance of value
** being removed from queue
** @param -number of rounds
****************************/
void Queue::simBuff(int perIn, int perOut, int userRounds) {
	cout << "***********************" << endl;
	int round = 1;
	for (int x = 0; x < userRounds; x++) {
		cout << "Round " << round << endl;
		//CALCULATE RANDOM INTEGER
		addChance = rand() % 100 + 1;
		total = buffQ.size();
		//ADD NUMBER TO BUFFER
		if (addChance <= perIn) {
			//GENERATE A NEW RANDOM INTEGER AND ADD TO QUEUE
			cout << "Adding element..." << endl;
			int add = genRand();
			cout << "Random number: " << add << endl;
			buffQ.push(add);
			add++;
		}
		remChance = rand() % 100 + 1;
		//REMOVE NUMBER FROM BUFFER
		if (remChance <= perOut) {
			//GENERATE A NEW RANDOM INTEGER AND REMOVE FROM QUEUE
			cout << "Removing element..." << endl;
			int rem = genRand();
			cout << "Random number: " << rem << endl;
			if (!buffQ.empty()) {
				buffQ.pop();
				rem++;
			}
		}
		avgVect.push_back(buffQ.size());
		//DISPLAY CURRENT QUEUE LENGTH
		cout << "Current queue length: " << buffQ.size() << endl;
		//AVERAGE QUEUE LENGTH
		for (int y = 0; y < avgVect.size(); y++) {
			avgLength += avgVect[y];
		}
		avgLength /= avgVect.size();
		cout << "Average queue length: " << avgLength << endl;
		round++;
		cout << "----------------------" << endl;
	}
	//DISPLAY INFO
	cout << "***********************" << endl;
	cout << "Queue size: " << total << endl;
	cout << "Average length: " << avgLength << endl;
	cout << "Total times new number added: " << add << endl;
	cout << "Total times number removed: " << rem << endl;
	cout << "***********************" << endl;
}