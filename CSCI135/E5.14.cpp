/*
Author: Stephanie Bravo
Course: CSCI-135
Instructor: Genady Maryash

Assignment: Homework E5.14 - Sort 2	, e.g., E5.14

This program will  have the function " void sort2( int&a, int&b)" that swaps the values of a and b if a is greater than b and other wise leaves a and b unchanged.
sort2(u, v); // u is still 2, v is still 3 sort2(w, x); // w is now 1, x is now 4
*/
#include <iostream>
using namespace std;

void  sort2(int& a, int& b){
   if (a > b) {
      /* code */
      int x = a;
      int y = b;
      b = x;
      a = y;
   }
   else{
      a = a;
      b = b;
   }
}

int main() {
   /* code */
   //Variable a and b
   int u,v,w,x;
   cout<< "Enter First Number ";
   cin>> u;
   cout<< "Enter next Number ";
   cin >> v;
   cout<< "Enter First Number ";
   cin>> w;
   cout<< "Enter next Number ";
   cin >> x;
   sort2(u,v);
   //int u = 2;
   cout << "int u = " << u << '\n';
   cout << "int v = " << v << '\n';
   sort2(w,x);
   cout << "int w = " << u << '\n';
   cout << "int x = " << v << '\n';
   return 0;
}
