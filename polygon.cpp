#include    <iostream>
#include    <vector>

#define SIZE    50

using namespace std;

int Evaluate(vector<int>    val,vector<char>    sym)
{
    int msum    =   0;
    
    
    
    return  msum;
}

int main()
{
    vector<int>     values;
    vector<char>    symbols;
    int n,v;
    char    c;

    cin >>  n;

    for(int i=0;i<n;i++)
    {
        cin >>  c   >>  v;
        values.push_back(v);
        symbols.push_back(c);
    }

    //remove one side
    for(unsigned int    i=0;i   <   symbols.size();i++)
    {
        vector<char>    side_removed(symbols);
        side_removed[i]  =   'r';
        Evaluate(values,cpy_symbols);
    }

    return 0;
}
