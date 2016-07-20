/*
ID  : ruthrab1
TASK: barn1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    fstream fin("barn1.in",ios::in),fout("barn1.out",ios::out);
    long long int Groups,tmp,M,S,C,Prev;
    vector<int> Gaps,Locations;
    bool Started = 0;
    Groups = 0;
    fin >>  M   >>  S   >>  C;
    for(long long int i = 0; i < C ; i++)
    {
        fin >>  tmp;
        Locations.push_back(tmp);
    }

    sort(Locations.begin(),Locations.end());
    for(unsigned int i =0; i < Locations.size(); i++)
    {
        //Calculate the length of each Gap
        if(Started)
        {
            //Non-Consecutive Locations
            if( ( Locations[i] - Prev ) != 1 )
            {
                Gaps.push_back(Locations[i] - Prev - 1);
                Groups++;
            }
        }
        else    Started = 1;

        Prev = Locations[i];
    }

    //Groups are always one higher than gaps so increment Groups
    Groups++;

    //If sufficient doors print stalls with cows
    if(Groups <= M) fout    <<  C   <<'\n';
    //If Not sufficient doors
    else
    {
        //Sort the gaps to get least possible gap
        sort(Gaps.begin(),Gaps.end());

        //Add stalls that are not having cows based on how big that gap is
        for(long long int i = 0; i < (Groups - M);i++)
        {
            C += Gaps[i];
        }
        fout    <<  C   <<  '\n';
    }


    return 0;
}
