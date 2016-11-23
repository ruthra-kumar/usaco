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

#define SIZE 25600

using namespace std;
struct  Frac
{
    int num,den;
    float   val;
};

Frac a[SIZE];

bool pred(const Frac  &a,const  Frac  &b)
{
    if(a.val    <   b.val)  return  true;
    return  false;
}

int gcd(int p,int q)
{
    if(q    ==  0)  return  p;
    return  gcd(q,(p%q));
}

int main()
{
    ios_base::sync_with_stdio(false);
    fstream fin("frac1.in",ios::in);

    int n,index =   2;
    float   frac    =   0.0;
    //cin >>  n;

    a[0].num    =   0;
    a[0].den    =   1;
    a[0].val    =   0;

    a[1].num    =   1;
    a[1].den    =   1;
    a[1].val    =   1;

    fin >>  n;
    fin.close();

    for(int i=1;i<n;i++)
    {
        for(int j=(i+1);j<=n;j++)
        {
            if(gcd(i,j) ==  1)
            {
                a[index].num  =   i;
                a[index].den  =   j;
                a[index].val  =   (float)i/(float)j;
                ++index;
            }
        }
    }
    sort(a,a+index,pred);
    fstream fout("frac1.out",ios::out);

    for(int i=0;i<index;i++)
    {
        fout    <<  a[i].num    <<  "/" <<  a[i].den    <<  '\n';
    }

    fout.close();

    return 0;
}

