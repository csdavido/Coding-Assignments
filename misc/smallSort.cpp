/*********************************************************************
** Author: David Rider
** Date: 1/25/2016
** Description: This program contains a function which organizes a group of three
** referenced integers in order from least to greatest.
*********************************************************************/
#include <iostream>
using namespace std;

//Function prototype
void smallSort (int &a, int &b, int &c);

void smallSort(int &a, int &b, int &c)
{
  /************************************************************************
  ** This function takes referenced integer values from the main function
  ** and orders then from least to greatest. Each if statement within this
  ** function utilizes a temporary integer and comparison operator to asses each
  ** integer's value one by one.
  ************************************************************************/
  if(a > b)
  { 
      int temp = a;
      a = b;
      b = temp;
  }
  if(a > c)
  {
      int temp = a;
      a = c;
      c = temp;
  }
  if(b>c)
  {
      int temp = b;
      b = c;
      c = temp;
  }    
}
