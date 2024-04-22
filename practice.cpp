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

std::string intToTwoDigitString(int num)
{
    std::string str = std::to_string(num);
    if (str.length() > 2) {
        str = str.substr(str.length() - 2);  // Get the last two characters
    } else if (str.length() < 2) {
        str = "0" + str;  // Add a leading zero if the string has only one character
    }
    return str;
}

int generateRandomNumber(int min, int max)
{
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(min, max); // Define the range

    return distr(gen); // Generate numbers
}
void sleepMilliseconds(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
using namespace std;
void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
class graph
{
    int sizeOfGraph;
    string *x;//This will store the x axis
    int *y;//This will store the y axis
    string fileLocation;//This will store the file location.
    public:
    graph()//If empty graph class is made, it will throw an error
    {
        try{
        throw 0;
        }
        catch(int a)
        {
            cout << "Could not find a file name attatched to the Graph Class";
        }
    }
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
        cout << setw(6) << fixed << setprecision(2) << yAxis<< "| ";
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
    cout << "     |";
  
    for(int i=1;i<=sizeOfGraph;i++)
    {
        cout << "____";
    }
    cout << endl;
    cout << "        ";
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
class Trading
{
    public:
    //virtual void display_dashboard() = 0;
    virtual void start()=0;
};
class Real_time:public Trading
{
    
};
class Practice_mode:public Trading
{
    int difficulty;
    vector<int> A,B,C,W;
    int liquidMoney;
    int Value;
    float noOfStocks;
    vector <string> x;
    vector <int> y;
    int count;
    bool mode;
    vector<int> valueChart;
    int starting;
    public:
    Practice_mode()
    {
        noOfStocks = 0,count = 1;
        cout << "Welcome to the practice mode: ";
        cout << endl;
        cout <<"Enter any number of a scale of 1 to 10"<<endl;
        cout << "1 being ease to predict and 10 being very unpredictable"<<endl;
        cin >> difficulty;
        //Now we have the difficulty
        cout << "What will be the initial value of a Share?"<<endl;
        cin >> Value;
        cout << "How much starter money is needed?"<<endl;
        cin >> liquidMoney;
        starting = Value;
        mode = true;
        valueChart.push_back(liquidMoney);

    }
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
        return ((int)ans);
    }
    void start()
    {
        int skip = 0;
        generateValues();
        y.push_back(Value);
        x.push_back("01");
        
        clearScreen();
        graph A(x,y);//compostition relation
        A.plotGraph();
        label:
        cout << "Shares Owned: " << noOfStocks << " | ";
        cout << "Current Value of a share: " << Value << endl;
        cout << "Liquid Worth: " << liquidMoney << " | ";
        cout << "Stocks Worth: " << (noOfStocks*Value) << endl;
        cout << "Press 1 to BUY"<<endl;
        cout << "Press 2 to Sell"<<endl;
        cout << "Press 3 to Move"<<endl;
        if(mode)
        cout << "Press 4 to see your Monetary Graph" << endl;
        else
        cout << "Press 4 to see the stock price graph" << endl;
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 1:
            cout << "Enter the value you want to invest";
            int investment;
            cin >> investment;
            if(investment>liquidMoney)
            {
                cout << "You do not have enough money";
                sleepMilliseconds(1000);
            }
            else
            {
                int tempMoney = investment;
                float tempStocks = (float)investment/Value;
                cout << "You will get "<<tempStocks<< "Stocks" <<endl;
                cout << "Press y to continue or any other button to not go further" <<endl;
                char choice;
                cin >> choice;
                if(choice == 'y')
                {
                liquidMoney -= tempMoney;
                noOfStocks += tempStocks;
                }

            }
            valueChart[size(valueChart)] = (Value*noOfStocks);
            clearScreen();
            if(mode)
            A.editGraph(x,y);
            else
            A.editGraph(x,valueChart);
            A.plotGraph();
            goto label;
            break;


            case 2:
            cout << "Enter How many stocks you want to sell?";
            float tempsell;
            cin >> tempsell;
            if(tempsell>noOfStocks)
            {
                cout << "You do not have enough stocks";
                sleepMilliseconds(1000);
            }
            else
            {
            cout << "You will get back " << tempsell*Value<<endl;
            cout << "Press y to continue or any other button to not go further" <<endl;
            char choice;
            cin >> choice;
            if(choice == 'y')
            {
            liquidMoney += tempsell*Value;
            noOfStocks -= tempsell;
            
            }
            valueChart[size(valueChart)] = (Value*noOfStocks);
            clearScreen();
            if(mode)
            A.editGraph(x,y);
            else
            A.editGraph(x,valueChart);
            A.plotGraph();
            goto label;
            break;
            
            }
            case 3:
            cout << "How many days do you want to move?";
            int skip;
            cin >> skip;
            for(int i=0;i<skip;i++)
            {
                clearScreen();
                //Generating Value for next stock
                int diff = generateRandomNumber(-difficulty,difficulty);
                Value = starting+soleForX(count);
                valueChart.push_back(Value*noOfStocks+liquidMoney);
                y.push_back(Value);
                count ++;
                string temp = intToTwoDigitString(count);
                x.push_back(temp);
                if(mode)
                    A.editGraph(x,y);
                else
                    A.editGraph(x,valueChart);
                A.plotGraph();
                sleepMilliseconds(100);
            }
            
            goto label;
            case 4:
            clearScreen();
            if(mode)
            {
                A.editGraph(x,valueChart);
                mode = !mode;
            }
            else
            {
                A.editGraph(x,y);
                mode = !mode;
            }
            A.plotGraph();
            goto label;
            break;

        }
    }
};

int main()
{
    Practice_mode prac;
    prac.start();
}
//The user class will inherit 