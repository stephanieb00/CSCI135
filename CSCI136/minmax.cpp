/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Minimum and Maximum storage,. e.g.,Lab3B

This program will find the minimum and maximum storage in East basin in 2018.
*/

//Include Files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){
	//Reading the Tsv file:
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		 cerr << "File cannot be opened for reading." << endl;
		 exit(1); // exit if failed to open the file
	}

	//Diregards the first line.
	string junk;        // new string variable
	getline(fin, junk); // read one line from the file

	//variables
	double eastSt, eastEl, westSt, westEl;
	string date;
	double max = INT_MAX; // Minimum value for an object of type int
	double min = INT_MIN; //Maximum value for an object of type int

	while(fin>> date >> eastSt){
		fin.ignore(INT_MAX, '\n'); // ignores the remaining columns.

		if (max > eastSt) {
			max = eastSt;
		}
		if (min < eastSt) {
			min = eastSt;
		}
	}
	cout << "minimum storage in East basin: " << max << " billion gallons" << endl;
	cout << "MAXimum storage in East basin: " << min << " billion gallons" << endl;
	//Close the file
	fin.close();
return 0;
}
