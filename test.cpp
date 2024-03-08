#include <iostream>
#include <iomanip>//for setw
using namespace std;
int main()
{
    int sample[19]={174,179,183,198,200,204,200,204,192,195,194,193,196,202,189,185,192,190,189};
    int sampleLength = 19;
    int min=sample[0],max=sample[0];
    for(int i=0;i<sampleLength;i++)
    {
        if(sample[i]>max)
            max = sample[i];
        if(sample[i]<min)
            min = sample[i];
    }
    int range = max-min;
    //There are 15 points in y axis (say)
    int step = range/15;
    int y=max;
    //A step is the difference between any two consecutive y index values
    for(int i=0;i<18;i++)//Going 18 instead of 15 to show the min val
    {
        cout << y << "|";
        for(int j=0;j<sampleLength;j++)
        {
            if(sample[j]>=y)
                cout << " HH ";
            else
             cout << "    ";
        }
        y-=step;
        cout << endl;
    }
    cout << "   |";
  
    for(int i=1;i<=30;i++)
    {
        cout << "____";
    }
    cout << endl;
    cout << "     ";
    for(int i=1;i<=30;i++)
    {
        cout << setw(2)<<i<<"  ";
    }
    cout <<endl;
}