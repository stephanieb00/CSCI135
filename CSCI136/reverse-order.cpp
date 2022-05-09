/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Reverse Chronological Order,. e.g.,Lab3D

This program will print which basin had higher elevations or if they were equal bettwen the two dates the user inputs.
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
	//Date Variable: it is a string.
	string date, earlier_date, later_date;
	cout<< "Enter earlier date: ";
	cin>> earlier_date;
   cout << "Enter later date: ";
   cin >> later_date;
	//varibale for the data.
	double eastSt, eastEl, westSt, westEl;
	//array
	int length = 0;
   string my_data[366];
	int capacity =0;
	double value[366];
	int range = 0;

//while loop
	while (fin>> date >> eastSt >> eastEl >> westSt >> westEl){
	fin.ignore(INT_MAX, '\n'); // ignores the remaining
		my_data[length] = date;
	//testing the array my_data
	//cout<< my_data[length] << endl;
		length++;
		value[capacity] = westEl;
	//testing the array value
	//cout<< value[capacity]<< endl;
		capacity++;
	}
//reading through the arrays
	for (int i = length-1; i >= 0; i--){
		if(my_data[i] == earlier_date){
				range = 0;
				cout<< my_data[i] <<" " <<value[i] <<endl;
		}
		else if (my_data[i] == later_date){
				range = 1;
			}
		if(range == 1){
			cout<< my_data[i] <<" " <<value[i] <<endl;
		}
	}
return 0 ;
}
