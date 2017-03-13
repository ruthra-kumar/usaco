/*
ID  : ruthrab1
TASK: subset
PROG: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("subset.in",ios::in);
    int n;
    fin >>  n;

    fin.close();

    fstream fout("subset.out",ios::out);

    int partition_sum   =   (n*(n+1))/4;
    if( (n*(n+1))%4  == 0)
    {
        int *F  =   new int[partition_sum+1];

        for(int i=0;i<(partition_sum+1);i++)    F[i]    =   0;

        F[1]    =   1;

        for(int i=2;i<=n;++i)
        {
            for(int j=partition_sum;j>0;--j)
            {
                if(j-i  >   0)
                {
                    F[j]   =    F[j]    +   F[j-i];
                }
            }
        }
        fout    <<  F[partition_sum]    <<  '\n';
        delete[] F;
    }
    else
    {
        fout    <<  "0\n";
    }
    fout.close();
    return 0;
}
