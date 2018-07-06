/*********************************************************************
** Author: David Rider
** Date: 1/18/2016
** Description: This program prompts the user for a number then asks the user
to guess the number. It utilizes a for loop with nested if/else if statements.
*********************************************************************/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int number,
		guess,
		tries;
	//prompt user for secret number
	cout << "Enter the number for the player to guess. \n";
	cin >> number;
	//prompt user for guess
	cout << "Enter your guess. \n";
	cin >> guess;
	//loop through guesses until the correct number is guessed
	for (tries = 1; ; tries++)
	{
		if (guess == number)
		{
			cout << "You guessed it in " << tries << " tries." << endl;
			break;
		}
		else if (guess > number)
		{
			cout << "Too high - try again." << endl;
			cin >> guess;
		}
		else if (guess < number)
		{
			cout << "Too low - try again." << endl;
			cin >> guess;
		}
	}
	return 0;
}