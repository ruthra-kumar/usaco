#include    <iostream>
#include    <stack>
#include    <vector>
#define SIZE    51

using namespace std;

int Map[SIZE][SIZE];
int Visited[SIZE][SIZE];

struct  Pos
{
    int x,y;
};

vector<Pos> Connections(int  x,int   y,int  m,int   n)
{
    vector<Pos> t;
    //North
    if(Map[x][y]    &   2   )
    {
        if(y-1  >=  1)
        {
            Pos p;
            p.x =   x;
            p.y =   y-1;
            t.push_back(p);
        }
    }
    //West
    if(Map[x][y]    &   1   )
    {
        if(x-1  >=  1)
        {
            Pos p;
            p.x =   x-1;
            p.y =   y;
            t.push_back(p);
        }
    }
    //East
    if(Map[x][y]    &   4   )
    {
        if(y+1  <=  n)
        {
            Pos p;
            p.x =   x;
            p.y =   y+1;
            t.push_back(p);
        }
    }
    //south
    if(Map[x][y]    &   8   )
    {
        if(x+1  <=  m)
        {
            Pos p;
            p.x =   x+1;
            p.y =   y;
            t.push_back(p);
        }
    }

    return t;
}

void    Traverse(int    x,int   y,int   m,int   n)
{
    stack<Pos>  lst;
    Pos cur;
    cur.x   =   x;
    cur.y   =   y;
    Visited[x][y]   =   1;
    lst.push(cur);

    while(!lst.empty())
    {
        Pos tmp =   lst.top();

        vector<Pos> l   =   Connections(tmp.x,tmp.y,m,n);

        for(unsigned    int i=0;    i   <   l.size();   i++)
        {
            //When not visited
            if(Visited[l[i].x][l[i].y]  ==  0)
            {
                lst.push(l);
            }
        }

        lst.pop();
    }
}

int main()
{
    int m,n;
    int rooms;
    cin >>   m   >>   n;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j  <=  n;   j++)
        {
            cin     >>  Map[i][j];
        }
    }

    for(int i=1;    i   <=  m;i++)
    {
        for(int j=1;    j   <=  n;  j++)
        {
            //Search if  not visited
            if(Visited[i][j]    ==  0)
            {
                rooms++;
                Traverse(i,j,m,n);
            }
        }
    }

    return  0;
}
