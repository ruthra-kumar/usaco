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
#define MAX_HEIGHT  17
using namespace std;

int N;
// one based indexing
int Elevations[MAX_HILLS+1];
int HighPoint,LowPoint;
int Highest =   -1,Lowest    =   101;
bool Modified[MAX_HILLS+1];

void Print()
{
    for(int i=1;    i   <=  N;  i++)
    {
        cout    <<  Elevations[i]   <<  "\t";
    }
    cout    <<  '\n';

    for(int i=1;    i   <=  N;  i++)
    {
        cout    <<  Modified[i] <<  "\t";
    }
    cout    <<  '\n';
}

int Modify_Hill(void)
{
    int cost    =   0;

    //cout    <<  Highest <<  " " <<  Lowest  <<  '\n';
    //modify the hills
    if(  Modified[Highest]    ==  0   &&    Modified[LowPoint]   ==  0  )
    {
        if(  ( (Highest -   Lowest )   -   MAX_HEIGHT  )%2 !=  0)
        {
            cost    +=  pow( ( (Highest -   Lowest )   -   MAX_HEIGHT  )/2+1,2);
            cost    +=  pow( ( (Highest -   Lowest )   -   MAX_HEIGHT  )/2-1,2);

            Elevations[HighPoint]   -=  ( (Highest -   Lowest )   -   MAX_HEIGHT  )/2+1;
            Elevations[LowPoint]   +=  ( (Highest -   Lowest )   -   MAX_HEIGHT  )/2-1;
        }
        else
        {
            cost    +=  pow(    (  (Highest    -   Lowest) -   MAX_HEIGHT    )/2,2) *   2;
            Elevations[HighPoint]   -=  ( (Highest -   Lowest )   -   MAX_HEIGHT  )/2;
            Elevations[LowPoint]   +=  ( (Highest -   Lowest )   -   MAX_HEIGHT  )/2;
        }
        Modified[HighPoint] =   Modified[LowPoint]  =   1;
    }
    else
    {
        //if Highest hill is not modified
        if( Modified[HighPoint] ==  0 )//&& Modified[Lowest]   ==  1)
        {
            cost    +=  pow(    (Highest-Lowest)-MAX_HEIGHT,2    );
            Elevations[HighPoint] -=  (Highest-Lowest)-MAX_HEIGHT;

            //Update Modified
            Modified[HighPoint] =   1;
        }
        else    if(Modified[LowPoint]   ==  0   )//&&  Modified[HighPoint] ==  1)
        {
            cost    +=  pow(    (Highest-Lowest)-MAX_HEIGHT,2    );
            Elevations[LowPoint]    +=  (Highest-Lowest)-MAX_HEIGHT;

            //Update Modified
            Modified[LowPoint]  =   1;
        }
        else{
            cout    <<  Highest <<  " " <<  Lowest  <<  '\n';
            Print();
            cin.get();
        }
    }

    //Update highest and lowest hills
    Highest =   -1;
    Lowest  =   101;
    for(int i=1;    i   <=  N;  i++)
    {
        if( Elevations[i]   >   Highest )
        {
            Highest =   Elevations[i];
            HighPoint =   i;
        }

        if(Elevations[i]    <   Lowest  )
        {
            Lowest  =   Elevations[i];
            LowPoint  =   i;
        }
    }

    return  cost;
}

int solve(void)
{
    int Total   =   0;
    while(Highest  -   Lowest  >   MAX_HEIGHT)
    {
        Total   +=  Modify_Hill();
        //cout    <<  Total   <<  '\n';
    }

    //if hills come under law no modification cost
    return Total;
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
