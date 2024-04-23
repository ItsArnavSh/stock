#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
//includig necessary header files
using namespace std;

string cfm="common";
string cfpm="passwords";
//cfm- common file name
// file named common contains the name of existing companies and users
//formation_of_file is overloaded function
//these are some set of functions to check whether the password input is valid or not
bool aexist(string password){
    bool flagp=false;//for condition inside of the while loop
    string myTextp;
//first checking with file with such name exists or not in the common names file list
ifstream MyReadFile(cfpm+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myTextp)) {
// Output the text from the file

if(myTextp==password){
 flagp=true;
 break;
}
else{
 flagp =false;
}
}
// Close the file
MyReadFile.close();
return flagp;   
}
bool checknumber(string c){
    bool test= false;
    int l=c.length();
    for(int i=0;i<=l;i++){
        if(c[i]>=0&&c[i]<=9){
            test =true;
            break;
        }
    }
    return test;
}
bool checkSize(string c)
{
    if(c.length()<12)
        return true;
    return false;
}
bool checkspcharacter(string c){
    bool test= false;
    int l=c.length();
    for(int i=0;i<=l;i++){
        if(c[i]=='&'||c[i]=='#'||c[i]=='@'||c[i]=='$'){
            test =true;
            break;
        }
    }
    return test;
}
bool checkalphabet(string c){
    bool test= false;
    int l=c.length();
    for(int i=0;i<=l;i++){
        if((c[i]>=65&&c[i]<=90)||(c[i]>=97&&c[i])){
            test =true;
            break;
        }
    }
    return test;
}bool checkpassword(string p){
if((checknumber(p))&&checkspcharacter(p)&&checkalphabet(p)&&checkSize(p)){
return true;
}
else {
return false;
}
}
class Company{
//type of company
string type;// for example automative and food or beverages 
string name1_comp;
string password_comp;
char statusC;
//+ or -
//will be decided as per most recent data
string myTextA;// for file handling
public:
void formation_of_file(string name,string password,float extra){
name1_comp=name;
password_comp=password;
int flag1=0;//for condition inside of the while loop
//first checking with file with such name exists or not in the common names file list
ifstream MyReadFile(cfm+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myTextA)) {
// Output the text from the file

if(myTextA==name1_comp){
 flag1=3;
 break;
}
else{
 flag1=4;
}
}
if(flag1==4){
    cout<<"Company not found";
    
}
MyReadFile.close();
/*// Creating and opening a text file
ofstream MyFile(name1_comp+".txt");
// Writing to the file
MyFile << password_comp;
// Closing the file
MyFile.close();*/
if(extra==1.0){//existing user
string myText;
// Reading from the text file
ifstream MyReadFile(name1_comp+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file
// we will be checking only the first line
// since only first line contains password
if(myText==password){
cout<<"Company verified";
break;
}
else{
cout<<"not verified";
break;
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
cout<<"Enter the companie's type  for example automative, financial etc"<<endl;
cin>>type;
//adding this information to the file of company
 MyFile.open(name1_comp+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile <<endl<<"Type of company: "<< type;
// Close the file
MyFile.close();
}
}

};

class User{
string name;
string password;
int yoi;//=2024;//year of investment
// 2024 by default
float profit;//profit or loss // the b
float loss;//if stocks sold // the b variable
int number_of_stocks;
int age;
float balance;
string myText;
char status;//+ or -
public:
void formation_of_file(string name1, string password1, int extra){
name=name1;
password=password1;
int flag=0;//for condition inside of the while loop
//first checking with file with such name exists or not in the common names file list
ifstream MyReadFile(cfm+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file

if(myText==name1){
 flag=3;
 break;
}
else{
 flag =4;
}
}
if(flag==4){
    cout<<"User not found";
    
}
// Close the file
MyReadFile.close();

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
// we will be checking only the first line
// since only first line contains password
if(myText==password){
cout<<"User verified";
break;
}
else{
cout<<"User not verified";
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
cout<<"Enter the necessary details- "<<endl;
 MyFile.open(name+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile <<endl<< yoi<< endl;
// Close the file
MyFile.close();

cout<<"Enter your age"<<endl;
cin>>age;
 MyFile.open(name+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile<< "Age: "<< age;
// Close the file
MyFile.close();
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
cout<<"Enter your email id"<<endl;
cin>>NCname;
ofstream MyFile(cfm+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile << NCname<<endl;
// Close the file
MyFile.close();
string NCpassword;
rewritew:
cout<<"Create a password"<<endl;
cout <<"Note the following conditions required for a valid password: "<<endl;
cout<<"1. The password can be alpha numeric but should not exceed the maximum limit of 12 characters"<<endl;
cout<<"2. The password must contain atleast one special character from &,#,$ and @"<<endl;
cout<<"3. The password must contain atleast one number and "<<endl;
cout<<"4. The password must contain atleast one alphabet"<<endl;
cout<<"Enter your password here - "<<endl;
//to throw an error if condition not met
cin>>NCpassword;
bool ans=checkpassword(NCpassword);
if(aexist(NCpassword)){
    cout<<"Kindly enter a unique password"<<endl;
    goto rewritew;
}
else{
ofstream MyFile(cfpm+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile << NCpassword<<endl;
// Close the file
MyFile.close();
}
if(ans){
    cout<<"Proceed"<<endl;
}
else{
    cout<<"Not valid as per requirements"<<endl;
    goto rewritew;
}
//input name,password.....
//checking if the password set is valid as per the conditions

CN1.formation_of_file(NCname,NCpassword,2.20);
}
else if(choice3=='E'){
Company CE1;
string CEname;
cout<<"Enter the name of the company"<<endl;
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
cout<<"Enter your email id"<<endl;
cin>>Nname;
//creating a common file containing names of all the user
//appending names in the file with every new entry
ofstream MyFile(cfm+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile << Nname<<endl;
// Close the file
MyFile.close();
string Npassword;
rewrite:
cout<<"Create a unique password"<<endl;
cout<<endl;
cout <<"Note the following conditions required for a valid password: "<<endl;
cout<<endl;
cout<<"1. The password can be alpha numeric but should not exceed the maximum limit of 12 characters"<<endl;
cout<<"2. The password must contain atleast one special character &,#,$ and @"<<endl;
cout<<"3. The password must contain atleast one number and "<<endl;
cout<<"4. The password must contain atleast one alphabet"<<endl;
cout<<"Enter your password here - "<<endl;
//to throw an error if condition not met
cin>>Npassword;
bool ans=checkpassword(Npassword);
//creating a common file containing all the existing passwords
//appending names in the file with every new entry
if(aexist(Npassword)){
    cout<<"Kindly enter a unique password"<<endl;
    goto rewrite;
}
else{
ofstream MyFile(cfpm+".txt",ofstream::out | ofstream::app);
// Write to the file
MyFile << Npassword<<endl;
// Close the file
MyFile.close();
}
if(ans){
    cout<<"Proceed"<<endl;
}
else{
    cout<<"NOT VALID "<<endl;
    cout<<endl;
    goto rewrite;
}
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
return 1;
}