/*
ID  :   ruthrab1
TASK:   skidesign
PROG:   skidesign
LANG:   C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#define MAX_HILLS   1000
using namespace std;

int N;
// one based indexing
int Elevations[MAX_HILLS+1];
int HighPoint,LowPoint;
int Highest =   -1,Lowest    =   101;

int solve()
{
    int cost   =    1000000,  tmp =   1000000;
    //Generate all range
    for(int i=17;    i   <=  Highest   ;i++)
    {
        tmp =   0;
        for(int j=1;j   <=N;j++)
        {
            if(Elevations[j]    <=   i   &&  Elevations[j]   >=   i-17)
            {
                tmp += 0;
            }
            else if(Elevations[j]   >   i)
            {
                tmp += pow( (Elevations[j]-i)  ,2);
            }
            else if(Elevations[j]   <   i-17)
            {
                tmp += pow(    ((i-17)-Elevations[j]), 2);
            }
        }

        if(tmp  <   cost)   cost    =   tmp;
    }

    return cost;
}

int main()
{
    fstream fin("skidesign.in",ios::in);
    fin >>  N;
    for(int i=1;    i   <=  N;  i++)
    {
        fin >>  Elevations[i];
        if( Elevations[i]   >   Highest){
            Highest =   Elevations[i];
            HighPoint  =   i;
        }

        if(Elevations[i]    <   Lowest)
        {
            Lowest  =   Elevations[i];
            LowPoint   =   i;
        }
    }
    fin.close();



    fstream fout("skidesign.out",ios::out);
    fout    <<  solve() <<  '\n';
    fout.close();
    return 0;
}
