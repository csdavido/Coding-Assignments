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
#include <vector>

#include "stack.hpp"

using std::cout;
using std::endl;
using std::vector;
/****************************
** palindrome() -creates a
** palindrome
** @param -string inputed by
** the user
****************************/
string Stack::palindrome(string input) {
	//CONVERT STRING TO VECTOR OF CHAR
	vector <char> cVector(input.begin(), input.end());
	//LOOP THROUGH CHAR VECTOR
	for (int i = 0; i < cVector.size(); i++) {
		//POPULATE STACK
		char iChar = cVector[i];
		palStack.push(iChar);
	}
	//LOOP THROUGH STACK
	while (!palStack.empty()) {
		//GETS TOP ELEMENT OF STACK
		char replace = palStack.top();
		//PUSHES ELEMENT TO END OF VECTOR
		cVector.push_back(replace);
		//REMOVES TOP ELEMENT
		palStack.pop();
	}
	//CONVERT VECTOR TO STRING
	string palindrome(cVector.begin(), cVector.end());
	//RETURN STRING
	return palindrome;
}