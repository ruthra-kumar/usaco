#include <iostream>
#include <vector>

using namespace std;

int n,partition_sum ;
vector< vector<int> >   partitions;

bool Found(vector<int> Lst,int Val)
{
    for(unsigned int i=0;i<Lst.size();i++)
    {
        if(Lst[i]   ==  Val)    return  true;
    }
    return false;
}

bool Partition_found(vector<int> L)
{
    for(unsigned int i=0;i<partitions.size();i++)
    {
    }
}

void    Print(vector<int> Ls)
{
    cout    <<  "{ ";
    for(unsigned int i=0;i<Ls.size();i++)
    {
        cout    <<  Ls[i]   << " ";
    }
    cout    <<  "} ";
}

void    AddElement(int  Sum,int Start,vector<int> left_partition)
{
    if(!Found(left_partition,Start))
    {
        left_partition.push_back(Start);
        Sum +=  Start;

        if(Sum  ==  partition_sum)
        {


            vector<int> right_partition;
            //Generate right partition based on what's left in left partition
            for(int i=1;i<=n;i++)
            {
                if(!Found(left_partition,i))
                {
                    right_partition.push_back(i);
                }
            }

            Print(left_partition);
            cout    <<  " and " ;
            Print(right_partition);
            cout    << '\n';

        }
    }
    for(int Next=Start+1;Next<=n;Next++)
    {
        AddElement(Sum,Next,left_partition);
    }
}

int main()
{
    cin >>  n;
    if((n*(n+1))%4  !=  0)
    {
        cout    <<  0   <<  '\n';
    }
    else
    {
        partition_sum   =   (n*(n+1))/4;
        vector<int> left;
        for(int i=1;i<=n;i++)
        {
            AddElement(0,i,left);
        }
    }


    return 0;
}
