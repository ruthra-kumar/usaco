/*
ID:ruthrab1
LANG:C++
TASK:prefix
PROG:prefix
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#define chars 26
#define max_seq 200000+50
using namespace std;

bool s[max_seq];

void init()
{
    for(size_t i=0;i<max_seq;i++)
    {
        s[i] = 0;
    }
}

int main(int argc,char *argv[])
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    string spart,primitive;
    string sequence;
    vector<string> primitives;

    while(true)
    {
        fin >> primitive;
        if(primitive == ".")
        {
            break;
        }
        else
        {
            //build a trie graph
            //build_trie(primitive);
            primitives.push_back(primitive);
        }
    }
    while(fin >> spart)
    {
        sequence.append(spart);
    }

    init();
    s[0] = 1;
    for(size_t i=0;i<sequence.size();i++)
    {
        for(size_t j=0; j<primitives.size();j++)
        {
            size_t k;
            for(k=0; i+k<sequence.size() && s[i] && primitives[j][k] == sequence[i+k];k++);

            if(k == primitives[j].size()) s[i+k]=1;
        }
    }

    size_t best = max_seq;
    for(;best >= 0 && !s[best];best--);

    fout << best << '\n';

    fin.close();
    fout.close();
    return 0;
}

