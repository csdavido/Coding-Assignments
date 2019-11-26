/***********************************************************************
** Author: David Rider
** Date: 1/25/2016
** Description: This program contains a function which emulates the 
** hailstone sequence based on a user-inputed variable.
***********************************************************************/
#include <iostream>

using namespace std;

//Function prototype
int hailstone(int n);

/************************************************************************
** This function takes value from the main function and uses a while
** loop to assess whether it is even or odd and some conditions
** to follow in each case. It counts how many times the number has to
** pass through the while loop before it becomes one.
************************************************************************/
int hailstone(int n)
{
  int count = 0;
  
  while (n != 1)
  {
      if (n % 2 == 0)
      {
          n = n / 2;
          count++;
      } 
      else 
      {
          n = 3 * n + 1;
          count++;
      }
  }    
      
      return count;
}
