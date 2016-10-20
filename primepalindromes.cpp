/*
ID  :   ruthrab1
TASK:   pprime
PROG:   pprime
LANG:   C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>  palin;

void Gen3()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            long long int   Palindrome  =   100*d1  +   10*d2   +   d1;
            palin.push_back(Palindrome);
        }
    }
}

void Gen4()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            long long int   Palindrome  =   1000*d1  +   100*d2 +   10*d2   +   d1;
            palin.push_back(Palindrome);
        }
    }
}

void Gen5()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            for(int d3  =   0;  d3  <=  9;  d3++)
            {
                long long int   Palindrome  =   10000*d1  +   1000*d2 +   100*d3   + 10*d2   +   d1;
                palin.push_back(Palindrome);
            }
        }
    }
}

void Gen6()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            for(int d3  =   0;  d3  <=  9;  d3++)
            {
                long long int   Palindrome  =   100000*d1  +   10000*d2 +   1000*d3    +    100*d3    + 10*d2   +   d1;
                palin.push_back(Palindrome);
            }
        }
    }
}

void Gen7()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            for(int d3  =   0;  d3  <=  9;  d3++)
            {
                for(int d4  =   0;  d4  <=  9;  d4++)
                {
                    long long int   Palindrome  =   1000000*d1  +   100000*d2 +   10000*d3    +    1000*d4    + 100*d3   + 10*d2   +   d1;
                    palin.push_back(Palindrome);
                }
            }
        }
    }
}

void Gen8()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            for(int d3  =   0;  d3  <=  9;  d3++)
            {
                for(int d4  =   0;  d4  <=  9;  d4++)
                {
                    long long int   Palindrome  =   10000000*d1  +   1000000*d2 +   100000*d3    +    10000*d4    + 1000*d4   + 100*d3  +   10*d2   +   d1;
                    palin.push_back(Palindrome);
                }
            }
        }
    }
}

void Gen9()
{
    for(int d1  =   1;  d1  <=  9;  d1+=2)  //Only Odd are allowed
    {
        for(int d2  =   0;  d2  <=  9;  d2++)
        {
            for(int d3  =   0;  d3  <=  9;  d3++)
            {
                for(int d4  =   0;  d4  <=  9;  d4++)
                {
                    for(int d5  =   0;  d5  <=  9;  d5++)
                    {
                        long long int   Palindrome  =   100000000*d1  +   10000000*d2 +   1000000*d3    +    100000*d4    + 10000*d5   + 1000*d4  +   100*d3   +   10*d2    +   d1;
                        palin.push_back(Palindrome);
                    }
                }
            }
        }
    }
}

void GenRemain(int  num)
{
    switch(num)
    {
        case 3:
        Gen3();
        break;
        
        case 4:
        Gen3();
        Gen4();
        break;
        
        case 5:
        Gen3();
        Gen4();
        Gen5();
        break;
        
        case 6:
        Gen3();
        Gen4();
        Gen5();
        Gen6();
        break;
        
        case 7:
        Gen3();
        Gen4();
        Gen5();
        Gen6();
        Gen7();
        break;
        
        case 8:
        Gen3();
        Gen4();
        Gen5();
        Gen6();
        Gen7();
        Gen8();
        break;
        
        case 9:
        Gen3();
        Gen4();
        Gen5();
        Gen6();
        Gen7();
        Gen8();
        Gen9();
        break;
        
        default:break;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    fstream fin("pprime.in",ios::in);   
    int len =   0;
    long    long    int a,b;
    
    int digits_upper,digits_lower;
    long long int tmp =   a;
    fin >>  a>> b;
    while(tmp)
    {
        len++;
        tmp/=10;
    }
    digits_lower    =   len;
    len =   0;
    
    tmp =   b;
    while(tmp)
    {
        len++;
        tmp/=10;
    }
    digits_upper    =   len;
    
    //One and Two digits
    for(int i=2;i<100;i++)
    {
        if(i    >=  10   && i   <=  99)
        {
            if(i/10 ==  i%10)
            {
                palin.push_back(i);
            }
        }
        else
            palin.push_back(i);
    }
    
    GenRemain(digits_upper);
    sort(palin.begin(),palin.end());
    
    fstream fout("pprime.out",ios::out);
    
    for(unsigned int i=0;   i   <   palin.size();   i++)
    {

        if(palin[i] >=  a   &&  palin[i]    <=  b)
        {
            bool Prime  =   true;
            for(int j=2;    j   <=  sqrt(palin[i]); j++)
            {
                if(palin[i]%j   ==  0)
                {
                    Prime   =   false;
                    break;
                }
            }
            
            if(Prime)
                fout    <<  palin[i]    <<  '\n';
            
        }
    }
    fout.close();
    return 0;
}
