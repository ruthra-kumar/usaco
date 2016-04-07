/*

ID  :   ruthrab1
TASK:   namenum
PROG:   namenum
LANG:   C++

*/

/* TODO
    Make the program more memory effecient
    use "a gram here and there" method

*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

vector<string> possibilities;
fstream fin,fout,dict;
bool found = false;
long long int nn;
vector<string> keypad;

class Equal{
    public:
    Equal(){}

    void operator()(const string &a){

        long long int num=0,multiplier=10;
        for(unsigned int j=0;j<a.size();++j){
            for(unsigned int i=0;i<keypad.size();++i){
                string str = keypad.at(i);
                if(find(str.begin(),str.end(),a.at(j)) != str.end()){
                    num = ((str.at(str.size()-1))-48)+(num*multiplier);
                }
            }
        }
        if(num == nn){
            if(!found) found = true;
            fout<<a<<'\n';
        }

    }
};

int main(int argc,char *argv[]){

    fin.open("namenum.in",ios::in),fout.open("namenum.out",ios::out);
    dict.open("dict.txt",ios::in);

    keypad.push_back("ABC2"),
                    keypad.push_back("DEF3"),
                    keypad.push_back("GHI4"),
                    keypad.push_back("JKL5"),
                    keypad.push_back("MNO6"),
                    keypad.push_back("PRS7"),
                    keypad.push_back("TUV8"),
                    keypad.push_back("WXY9");

    long long int n,multiplier=10,cowcode=0;
    unsigned int len = 0;
    vector<int> code;
    vector<string> dictionary;
    string ss;
    fin>>n;
    nn = n;
    fin.close();

    while(n){
        cowcode=((n%10)+(cowcode*multiplier));
        n/=10;
        len++;
    }
    n=cowcode;
    while(n){
        code.push_back((n%10));
        n/=10;
    }

    while(!dict.eof()){
        dict>>ss;
        if(ss.size() == len )dictionary.push_back(ss);
    }
    dict.close();
    for_each(dictionary.begin(),dictionary.end(),Equal());

    if(!found) fout<<"NONE"<<'\n';

    dict.close();
    fout.close();
    return 0;
}
