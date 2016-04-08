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
        //Keypad stores the key value in which they appear for ease of access 
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
        for(string::iterator i=a.begin();i!=a.end();++i){                   //go through each character of string
            for(vector<string>::iterator j=keypad.begin();j!=keypad.end();++j){ //loop through each key in keypad
                string str = *j;
                if(find(str.begin(),str.end(),*i) != str.end()){        //if character is prsent in key add that digit to value
                    num = ((str.at(str.size()-1))-48)+(num*multiplier); //code to add a digit to the generated number
                }
            }
        }
        if(num == n) cout<<a<<'\n'; //if generated number equals the given number print
    }
};


int main(int argc,char *argv[]){
    fstream dictionary("namenumdict.txt",ios::in);
    string tmp;
    vector<string> dict;
    unsigned long int num,rev=0,len=0;
    cin>>num;
    Ifequal Equal(num);
    
    //reverse the number provided
    while(num){
        rev = (num%10) + rev*10;
        num/=10;
        len++;      //length of number
    }
    num=rev;
    //only get words with same length as number
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
