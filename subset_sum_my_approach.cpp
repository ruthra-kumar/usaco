/*
ID  : ruthrab1
TASK: subset
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void Print(vector<int> &r)
{
    for(int j=0;j<r.size();j++)
    {
        cout    <<  r[j] << ' ';
    }
    cout    <<  '\n';
}

int main()
{
    fstream fin("subset.in",ios::in);
    int n;
    //cin >>  n;
    fin >>  n;
    fin.close();

    fstream fout("subset.out",ios::out);

    int partition_sum   =   (n*(n+1))/4;
    //if partition can be divided into two equal parts
    if( (n*(n+1))%4  == 0)
    {
        vector<long long int> bucket(((n*(n+1))),0);
        bucket[0]   =   bucket[1]   =   1;
        int tmp,index_limit =   1;

        //Print(bucket);
        //loop till 'n'
        for(int added_value=2;added_value<=n;++added_value)
        {
            //loop j from 1 to i

            //keep track of largest possible sum
            tmp =   0;

            //a buffer
            vector<long long int> new_bucket(bucket);
            for(int sum=0;sum<=index_limit;++sum)
            {
                //Print(bucket);

                new_bucket[ sum + added_value]    +=    bucket[sum];

                if(sum+added_value    >   index_limit)    tmp =   (sum  +   added_value);
                //cout    <<  i   << ' '  <<  index   <<  '\t';
                //Print(bucket);
            }
            if(tmp  >   index_limit)    index_limit =   tmp;
            bucket  =   new_bucket;

            //cout    <<  "added_val: "   <<  added_value <<  '\t';
            //Print(bucket);
        }

        fout    <<  bucket[partition_sum]/2   <<  '\n';
    }
    else
    {
        //If partition cannot be divided into equal parts then no solution can exist
        fout    <<  "0\n";
    }
    fout.close();
    return 0;
}
