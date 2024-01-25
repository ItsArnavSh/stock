#include <iostream>
#include <iomanip>//for setw
using namespace std;
int main()
{
    int sample[30]={200,210,220,230,260,290,300,290,290,260,270,300,310,230,220,210,210,200,190,211,234,254,211,211,211,245,250,290,320,300};
    int sampleLength = 30;
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