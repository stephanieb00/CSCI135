#include <iostream>
#include <string>
using namespace std;
int main(){
int width, height;
cout << "Input width: ";
cin >> width;
cout << "Input height: ";
cin >> height;
char stars = '*';
char rows_stars = '*';
for(int row = 1; row <= height; row++){
rows_stars= stars; //start with the character that the row should begin with
for(int col = 1; col <= width; col++){
cout << rows_stars;
//check if we should toggle the current character,
//after every 3 columns, we need to toggle
if(col % 3 == 0){
   if(rows_stars == '*'){
      rows_stars = ' ';}
   else{
      rows_stars = '*';}
   }
}
cout << endl;
//check if we should toggle the row starting character, after every 3 lines, we need to toggle
if(row % 3 == 0){
if(stars == '*'){
stars = ' ';}
else{
stars = '*';}
}
}
}
