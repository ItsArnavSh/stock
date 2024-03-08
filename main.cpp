#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
using namespace std;
//formation_of_file is overloaded function
class Company{
//type of company
string type;
string name1_comp;
string password_comp;
char statusC;//+ or -
//will be decided as per most recent data
public:
void formation_of_file(string name,string password,float extra){
name1_comp=name;
password_comp=password;
/*// Create and open a text file
ofstream MyFile(name1_comp+".txt");
// Write to the file
MyFile << password_comp;
// Close the file
MyFile.close();*/
if(extra==1.0){//existing user
string myText;
// Read from the text file
ifstream MyReadFile(name1_comp+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file
if(myText==password){
cout<<"Company verified";
}
else{
cout<<"not verified";
}
}
// Close the file

MyReadFile.close();
}
else{//new user
// Create and open a text file
ofstream MyFile(name1_comp+".txt");
// Write to the file
MyFile << password_comp;
// Close the file
MyFile.close();
cout<<"New company id formed"<<endl;
cout<<"Enter necessary details"<<endl;
}
}
};
class User{
string name;
string password;
int yoi;//year of investment
float profit;//profit or loss
float loss;//is stocks sold
int number_of_stocks;
float balance;
char status;//+ or -
public:
void formation_of_file(string name1, string password1, int extra){
name=name1;
password=password1;
/*// Create and open 'a text file
ofstream MyFile(name+".txt");
// Write to the file
MyFile << password;
// Close the file
MyFile.close();
// Create a text string, which is used to output the text file*/
if(extra==1){//existing user
string myText;
// Read from the text file
ifstream MyReadFile(name+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file

if(myText==password){
cout<<"User verified";
}
else{
cout<<"not verified";
}
}
// Close the file
MyReadFile.close();
}
else{//new user
//Create and open 'a text file
ofstream MyFile(name+".txt");
// Write to the file
MyFile << password;
// Close the file
MyFile.close();
cout<<"New user id formed"<<endl;

}
}
};
int main(){
cout<<"WELCOME"<<endl;
// system("cls");
char choice1;
start:
cout<<"Press C for company based approach and U for user based approach"<<endl;
cin>>choice1;
if(choice1=='C'){
char choice3;
Companyapp:
cout<<"Press N if you are new to our application else press E"<<endl;
cin>>choice3;
if(choice3=='N'){
Company CN1;
string NCname;
cout<<"Enter first name"<<endl;
cin>>NCname;
string NCpassword;
cout<<"Enter the password"<<endl;
cin>>NCpassword;
//input name,password.....

CN1.formation_of_file(NCname,NCpassword,2.20);
}
else if(choice3=='E'){
Company CE1;
string CEname;
cout<<"Enter first name"<<endl;
cin>>CEname;
string CEpassword;
cout<<"Enter the password"<<endl;
cin>>CEpassword;
CE1.formation_of_file(CEname,CEpassword,1.0);
}
else{
cout<<"Please enter a valid choice";
goto Companyapp;
}
}
else if (choice1=='U'){
char choice2;
Userapp:
cout<<"Press N if you are new user else Press E if you are an existing user"<<endl;
cin>>choice2;
if(choice2=='N'){
User UN1;
string Nname;
cout<<"Enter first name"<<endl;
cin>>Nname;
string Npassword;
cout<<"Enter the password"<<endl;
cin>>Npassword;
//input name,password.....
UN1.formation_of_file(Nname,Npassword,2);
}
else if(choice2=='E'){
User UE1;
string Ename;
cout<<"Enter first name"<<endl;
cin>>Ename;
string Epassword;
cout<<"Enter the password"<<endl;
cin>>Epassword;
UE1.formation_of_file(Ename,Epassword,1);
}

else{
cout<<"Please enter a valid choice";
goto Userapp;
}
}
else{
cout<<"Please enter valid choice"<<endl;
goto start;
}
}




