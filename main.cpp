#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <random>
#include <cmath>
#include <limits>
//include necessary headings
using namespace std;
string cfm="common";
string cfpm="passwords";
//cfm- common file name
// file named common contains the name of existing companies and users
//formation_of_file is overloaded function
//these are some set of functions to check whether the password input is valid or not
bool aexist(string password)
{
    bool flagp=false;//for condition inside of the while loop
    string myTextp;
//first checking with file with such name exists or not in the common names file list
ifstream MyReadFile(cfpm+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myTextp)) {
// Output the text from the file

if(myTextp==password)
{
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
bool checknumber(string c)
{
    bool test= false;
    int l=c.length();
    for(int i=0;i<=l;i++)
{
        if(c[i]>=0&&c[i]<=9)
{
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
bool checkspcharacter(string c)
{
    bool test= false;
    int l=c.length();
    for(int i=0;i<=l;i++)
{
        if(c[i]=='&'||c[i]=='#'||c[i]=='@'||c[i]=='$')
{
            test =true;
            break;
        }
    }
    return test;
}
bool checkalphabet(string c)
{
    bool test= false;
    int l=c.length();
    for(int i=0;i<=l;i++)
{
        if((c[i]>=65&&c[i]<=90)||(c[i]>=97&&c[i]))
{
            test =true;
            break;
        }
    }
    return test;
}bool checkpassword(string p)
{
if((checknumber(p))&&checkspcharacter(p)&&checkalphabet(p)&&checkSize(p))
{
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
void formation_of_file(string name,string password,float extra)
{
name1_comp=name;
password_comp=password;
int flag1=0;//for condition inside of the while loop
//first checking with file with such name exists or not in the common names file list
ifstream MyReadFile(cfm+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myTextA)) {
// Output the text from the file

if(myTextA==name1_comp)
{
 flag1=3;
 break;
}
else{
 flag1=4;
}
}
if(flag1==4)
{
    cout<<"Company not found";
    
}
MyReadFile.close();
/*// Creating and opening a text file
ofstream MyFile(name1_comp+".txt");
// Writing to the file
MyFile << password_comp;
// Closing the file
MyFile.close();*/
if(extra==1.0)
{//existing user
string myText;
// Reading from the text file
ifstream MyReadFile(name1_comp+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file
// we will be checking only the first line
// since only first line contains password
if(myText==password)
{
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
void formation_of_file(string name1, string password1, int extra)
{
name=name1;
password=password1;
int flag=0;//for condition inside of the while loop
//first checking with file with such name exists or not in the common names file list
ifstream MyReadFile(cfm+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file

if(myText==name1)
{
 flag=3;
 break;
}
else{
 flag =4;
}
}
if(flag==4)
{
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
if(extra==1)
{//existing user
string myText;
// Read from the text file
ifstream MyReadFile(name+".txt");
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
// Output the text from the file
// we will be checking only the first line
// since only first line contains password
if(myText==password)
{
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
//All the important functions
int generateRandomNumber(int min, int max)
{
    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd()); // Seed the generator
    uniform_int_distribution<> distr(min, max); // Define the range
    return distr(gen); // Generate numbers
}

void sleepMilliseconds(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

string intToTwoDigitString(int num)
{
    string str = to_string(num);
    if (str.length() > 2) {
        str = str.substr(str.length() - 2);  // Get the last two characters
    } else if (str.length() < 2) {
        str = "0" + str;  // Add a leading zero if the string has only one character
    }
    return str;
}

//To reliably input values
float inputNumber(int min=0,int max=0,int def = 0)
{
    if(min==max)
    {
        int min = numeric_limits<int>::min();
        int max = numeric_limits<int>::max();
    }
    float input = def;
    try {
        cin >> input;
        if(cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Invalid input");
        }
    }
     catch(const invalid_argument& e) 
    {
        cout << e.what() << endl << "Wrong Range" << endl;
        cout << "The value is being set to "<< def<<endl;
        input = def;
    }
    return input;
}

class graph
{
    int sizeOfGraph;
    string *x;//This will store the x axis
    int *y;//This will store the y axis
    string fileLocation;//This will store the file location.
    public:
    graph()//If empty graph class is made, it will throw an error
    {}
graph(vector<string> x1,vector<int> y1)
{
    // If the size of the vectors is more than 30, erase the extra elements
    if (x1.size() > 30) {
        x1.erase(x1.begin(), x1.end() - 30);
    }
    if (y1.size() > 30) {
        y1.erase(y1.begin(), y1.end() - 30);
    }

    sizeOfGraph  = x1.size();
    x = new string[sizeOfGraph];
    y = new int[sizeOfGraph];
    for(int i=0;i<sizeOfGraph;i++)
    {
        x[i] = x1[i];
        y[i] = y1[i];
    }
}
void editGraph(vector<string> x1,vector<int> y1)
{
    // If the size of the vectors is more than 30, erase the extra elements
    if (x1.size() > 30) {
        x1.erase(x1.begin(), x1.end() - 30);
    }
    if (y1.size() > 30) {
        y1.erase(y1.begin(), y1.end() - 30);
    }

    sizeOfGraph  = x1.size();
    x = new string[sizeOfGraph];
    y = new int[sizeOfGraph];
    for(int i=0;i<sizeOfGraph;i++)
    {
        x[i] = x1[i];
        y[i] = y1[i];
    }
}
    graph(string location)//The actual constructor
    {
        fileLocation = location;
    }
    void generateData();
    void plotGraph();
    vector<vector<string>> readCSV();

};
void graph::generateData()
{
    vector<vector<string>> data = readCSV();
    sizeOfGraph  = data.size()-1;//-1 to account for the header also
    x = new string[sizeOfGraph];
    y = new int[sizeOfGraph];
    //We will access the fileLocation and read the values from therre
    //Store them in the vectors x and y
    //Save other major integers here, which can be later ysed by plot graph method
    for (int i = 1; i <= sizeOfGraph; i++)
    {
        
        x[i-1] = data[i][0].substr(3,2);
        y[i-1] = stoi(data[i][1].substr(1,3));
    }

}
void graph::plotGraph()
{
    int min=y[0],max=y[0];
    for(int i=0;i<sizeOfGraph;i++)
    {
        if(y[i]>max)
            max = y[i];
        if(y[i]<min)
            min = y[i];
    }
    float range = max-min;
    
    //There are 18 points in y axis (say)
    float step = range/15;
    if(max==min)
        step = (float)max/18;
    float yAxis=max;
    cout << endl;
    //A step is the difference between any two consecutive y index values
    for(int i=0;i<18;i++)//Going 18 instead of 10 to show the min val
    {
        //cout << setw(5)<<yAxis<<"| ";
        cout << setw(8) << fixed << setprecision(2) << yAxis<< "| ";
        for(int j=0;j<sizeOfGraph;j++)
        {
            if(y[j]>=yAxis)
                cout << " HH ";
            else
             cout << "    ";
        }
        yAxis-=step;
        cout << endl;
    }
    cout << "        |";
  
    for(int i=1;i<=sizeOfGraph;i++)
    {
        cout << "____";
    }
    cout << endl;
    cout << "           ";
    for(int i=1;i<=sizeOfGraph;i++)
    {
        cout << setw(2)<<x[i-1]<<"  ";
    }
    cout <<endl;
}
vector<vector<string>> graph::readCSV()
{
    vector<vector<string>> data;
    ifstream file(fileLocation);

    if (!file.is_open()) {
        cerr << "Could not open file " << fileLocation << endl;
        return data;
    }

    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string value;

        while (getline(ss, value, ',')) {
            row.push_back(value);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}
class practiceMode;
class fakeCompany
{
    int UID;
    graph shareGraph;
    vector<int> A,B,C,W;
    int difficulty;
    int stocksOwned;
    practiceMode *point;
    public:
    vector<int> stockValue;
    int startingValue;
    float investment;
    fakeCompany(int uid,int diff,practiceMode *pointer);
    void intro();
    void companyDashboard();
    void calculate();
    void generateValues()
    {   
        for(int i=0;i<difficulty;i++)
        {
            A.push_back(generateRandomNumber(-4,4));
            B.push_back(generateRandomNumber(-1,1));
            C.push_back(generateRandomNumber(-10,10));
            W.push_back(generateRandomNumber(-5,5));

        }
    }
    int soleForX(int x)
    {
        float ans = 10*(sin(0.1*x)+sin(0.2*x));
        for(int i=0;i<difficulty;i++)
        {
            ans+=(A[i]*sin(B[i]*x+C[i]))+W[i];
        }
        ans += startingValue;
        return ((int)ans);
    }
};
class practiceMode
{
    vector<fakeCompany> companies;
    vector<int> userWorth;
    int numberCompanies;
    float networth;
    float stockWorth;
    int difficulty;
    float startingValue;
    graph userGraph;
    public:
    float liquidWorth;
    vector<string> days;
    practiceMode *pointer;
    practiceMode();
    void start();
    void userDashboard();
    void moveDays();
    void displayCompanies();
    float calculateNetworth();
};
practiceMode::practiceMode()
{
    startingValue = 1000;
    liquidWorth = startingValue;
    stockWorth = 0;
}
void practiceMode::moveDays()
{
    //Generate the data for each company
    for(int i=0;i<companies.size();i++)
    {
        companies[i].stockValue.push_back(companies[i].soleForX(companies[i].stockValue.size()));
        companies[i].calculate();
    }
    stockWorth = calculateNetworth();
    networth = stockWorth+liquidWorth;
    userWorth.push_back(networth);
    days.push_back(intToTwoDigitString(userWorth.size()));
}
void practiceMode::start()
{
    
    cout << "Welcome to the Practice Mode" << endl;
    cout << "What should be the difficulty level on a scale from 1 to 10"<<endl;
    difficulty = inputNumber(1,10,5);
    cout << "What should be the number of companies" << endl;
    numberCompanies = inputNumber(1,5,3);
    cout << "You are given 1000 starting points to invest"<<endl;
    sleepMilliseconds(3000);
    //Adding all the companies
    for(int i=0;i<numberCompanies;i++)
    {
        fakeCompany temp(i,difficulty,pointer);
        companies.push_back(temp);
    }
    stockWorth = calculateNetworth();
    networth = stockWorth+liquidWorth;
    days.push_back("01");
    userWorth.push_back(networth);
    userGraph.editGraph(days,userWorth);
    userDashboard();

}
void practiceMode::userDashboard()
{
    here:
    stockWorth = calculateNetworth();
    networth = stockWorth+liquidWorth;
    userGraph.editGraph(days,userWorth);
    clearScreen();
    userGraph.plotGraph();
    cout << "Networth: " << networth<<endl;
    cout << "Stocks are Worth " << stockWorth << "  |  "<< "Liquid Worth is " << liquidWorth<<endl;
    int pl = networth-startingValue;
    if(pl>0)
    {
        cout << "You are in profit" <<endl;
    }
    else if(pl<0)
    {
        cout << "You are in loss"<<endl;
    }
    else
    {
        cout << "No net profit"<<endl;
    }
    cout << endl;
    cout << "Press 1 to see the company List"<<endl;
    cout << "Press 2 to move"<< endl;
    cout << "Press 3 to QUIT"<<endl;
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
        clearScreen();
        displayCompanies();
        break;
        case 2:
        clearScreen();
        cout << "Enter the number of days you want to move."<<endl;
        int temp;
        cin >> temp;
        for(int i=0;i<temp;i++)
        {
            clearScreen();
            moveDays();
            userGraph.editGraph(days,userWorth);
            userGraph.plotGraph();
            sleepMilliseconds(200);
        }
        goto here;
        break;
        default:

        break;
    }
}
void practiceMode::displayCompanies()
{
    int i;
    for(i=0;i<companies.size();i++)
    {
        cout << "Press " << i << " for company number " << i << endl;
        cout << "You have invested " << companies[i].investment << " here " << endl;
        cout << "Current Stock Value of this company is " << companies[i].stockValue.back()<<endl<<endl;
    }
    cout << "Press any other button to go back"<<endl;
    int choice = (int)inputNumber(0,i-1,-1);
    if(choice==-1)
    {
        userDashboard();
    }
    else
    {
        companies[choice].companyDashboard();
    }

}
float practiceMode::calculateNetworth()
{
    float temp = 0;
    for(int i=0;i<companies.size();i++)
    {
        temp+=companies[i].investment;
    }
    return temp;
}
void fakeCompany::intro()
{
    clearScreen();
    shareGraph.plotGraph();
    cout << "The current Value of a share: "<< stockValue.back()<<endl;
    cout << "You currently own " << stocksOwned << " shares in the company"<<endl;
    cout << "Your liquid worth is " << point->liquidWorth << endl;
    cout << "You current Investment in this company is " << investment<<endl;
    cout << endl;
    cout << "Press 1 to BUY more stock" << endl;
    cout << "Press 2 to SELL stock" << endl;
    cout << "Press 3 to MOVE some days"<<endl;
    cout << "Press 4 to move back"<<endl;
}
void fakeCompany::companyDashboard()
{
    label:
    shareGraph.editGraph(point->days,stockValue);
    float stock = 0;
    float money = 0;
    intro();
    int choice;
    cin >> choice;
    switch(choice)
    {
        case 1:
        cout << "Enter the Number of stocks you want to buy"<<endl;
        cin >> money;
        money = money*stockValue.back();
        if(money>point->liquidWorth)
        {
            cout<< "You Do not have enough money!";
            sleepMilliseconds(2000);
        }
        else
        {
            cout << "You will get " << (float)money/stockValue.back() << "shares"<<endl;
            sleepMilliseconds(1000);
            point->liquidWorth -= money;
            stock = (float)money/stockValue.back();
            
        }
        stocksOwned += stock;
        calculate();
        goto label;
        break;
        case 2:
        cout << "Enter the amount of shares you want to sell? "<<endl;
        cin >> money;
        if(money>stocksOwned)
        {
            cout<< "You Do not have enough Stocks!";
            sleepMilliseconds(2000);
            money = 0;
        }
        else
        {
            cout << "You will get " << stockValue.back()*money << " points"<<endl;
            sleepMilliseconds(1000);
            point->liquidWorth += money*stockValue.back();
            
        }
        stocksOwned -= money;
        calculate();
        goto label;
        break;
        case 3:
        cout << "Enter the number of days you want to move."<<endl;
        int temp;
        cin >> temp;
        for(int i=0;i<temp;i++)
        {
            clearScreen();
            point->moveDays();
            shareGraph.editGraph(point->days,stockValue);
            shareGraph.plotGraph();
            cout << stockValue.back();
            sleepMilliseconds(200);
        }
        goto label;
        break;
        default:
        point->userDashboard();
        break;
    }

}
fakeCompany::fakeCompany(int uid,int diff,practiceMode *pointer)
{
    point = pointer;
    investment = 0;
    UID = uid;
    difficulty = diff;
    stocksOwned = 0;
    generateValues();
    stockValue.push_back(generateRandomNumber(50,100));
    shareGraph.editGraph(point->days,stockValue);
    startingValue = stockValue.back();
}
void fakeCompany::calculate()
{
    investment = stockValue.back()*stocksOwned;
}

int main()
{
cout<<"WELCOME"<<endl;
// system("cls");
char choice1;
start:
cout<<"Press C for company based approach and U for user based approach"<<endl;
cin>>choice1;
if(choice1=='C')
{
char choice3;
Companyapp:
cout<<"Press N if you are new to our application else press E"<<endl;
cin>>choice3;
if(choice3=='N')
{
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
if(aexist(NCpassword))
{
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
if(ans)
{
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
else if(choice3=='E')
{
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
else if (choice1=='U')
{
char choice2;
Userapp:
cout<<"Press N if you are new user else Press E if you are an existing user"<<endl;
cin>>choice2;
if(choice2=='N')
{
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
if(aexist(Npassword))
{
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
if(ans)
{
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
else if(choice2=='E')
{
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