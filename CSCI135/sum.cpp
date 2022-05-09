/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Adding integers. , e.g., Project1A

This program will read a sequence of integers from cin, and reports their sum.
*/

#include <iostream>
using namespace std;

int main() {
   //variable x
   int x;
   int sum = 0;
   // While the reading operation is a success
   while (cin >> x) {
      sum +=x;
      //Print the sum of the numbers
      //cout << sum << endl;
   }
   //Print the sum of the numbers
   cout << sum << endl;
   return 0;
}
