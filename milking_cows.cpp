/*
ID  : ruthrab1
TASK: milk2
PROG: milk2
LANG: C++
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#define llt long long int
#define newline cout<<'\n';
#define debug(x) cout<<"__DEBUG__"<<x<<'\n'
using namespace std;
struct node{
    llt Start,End;

    bool operator<(const node &r) const{
        if(Start == r.Start){
            return End<r.End;
        }
        return Start<r.Start;
    }
};


int main(int argc,char **argv){
    llt n,x,y,Max,Min,t;
    vector<node> lst;

    fstream fin("milk2.in",ios::in),fout("milk2.out",ios::out);
    fin>>n;

    Max = 0,Min = 0;
    for(llt i=0;i<n;i++){
        fin>>x>>y;
        node new_node;
        new_node.Start = x;
        new_node.End = y;
        lst.push_back(new_node);
    }

    sort(lst.begin(),lst.end());
    int l;
    for(int i=0;i<n;i++){
        t = lst[i].End - lst[i].Start;
        l = i;
        for(int j=i+1;j<n;j++){
            if(lst[j].Start <= lst[l].End){
                if(lst[j].End >= lst[l].End){
                    t += (lst[j].End - lst[l].End);
                    l = j;
                }
            }
            else{
                l = j;
                if(t >= Max){
                    Max = t;
                }
                t = 0;
            }
        }
        if(t >= Max){
            Max = t;
        }
    }
    int j,i = 0;
    j = i+1;
    while(j<n){
        if(lst[j].Start > lst[i].End){
            if((lst[j].Start - lst[i].End) > Min){
                Min = lst[j].Start - lst[i].End;
            }
            i = j;
        }
        else{
            if(lst[j].End >= lst[i].End) i = j;
        }
        j++;
    }

    fout<<Max<<" "<<Min<<'\n';

    fin.close();
    fout.close();
    return 0;
}
