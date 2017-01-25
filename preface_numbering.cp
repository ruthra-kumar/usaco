/*
ID  : ruthrab1
TASK: preface
PROG: preface
LANG: C++
*/
#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

string  GetRomanChar(int n)
{
    int m,d,c,l,x,v,I;
    string  Roman;
    if((m    =   n/1000)   !=  0)
    {
        for(int i=0;i<m;i++)
        {
            Roman   +=  'M';
        }
        n   -=       m*1000;
    }
    //cout<<n<<" "<<Roman<<'\n';
    if((d  =   n/500)  !=  0)
    {
        if(n    >=  900)
        {
            Roman   +=  "CM";
            n   -=  900;
        }
        else
        {
            for(int i=0;i<d;i++)
            {
                Roman   +=  'D';
            }
            n   -=  (d*500);
        }
    }
    //cout<<n<<" "<<Roman<<'\n';
    if((c  =   n/100)  !=  0)
    {
        if(n    >=  400)
        {
            Roman   +=  "CD";
            n   -=  400;
        }
        else
        {
            for(int i=0;i<c;i++)
            {
                Roman   +=  'C';
            }
            n   -=  (c*100);
        }
    }
    //cout<<n<<" "<<Roman<<'\n';
    if((l  =   n/50)   !=  0)
    {
        if(n    >=  90)
        {
            Roman   +=  "XC";
            n   -=  90;
        }
        else
        {
            for(int i=0;i<l;i++)
            {
                Roman   +=  'L';
            }
            n   -=  (l*50);
        }
    }
    //cout<<n<<" "<<Roman<<'\n';
    if((x  =   n/10)   !=  0)
    {
        if(n    >=  40)
        {
            Roman   +=  "XL";
            n   -=  40;
        }
        else
        {
            for(int i=0;i<x;i++)
            {
                Roman   +=  'X';
            }
            n   -=  (x*10);
        }
    }
    //cout<<n<<" "<<Roman<<'\n';
    if((v  =   n/5)    !=  0)
    {
        if(n    ==  9)
        {
            Roman   +=  "IX";
            n   -=  9;
        }
        else
        {
            for(int i=0;i<v;i++)
            {
                Roman   +=  'V';
            }
            n   -=  (v*5);
        }
    }
    //cout<<n<<" "<<Roman<<'\n';
    if((I   =   n/1)   !=  0   )
    {
        if(n    ==  4)
        {
            Roman   +=  "IV";
            n   -=  4;
        }
        else
        {
            for(int i=0;i<I;i++)
            {
                Roman   +=  'I';
            }
            n   -=  (I*1);
        }
    }
    //cout<<n<<" "<<Roman<<'\n';

    return  Roman;
}

int main()
{
    fstream fin("preface.in",ios::in),fout("preface.out",ios::out);

    int N;
    map<char,int>  total;
    total['I']   =   0;
    total['V']   =   0;
    total['X']   =   0;
    total['L']   =   0;
    total['C']   =   0;
    total['D']   =   0;
    total['M']   =   0;

    fin >>  N;
    fin.close();
    string  s;

    for(int i=1;i<=N;i++)
    {
        s   =   GetRomanChar(i);
        for(unsigned int i=0;i<s.size();i++)
        {
            total[s[i]]++;
        }
    }

    if(total['I']   >   0) fout    <<  "I " <<  total['I']   <<  '\n';
    if(total['V']   >   0) fout    <<  "V " <<  total['V']   <<  '\n';
    if(total['X']   >   0) fout    <<  "X " <<  total['X']   <<  '\n';
    if(total['L']   >   0) fout    <<  "L " <<  total['L']   <<  '\n';
    if(total['C']   >   0) fout    <<  "C " <<  total['C']   <<  '\n';
    if(total['D']   >   0) fout    <<  "D " <<  total['D']   <<  '\n';
    if(total['M']   >   0) fout    <<  "M " <<  total['M']   <<  '\n';
    fout.close();
    return 0;
}
