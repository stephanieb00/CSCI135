/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Katherine Howitt
Assignment:Decryption.,Lab6D

This program will ask the user first to input plaintext, then ask for a right shift for the Caesar cipher and report the ciphertext and its subsequent decryption. After that, it should do the same for the Vigenere cipher.
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
	else if (c >= 'A' && c <= 'Z') {
		c = 'A' + (uppercase % 26);
	}
	return c;
}
//--------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------
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
		if ((c >= 'a' && c <='z') ||  (c >= 'A' && c <= 'Z')) {
			/* code */
			shifting = keyword[z] - 'a';
			z = (z+1)% key_length;
			plaintext[i] = shiftChar(plaintext[i],shifting);
		}
	}
	return plaintext;
}
//--------------------------------------------------------------------------------
string decryptCaesar(string ciphertext, int rshift){
   //int new_shift = -(rshift);
   int length = ciphertext.length(); //+ rshift;
   //for loop
   for (int i = 0; i < length; i++) {
      /* code */
      char c = ciphertext[i];
      if (c >= 'a' && c <='z') {
         /* code */
         c = c - rshift;
         if (c < 'a') {
            /* code */
            c = c + 'z' - 'a' + 1;
            //ciphertext[i] = shiftChar(ciphertext[i], -(rshift));
         }
         ciphertext[i] = c;
      }
      else if (c >= 'A' && c <= 'Z') {
         /* code */
         c = c - rshift;
         if (c < 'A') {
            /* code */
             c = c + 'Z' - 'A' + 1;
            //ciphertext[i] = shiftChar(ciphertext[i], -(rshift));
         }
         ciphertext[i] = c;
      }
   }
   return ciphertext;
} //== plaintext
//--------------------------------------------------------------------------------
string decryptVigenere(string ciphertext, string keyword){
   int key_length = keyword.length();
	int text_length = ciphertext.length();
   //char my_data[25]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}
   //char my_data2[25]= {'A','B','C,'D','E','F,'G','H','I','J,'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}
	//int shifting;
	int z = 0;
   char c;
   string new_cipher = "";
   int avg_length = text_length/key_length;
   //When reporting decrypted strings, they should be the result of applying decryption functions to the ciphertext, not the original plaintext variable.

   //To decrypt, take the first letter of the ciphertext and the first letter of the key, and subtract their value (letters have a value equals to their position in the alphabet starting from 0). If the result is negative, add 26 (26=the number of letters in the alphabet), the result gives the rank of the plain letter.
   //For loop

   //change all of the letter to uppercase maybe this will make the string work since we did that for phase 1?

   //cout <<"keyword: " <<keyword<< endl;
   for (int i = 0; i < key_length; i++) {
      /* code */
      if (islower(keyword[i])) {
         /* code */
         keyword[i]= keyword[i]-32;
      }
   }
	for(int i = 0; i < text_length; i++){
		// looking for the character in said position. first 0 and then the length.
		//doesnt matter is the character is lowercase or uppercase still send the character to the shiftChar function.
      //Why doesnt cakeca keca, k fdblf","cake"
      if (islower(ciphertext[i])) {
         //less than c
         // a is the new character
         c = (ciphertext[i] - 'a' - (keyword[z] - 'A') +26)%26 + 'a';
         //new_cipher+= a;
         z = (z+1)% key_length;
      }
      else if(isupper(ciphertext[i])){
         //greater than c
         c = (ciphertext[i] - keyword[z] +26)%26 + 'A';
         //new_cipher+= a;
         z = (z+1)% key_length;
      }

      //Why cant x work???


      // if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <='z')) {
      //    /* code */
      //    if(c >= 'a' && c <='z'){
      // 		c = 'a' + ((c -'a'- (keyword[z]-'a')) % 26);
      //       z = (z+1)% key_length;
      // 	}
      // 	// else it is uppercase
      // 	else if (c >= 'A' && c <= 'Z') {
      // 		c = 'A' + ((c -'A'- (keyword[z]-'a')) % 26);
      //       z = (z+1)% key_length;
      // 	}
         //c = 'a' - (keyword[z] - 'a');

         //c = 'a' + ( lowercase % 26);
         //c = 'a' + ( uppercase % 26);
         //char lowercase = (c - 'a' + rshift);
         //char uppercase = (c - 'A' + rshift);
         //ciphertext[i] = c;

      //}
      // else if (isspace(c)) {
      //    /* code */
      //    new_cipher += ' ';
      // }
      // else if (c == ',') {
      //    /* code */
      //    new_cipher += ',';
      // }
      // else if (c == '!') {
      //    /* code */
      //    new_cipher += '!';
      // }
      // else if (c == '.') {
      //     /* code */
      //    new_cipher += '.';
      //  }
      //  else if(c == '='){
      //     new_cipher += '=';
      // }
      else{
         c = ciphertext[i];
      }
      new_cipher += c;
	}
return new_cipher;
}  //== plaintext
//Main Function:
int main(){
	//variables
	string plain_text, keyword;
	int shift;
	//entering the text. This is for both Caesar and Vigenere functions
	cout << "Enter plaintext: ";
	getline(cin, plain_text);
//--------------------------------------------------------------------------------
   //Caesar:
   cout<< "Enter shift    : ";
   cin>> shift;
   string ciphertext_caesar = encryptCaesar(plain_text, shift);
   cout<<  "Ciphertext     :" << ciphertext_caesar<< endl;
   cout << "Decrypted      :"<< decryptCaesar(ciphertext_caesar, shift) << endl;
//--------------------------------------------------------------------------------
   //Vigenere
   //the keyword
	cout<< "Enter keyword: ";
	cin>> keyword;
	//calling the encryptVigenere function
   string ciphertext_vigenere = encryptVigenere(plain_text, keyword);
	cout<< "Ciphertext     :" <<ciphertext_vigenere<< endl;
   cout << "Decrypted      :" <<decryptVigenere(ciphertext_vigenere, keyword)<< endl;
return 0;
}
