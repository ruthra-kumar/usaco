/*
ID  : ruthrab1
TASK: hamming
PROG: hamming
LANG: C++
*/

#include    <iostream>
#include    <fstream>
#include    <bitset>

#define SIZE    256
using namespace std;

int n,b,d;
int hamming_code[SIZE];
int code_found  =   1;

bool    satisfy_haming_code(int    x)
{
    for(int i=0;i<code_found;i++)
    {
        int tmp =   (hamming_code[i] ^   x);
        bitset<8>   diff(tmp);

        if(diff.count() <  d)
        {
            return  false;
        }
    }
    return  true;
}

int main()
{
    fstream fin("hamming.in",ios::in),fout("hamming.out",ios::out);
    fin >>  n   >>  b   >>  d;
    fin.close();
    for(int i=1;(i<=SIZE)  &&  (code_found  !=  n);i++)
    {
        if(satisfy_haming_code(i))
        {
            hamming_code[code_found++]  =   i;
        }
    }

    for(int i=1;i<=code_found;i++)
    {
        fout    <<  hamming_code[i-1];
        if((i%10)   ==  0   ||  (i==code_found))
        {
            fout    <<  '\n';
        }
        else
        {
            fout    <<  " ";
        }
    }
    fout.close();

    return 0;
}
