#include    <iostream>
#include    <queue>
#include    <stack>
#include    <vector>
#include    <utility>
#define SIZE    51

using namespace std;

int Map[SIZE][SIZE];
int CopyMap[SIZE][SIZE];
int Visited[SIZE][SIZE];

struct  Pos
{
    int x,y;
};

struct Possibility
{
    int x,y;
    char    Direction;

    Possibility()
    {
        x   =   y   =   0;
        Direction   =   'A';
    }
};

vector<Pos> Connections(int  x,int   y,int  m,int   n)
{
    vector<Pos> t;
    //North
    if((Map[x][y]    &   2   )   ==  0)
    {
        Pos p;
        p.x =   x-1;
        p.y =   y;

        if(Visited[p.x][p.y]    ==  0   &&   (p.x   >=  1)   )
            t.push_back(p);
    }
    //West
    if((Map[x][y]    &   1   )  ==  0)
    {
        Pos p;
        p.x =   x;
        p.y =   y-1;
        if(Visited[p.x][p.y]    ==  0   &&  (p.y >= 1 ) )
            t.push_back(p);

    }
    //East
    if((Map[x][y]    &   4   )   ==  0 )
    {

        Pos p;
        p.x =   x;
        p.y =   y+1;
        if(Visited[p.x][p.y]    ==  0   &&  (p.y    <=  m))
            t.push_back(p);

    }
    //south
    if((Map[x][y]    &   8   )  ==  0)
    {
        Pos p;
        p.x =   x+1;
        p.y =   y;
        if(Visited[p.x][p.y]    ==  0   &&  (p.x    <=  n))
            t.push_back(p);
    }

    return t;
}

vector<pair<int,int> > Traverse(int    x,int   y,int   m,int   n)
{
    queue<Pos>  lst;
    Pos cur;
    cur.x   =   x;
    cur.y   =   y;
    lst.push(cur);
    vector<pair<int,int> >    rooms;

    while(!lst.empty())
    {
        Pos tmp =   lst.front();
        vector<Pos> l   =   Connections(tmp.x,tmp.y,m,n);
        for(unsigned    int i=0;    i   <   l.size();   i++)
        {
            lst.push(l[i]);
        }

        //Mark Visited
        Visited[tmp.x][tmp.y]   =   1;

        //add to list to return
        rooms.push_back(    make_pair(tmp.x,tmp.y)    );
        lst.pop();
    }
    return  rooms;
}

vector<Pos> ConnectionsPossibilities(int  x,int   y,int  m,int   n)
{
    vector<Pos> t;
    //North
    if((CopyMap[x][y]    &   2   )   ==  0)
    {
        Pos p;
        p.x =   x-1;
        p.y =   y;

        if(Visited[p.x][p.y]    ==  0   &&   (p.x   >=  1)   )
            t.push_back(p);
    }
    //West
    if((CopyMap[x][y]    &   1   )  ==  0)
    {
        Pos p;
        p.x =   x;
        p.y =   y-1;
        if(Visited[p.x][p.y]    ==  0   &&  (p.y >= 1 ) )
            t.push_back(p);

    }
    //East
    if((CopyMap[x][y]    &   4   )   ==  0 )
    {

        Pos p;
        p.x =   x;
        p.y =   y+1;
        if(Visited[p.x][p.y]    ==  0   &&  (p.y    <=  m))
            t.push_back(p);

    }
    //south
    if((CopyMap[x][y]    &   8   )  ==  0)
    {
        Pos p;
        p.x =   x+1;
        p.y =   y;
        if(Visited[p.x][p.y]    ==  0   &&  (p.x    <=  n))
            t.push_back(p);
    }

    return t;
}

void    ResetVisited()
{
    for(int i=0;    i<SIZE; i++)
    {
        for(int j=0;    j<SIZE; j++)
        {
            Visited[i][j]   =   0;
        }
    }
}

void    ResetMap(int    n,int   m)
{
    for(int i=1;    i   <=  n;  i++)
    {
        for(int j=1;    j  <=  m;   j++)
        {
            CopyMap[i][j]   =   Map[i][j];
        }
    }
}

vector<pair<int,int> >    TraversePossibility(int   x,int   y,int   m,int   n)
{
    queue<Pos>  lst;
    Pos cur;
    cur.x   =   x;
    cur.y   =   y;
    lst.push(cur);
    vector<pair<int,int> >    rooms;

    while(!lst.empty())
    {
        Pos tmp =   lst.front();
        vector<Pos> l   =   ConnectionsPossibilities(tmp.x,tmp.y,m,n);
        for(unsigned    int i=0;    i   <   l.size();   i++)
        {
            lst.push(l[i]);
        }

        //Mark Visited
        Visited[tmp.x][tmp.y]   =   1;

        //add to list to return
        rooms.push_back(    make_pair(tmp.x,tmp.y)    );
        lst.pop();

    }
    return  rooms;
}

vector< vector< pair<int,int>   >   >    CheckPossibility(int m,int n)
{
    vector< vector< pair<int,int>   >   > lst;
    for(int i=1;    i<=n;   i++)
    {
        for(int j=1;    j<=m;   j++)
        {
            if(Visited[i][j]    ==  0)
            {
                lst.push_back(  TraversePossibility(i,j,m,n)  );
            }
        }
    }
    return  lst;
}

int Getsize(vector< vector< pair< int, int > > > lst)
{
    int Max = 0;

    for(unsigned int i=0;   i<lst.size();   i++)
    {
        if(lst[i].size()    >=  Max)
        {
            Max =   lst[i].size();
        }
    }

    return Max;
}

void    Permute(int m,int n)
{
    vector< pair<Possibility, vector< vector< pair<int,int>   >   > > > Possibilities;
    //Remove walls
    vector<int> walls{1,2,4,8};
    for(unsigned int index=0;   index    <  walls.size();   index++)
    {
        int wall    =   walls[index];

        //remove wall for each module
        for(int i=1;    i<=n;   i++)
        {
            for(int j=1;    j<=m;   j++)
            {
                if((CopyMap[i][j]    &   wall)   ==  wall)
                {
                    ResetMap(n,m);
                    ResetVisited();

                    Possibility tmp;

                    tmp.x   =   i;
                    tmp.y   =   j;

                    switch(wall)
                    {
                        case    1:
                            tmp.Direction   =   'W';
                        break;
                        case    2:
                            tmp.Direction   =   'N';
                        break;
                        case    4:
                            tmp.Direction   =   'E';
                        break;
                        case    8:
                            tmp.Direction   =   'S';
                        break;
                        default:break;
                    }

                    //REMOVE WALL IF PRESENT
                    CopyMap[i][j]   =   (CopyMap[i][j]   -   wall);

                    //Traverse the new possibility
                    Possibilities.push_back(make_pair(tmp,CheckPossibility(m,n)));
                }
            }
        }
    }

    for(unsigned int x=0;   x<Possibilities.size(); x++)
    {
        cout    << "("<<  (Possibilities[x].first).x <<  "," <<  (Possibilities[x].first).y <<  ") "  <<  (Possibilities[x].first).Direction <<
        " -> " <<  Getsize(Possibilities[x].second)   <<  '\n';
    }
}

int main()
{
    int m,n;
    int rooms   =   0;
    vector< vector< pair<int,int> > > roomSize;
    cin >>   m   >>   n;

    for(int i=1;    i   <=  n;  i++)
    {
        for(int j=1;    j  <=  m;   j++)
        {
            cin >>  Map[i][j];
        }
    }

    ResetMap(n,m);

    for(int i=1;    i   <=  n;  i++)
    {
        for(int j=1;    j   <=  m;  j++)
        {
            if(Visited[i][j]    ==  0)
            {
                rooms++;
                roomSize.push_back(Traverse(i,j,m,n));
            }
        }
    }

    //Start permutation
    Permute(m,n);

    return  0;
}
