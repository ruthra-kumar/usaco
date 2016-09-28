/*
ID  : ruthrab1
TASK: ariprog
PROG: ariprog
LANG: C++
*/
#include    <iostream>
#include    <fstream>

#define SIZE    125000

using namespace std;

//1 based indexing
bool pq[SIZE+1];

int main()
{
    fstream fin("ariprog.in",ios::in);
    int highest =   0;
    int tmp,m,n;
    bool found  =   0;
    long    long    int seq =   0;

    fin >>  n   >>  m;
    fin.close();
    
    //produce all (p2 + q2)w
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            tmp =   (i*i)+(j*j);
            if(!pq[tmp])
            {
                pq[  tmp   ]   =   1;
            }
        }
    }
    
    highest =   (m*m)+(m*m);
    
    fstream fout("ariprog.out",ios::out);
    
    /*
        Start searching for sequence a,a+b,a+2b,...
        
        First for loop is for difference
        Second for loop is for Starting position 
    
    */
    
    /*
    Note: 
        (incr) variable is put it first for loop so that 
        the sequences are found in smallest difference sequence first
        from the smallest starting position
    */
    
    for(int  incr    =   1;  (incr*(n-1))    <=  highest;  incr++)
    {
        for(int  start   =   0;  start+(incr*(n-1))   <=   highest;   start++)
        {
            
            int  cnt =   0;
            for(int  mul =   0;  mul <  n;  mul++)
            {
                if(start+(incr*mul)<=highest    &&  pq[start+(incr*mul)])
                {
                   cnt++;
                }
                else break;
            }
            
            // if Sequence of N elements present the print
            
            if(cnt   ==  n)
            {
                fout << start   <<  " "   <<    incr   <<  '\n';
                found   =   1;
            }
        }
    }
    
    if(!found)  fout    <<  "NONE"  <<  '\n';
    
    fout.close();
    return 0;
}