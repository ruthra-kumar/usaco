/*

ID  :   ruthrab1
TASK:   namenum
PROG:   namenum
LANG:   C++

*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

class Ifequal{
    private:
    unsigned long int n;
    vector<string> keypad;

    public:
    Ifequal(unsigned long int a):n(a){
        keypad.push_back("ABC2"),
        keypad.push_back("DEF3"),
        keypad.push_back("GHI4"),
        keypad.push_back("JKL5"),
        keypad.push_back("MNO6"),
        keypad.push_back("PRS7"),
        keypad.push_back("TUV8"),
        keypad.push_back("WXY9");
    }

    void operator()(string &a){
        long long int num=0,multiplier=10;
        for(string::iterator i=a.begin();i!=a.end();++i){
            for(vector<string>::iterator j=keypad.begin();j!=keypad.end();++j){
                string str = *j;
                if(find(str.begin(),str.end(),*i) != str.end()){
                    num = ((str.at(str.size()-1))-48)+(num*multiplier);
                }
            }
        }
        if(num == n) cout<<a<<'\n';
    }
};


int main(int argc,char *argv[]){
    fstream dictionary("namenumdict.txt",ios::in);
    string tmp;
    vector<int> cowcode;
    vector<string> dict;
    unsigned long int num,rev=0,len=0;
    cin>>num;
    Ifequal Equal(num);

    while(num){
        rev = (num%10) + rev*10;
        num/=10;
        len++;
    }
    num=rev;
    while(num){
        cowcode.push_back(num%10);
        num/=10;
    }

    while(!dictionary.eof()){
        dictionary>>tmp;
        if(tmp.size() == len){
            dict.push_back(tmp);
        }
    }
    dictionary.close();

    for_each(dict.begin(),dict.end(),Equal);

    return 0;
}
