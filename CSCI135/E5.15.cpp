/*
Author: Stephanie Bravo
Course: CSCI-135
Instructor: Genady Maryash

Assignment: Homework E5.15 - Sort 3	, e.g., E5.15

This program will  have the function "sort3(int&a ,int&b ,int&c)" that swaps its three arguments to arrange them in sorted order.
*/
#include <iostream>
using namespace std;

void sort2(int& a, int& b){
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
void sort3(int&a ,int&b ,int&c){
   //rmm that sort2 rmms the arguments
   sort2(a,b); //we are sending a and b. we get the smaller number first then the big number;
   sort2(a,c);
   sort2(b,c);
   //std::cout << a << b<< c<<'\n';
}

int main() {
   /* code */
   //Variable a and b
   int u,v,w;
   cout<< "Enter First Number ";
   cin>> u;
   cout<< "Enter next Number ";
   cin >> v;
   cout<< "Enter third Number ";
   cin>> w;
   //std::cout <<u << v <<w << '\n';
   sort3(u,v,w);
   //int u = 2;
   cout << "int u = " << u <<endl;
   cout << "int v = " << v <<endl;
   cout << "int w = " << w << endl;
   return 0;
}
