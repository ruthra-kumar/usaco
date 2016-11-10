#include    <iostream>
#include    <queue>
#define SIZE    51

using namespace std;

int Map[SIZE][SIZE];
int Visited[SIZE][SIZE];

void    Traverse(int    x,int   y)
{


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
                Traverse(i,j);
            }
        }
    }

    return  0;
}
