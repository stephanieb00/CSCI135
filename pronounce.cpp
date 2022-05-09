/*
Author: Stephanie Bravo
Course: CSCI-136
Instructor: Genady Maryash
Assignment:Project2: Phase 2 program, e.g., Project2

This program will use the dictionary file cmudict.0.7.a. User enters a wordand  In addition to the functionality of phases I, II, III, IV, and V print a list of words that can be obtained by replacing just one phoneme — words made up of exactly the same sequence of phonemes with just one of them different. WIll remove just one phonem. will find the identical and will add a phoneme

*/
//Splitting the word upon the first space.

//Hello should print: HH AH0 L OW1
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

//----------------------------------SLIT WORD!-----------------------------------

void splitOnSpace(string s, string & before, string & after) {
  // reset strings
    before = "";
    after = "";
  // accumulate before space
    int i = 0;
    while (i < s.size() && not isspace(s[i])) {
        before = before + s[i];
        i++;
    }
  // skip the space
    i++;
    // accumulate after space
    while (i < s.size()) {
        after = after + s[i];
        i++;
    }
}
//----------------------------------PRONOUNCIATION(PHASE1)-----------------------------------

//Phase 1: Get the pronunciation of the word:
string pronunce(string text){
   //print words pronunciation
   //Read the file
   //print words pronunciation
   ifstream fin("cmudict.0.7a");
   if (fin.fail()){
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
   }
   //length of the word.
   int length = text.length();
   string new_word = "";
   string beforeSpace = "";
   string afterSpace = "";
   string words = "";
   string not_found = "Not Found";
   //this will make sure that the characters are uppercase since thats how they are in the txt file.
   for (int i = 0; i < length; i++) {
      /* code */
      char c = text[i];
      if ( c >= 'a' && c <= 'z') {
         /* code */
         c = c-32;
      }
      new_word = new_word + c;
   }
   //std::cout << "Word" << new_word <<'\n';
   //the above part works!
   // How do you get each line. cin >> words does not work?
   //std::ifstream file("input.txt"); std::string str;  while (std::getline(file, str)) {  // process string ...}
   //this reads each line .
   while ( getline(fin, words) ) {
      /* code */
      //send it to the other function;
      splitOnSpace(words, beforeSpace, afterSpace);
      if (new_word == beforeSpace) {
         /* code */
         afterSpace = afterSpace;
         return afterSpace;
      }
      //else{
         //afterSpace = "Not found";
         //return "Not Found";
      //}
   }
   //return afterSpace;
   fin.close();
   return not_found;
}
//----------------------------------IDENTICAL(PHASE2)-----------------------------------

//this has to be void because if it isnt it does not print all the possibilities but instead just the first it finds!
void identical(string text, string pronounciation){
   //print words pronunciation
   //Read the file
   //print words pronunciation
   ifstream fin("cmudict.0.7a");
   if (fin.fail()){
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
   }
   //length of the word.
   int length = text.length();
   string new_word = "";
   string beforeSpace = "";
   string afterSpace = "";
   string words = "";
   string not_found = "Not Found";
   //this will make sure that the characters are uppercase since thats how they are in the txt file.
   for (int i = 0; i < length; i++) {
      /* code */
      char c = text[i];
      if ( c >= 'a' && c <= 'z') {
         /* code */
         c = c-32;
      }
      new_word = new_word + c;
   }
   //you want to repeat this process until the end of the file!
   while (getline(fin, words)) {
      /* code */
      //each word will go to phase 2 to see if it has an identical pronounciations
      //pronunce(words);
      splitOnSpace(words, beforeSpace, afterSpace);
      //if it does it will print out that word.
      // looks to see that the Pronunciation is the same as in phase 1 but cant be the actual word that has been input.
      if (pronounciation == afterSpace && new_word != beforeSpace) {
         /* code */
         //return beforeSpace;
         cout << beforeSpace<< " ";
      }
   }
   cout  << endl;
   fin.close();
   //return not_found;
}

//----------------------------------REPLACE phoneme(PHASE3)-----------------------------------
void replace_phoneme(string text, string pronounciation) {
   /* code */
   //print words pronunciation
   //Read the file
   //print words pronunciation
   ifstream fin("cmudict.0.7a");
   if (fin.fail()){
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
   }
   //length of the word.
   int length = text.length();
   int z = 0;
   string new_word = "";
   string beforeSpace = "";
   string afterSpace = "";
   string pro_beforeSpace = "";
   string pro_afterSpace = "";
   string words = "";
   string new_pronoun = "";
   string not_found = "Not Found";
   string pron = "";
   //this will make sure that the characters are uppercase since thats how they are in the txt file.
   for (int i = 0; i < length; i++) {
      /* code */
      char c = text[i];
      if ( c >= 'a' && c <= 'z') {
         /* code */
         c = c-32;
      }
      new_word = new_word + c;
   }
   while (getline(fin, words)) {
		splitOnSpace(words, beforeSpace, afterSpace); //good.
      new_pronoun = beforeSpace;

      pron = afterSpace;
      //getthe first PHENOME; AH0 K AO1 R D = AHO
      splitOnSpace(afterSpace, beforeSpace, afterSpace);
      splitOnSpace(afterSpace, beforeSpace, afterSpace);
      // now split the inputted pronounciation
      splitOnSpace(pronounciation, pro_beforeSpace, pro_afterSpace);
      splitOnSpace(pro_afterSpace, pro_beforeSpace, pro_afterSpace);
      z = 0;// you want to set it again because you want for every word this to be the case. it doesn't matter that you set it in the beggining.
      //While loop!!! WHile there is something in the these two variable and they arent blank. which they will be if there is none.
      bool t_or_f = true;
      while (((afterSpace != "") || (beforeSpace != "")) && (t_or_f == true)) {
         /* code */
         // if thse two are not equal to eachother you want to increase the integer varibale z by 1.
         if (beforeSpace != pro_beforeSpace) {
            /* code */
            z+= 1;
         }
         //
         if (z > 1) {
            /* code */
            //cout<< words;
            t_or_f = false; // so it could exit loop. but it continues on to the
         }
         //this happend if before space is equal to pro_beforeSpace. you want to split it again.

         //we dont want something that has similar things.
         splitOnSpace(afterSpace, beforeSpace, afterSpace);
         splitOnSpace(pro_afterSpace, pro_beforeSpace, pro_afterSpace);
         //if these those are empty you want no longer be in the loop.
         if ((afterSpace == "") || (pro_afterSpace == ""))
         {
             //to exit loop set bool to false.
             t_or_f = false;
         }

      }
      //if(z == 1 && pro_afterSpace == "" && beforeSpace == "") {
         /* code */
         //if ( beforeSpace == pro_beforeSpace) {
            /* code */
            //cout<< words<< " ";
         //}
      //}
      //else if (z == 0 && pro_afterSpace == "" && beforeSpace == "") {
         /* code */
         //if ( words!= new_word) {
            /* code */
            //cout << words << " ";
         //}
      //}
      int y = 0;
      if ((z <= 1) && (pro_afterSpace == "") && (afterSpace == "") && (pronounciation != pron)){
         if ((z == 0) &&  (new_pronoun!= new_word) ) {
            /* code */
            for (int i = 0; i < new_pronoun.length(); i++) {
               /* code */
               char c = new_pronoun[i];
               if (isdigit(c)) {
                  /* code */
                  y++;

               }
            }
            //cout<< y<< endl;
            if (y== 0) {
               /* code */

               cout << new_pronoun << " ";
            }
         }
         else if ((z == 1) && (beforeSpace == pro_beforeSpace) ) {
            /* code */
            for (int i = 0; i < new_pronoun.length(); i++) {
               /* code */
               char c = new_pronoun[i];
               if (isdigit(c)) {
                  /* code */
                  y++;

               }
            }
            if (y==0) {
               /* code */
               cout << new_pronoun << " ";
            }
            //cout<< new_pronoun<< " ";
         }
      }

		//if (afterSpace == new_word) {
		//	words += beforeSpace;
			//words += " ";
         //cout<< words;
		//}
   }
   cout  << endl;
   fin.close();
}
//---------------------------------- Add phoneme(PHASE4)-----------------------------------


void adding_phoneme(string pronounciation){
   ifstream fin("cmudict.0.7a");
   if (fin.fail()){
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
   }
   string beforeSpace = "";
   string afterSpace = "";
   string pro_beforeSpace = "";
   string pro_afterSpace = "";
   string words = "";
   string new_pronoun = ""; //add
   //string not_found = "Not Found";
   int z;
   string pron = "";
   bool letter;
   while(getline(fin, words)){
      int x = 0;

      for(int i = 0;i < words.length(); i++){
         //alpha(c) isn't working
         char c = words[i];
         if(((c > 64)&&(c < 91 ))||((c > 96 )&&(c < 123 ))|| c == 39 || c == ' '||(c <= 50 && c >=48)){
            x+= 1;
          }
       }
      if(x == words.length()){
         letter = true;
      }
      else{
         letter = false;
      }
      if(letter == true){
         splitOnSpace(words, beforeSpace, afterSpace);
         z= 0;
         for(int i = 0; i < afterSpace.length(); i++ ){
            if(afterSpace[i] == ' '){
               z++;// want to get rid of the planet one.
            }
         }
         for(int i=0; i< z; i++){
            splitOnSpace(afterSpace, pro_beforeSpace, pro_afterSpace);
            if(i == 0){
               if(pro_afterSpace == pronounciation){
                  cout << beforeSpace << " ";
               }
               pron = pro_beforeSpace;
            }
            else{
               if(pron + " " + pro_afterSpace == pronounciation){
                  cout << beforeSpace << " ";
               }
               pron += " " + pro_beforeSpace;
               if(pron == pronounciation && i == z-1){
                  cout << beforeSpace<< " ";
               }
            }
            afterSpace = pro_afterSpace;
         }
      }
   }
    cout<< endl;
    fin.close();
}
//---------------------------------- Remove phoneme(PHASE6)-----------------------------------
void removing_phoneme(string pronounciation){
   ifstream fin("cmudict.0.7a");
   if (fin.fail()){
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
   }
   int length = pronounciation.length();
   string line = "";
   string beforeSpace = "";
   string afterSpace = "";
   string pro_beforeSpace = "";
   string pro_afterSpace = "";
   string words = "";
   string new_pronoun = ""; //add
   //string not_found = "Not Found";
   int z;
   string pron = "";
   bool letter;

   //we want to check how many spaces there are in the pronounciation. so we could remove just one of the phonemes in said space.
   for (int i = 0; i < length; i++) {
      /* code */
      char c = pronounciation[i];
      if (isspace(c)) {
         /* code */
         z++;
      }
   }

   while (getline(fin, words)) {
      int x = 0;
      for(int i = 0;i < words.length(); i++){
         //alpha(c) isn't working
         char c = words[i];
         if(((c > 64)&&(c < 91 ))||((c > 96 )&&(c < 123 ))|| c == 39 || c == ' '||(c <= 50 && c >=48)){
            x+= 1;
          }
       }
      if(x == words.length()){
         letter = true;
      }
      else{
         letter = false;
      }

      //if the bool is true we want to split on space the word!!
      if (letter == true) {
         /* code */
         splitOnSpace(words, beforeSpace, afterSpace);
         //for the length of how many spaces(z) there were in thepronounciation you want split!
         for (int i = 0; i < z; i++) {
            /* code */
            splitOnSpace(line,pro_beforeSpace,pro_afterSpace);
            //i will equal 0 one time in the beggining. we want to check for the first phoneme
            //will only be done one time!
            if (i == 0) {
               //we wnat to see if both afterSPace and Pro after space are equal to eachother!
               if (pro_afterSpace == afterSpace) {
                  /* code */
                  pron = pron + " " + beforeSpace;
               }
               //set new_pronoun equal to beforeSpace;
               new_pronoun = pro_beforeSpace;
            }


            //when i is greater then z. so basically else than 0;
            else{
               //if after space is equal to the new pronounciation recieved then!
               if (afterSpace == new_pronoun + " " + pro_afterSpace) {
                  /* code */
                  pron = pron + " " + beforeSpace;
               }

               new_pronoun = new_pronoun + " " + pro_beforeSpace;
               if ((new_pronoun == afterSpace) && (i == z-1) ) {
                  /* code */
                  pron = pron + " " + beforeSpace;
               }
            }

            line = pro_afterSpace;
         }
         line = pronounciation;
      }
   }

   cout<< pron<< endl;
   fin.close();
}






//Main!!!!!!!!!!!!!!!!!!
int main() {
   /* code */
   //variables
   string text;
   //get the user to input the word;
   cout << "Enter a word: ";
	getline(cin, text);
   cout  << endl;
   //cout  << endl;
   //print words pronunciation
   /*ifstream fin("cmudict.0.7a.txt");
   if (fin.fail()){
      cerr << "File cannot be opened for reading." << endl;
      exit(1); // exit if failed to open the file
   }*/

   //set a varible eqaul to the the pronunciation so we could use it for the identical thing.
   string pronounciation = pronunce(text);
   cout << "Pronunciation    :" << pronounciation <<endl;
   cout << "Identical        :";
   identical(text, pronounciation);
   cout << "Replace phoneme  :";
   replace_phoneme(text,pronounciation);
   cout << "Add phoneme  :";
   adding_phoneme(pronounciation);
   cout << "Remove phoneme  :";
   removing_phoneme(pronounciation);

   //fin.close();
   return 0;
}
