/*********************************************************************
** Author: David Rider
** Date: 1/18/2016
** Description: This program identifies the maximum and minimum of a group of integers. 
*********************************************************************/
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

//This program identifies the maximum and minimum integer of a group of integers.
int main()
{
  int userInt, //number of integers the user will enter
      max, //the maximum of the integers
      min, //the minimum of the integers
      value; //the integer values
      
  cout << "How many integers would you like to enter? \n";
  cin >> userInt;
  cout << "Please enter " << userInt << " numbers.\n";
  
  value = 1;
  
  for (int num = 1; num <= userInt; num++)
  {
      cin >> value;
      if (value > max)
      max = value;
      else if (value < min)
      min = value;
      
  }
   cout << "min: " << min << endl;
   cout << "max: " << max << endl;
   
  return 0;
}
