/*
ID  :   ruthrab1
TASK:   sprime
PROG:   sprime
LANG:   C++
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static const int    arr1[]  =   {2,3,5,7};
static const int    arr2[]  =   {1,3,5,7,9};

vector<int> first_digit(arr1,(arr1  +   sizeof(arr1)/sizeof(arr1[0])));
vector<int> other_digits(arr2,(arr2  +   sizeof(arr2)/sizeof(arr2[0])));

vector<long long    int> sprime;

bool ifPrime(long   long    int n)
{
    if(n    ==  1)  return  false;
    for(long    long    int i   =   2;  (i*i)   <=  n;    i++)
    {
        if(n%i  ==  0)
            return  false;
    }
    return  true;
}

void    GenSprime(int   digits,int  cur_digit,long  long    int cur_value)
{
    if(cur_digit   <=   digits)
    {
        
        if(cur_digit    ==  1)
        {
            for(unsigned int    i=0;    i   <   first_digit.size(); i++)
            {
                long    long    int nxt_value   =   (cur_value   *   10)  +   first_digit[i];
                if(ifPrime(nxt_value))
                {
                    GenSprime(digits,cur_digit+1,nxt_value);
                }
            }   
        }
        else
        {
            for(unsigned int    i=0;    i   <   other_digits.size(); i++)
            {
                long    long    int nxt_value   =   (cur_value   *   10)  +   other_digits[i];
                if(ifPrime(nxt_value))
                {
                    GenSprime(digits,cur_digit+1,nxt_value);
                }
            } 
        }
    }
    else
    {
        sprime.push_back(cur_value);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    fstream fin("sprime.in",ios::in);
    int n;
    fin >>  n;
    fin.close();
    GenSprime(n,1,0);
    
    fstream fout("sprime.out",ios::out);
    
    for(unsigned int    i=0;    i<sprime.size();    i++)
    {
        fout    <<  sprime[i]   <<  '\n';
    }
    
    fout.close();
    return 0;
}
