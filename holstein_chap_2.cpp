/*
ID  : ruthrab1
TASK: holstein
PROG: holstein
LANG: C++
*/
#include    <iostream>
#include    <vector>
#include    <utility>
#include    <fstream>

#define VITS    25
#define FEEDS   15

using namespace std;

int v[VITS],g[FEEDS][VITS];
int vit,feeds;
int sol_seq[FEEDS];
int sol_seq_size    =   1000000000;
int SmallestFeed    =   1000000000;

void    calculate_feeds(int st,vector<int> cur_list)
{
    if(st   ==   feeds)
    {
        //cout    <<  '\n'    <<  st  <<  '\n';

        int cur_sol[VITS];

        //initialize cur_sol
        for(int i=0;i<vit;i++)
        {
            cur_sol[i]  =   0;
        }


        //find the solution of current sequence
        for(unsigned int i=0;i<cur_list.size();i++)
        {
            for(int x=0;x<vit;x++)
            {
                cur_sol[x]  +=  g[cur_list[i]][x];
            }
        }

        //check if the feed is sufficient
        for(int i=0;i<vit;i++)
        {
            if(cur_sol[i]   <   v[i])
            {
                return;
            }
        }

        int tmp_sum =   0;
        //check if sequence yeilds a result
        for(int i=0;i<vit;i++)
        {
            tmp_sum +=  cur_sol[i];
        }

        if(cur_list.size()  <=  sol_seq_size)
        {
            //Special case
            if(sol_seq_size  ==  cur_list.size())
            {
                if(tmp_sum  <=   SmallestFeed)
                {
                    //Add it ot solution list
                    for(unsigned int i=0;i<cur_list.size();i++)
                    {
                        sol_seq[i]  =   cur_list[i];
                    }
                    sol_seq_size    =   cur_list.size();
                }
                return;
            }

            SmallestFeed    =   tmp_sum;

            //Add it ot solution list
            for(unsigned int i=0;i<cur_list.size();i++)
            {
                sol_seq[i]  =   cur_list[i];
            }
            sol_seq_size    =   cur_list.size();
        }

    }
    else
    {
        cur_list.push_back(st);
        for(int step=1;(st+step)<=feeds;step++)
        {
            calculate_feeds((st+step),cur_list);
        }
    }
}

int main()
{
    fstream fin("holstein.in",ios::in),fout("holstein.out",ios::out);
    fin >>  vit;
    for(int i=0;i<vit;i++)
    {
        fin >>  v[i];
    }
    fin >>  feeds;

    for(int i=0;i<feeds;i++)
    {
        for(int j=0;j<vit;j++)
        {
            fin >>  g[i][j];
        }
    }
    fin.close();

    for(int start=0;start<feeds;start++)
    {
        vector<int> l;
        calculate_feeds(start,l);
    }
    fout    <<  sol_seq_size;
    for(int i=0;i<sol_seq_size;i++)
    {
        fout    <<  " "    <<  (sol_seq[i]+1);
    }
    fout    <<  '\n';
    fout.close();

    return 0;
}
