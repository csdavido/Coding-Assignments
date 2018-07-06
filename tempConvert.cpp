/*********************************************************************
** Author: David Rider
** Date: 1/11/2016
** Description: This program calculates the average
   of five different numbers.
*********************************************************************/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

//This program converts Celsius temperatures to Fahrenheit temperatures.
int main()
{
  double celsius, fahrenheit;
  
  cout << "Please enter a Celsius temperature.\n";
  cin >> celsius;
  
  //computing the conversion
  fahrenheit = (9 * celsius)/5 + 32;
  cout << "The equivalent Fahrenheit temperature is:\n" << fahrenheit << endl;
  
  return 0;
}