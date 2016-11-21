/*
ID  : ruthrab1
TASK: castle
PROG: castle
LANG: C++
*/
#include    <iostream>
#include    <fstream>
#include    <utility>
#include    <queue>
#include    <algorithm>
#include    <vector>
#define SIZE    51
using namespace std;

int MapOrigial[SIZE][SIZE];

int Map[SIZE][SIZE];
int Visited[SIZE][SIZE];
pair<   pair<int,int>,  char>   Wallsremoved[SIZE][SIZE];

int m,n,LargestRoom =   0,roomCount   =   1;

void    PrintVisited()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout    <<  Visited[i][j]   <<  ' ';
        }
        cout    <<  '\n';
    }
    cout    <<  '\n';
}


int BiggestRoom(vector< vector< pair<   int,int>    >   >   floor)
{
    int Max =   0;
    for(unsigned int i=0;   i<floor.size(); i++)
    {
        if(floor[i].size()  >   Max)
        {
            Max =   floor[i].size();
        }
    }
    return  Max;
}

vector< pair<   int,    int>    >   Connections(int x,int   y)
{
    vector< pair<   int,int>    >   Neighbours;

    //check west
    if((Map[x][y]    &   1)  ==  0)
    {
        if(y-1  >=  1)
        {
            if(Visited[x][y-1]  ==  0)
                Neighbours.push_back(make_pair(x,y-1));
        }
    }

    //check north
    if((Map[x][y]    &   2)  ==  0)
    {
        if(x-1  >=  1)
        {
            if(Visited[x-1][y]  ==  0)
                Neighbours.push_back(make_pair(x-1,y));
        }
    }

    //check east
    if((Map[x][y]    &   4)  ==  0)
    {
        if(y+1  <=  n)
        {
            if(Visited[x][y+1]  ==  0)
                Neighbours.push_back(make_pair(x,y+1));
        }
    }
    //check south
    if((Map[x][y]    &   8)  ==  0)
    {
        if(x+1  <=  m)
        {
            if(Visited[x+1][y]  ==  0)
                Neighbours.push_back(make_pair(x+1,y));
        }
    }

    return  Neighbours;
}

vector< pair<   int,int >   >   Traverse(int    x,int   y)
{
    vector< pair<   int,int >   >   rooms;
    queue<  pair<int,int>   >   buffer;
    vector< pair<int,int>   >   sample;

    buffer.push(    make_pair(x,y)    );

    while(!buffer.empty())
    {
        //PrintVisited();
        //cin.get();
        pair<int    ,int>   tmp =   buffer.front();
        vector< pair<   int,int >   >   Con =   Connections(tmp.first,tmp.second);

        if(Visited[tmp.first][tmp.second]   ==  0)
        {
            rooms.push_back(tmp);
        }
        //cout    <<  "(" <<  tmp.first   <<  "," <<  tmp.second  <<  ") -> \t";
        for(unsigned int i=0;   i<Con.size();  i++)
        {
           // cout    <<"("<<  Con[i].first    <<  "," <<  Con[i].second   << ")\t";
            if( (Visited[Con[i].first][Con[i].second]    ==  0)  &&  find(sample.begin(),sample.end(),Con[i])   ==  sample.end() )
            {
                buffer.push(Con[i]);
                sample.push_back(Con[i]);
            }
        }
        //cout    <<  '\n';

        Visited[tmp.first][tmp.second]   =   roomCount;
        buffer.pop();
    }
    roomCount++;

    return  rooms;
}

pair<int,int>    DFS()
{
    roomCount   =   1;

    vector< vector< pair<   int,int>    >   >   floor;
    for(int i=1;    i<=m;   i++)
    {
        for(int j=1;    j<=n;   j++)
        {
            if(Visited[i][j]    ==  0)
            {
                floor.push_back(Traverse(i,j));
            }
        }
    }

    return  make_pair(floor.size(),BiggestRoom(floor));

}
void    ResetMap()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            Map[i][j]   =   MapOrigial[i][j];
        }
    }

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            Visited[i][j]   =   0;
        }
    }
}

pair<   pair<int,int>,  char>    Removewalls(int x,int   y)
{
    vector< pair<   pair<   int,int>,   char>    >   Configs;
    vector<char>    Dir;

    //Remove wall on west
    if((Map[x][y]    &   1)  ==  1)
    {
        Map[x][y]   =   (Map[x][y]   -   1);
        Map[x][y-1] =   (Map[x][y-1]    -   4);

        Configs.push_back(  make_pair(DFS(),'W'));
    }

    ResetMap();

    //Remove wall on north
    if((Map[x][y]    &   2)  ==  2)
    {
        Map[x][y]   =   (Map[x][y]   -   2);
        Map[x-1][y] =   (Map[x-1][y]    -   8);

        Configs.push_back(  make_pair(DFS(),'N'));
    }

    ResetMap();

    //Remove wall on east
    if((Map[x][y]    &   4)  ==  4)
    {
        Map[x][y]   =   (Map[x][y]   -   4);
        Map[x][y+1] =   (Map[x][y+1]    -   1);

        Configs.push_back(  make_pair(DFS(),'E'));
    }

    ResetMap();

    //Remove wall on south
    if((Map[x][y]    &   8)  ==  8)
    {
        Map[x][y]   =   (Map[x][y]   -   8);
        Map[x+1][y] =   (Map[x+1][y]    -   2);

        Configs.push_back(  make_pair(DFS(),'S'));
    }

    ResetMap();

    pair<   pair<int,int>,  char>   High    =   make_pair(make_pair(0,0),'A');
    for(unsigned int i=0;   i   <   Configs.size(); i++)
    {
        if((Configs[i].first).second >=  (High.first).second)
        {

            if((Configs[i].first).second ==  (High.first).second)
            {
                if(Configs[i].second    ==  'N')
                {
                    High    =   Configs[i];
                }
            }
            else
            {
                High    =   Configs[i];
            }
        }
        //cout    << "("<<x<<","<<y<<") "<<  Configs[i].second << " " << (Configs[i].first).second<<'\n';
    }
    //  cout<<'\n';

    return  High;

}

void    Joinrooms()
{
    vector< pair<int,int>   >   flr;
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            //Remove walls
            /*
            Wallsremoved[i][j]  =   Removewalls(i,j);
            if( (Wallsremoved[i][j].first).second   >   LargestRoom)
            {
                LargestRoom =   (Wallsremoved[i][j].first).second;
            }
            */

            if((Map[i][j]    &   4)  ==  4)
            {
                cout    <<  "Wall " << i << " " <<  j   <<  '\n';
                Map[i][j]   =   Map[i][j]   -   4;
                Map[i][j+1] =   Map[i][j+1] -   1;

                //flr.push_back( DFS() );
                ResetMap();
            }

        }
    }

    for(auto &X:flr)
    {
        //cout    <<  X.first <<   " "    <<  X.second    <<  '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    fstream fin("castle.in",ios::in);
    fin >>  n   >>  m;

    for(int i=1;    i<=m;i++)
    {
        for(int j=1;    j<=n;   j++)
        {
            fin >>  Map[i][j];
            MapOrigial[i][j]    =   Map[i][j];
        }
    }
    fin.close();

    fstream fout("castle.out",ios::out);
    /*
    pair<int,int> ans   =   DFS();
    cout    <<  ans.first   <<'\n'  <<  ans.second  <<  '\n';
    fout    <<  ans.first   <<'\n'  <<  ans.second  <<  '\n';
    */
    Joinrooms();
    /*
    bool Found  =   false;

    for(int j=1;j<=n    &&  (!Found);j++)
    {
        for(int i=m;i>=1    &&  (!Found);i--)
        {
            if((Wallsremoved[i][j].first).second ==  LargestRoom)
            {
                //cout    <<  i   <<  " " <<  j   <<  '\n';
                fout    <<  (Wallsremoved[i][j].first).second   <<  '\n';
                fout    <<  i   <<  " " <<  j   <<  " " <<  Wallsremoved[i][j].second   <<  '\n';
                Found   =   true;
            }
        }
    }
    fout.close();
    /*
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout    <<"("<<  i   <<  "," <<  j   <<  ") " <<  Wallsremoved[i][j].second <<  " "
            <<  (Wallsremoved[i][j].first).second   <<  '\n';
        }
        cout    <<  '\n';
    }*/


    return 0;
}
