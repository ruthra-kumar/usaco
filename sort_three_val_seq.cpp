/*
ID  : ruthrab1
TASK: sort3
PROG: sort3
LANG: C++
*/
#include    <iostream>
#include    <algorithm>
#include    <vector>
#include    <cstdlib>
#include    <utility>
#include    <fstream>

#define RANGE   3
using namespace std;

int NIP[RANGE][RANGE];
vector<int> seq,sorted;

int XinYPlace(int x,int y)
{
    int cnt =   0;
    for(unsigned int i=0;i<sorted.size();i++)
    {
        if((sorted[i]    ==  y)  &&  (seq[i]  ==  x))
        {
            cnt++;
        }
    }
    return  cnt;
}

int Max(int x,int y)
{
    return  (x  >   y)?x:y;
}
int Min(int x,int y)
{
    return  (x  <   y)?x:y;
}

int main(int argc,char *argv[])
{
    int N,tmp,totalexchange =   0;

    int min01   =   0,min12 =   0,min02 =   0;
    cin >>  N;

    for(int i=0;i<N;i++)
    {
        cin >>  tmp;
        seq.push_back(tmp);
    }
    sorted  =   seq;

    sort(sorted.begin(),sorted.end());

    for(int i=1;i<=RANGE;i++)
    {
        for(int j=1;j<=RANGE;j++)
        {
            if(i    !=  j)
            {
                NIP[i-1][j-1] =   XinYPlace(i,j);
            }
        }
    }

    if(NIP[0][1]    !=  0   &&  NIP[1][0]   !=  0)
    {
        min01   =   Min(NIP[0][1],NIP[1][0]);
        NIP[0][1]   =   NIP[0][1]   -   min01;
        NIP[1][0]   =   NIP[1][0]   -   min01;
    }

    if(NIP[1][2]    !=  0   &&  NIP[2][1]   !=  0)
    {
        min12   =   Min(NIP[1][2],NIP[2][1]);
        NIP[1][2]   =   NIP[1][2]   -   min12;
        NIP[2][1]   =   NIP[2][1]   -   min12;
    }

    if(NIP[0][2]    !=  0   &&  NIP[2][0]   !=  0)
    {
        min02   =   Min(NIP[0][2],NIP[2][0]);
        NIP[0][2]   =   NIP[0][2]   -   min02;
        NIP[2][0]   =   NIP[2][0]   -   min02;
    }

    int Sum     =   0;
    for(int i=1;i<=RANGE;i++)
    {
        for(int j=1;j<=RANGE;j++)
        {
            Sum +=  NIP[i-1][j-1];
        }
    }

    totalexchange   =   min01   +   min02   +   min12   +   ((Sum/3)*2);

    cout    <<  totalexchange   <<  '\n';

    return 0;
}
