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
#ifndef STACK_HPP
#define STACK_HPP

#include <stack>

using std::stack;
using std::string;

class Stack {
public:
	/****************************
	** palindrome() -creates a
	** palindrome
	** @param -string inputed by
	** the user
	****************************/
	string palindrome(string);
private:
	stack <char> palStack;
};
#endif