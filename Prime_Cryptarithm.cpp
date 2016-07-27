/*
ID  : ruthrab1
TASK: crypt1
PROG: crypt1
LANG: C++
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool Prime(int d)
{
    if( d   ==  2   ||  d   ==  3   ||  d   ==  5   ||  d   ==  7 )
    {
        return true;
    }
    return false;
}

bool Valid(int i,vector<int> &d)
{
    int tmp = i;

    //if a zero is present or a digit is present which is not provided by user return false
    while(tmp)
    {
        if( (find(d.begin(),   d.end(), (tmp%10) ) ==  d.end() ) )  return false;
        tmp/=10;
    }
    return true;
}

//returns the length of the number
int Length(int n)
{
    int len =   0;

    while(  n   )
    {
        len++;
        n/=10;
    }

    return len;
}

int GetDigit(int    n,int   d)
{
    int len =   0;
    int digit;
    while(n)
    {
        digit = n%10;
        n/=10;
        len++;
        if(len  ==  d)  break;
    }
    return digit;
}

int main()
{
    fstream fin("crypt1.in",ios::in),  fout("crypt1.out",ios::out);
    vector<int> digits,valid_numbers;
    int N,tmp,cnt   =   0;
    //reading input
    fin >>  N;
    for(int i = 0;  i   <   N;  i++)
    {
        fin >>  tmp;
        digits.push_back(tmp);
    }
    fin.close();
    //Generating valid 3-digit numbers
    for( int    i=111;  i   <=  999 ;   i++)
    {
        if(Valid(i,digits)){
            valid_numbers.push_back(i);
        }
    }

    //generating all two digit numbers
    //for each valid 3-digit number
    for(unsigned int i=0;    i   <   valid_numbers.size(); i++)
    {
        for(unsigned int x=0;    x   <   digits.size();  x++)
        {
            //First digit of the 2-digit number
            //if partial product is equal to 3 digits
            if( ( Length( valid_numbers[i]    *   digits[x] )    ==  3) && Valid( (valid_numbers[i]    *   digits[x]),digits))
            {
                //cout    <<  digits[x]   <<  '\n';
                //if partial product is 3 digits
                //second digit of 2-digit number
                for(unsigned int y=0;    y   <   digits.size();  y++)
                {
                    if( ( Length(valid_numbers[i]    *   digits[y] ) ==  3 ) && Valid( (valid_numbers[i]    *   digits[y]),digits))
                    {
                        int DE = digits[x] + (digits[y] *   10);

                        if( Length( valid_numbers[i]    *   DE )    ==  4 )
                        {
                            if( Valid( (valid_numbers[i]    *   DE),digits )    )
                            {
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
    }

    fout    <<  cnt <<  '\n';

    fout.close();

    return 0;
}
