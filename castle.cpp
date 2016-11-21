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

struct  Ans
{
    int x,y;
    int LSize;
    char    Wall;

};

int Map[SIZE][SIZE];
int Visited[SIZE][SIZE];
pair<int,char> Score[SIZE][SIZE];

int m,n,roomcount   =   1;
int LargestRoom =   0;
int NewLargestRoom  =   0;
int LargestRoomNo   =   0;
vector<int> Rooms;
vector<Ans> Sol;

void    PrintVisited()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout    <<  Visited[i][j] << " ";
        }
        cout    <<  '\n';
    }
    cout    <<  '\n';
    //cin.get();
}

void    FindBiggestRoom()
{
    for(unsigned int i=0;i<Rooms.size();    i++)
    {
        if(Rooms[i] >   LargestRoom)
        {
            LargestRoom =   Rooms[i];
            LargestRoomNo   =   i;
        }
    }
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

int Traverse(int    x,int   y)
{
    vector< pair<int,int>   >   sample;
    queue<  pair<int,int>   >   buffer;
    buffer.push(    make_pair(x,y)    );
    int roomSize    =   0;

    while(!buffer.empty())
    {
        pair<int,int>   tmp =   buffer.front();

        if(Visited[tmp.first][tmp.second]   ==  0)
        {
            roomSize++;
        }

        vector< pair<int,int>   >   cons    =   Connections(tmp.first,tmp.second);

        for(unsigned int i=0;   i<cons.size();  i++)
        {
            if((Visited[cons[i].first][cons[i].second]   ==  0)
               && (find(sample.begin(),sample.end(),cons[i])   ==  sample.end()) )
            {
                buffer.push(cons[i]);
                sample.push_back(cons[i]);
            }
        }

        Visited[tmp.first][tmp.second]   =   roomcount;
        buffer.pop();
    }
    return  roomSize;
}

void    DFS()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(Visited[i][j]    ==  0)
            {
                Rooms.push_back(Traverse(i,j));
                roomcount++;
            }
        }
    }
}

void    Joinrooms()
{
    //Remove wall only on east side
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<n;j++)
        {
            //If a wall is present on east side
            if((Map[i][j]    &   4)  ==  4)
            {
                if(Visited[i][j]    !=  Visited[i][j+1]
                   && ( (Rooms[Visited[i][j]]    +   Rooms[Visited[i][j+1]])    >   LargestRoom)    )
                {
                    Ans pos;
                    pos.x   =   i;
                    pos.y   =   j;
                    pos.Wall    =   'E';
                    pos.LSize   =   (Rooms[Visited[i][j]]    +   Rooms[Visited[i][j+1]]);

                    Sol.push_back(pos);

                    pos.x   =   i;
                    pos.y   =   j+1;
                    pos.Wall    =   'W';
                    pos.LSize   =   (Rooms[Visited[i][j]]    +   Rooms[Visited[i][j+1]]);

                    Sol.push_back(pos);
                }
            }

        }
    }

    //Remove wall only on south
    for(int i=m;i>=2;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if((Map[i][j]    &   2)  ==  2)
            {

                if(Visited[i][j]    !=  Visited[i-1][j]
                   && ( (Rooms[Visited[i][j]]    +   Rooms[Visited[i-1][j]])    >   LargestRoom)    )
                {
                    Ans pos;
                    pos.x   =   i;
                    pos.y   =   j;
                    pos.Wall    =   'N';
                    pos.LSize   =   (Rooms[Visited[i][j]]    +   Rooms[Visited[i-1][j]]);

                    Sol.push_back(pos);

                    pos.x   =   i-1;
                    pos.y   =   j;
                    pos.Wall    =   'S';
                    pos.LSize   =   (Rooms[Visited[i][j]]    +   Rooms[Visited[i-1][j]]);

                    Sol.push_back(pos);
                }
            }

        }
    }
}

int main()
{

    Rooms.push_back(0);
    ios_base::sync_with_stdio(false);
    fstream fin("castle.in",ios::in);
    fin >>  n   >>  m;

    for(int i=1;    i<=m;i++)
    {
        for(int j=1;    j<=n;   j++)
        {
            fin >>  Map[i][j];
        }
    }
    fin.close();

    DFS();

    FindBiggestRoom();

    Joinrooms();

    for(unsigned int i=0;   i<Sol.size();   i++)
    {
        if(Sol[i].LSize >   NewLargestRoom)
        {
            NewLargestRoom  =   Sol[i].LSize;
        }

        if(Sol[i].LSize >= Score[Sol[i].x][Sol[i].y].first )
        {

            if(Score[Sol[i].x][Sol[i].y].first  ==  Sol[i].LSize)
            {
                if(Sol[i].Wall  ==  'N')
                {
                    Score[Sol[i].x][Sol[i].y].first =   Sol[i].LSize;
                    Score[Sol[i].x][Sol[i].y].second =   Sol[i].Wall;
                }
                else    if(Sol[i].Wall  ==  'E')
                {
                    Score[Sol[i].x][Sol[i].y].first =   Sol[i].LSize;
                    Score[Sol[i].x][Sol[i].y].second   =   Sol[i].Wall;
                }
            }
            else
            {
                Score[Sol[i].x][Sol[i].y].first =   Sol[i].LSize;
                Score[Sol[i].x][Sol[i].y].second =   Sol[i].Wall;
            }

        }
    }

    fstream fout("castle.out",ios::out);
    fout    <<  roomcount-1   <<  '\n'    <<  LargestRoom <<  '\n';
    bool    Found   =   false;
    for(int i=1;i<=m    &&  (!Found);i++)
    {
        for(int j=n;j>=1    &&  (!Found);j--)
        {
            if(Score[j][i].first  ==  NewLargestRoom)
            {
                Found   =   true;
                fout    <<  NewLargestRoom  <<  '\n';
                fout    <<  j   << " "  <<  i <<  " " <<  Score[j][i].second    <<  '\n';
            }
        }
    }

    fout.close();

    return 0;
}
