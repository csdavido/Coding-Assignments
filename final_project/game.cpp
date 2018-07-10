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
#include <string>
#include <algorithm>
#include <limits>
#include <ctime>
#include "game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;
//CONSTRUCTOR
Game::Game() {

}
/********************************
** welcome() -gives instructions
********************************/
void Game::welcome() {
	//DISPLAY INSTRUCTIONS
	cout << "********************************CRY**BABY**************************************" << endl;
	cout << "------------------------------Intsructions-------------------------------------" << endl;
	cout << "Your partner will be home soon, and your baby is starting to cry." << endl;
	cout << "If your partner gets home and your baby is crying, then you will be " << endl;
	cout << "in BIG trouble. There are four things that can make your baby stop crying: " << endl;
	cout << "a bottle, a fresh diaper, a blanket, or a toy. Actually, your baby wants " << endl;
	cout << "ONLY ONE of these things, but you need to figure out which one it is." << endl;
	cout << "For example, if you find the bottle and bring it to your baby, your baby will " << endl;
	cout << "either quiet down a little or cry more. If your baby cries more, then you need " << endl;
	cout << "to try a new item. Your baby will stop crying for good when you have the " << endl;
	cout << "correct item. You can only hold one item at a time. However, you can only " << endl;
	cout << "leave items in an empty room. But hurry!Your partner just called, and they " << endl;
	cout << "are on their way!" << endl;
	cout << endl;
	cout << "First, find out where your baby is, and then find the items." << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << endl;
}
/********************************
** play() -simulates game
********************************/
void Game::play() {
	//SEED RANDOM
	srand(time(NULL));
	//CREATE PLAYER OBJECT
	Player player1;
	//CREATE ROOM OBJECTS
	BedRoom1 bedRoom;
	BedRoom2 nursery;
	Hall hallway;
	LivingRoom lRoom;
	Stairs stairs;
	Kitchen kitchen;
	//GENERATE RANDOM NUMBERS FOR ITEM ID
	//THE ITEM ID WILL DETERMINE THE CORRECT
	//THE ITEMS NEED TO BE FOUND.
	int ranNum[] = { 0, 1, 2, 3 };
	//SHUFFLE THE ARRAY
	std::random_shuffle(ranNum, ranNum + 4);
	//TESTING
	//VIEW ARRAY
	/*cout << "RANDOM ITEM NUM" << endl;
	for (int n = 0; n < 4; n++) {
		cout << ranNum[n] << " ";
	}*/
	//CREATE ITEM OBJECT AND ASSIGN ID
	Bottle bottle(ranNum[0]);
	Diaper diaper(ranNum[1]);
	Blanket blanket(ranNum[2]);
	Toy toy(ranNum[3]);
	//SET NODES
	bedRoom.setLeft(NULL);
	bedRoom.setUp(NULL);
	bedRoom.setRight(&hallway);
	bedRoom.setDown(NULL);
	nursery.setLeft(&hallway);
	nursery.setUp(NULL);
	nursery.setRight(NULL);
	nursery.setDown(NULL);
	hallway.setLeft(&bedRoom);
	hallway.setUp(NULL);
	hallway.setRight(&nursery);
	hallway.setDown(&stairs);
	lRoom.setLeft(NULL);
	lRoom.setUp(NULL);
	lRoom.setRight(&stairs);
	lRoom.setDown(NULL);
	stairs.setLeft(&lRoom);
	stairs.setUp(&hallway);
	stairs.setRight(&kitchen);
	stairs.setDown(NULL);
	kitchen.setLeft(&stairs);
	kitchen.setUp(NULL);
	kitchen.setRight(NULL);
	kitchen.setDown(NULL);
	//SET PLAYER LOCATION
	int playerLoc = rand() % 6 + 1;
	if (playerLoc == 1) {
		player1.setCurrentLoc(&bedRoom);
	}
	else if (playerLoc == 2) {
		player1.setCurrentLoc(&hallway);
	}
	else if (playerLoc == 3) {
		player1.setCurrentLoc(&nursery);
	}
	else if (playerLoc == 4) {
		player1.setCurrentLoc(&lRoom);
	}
	else if (playerLoc == 5) {
		player1.setCurrentLoc(&stairs);
	}
	else {
		player1.setCurrentLoc(&kitchen);
	}
	//SET BABY LOCATION
	int babyLoc = rand() % 6 + 1;
	if (babyLoc == 1) {
		bedRoom.setBaby();
	}
	else if (babyLoc == 2) {
		hallway.setBaby();
	}
	else if (babyLoc == 3) {
		nursery.setBaby();
	}
	else if (babyLoc == 4) {
		lRoom.setBaby();
	}
	else if (babyLoc == 5) {
		stairs.setBaby();
	}
	else if (babyLoc == 6) {
		kitchen.setBaby();
	}
	//SET ITEM LOCATIONS
	//THIS METHOD CREATES MULTIPLE RANDOM INTEGERS
	//AT ONCE WHICH DO NOT CHANGE
	int ranItem[] = { 0, 1, 2, 3 };
	std::random_shuffle(ranItem, ranItem + 3);
	int ranRoom[] = { 0, 1, 2, 3, 4, 5 };
	std::random_shuffle(ranRoom, ranRoom + 6);
	int counter = 0;
	//TESTING
	/*cout << "RANDOM ITEM ASSIGN" << endl;
	for (int o = 0; o < 4; o++) {
		cout << ranItem[o] << " ";
	}
	cout << endl;
	cout << "RANDOM ROOM ASSIGN" << endl;
	for (int p = 0; p < 6; p++) {
		cout << ranRoom[p] << " ";
	}
	cout << endl;*/
	//END TEST
	//ASSIGN ITEMS TO ROOMS
	for (int x = 0; x < 4; x++) {
		if (ranItem[counter] == 0) {
			//ASSIGN BOTTLE
			if (ranRoom[counter] == 0) {
				bedRoom.setItem(&bottle);
			}
			else if (ranRoom[counter] == 1) {
				hallway.setItem(&bottle);
			}
			else if (ranRoom[counter] == 2) {
				nursery.setItem(&bottle);
			}
			else if (ranRoom[counter] == 3) {
				lRoom.setItem(&bottle);
			}
			else if (ranRoom[counter] == 4) {
				stairs.setItem(&bottle);
			}
			else if (ranRoom[counter] == 5) {
				kitchen.setItem(&bottle);
			}
		}
		else if (ranItem[counter] == 1) {
			//ASSIGN DIAPER
			if (ranRoom[counter] == 0) {
				bedRoom.setItem(&diaper);
			}
			else if (ranRoom[counter] == 1) {
				hallway.setItem(&diaper);
			}
			else if (ranRoom[counter] == 2) {
				nursery.setItem(&diaper);
			}
			else if (ranRoom[counter] == 3) {
				lRoom.setItem(&diaper);
			}
			else if (ranRoom[counter] == 4) {
				stairs.setItem(&diaper);
			}
			else if (ranRoom[counter] == 5) {
				kitchen.setItem(&diaper);
			}
		}
		else if (ranItem[counter] == 2) {
			//ASSIGN BLANKET
			if (ranRoom[counter] == 0) {
				bedRoom.setItem(&blanket);
			}
			else if (ranRoom[counter] == 1) {
				hallway.setItem(&blanket);
			}
			else if (ranRoom[counter] == 2) {
				nursery.setItem(&blanket);
			}
			else if (ranRoom[counter] == 3) {
				lRoom.setItem(&blanket);
			}
			else if (ranRoom[counter] == 4) {
				stairs.setItem(&blanket);
			}
			else if (ranRoom[counter] == 5) {
				kitchen.setItem(&blanket);
			}
		}
		else if (ranItem[counter] == 3) {
			//ASSIGN TOY
			if (ranRoom[counter] == 0) {
				bedRoom.setItem(&toy);
			}
			else if (ranRoom[counter] == 1) {
				hallway.setItem(&toy);
			}
			else if (ranRoom[counter] == 2) {
				nursery.setItem(&toy);
			}
			else if (ranRoom[counter] == 3) {
				lRoom.setItem(&toy);
			}
			else if (ranRoom[counter] == 4) {
				stairs.setItem(&toy);
			}
			else if (ranRoom[counter] == 5) {
				kitchen.setItem(&toy);
			}
		}
		counter++;
	}
	//PLAY GAME
	int difCounter = 0;
	bool correctItem = false;
	bool gameOver = false;
	//RANDOM DETERMINE WHAT BABY NEEDS TO STOP CRYING
	int babyDesire = rand() % 3 + 1;
	//TESTING
	//SEE WHAT THE BABY WANTS
	/*cout << "Baby Desire: " << babyDesire << endl;
	cout << endl;*/
	while (!gameOver) {
		std::cout << "\033[2J\033[1;1H";
		//DISPLAY HOUSE GRAPHIC
		displayGrid();
		cout << "Parters progress" << endl;
		//(EACH TIME YOU MOVE ROOMS THE PARTNER GETS CLOSER TO HOME)
		//DISPLAY PARTNER PROGRESS
		for (int prog = difCounter; prog < difficulty + 1; prog++) {
			cout << "*";
		}
		cout << "HOME";
		cout << endl;
		for (int prog2 = 0; prog2 < difficulty; prog2++) {
			cout << "-";
		}
		cout << endl;
		cout << endl;
		//DISPLAY CURRENT ROOM INFO
		player1.getCurrentLoc()->displayInfo();
		cout << "---------------------------------" << endl;
		bool roomFinished = false;
		//LOOP FOR EACH ROOM
		while (!roomFinished) {
			//USER OPTIONS
			cout << "(1) Look for item" << endl;
			cout << "(2) Look for baby" << endl;
			cout << "(3) Drop item" << endl;
			cout << "(4) Leave the room" << endl;
			cout << "(5) Display item" << endl;
			//GET USER CHOICE AND VALIDATE
			int c1;
			while (!(cin >> c1) || c1 < 1 || c1 > 5) {
				cout << "Error! Re-enter choice: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			//LOOK FOR ITEM
			if (c1 == 1) {
				if (player1.getCurrentLoc()->getItemStatus()) {
					cout << "You found the " << player1.getCurrentLoc()->getItem()->getName() << "!" << endl;
					cout << "Take item? y/n: ";
					char take;
					while (!(cin >> take) || take != 'y' && take!= 'n') {
						cout << "Error! Re-enter choice: ";
						cin.clear();
					}
					if (take == 'y') {
						player1.push(player1.getCurrentLoc()->getItem());
						player1.getCurrentLoc()->setItem(NULL);
					}
				}
				else {
					cout << "You looked, but you didn't find anything." << endl;
				}
			}
			//LOOK FOR BABY
			//GIVE BABY ITEM
			else if (c1 == 2) {
				if (player1.getCurrentLoc()->getBaby()) {
					cout << "You found your baby!" << endl;
					cout << "Give baby item? y/n: ";
					char give;
					while (!(cin >> give) || give != 'y' && give != 'n') {
						cout << "Error! Re-enter choice: ";
						cin.clear();
					}
					if (give == 'y') {
						if (player1.top() == NULL) {
							cout << "You have no items to give!" << endl;
						}
						else {
							cout << "You give the baby " << player1.top()->getName() << "." << endl;
							if (babyDesire == player1.top()->getID()) {
								cout << "Your baby quiets down a little!" << endl;
								correctItem = true;
								roomFinished = true;
							}
							else {
								cout << "Your baby is still crying." << endl;
							}
						}
					}
				}
				else {
					cout << "Your baby is somewhere else." << endl;
				}
			}
			//DROP ITEM
			else if (c1 == 3) {
				if (player1.top() == NULL) {
					cout << "You don't have any items" << endl;
				}
				else if (player1.getCurrentLoc()->getItemStatus()) {
					cout << "This room has an item, you cannot leave another." << endl;
					cout << "Go to a different room." << endl;
				}
				else {
					cout << "Leaving " << player1.top()->getName() << " here." << endl;
					player1.getCurrentLoc()->setItem(player1.top());
					player1.pop();
				}
			}
			//LEAVE ROOM
			else if (c1 == 4) {
				cout << "Leave room? y/n: ";
				char leave1;
				while (!(cin >> leave1) || leave1 != 'y' && leave1 != 'n') {
					cout << "Error! Re-enter choice: ";
					cin.clear();
				}
				if (leave1 == 'y') {
					roomFinished = true;
				}
				else {
					roomFinished = false;
				}
			}
			else {
				player1.display();
			}
		}
		//GO TO NEW ROOM
		if (!correctItem) {
			if (player1.getCurrentLoc()->getRoomName() == "den") {
				cout << "Entering the stairs." << endl;
				player1.setCurrentLoc(player1.getCurrentLoc()->getRight());
			}
			else if (player1.getCurrentLoc()->getRoomName() == "stairs") {
				cout << "(1) Go to the kitchen." << endl;
				cout << "(2) Go upstairs." << endl;
				cout << "(3) Go to the living room." << endl;
				int stairChoice;
				while (!(cin >> stairChoice) || stairChoice < 1 || stairChoice > 3) {
					cout << "Error! Re-enter choice: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if (stairChoice == 1) {
					cout << "Going to the kitchen..." << endl;
					player1.setCurrentLoc(player1.getCurrentLoc()->getRight());
				}
				else if (stairChoice == 2) {
					cout << "Going upstairs..." << endl;
					player1.setCurrentLoc(player1.getCurrentLoc()->getUp());
				}
				else if (stairChoice == 3) {
					cout << "Going to the living room..." << endl;
					player1.setCurrentLoc(player1.getCurrentLoc()->getLeft());
				}
			}
			else if (player1.getCurrentLoc()->getRoomName() == "kitchen") {
				cout << "Entering the stairs." << endl;
				player1.setCurrentLoc(player1.getCurrentLoc()->getLeft());
			}
			else if (player1.getCurrentLoc()->getRoomName() == "bedroom") {
				cout << "Entering the hallway." << endl;
				player1.setCurrentLoc(player1.getCurrentLoc()->getRight());
			}
			else if (player1.getCurrentLoc()->getRoomName() == "hall") {
				cout << "(1) Go to the nursery." << endl;
				cout << "(2) Go downstairs." << endl;
				cout << "(3) Go to the bedroom." << endl;
				int stairChoice;
				while (!(cin >> stairChoice) || stairChoice < 1 || stairChoice > 3) {
					cout << "Error! Re-enter choice: ";
					cin.clear();
				}
				if (stairChoice == 1) {
					cout << "Going to the nursery..." << endl;
					player1.setCurrentLoc(player1.getCurrentLoc()->getRight());
				}
				else if (stairChoice == 2) {
					cout << "Going downstairs..." << endl;
					player1.setCurrentLoc(player1.getCurrentLoc()->getDown());
				}
				else if (stairChoice == 3) {
					cout << "Going to the bedroom..." << endl;
					player1.setCurrentLoc(player1.getCurrentLoc()->getLeft());
				}
			}
			else if (player1.getCurrentLoc()->getRoomName() == "nursery") {
				cout << "Entering the hallway." << endl;
				player1.setCurrentLoc(player1.getCurrentLoc()->getLeft());
			}
		}
		std::cout << "\033[2J\033[1;1H";
		cout << "---------------------------------------------" << endl;
		//DIFFICULTY MEASURE
		//GAME IS OVER WHEN NUMBER OF TURNS (TIMES MOVED TO A NEW ROOM) IS EXCEDED
		//OR WHEN BABY RECIEVES ITEM
		if (difCounter >= difficulty) {
			cout << "Your partner is home and the baby is crying!" << endl;
			cout << "GAME OVER!" << endl;
			gameOver = true;
		}
		else {
			difCounter++;
		}
		if (correctItem) {
			cout << "Your baby has stopped crying!" << endl;
			cout << "You win!" << endl;
			gameOver = true;
		}
	}
}
/********************************
** displayGrid() -prints house
********************************/
void Game::displayGrid() {
	cout << "              ___               " << endl;
	cout << "            _______             " << endl;
	cout << "        ________________        " << endl;
	cout << "  ___________________________   " << endl;
	cout << "________________________________" << endl;
	cout << "| Bed Room | Hallway | Nursery |" << endl;
	cout << "|------------------------------|" << endl;
	cout << "| L. Room  |  Stairs | Kitchen |" << endl;
	cout << "--------------------------------" << endl;
	cout << endl;
}
//MUTATOR
void Game::setDiff(int d) {
	this->difficulty = d;
}
//ACCESOR
int Game::getDiff() {
	return difficulty;
}