/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment:Implementing Vigenere cipher encryption.,Lab6C

This program will ask the user to input a plaintext sentence, then enter a keyword, and will report the ciphertext computed using your encryption function and shift according to the keyword.
*/
#include <iostream>
#include <string>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift){
	char lowercase = (c - 'a' + rshift);
	char uppercase = (c - 'A' + rshift);
	// if it is lowercase. the % 26 makes it wrap around back to a or b if it goes more than 26.
	if(c >= 'a' && c <='z'){
		c = 'a' + ( lowercase % 26);
	}
	// else it is uppercase
	else if (c >= 'A' && c <= 'z') {
		c = 'A' + (uppercase % 26);
	}
	return c;
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift){
	int length = plaintext.length(); //+ rshift;
	for(int i = 0; i < length; i++){
		// looking for the character in said position. first 0 and then the length.
		char c = plaintext[i];
		//doesnt matter is the character is lowercase or uppercase still send the character to the shiftChar function.
		if ((c >= 'a' && c <='z') ||  (c >= 'A' && c <= 'z')) {
			/* code */
			plaintext[i] = shiftChar(plaintext[i],rshift);
		}
	}
	return plaintext;
}
//Vigenere cipher encryption
string encryptVigenere(string plaintext, string keyword){
	int key_length = keyword.length();
	int text_length = plaintext.length();
	int shifting;
	int z = 0;

	//For loop
	for(int i = 0; i < text_length; i++){
		// looking for the character in said position. first 0 and then the length.
		char c = plaintext[i];
		//doesnt matter is the character is lowercase or uppercase still send the character to the shiftChar function.
		if ((c >= 'a' && c <='z') ||  (c >= 'A' && c <= 'z')) {
			/* code */
			shifting = keyword[z] - 'a';
			z = (z+1)% key_length;
			plaintext[i] = shiftChar(plaintext[i],shifting);
		}
	}
	return plaintext;
}

//Main Function:
int main(){
	//variables
	string plain_text, keyword;
	int shift;
	//entering the text.
	cout << "Enter plain text: ";
	getline(cin, plain_text);
	//the keyword
	cout<< "Enter keyword: ";
	cin>> keyword;

	//calling the encryptVigenere function
	cout<< "Ciphertext: " <<encryptVigenere(plain_text, keyword)<< endl;
return 0;
}
