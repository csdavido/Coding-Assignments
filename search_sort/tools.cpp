/*******************************************************************
** Program name: search
** Author: David Rider
** Date: 3/5/2017
** Description: CS 162 Lab 8: This program contains three functions.
** The first function performs a simple linear search. The second
** sorts a file. The third performs a binary search.
*******************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include "tools.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::vector;
/*****************************
** search() -performs a linear
** search for a target value
** @param -file -string
*****************************/
int search(string file) {
	vector<int> sVector;
	ifstream sFile;

	sFile.open(file.c_str());

	bool searched = false;
	int i = 0;
	int holder = -1;
	//PUSH STRING INTO VECTOR
	while (!sFile.peek() == sFile.eof()) {
		int x;
		while (sFile >> x) {
			sVector.push_back(x);
		}
	}
	while (i < sVector.size() && !searched) {
		if (sVector[i] == 0) {
			holder = i;
			searched = true;
		}
		i++;
	}
	sFile.close();
	return holder;
}
/*****************************
** sort() -uses a bubble sort
** to
** @param -iFile -string
** @param -oFile -string
** Gaddis 9ed. p. 613-617
*****************************/
void sort(string iFile, string oFile) {
	ifstream inputFile(iFile.c_str());
	ofstream outputFile(oFile.c_str());
	int temp;
	bool sorted;

	vector<int> sVector;

	while (!inputFile.peek() == inputFile.eof()) {
		int x;
		while (inputFile >> x) {
			sVector.push_back(x);
		}
	}
	do {
		sorted = false;
		for (int a = 0; a < (sVector.size() - 1); a++) {
			if (sVector[a] > sVector[a + 1]) {
				temp = sVector[a];
				sVector[a] = sVector[a + 1];
				sVector[a + 1] = temp;
				sorted = true;
			}
		}
	} while (sorted);
	//WRITE TO NEW FILE
	for (int x = 0; x < sVector.size(); x++) {
		outputFile << sVector[x];
	}
	//CLOSE FILES
	inputFile.close();
	outputFile.close();
}
/*****************************
** binarySearch() -conducts a
** binary search on an input
** file
** @param -iFile -string
** @param -val -int value
** Gaddis 9ed. p. 606-609
*****************************/
int binarySearch(string iFile, int val) {
	ifstream searchFile;
	searchFile.open(iFile.c_str());

	vector<int> sVector;
	//PUSH STRING INFO TO VECTOR
	while (!searchFile.peek() == searchFile.eof()) {
		char x;
		while (searchFile.get(x)) {
			sVector.push_back(x - '0');
		}
	}
	bool searched = false;
	int head = 0;
	int tail = sVector.size() - 1;
	int mid = sVector.size() / 2;
	int holder = -1;
	while (searched == false && head != tail) {
		mid = (head + tail) / 2;
		if (sVector[mid] == val) {
			searched = true;
			holder = mid;
		}
		else if (sVector[mid] > val) {
			tail = mid - 1;
		}
		else {
			head = mid + 1;
		}
	}
	return holder;
	//CLOSE FILE
	searchFile.close();
}