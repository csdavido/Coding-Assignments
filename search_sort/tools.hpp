/*******************************************************************
** Program name: search
** Author: David Rider
** Date: 3/5/2017
** Description: CS 162 Lab 8: This program contains three functions.
** The first function performs a simple linear search. The second
** sorts a file. The third performs a binary search.
*******************************************************************/
#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <fstream>
using std::fstream;
using std::string;
/*****************************
** search() -performs a linear
** search for a target value
** @param -file -string
*****************************/
int search(string file);
/*****************************
** sort() -uses a bubble sort
** to 
** @param -iFile -string
** @param -oFile -string
** Gaddis 9ed. p. 613-617
*****************************/
void sort(string iFile, string oFile);
/*****************************
** binarySearch() -conducts a
** binary search on an input
** file
** @param -iFile -string
** @param -val -int value
** Gaddis 9ed. p. 606-609
*****************************/
int binarySearch(string iFile, int val);
#endif 