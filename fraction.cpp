/*
ID  : ruthrab1
TASK: frac1
PROG: frac1
LANG: C++
*/
#include    <fstream>
#include    <iostream>
#include    <utility>
#include    <vector>
#include    <list>
#include    <algorithm>
using namespace std;
struct  Frac
{
    int num,den;
    float   val;
};
Frac    tmp;
struct  pred
{
    Frac    a;
    pred(const  Frac    &b) :   a(b){}

    bool    operator()(const  Frac    &b)
    {
        return  (a.val   <   b.val);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    //vector< pair<pair<int,int>,float> >   Fractions;
    //vector<Frac>   Fractions;
    list<Frac>  Fractions;
    vector<float>   buffer;
    int n;
    float   frac    =   0.0;
    //cin >>  n;
    fstream fin("frac1.in",ios::in);
    fin >>  n;
    fin.close();

    for(int i=0;i<=n;i++)
    {
        for(int j=n;(j>=i);j--)
        {
            frac    =   (float)i/(float)j;
            if(frac >=  0   &&  frac    <=  1   )
            {
                tmp.num =   i;
                tmp.den =   j;
                tmp.val =   frac;
                list<Frac>::iterator it  =   find_if(Fractions.begin(),Fractions.end(),pred(tmp));
                if( it  !=  Fractions.end())
                {
                    //add before found element
                    if(find(buffer.begin(),buffer.end(),tmp.val)    ==  buffer.end())
                    {
                        Fractions.insert(it,tmp);
                        buffer.push_back(tmp.val);
                    }
                }
                else
                {
                    //add to the end
                    if(find(buffer.begin(),buffer.end(),tmp.val)    ==  buffer.end())
                    {
                        Fractions.push_back(tmp);
                        buffer.push_back(tmp.val);
                    }
                }
            }
        }
    }
    fstream fout("frac1.out",ios::out);
    for(Frac f  :   Fractions)
    {
        //cout    <<  f.num   <<  "/" <<  f.den   <<  '\n';   //<<  " -> "  <<  f.val  <<'\n';
        fout    <<  f.num   <<  "/" <<  f.den   <<  '\n';   //<<  " -> "  <<  f.val  <<'\n';
    }
    fout.close();

    return 0;
}
