/*
ID  :   ruthrab1
TASK:   pprime
PROG:   pprime
LANG:   C++
*/
#include <iostream>
#include <fstream>
#define SIZE    100000001

using namespace std;

//One based Indexing
bool    Primes[SIZE];

int main()
{
    std::ios_base::sync_with_stdio(false);
    fstream fin("pprime.in",ios::in),fout("pprime.out",ios::out);
    long    long    int a,b;
    for(long    long    int i=0;    i<SIZE;i++) Primes[i]   =   1;
    fin >>  a   >>  b;
    fin.close();
    long    long    int upper_range =   (b/2);
    for(long    long    int index   =   2;  index   <= upper_range; index++)
    {
        if(Primes[index])
        {
            for(long    long    int val =   index+index;  val <   SIZE;   val+=index)
            {
                Primes[val] =   0;
            }
        }
    }

    for(;   a   <=  b;  a++)
    {
        if(Primes[a])
        {
            long    long    int rev =   0,tmp =   a;

            while(tmp)
            {
                rev =   ( (rev * 10)+tmp%10);
                tmp/=10;
            }

            if(rev  ==  a)  fout    <<  a   <<  '\n';
        }
    }
    fout.close();
    return 0;
}
