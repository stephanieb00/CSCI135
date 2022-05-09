/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment:Task D. One-pixel-thick frame.,Lab8D

This program will read a PGM image from the file "inImage.pgm", and outputs a modified image to "outImage.pgm". It will draw a white box exactly in the middle of the picture. The dimensions of the box should be 50% by 50% of the original picture’s width and height. and then the frame should be exactly one pixel thick.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;
// Reads a PGM file.

// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	ifstream instr;
	instr.open("inImage.pgm");

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
	ofstream ostr;
	ostr.open("outImage.pgm");
	if (ostr.fail()) {
		cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << endl;
	// width, height
	ostr << width << ' ';
	ostr << height << endl;
	ostr << 255 << endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << endl;
		}
	}
	ostr.close();
	return;
}

//Nothing above this line should be modified!!!!

//Task A. Invert Colors!
void invert_colors(int image[MAX_H][MAX_W], int height, int width){
	for(int row = 0; row < height; row++){
		for (int col = 0; col < width; col++){
			//if((image[row][col]<=255) && (image[row][col] >127.5)){ //between 127.5 and 255
				image[row][col] = 255 - (image[row][col]);

			//}
			//if((image[row][col]>=0) && (image[row][col] < 127.5)){ //between 0 and 127.5
				//image[row][col] = 255 - (image[row][col]);
			//}
		}

	}
return;
}

//Task B. Invert Half Right.
void invert_half(int image[MAX_H][MAX_W], int height, int width){
	int new_width = width/2;
	for(int row = 0; row < height; row++){
		for (int col = new_width; col < width; col++){
			//if((image[row][col]<=255) && (image[row][col] >127.5)){ //between 127.5 and 255
				image[row][col] = 255 - (image[row][col]);
			//}
			//if((image[row][col]>=0) && (image[row][col] < 127.5)){ //between 0 and 127.5
				//image[row][col] = 255 - (image[row][col]);
			//}
		}

	}
return;
}

//Task C. Add a white box;
void box(int image[MAX_H][MAX_W], int height, int width){
	int new_width = width/2;
	int new_height = height/2;
	int start_height = height/4;
	int start_width = width/4;
	for(int row = start_height; row < (height - start_height); row++){
		for (int col = start_width; col < (width- start_width); col++){
			//if((image[row][col]<=255) && (image[row][col] >127.5)){ //between 127.5 and 255
			image[row][col] = 255 ;//(image[row][col]);
			//}
			//if((image[row][col]>=0) && (image[row][col] < 127.5)){ //between 0 and 127.5
				//image[row][col] = 255 - (image[row][col]);
			//}
		}

	}
return;
}


//Task D. One-pixel-thick frame
void frame(int image[MAX_H][MAX_W], int height, int width){
	int new_width = width/2;
	int new_height = height/2;
	int start_height = height/4;
	int start_width = width/4;
	int end_width = width - start_width;
	int end_height = height - start_height;
	for(int row = start_height; row <= end_height; row++){
		for (int col = start_width; col <= end_width; col++){
			if (row == start_height || row == end_height) {
				/* code */
				image[row][col] = 255 ;//(image[row][col]);
			}
			else if( start_width == col || col == end_width){
				image[row][col] = 255 ;//(image[row][col]);
			}
		}
	}
return;
}
int main() {

	int img[MAX_H][MAX_W];
	int h, w;

	readImage(img, h, w); // read it from the file "inImage.pgm"
	// h and w were passed by reference and
	// now contain the dimensions of the picture
	// and the 2-dimesional array img contains the image data

	//invert_colors(img,h,w);
	//invert_half(img,h,w);
	//box(img,h,w);
	frame(img,h,w);
	// Now we can manipulate the image the way we like
	// for example we copy its contents into a new array
	int out[MAX_H][MAX_W];

	for(int row = 0; row < h; row++) {
		for(int col = 0; col < w; col++) {
			out[row][col] = img[row][col];
		}
	}

	// and save this new image to file "outImage.pgm"
	writeImage(out, h, w);

}
