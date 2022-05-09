/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment:Removing indentation.,Task 7B

This program will read in a file and remove indentations becuase of task A.  This time we will count how many curly braces get opened and closed on each line, so we need to count
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeLeadingSpaces(string line){
	// this function: will change something that has spaces and remove them. but not the spaces in between letters just indentation. removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  "


   //Your function should probably iterate over the input string, skip all spaces, and after it finds the first non-space character, start accumulating the characters into a new string, which will be returned.

   //variables
	int length = line.length();
   char c; //isspace(c)
   string new_string = "";
   bool t_or_f = true;
   for (int i = 0; i < length; i++) {
      /* code */
      c = line[i];
      if (isspace(c) && t_or_f == true) {
         /* code */
         new_string= new_string;
      }
      else //if(!isspace(c))
        {
          new_string+= c;

          //making the bool false you are allowing for the thing to only take out the indentation and not the spaces in between words!
            t_or_f = false;
        }
   }
   return new_string;
}
int countChar(string line, char c){
	//c is either { or }
	int length = line.length();
	//cout<< length;
	int tabs = 0;
	int count = 0;
	for (int i = 0; i < length; i++) {
		//we want to count how many of c there are in that line.
		char z = line[i];
		char y = line[i+2];
		char x = line[i+5];
		char s = line[i+4];
		char d = line[i+6];
		if(z == c) {
			count +=1;
		}
		//if ( (z == '{') && (y == '}')) {
			/* code */
		//	count--;
		//}
	//	if ( (z == '{') && (x == '}')) {
			/* code */
		//	count--;
	//	}
		//if ( (z == '{') && (y == '{') && (s == '}') && (d == '}')) {
			/* code */
			//count--;
		//}
   }
	return count;
}
int main() {
   /* code */
   //variables
   string line;
	int z = 0;
	int curly;
	int x = 0;
	char c;
   //while reading the operation is a success. Which is each line.
	while (getline(cin,line)) {
		//getline(cin,line);
		int length = line.length();
      /* code */
      //send each line to the removeLeadingSpaces function.
     line = removeLeadingSpaces(line);
		//We printed here the number of open blocks so the indentation code will go here.
		//cout<< x;
		//add x amount of tabs. '\t'
		//string tabs = '\t';
		//if(line[0]!= '}'){
		// for (i=0; i <= line.size(); i++){
		// 	if(line[i] == '{'){
		// 		c = '{';
		// 	}
		// 	if (line[i] == '}'){
		// 		c = '}';
		// 	}
		// }
      //x -= countChar(line, '}');
		//for(int j = 0; j < x; j++){
         //cout<< '\t';// this is to big.
			//cout << "    ";
		//}
      z = x;
      for(int i = 0; i < x; i++){
         if(line[i] == '}' || line[0] ==  '}'){
            z = x - 1;
         }
      }
      for (int i = 0; i < z; i++){
         line = '\t' + line;
      }
		//}
		//---------------//
		//cout<< x;
		cout<< line <<endl;
      x -= countChar(line, '}');
      x += countChar(line, '{');
   }

   return 0;
}
