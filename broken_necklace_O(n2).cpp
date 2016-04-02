/*
ID  : ruthrab1
TASK: beads
PROG: beads
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
#define newline cout<<'\n';
using namespace std;

int nfbeads(string s,int sp,bool dir){
    int i,l;
    if(dir){
        char c = s.at(sp);
        l = (sp%s.size());
        for(i=0;i<s.size();i++){
            if(c == 'w' && s[l] != 'w'){
                c = s[l];
            }
            if(s[l] != c && s[l] != 'w'){
                break;
            }
            sp++;
            l = (sp%s.size());
        }
    }
    else{
        l = (s.size() + --sp)%s.size();
        char c = s.at(l);
        for(i=0;i<s.size();i++){
            if(c == 'w' && s[l] != 'w'){
                c = s[l];
            }
            if(s[l] != c && s[l] != 'w'){
                break;
            }
            sp--;
            l = (s.size()+sp)%s.size();
        }
    }
    return i;
}

int main(int argc,char **argv){
    int n,maxx,nmax;
    fstream fin("beads.in",ios::in),fout("beads.out",ios::out);
    string str;
    fin>>n;
    fin>>str;
    maxx = 0;
    for(int i=0;i<str.size();i++){
        nmax = (nfbeads(str,i,0)+nfbeads(str,i,1));
        if(nmax >= maxx){
            maxx = nmax;
        }
    }
    if(maxx > str.size()){
        maxx = str.size();
    }
    fout<<maxx<<'\n';
    fin.close();
    fout.close();
    return 0;
}
