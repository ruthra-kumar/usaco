/*
ID: ruthrab1
LANG: C++
TASK: dualpal
PROB: dualpal
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;

//returns true if Palindrome and false otherwise
bool Palindrome(long long num)
{
    long long tmp,n1=0,multiplier=10;
    tmp = num;

    while(tmp)
    {
        n1 = (n1*multiplier)+(tmp%10);
        tmp/=10;
    }

    return (num == n1);
}

//return a list of numbers in bases ranging [2-10]
vector<long long> Convert_to_bases(long long int Num)
{
    vector<long long> new_bases;
    for(int Base=2; Base<=10; ++Base)
    {
        int Multiplier = 10;
        long long tmp,N1 = 0;
        tmp = Num;
        stack<int> digits;

        //genrating new base using stack 
        while(tmp)
        {
            digits.push(tmp%Base);
            tmp/=Base;
        }
        while(!digits.empty())
        {
            N1 = (N1*Multiplier)+digits.top();
            digits.pop();
        }

        new_bases.push_back(N1);
    }
    return new_bases;
}

//returns true if a double plaindrome
bool Doublepal(vector<long long> NB)
{
    int Cnt = 0;
    for(vector<long long>::iterator iter = NB.begin(); iter != NB.end() ; iter++)
    {
        if(Palindrome(*iter)){
            Cnt++;
        }
        if(Cnt >= 2) return true;
    }
    return false;
}

int main(int argc,char *argv[])
{
    long long N,S,cnt=0;
    fstream fin("dualpal.in",ios::in),fout("dualpal.out",ios::out);
    fin>>N>>S;

    for(long long i=S+1; ; ++i)
    {

        if(Doublepal(Convert_to_bases(i)))
        {
            fout<<i<<'\n';
            cnt++;
        }

        if(cnt >= N) break;

    }

    return 0;
}
