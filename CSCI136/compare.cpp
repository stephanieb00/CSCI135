/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Comparing Elevations,. e.g.,Lab3C

This program will print which basin had higher elevations or if they were equal bettwen the two dates the user inputs.
*/

//Include Files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int main() {
   //Reading the Tsv file:
	ifstream fin("Current_Reservoir_Levels.tsv");
	if (fin.fail()) {
		 cerr << "File cannot be opened for reading." << endl;
		 exit(1); // exit if failed to open the file
	}

	//Diregards the first line.
	string junk;        // new string variable
	getline(fin, junk); // read one line from the file
   int range = 0;
   //variables
	double eastSt, eastEl, westSt, westEl;
	string date, start, end;//start is the starting date while end is the ending date
   //Starting Date
   cout << "Enter starting date: ";
   cin >> start;
	string month1 = start.substr(0,2);
	int month1_1 = stoi(month1);
	//std::cout << month1_1 << '\n';
	string x = start.substr(3,5);
	int i = stoi(x);

   //Ending Date:
   cout << "Enter ending date: ";
   cin>> end;
	string month2 = end.substr(0,2);
	int month2_2 = stoi(month2);
	//std::cout << month2_2 << '\n';
	string r = end.substr(3,5);
	int j = stoi(r);
   while (fin>> date >> eastSt >> eastEl >> westSt >> westEl) {
      /* code */
      fin.ignore(INT_MAX, '\n'); // ignores the remaining
      if (date == start) {
         /* code */
         range =1;
      }
      if (date == end) {
         /* code */
         range = 0;
         if (westEl < eastEl) {
            cout << date << " East" << endl;
         }
         //else if east is less than west print west.
         else if (eastEl < westEl) {
            cout << date << " West" << endl;
         }
         else if (eastEl == westEl) {
            cout << date << " Equal" << endl;
         }
      }
      if (range == 1) {
         /* code */
         if (westEl < eastEl) {
            cout << date << " East" << endl;
         }
         //else if east is less than west print west.
         else if (eastEl < westEl) {
            cout << date << " West" << endl;
         }
         else if (eastEl == westEl) {
            cout << date << " Equal" << endl;
         }
      }
   }
   return 0;
}
