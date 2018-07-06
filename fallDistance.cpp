/*********************************************************************
** Author: David Rider
** Date: 1/25/2016
** Description: This program contains a function which calculates the distance
that an object has fallen.
*********************************************************************/
#include <iostream>
#include <string>

using namespace std;

//Function prototype
float fallDistance(float seconds);

/***************************************************************
** This function contains a formula which calculates the results of
** gravity on a falling object. THe formula requires input from the 
** main function, but can be inputed by calling the function and
** inputing the parapmetes (seconds). The function returns the
** result of the calculation.
****************************************************************/
float fallDistance(float seconds)
{
    double distance = 0.5 * 9.8 * (seconds * seconds);
    return distance; 
}