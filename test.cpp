#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
//The purpose of this graph is to save and plot data
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
    //There are 15 points in y axis (say)
    float step = range/15;
    float yAxis=max;
    cout << endl;
    //A step is the difference between any two consecutive y index values
    for(int i=0;i<18;i++)//Going 18 instead of 15 to show the min val
    {
        cout << setw(5)<<yAxis<<"| ";
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
int main()
{
    graph test("imp.csv");
    test.generateData();
    test.plotGraph();
}
