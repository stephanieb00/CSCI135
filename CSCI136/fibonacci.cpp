/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: Using arrays to store, update, and retrieve numbers, e.g., Lab2c

This program creates an array of integers to compute and print all Fibonacci numbers from F(0) to F(59)
*/

#include <iostream>
using namespace std;

int main() {
   //Setting an array named "fib" with 60 box titles 0-59 and i
   int fib[60],i;
   //The first two items are given. we give these two first numbers because if not the formual cannot calculate for it.
   fib[0] = 0;
   cout << fib[0] << endl;
   fib[1] = 1;
   cout << fib[1] << endl;
   // for all numbers in the array compute the Fibonacci number.
   for (i = 2; i < 60; i++) {
      //calculation for 2 till 59
      fib[i] = fib[i-1] + fib[i-2];
      //print the Fibonacci number at said i value.
      cout << fib[i] << endl;
   }
   /*Answer to the question: the first number in the billions is "1134903170" however after it starts to reach 2 billion the number begins to become negative. It starts to switch from negative to postive intechangably. This happens at the array of 46.  I think that the code works but it only works for the first few numbers. In the lecture we learned that the integers variables have a maximum value it can hold which I think the program surpasses.    */
   return 0;
}
