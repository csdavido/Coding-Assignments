/*********************************************************************
** Author: David Rider
** Date: 1/11/2016
** Description: This program calculates the average
   of five different numbers.
*********************************************************************/
# include <iostream>
# include <string>

using std::cin;
using std::cout;
using std::endl;

//This program calsulates the average of five numbers.
int main()
{
	double number1, number2, number3, number4, number5, average;
	cout << "Please enter five numbers.\n";
	cin >> number1;
	cin >> number2;
	cin >> number3;
	cin >> number4;
	cin >> number5; 
	
	//computing the average
	average = (number1 + number2 + number3 + number4 + number5) / 5;
	cout << "The average of those numbers is: " << endl;
  cout << average << endl;
    
	return 0;
}