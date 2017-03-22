/*
ID  :   ruthrab1
TASK:   runround
PROG:   runround
LANG:   C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

bool uniq(unsigned long int num)
{
    vector<bool> digits(10,0);

    while(num)
    {
        if(digits[num%10]   ==  0   &&  (num%10 != 0))
        {
            digits[num%10]  =   1;
        }
        else
            return false;
        num/=10;
    }
    return true;
}

bool all_present(vector<char> vis,string n)
{
    for(unsigned int i=0;i<n.size();)
    {
        if(find(vis.begin(),vis.end(),n[i]) !=  vis.end())
        {
            i++;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool runaround(unsigned long int num)
{
    unsigned long int tmp   =   num;
    vector<char> visited;

    stack<char> s;

    while(tmp)
    {
        s.push((char)(48 + (tmp%10)));
        tmp/=10;
    }

    string n,n_copy;
    while(!s.empty())
    {
        n   +=  s.top();
        s.pop();
    }

    n_copy  =   n;
    for(int i=0;i<4;i++)
    {
        n   +=  n;
    }

    for(unsigned int i=(n[0]    -   48);i<n.size();)
    {

        if(find(visited.begin(),visited.end(),n[i]) ==  visited.end())
        {
            visited.push_back(n[i]);
            i   +=  (n[i]    -   48);
        }
        else
        {
            if(!all_present(visited,n_copy))
            {
                return false;
            }
            else
            {
                break;
            }
        }
    }

    return true;
}

int main()
{
    fstream fin("runround.in",ios::in);
    unsigned long int n =   1;

    fin >>  n;
    fin.close();
    n++;
    fstream fout("runround.out",ios::out);
    for(;   n   <   1000000000; ++n)
    {
        if(uniq(n))
        {
            if(runaround(n))
            {
                fout    <<  n  <<  '\n';
                break;
            }
        }
    }
    fout.close();
    return 0;
}
