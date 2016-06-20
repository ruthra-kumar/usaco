/*
ID: ruthrab1
LANG: C++
TASK: palsquare
PROB: palsquare

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
typedef int BASE;
//returns a string of characters that denote the num in new 'base'
string decimal_to_base(long long num,BASE base,vector<char> &Digits)
{
    string new_digits,Rev;

    //digits will be obtained in reverse order
    while(num)
    {
        new_digits += Digits[(num%base)];
        num/=base;
    }
    //copy(new_digits.crbegin(),new_digits.crend(),back_inserter(Rev));
    //Implementing copy manually
    /*for(unsigned int i=new_digits.size(); i>=0 ; i--)
    {
        Rev += new_digits.at(i);
    }
    */
    for(reverse_iterator<string::iterator> rev = new_digits.rbegin(); rev != new_digits.rend(); rev++)
    {
        Rev += *rev;
    }

    return Rev;
}

//returns true if given number is a palindrome
bool Palindrome(long long N,BASE B,vector<char> &D)
{
    string original,reversed;
    original = decimal_to_base(N,B,D);

    //copy(original.crbegin(),original.crend(),back_inserter(reversed));
    //Manual implementation of above copy code
    for(reverse_iterator<string::iterator> rev = original.rbegin(); rev != original.rend(); rev++)
    {
        reversed += *rev;
    }

    return (original == reversed);
}

int main(int argc,char *argv[])
{
    char dts[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K'};
    //vector initalization using above array for c++03 standard compiler to work
    vector<char> digits(dts,(dts+sizeof(dts)/sizeof(char)));
    BASE to_base;
    fstream fin("palsquare.in",ios::in),fout("palsquare.out",ios::out);

    fin>>to_base;

    fin.close();
    for(int i=1;i<=300;++i)
    {
        if(Palindrome(i*i,to_base,digits))
        {
            fout<<decimal_to_base(i,to_base,digits)<<" "<<decimal_to_base(i*i,to_base,digits)<<'\n';
        }
    }

    fout.close();

    return 0;
}
