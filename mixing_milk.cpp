/*
ID  :   ruthrab1
TASK:   milk
PROG:   milk
LANG:   C++
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <fstream>

typedef long long int llt;

using namespace std;

//Comapare function object for the sorting algorithm to use
bool cmp(const pair<llt,llt> a, const pair<llt,llt> b)
{
    return (a.first < b.first);
}

int main()
{
    llt N,M,P,Q;
    llt Cost = 0;
    fstream fin("milk.in",ios::in),  fout("milk.out",ios::out);

    vector< pair<llt,llt>    > Farmers;

    fin >>  N   >>  M;

    for(    int i = 0;  i   <   M   ;   i++ )
    {
        fin >>  P   >>  Q;
        Farmers.push_back(  make_pair(P,Q)  );
    }

    //Sort based on the price
    sort(   Farmers.begin(),    Farmers.end(),  cmp  );


    //since the list is sorted get as much from each farmer
    pair<   llt,    llt> tmp;
    for(    vector< pair<llt,llt>   >::iterator   X   =   Farmers.begin() ;   X   !=  Farmers.end()   ;   X++    )
    {
        tmp = *X;
        if( N  ==   0)  break;
        if( tmp.second <= N )
        {
            Cost += (   tmp.first *   tmp.second );
            N -=    tmp.second;
        }
        else
        {
            Cost += (   tmp.first *   N   );
            N -=    N;
        }
    }

    fout    <<  Cost    <<  '\n';
    return 0;
}
