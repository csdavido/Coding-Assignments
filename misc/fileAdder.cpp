/*********************************************************************
** Author: David Rider
** Date: 1/18/2016
** Description: This program prompts the user for the name of a file and
then tries to open it, reads the integer data, then prints the sum
of the integers into a new file.
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string filename;
	
	
	int integers, //data to be read and added
       numberOfIntegers, //counts the number of integers
       x,
       sum = 0; //sum of integers
 
  
	//get the filename from the user
	cout << "Enter the filename" << endl;
	cin >> filename;
	
	//open the input file
	inputFile.open(filename.c_str());
	
	//If the file successfully opened, process it
	if (inputFile)
	{
      //Read the numbers from the file
      while (inputFile >> x)
     {
          sum += x;
	   }
	 }
   else
   {
      cout << "Error opening the file.\n";
   }
     
	//close the input file
  inputFile.close();

	//open the output file
	outputFile.open("sales.txt");

	//Write to the file
	outputFile << sum << endl;

	//close the file
	outputFile.close();


	return 0;
}
