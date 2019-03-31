/*
ID:ruthrab1
LANG:C++
TASK:lamps
PROG:lamps
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#define N 100
using namespace std;

struct{
    bool operator()(bitset<N> a,bitset<N> b)
    {
        for(int i=0;i<a.size();)
        {
            if(a[i] == b[i])
            {
                i++;
            }
            else if(a[i] < b[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
} compare_bitset;

vector<int> on,off;
vector<bitset<N>> valid_matches;

bool is_valid(bitset<N> cur_lmp)
{
    for(auto &x:on)
    {
        if(cur_lmp[x-1] != 1)
        {
            return false;
        }
    }

    for(auto &y:off)
    {
        if(cur_lmp[y-1] != 0)
        {
            return false;
        }
    }

    return true;
}

bool compare(bitset<N> &a, bitset<N> &b, int limit)
{
    for(int i=0;i<limit;i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

bool present(bitset<N> &lmp,int no)
{
    for(auto &x:valid_matches)
    {
        if(compare(x,lmp,no))
            return true;
    }
    return false;
}

void print(bitset<N> &lmp)
{
    cout << lmp.to_string();
    cout << '\n';
}

void press_but(bitset<N> &cur_lmp,int but)
{
    switch(but)
    {
    case 1:
        cur_lmp.flip();
        break;
    case 2:
        for(int i=0;i<cur_lmp.size();i+=2)
        {
            cur_lmp.flip(i);
        }
        break;
    case 3:
        for(int i=1;i<cur_lmp.size();i+=2)
        {
            cur_lmp.flip(i);
        }
        break;
    case 4:
        for(int i=0;i<cur_lmp.size();i+=3)
        {
            cur_lmp.flip(i);
        }
    break;
    default:break;
    }
}

int main(int argc,char *argv[])
{
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    bitset<N> lmps;
    int n,c,f_lamp_pos;
    fin >> n >> c ;
    fin >> f_lamp_pos;
    while(f_lamp_pos != -1)
    {
        on.push_back(f_lamp_pos);
        fin >> f_lamp_pos;
    }
    fin >> f_lamp_pos;
    while(f_lamp_pos != -1)
    {
      off.push_back(f_lamp_pos);
      fin >> f_lamp_pos;
    }

    lmps.flip();
    if(c == 0)
    {
        if(is_valid(lmps) && !present(lmps,n))
            valid_matches.push_back(lmps);
    }
    else if(c == 1)
    {
        for(int i=1;i<=4;i++)
        {
            lmps.set();
            press_but(lmps,i);
            if(is_valid(lmps) && !present(lmps,n))
                valid_matches.push_back(lmps);
        }

    }
    else
    {
        int butns[4];
        for(int i=0;i<2;i++)
        {
            butns[0] = i;
            for(int j=0;j<2;j++)
            {
                butns[1] = j;
                for(int k=0;k<2;k++)
                {
                    butns[2] = k;
                    for(int l=0;l<2;l++)
                    {
                        butns[3] = l;

                        //do all operations
                        bitset<N> str_lmp;
                        str_lmp.flip();
                        for(int op = 0;op < 4;op++)
                        {
                            if(butns[op])
                                press_but(str_lmp,(op+1));
                        }
                        if(is_valid(str_lmp) && !present(str_lmp,n))
                            valid_matches.push_back(str_lmp);

                    }
                }
            }
        }

    }

    if(valid_matches.empty())
    {
        fout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        sort(valid_matches.begin(),valid_matches.end(), compare_bitset);
        for(auto &x:valid_matches)
        {
            for(size_t i=0;i<n;i++)
            {
                fout << x[i];
            }
            fout << '\n';
        }
    }

    fin.close();
    fout.close();
    return 0;
}

