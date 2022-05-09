/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Genady Maryash
Assignment: Practice Exercises , e.g., E.7.16

This program will define a structure point. A point has an x - and a y-coordinate. There will be a function called "double distance(Point a, Point b)"" that computes the distance from a to b.It will read the coordinates of the points, call the function, and display the result.

*/

//distance formula: d = sqrt ((x2-x1)^2+ (y2-y1)^2)
#include <iostream>
#include <cmath>
using namespace std;

struct Point{
   double x;
   double y;
};

double distance(Point a, Point b){
   // a is (x,y)
   double z;
   z = sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
   return z;
}
int main() {
   /* code */
   //structure two points!
   Point a;
   Point b;

   //first coordinate!
   cout<< "What is the x value of the first coordinate:";
   cin>> a.x;
   cout<< "What is the y value of the first coordinate:";
   cin>> a.y;

   //second coordinate!
   cout<< "What is the x value of the second coordinate:";
   cin>> b.x;
   cout<< "What is the y value of the second coordinate:";
   cin>> b.y;
   cout << "The distance of the points "<<"(" << a.x <<", "<< a.y << ")" << "and "<<"(" << b.x <<", "<< b.y << ") is: "<< distance(a, b)<< endl;
   return 0;
}
