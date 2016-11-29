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
//vector< pair<   vector<int>,    vector<int> > >  lst;
vector< vector<int> >  lst;

int SmallestFeed    =   1000000000;

bool    morethan(vector<int>    cur)
{
    for(int i=0;i<vit;i++)
    {
        if(cur[i]   <  v[i])
        {
            return  false;
        }
    }
    return  true;
}

void    addtoc(int index,vector<int>    &cr)
{
    for(int i=0;i<vit;i++)
    {
        cr[i]   +=  g[index][i];
    }
}
/*
void    PrintVec(vector<int>    a)
{
    for(auto &b:a)
    {
        cout    <<  b   <<  '\t';
    }
    cout    <<  '\n';
}
*/
void recursive_add(int   index,vector<int>  cur_sum,vector<int> cur_list)
{
    /*
    cout    <<  "Current Index: "   <<  index   <<  '\n';
    PrintVec(cur_list);
    PrintVec(cur_sum);
    cout    <<  '\n';
    */
    if(morethan(cur_sum)  ||  index   ==  feeds)
    {
        if(morethan(cur_sum))
        {
            int tmp =   0;
            for(int x:cur_sum)
            {
                tmp +=  x;
            }

            if(tmp    <=  SmallestFeed)
            {
                lst.clear();
                lst.push_back(cur_list);
                SmallestFeed    =   tmp;
            }
            //lst.push_back(  make_pair(cur_list,cur_sum));
        }
        else
        {
            return;
        }
    }
    else
    {
        //Add to current sequence
        addtoc(index,cur_sum);
        //Print(c);
        cur_list.push_back(index);

        for(int step    =   1;  (step+index)    <=   feeds   ;step++)
        {
            //cout    <<"Index: "  <<  index   <<  " Step :"  <<  step    <<  '\n';
            //change index and call recursively again
            recursive_add((index+step),cur_sum,cur_list);
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
        vector<int> a;
        vector<int> b(vit,0);
        recursive_add(start,b,a);
    }
    /*
    for(auto &X:lst)
    {
        for(auto &Y:X.first)
        {
            cout    <<  Y   <<  '\t';
        }
        cout<<'\n';
        int Sum =   0;
        for(auto &Z:X.second)
        {
            Sum +=  Z;
            cout    <<  Z   <<  '\t';
        }
        cout    <<  Sum ;
        cout    <<  "\n\n";
    }
    */
    fout    <<  lst[0].size()   <<  " ";
    for(int i=0;i<lst[0].size();i++)
    {
        fout    <<  ((lst[0][i])+1)   <<  " ";
    }
    fout    <<  '\n';
    fout.close();

    return 0;
}
