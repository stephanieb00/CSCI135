/*
Author: Stephanie Bravo
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Practice Exercises , e.g., E.9.5

This program will Implement a class Rectangle. Provide a constructor to construct a rectangle with a given width and height, member functions get_perimeter and get_area that compute the perimeter and area, and a member function void resize(double factor) that resizes the rectangle by multiplying the width and height by the given factor.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Rectangle {
	public:
		Rectangle(double input_w, double input_h);
		double get_perimeter();
		double get_area();
		void resize(double factor);
	private:
		double width;
		double height;
};

//Provide a constructor to construct a rectangle with a given width and height,

Rectangle:: Rectangle(double input_w, double input_h){
   height = input_h;
   width = input_w;
}

double Rectangle:: get_perimeter(){
   return  2*(width+height);
}

double Rectangle:: get_area(){
   return height * width;
}

void Rectangle:: resize(double factor){
   height = height * factor;
   width = width * factor;
}
