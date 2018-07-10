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
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Queue {
public:
	//DEFAULT CONSTRUCTOR
	Queue();
	/****************************
	** genRand() -generates a 
	** random
	****************************/
	int genRand();
	/****************************
	** genBuff() -simulates a
	** buffer
	** @param -chance of value
	** put into the queue
	** @param -chance of value
	** being removed from queue
	** @param -number of rounds
	****************************/
	void simBuff(int, int, int);
private:
	double avgLength;
	queue<int> buffQ;
	vector<int> avgVect;
	int addChance, remChance, total, rem, add;
};
#endif