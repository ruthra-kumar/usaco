#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

#define vector_matrix(i,j,k) vector<vector<int>> k((i),vector<int>(j))
//  #define vector_matrix_ref(i,j,k) vector<vector<int>> &k((i),vector<int>(j))
using namespace std;

int na = 0,nb = 0,nc = 0;

void Print(vector<int> &Se)
{
    for(auto &x:Se) cout<<x<<" ";
        cout<<'\n';
}

void Nep_First(vector<int> &v,
                vector<vector<int>> &nep,
                vector<vector<int>> &first  )
{
    for(unsigned int i=0;   i<v.size(); ++i)
    {
        if(i < na)
        {
            if(nep[v[i]-1][0] == 0) first[v[i]-1][0] = i+1;
            ++nep[v[i]-1][0];
        }
        else if(i < (na+nb) )
        {
            if(nep[v[i]-1][1] == 0) first[v[i]-1][1] = i+1;
            ++nep[v[i]-1][1];
        }
        else
        {
            if(nep[v[i]-1][2] == 0) first[v[i]-1][2] = i+1;
            ++nep[v[i]-1][2];
        }
    }
}

void Print_first_nep(vector<vector<int>> &n,
                vector<vector<int>> &f)
{
    cout    <<  "NEP table: \n"  ;
    for(int i=0;    i<3;    i++)
    {
        for(int j=0;    j<3;    j++)
        {
            cout<< n[i][j] << " " ;
        }
        cout<<'\n';
    }

    cout    <<  "First table: \n"  ;

    for(int i=0;    i<3;    i++)
    {
        for(int j=0;    j<3;    j++)
        {
            cout << f[i][j] << " ";
        }
        cout<< '\n';
    }

    cout    <<  '\n';
}

bool not_sorted(vector<int> &v)
{
    int prev = 0;
    for(auto X:v)
    {
        if(prev > X) return true;
        prev = X;
    }
    return false;
}

void Next(int x, int y, vector<int> &s, vector<vector<int>> &n, vector<vector<int>> &f)
{
    --n[x][y];
    if(n[x][y] > 0 )
    {
        do
        {
            ++f[x][y];
        }while(s[ (f[x][y])-1 ] != x+1);
    }
}

void Pairs(vector<int> &sq, vector<vector<int>> &n,vector<vector<int>> &p)
{
    {
    for(int i=0;i<3;i++)
        for(int j=i+1;j<3;j++)
        {
            int M = min(n[i][j],n[j][i]);
            for(int z = 1 ; z <= M ;z++)
            {
                cout << p[j][i] << " " << p[i][j] << '\r'   <<  '\n';
                Next(i,j,sq,n,p);
                Next(j,i,sq,n,p);
            }
        }
    }
}

void Triples(vector<int> &sq,vector<vector<int>> &n, vector<vector<int>> &p)
{
    int M = 0;
    if(n[0][1] > 0)
    {
        M = n[0][1];
        for(int i = 1; i<=M ;i++)
        {
            cout<<  p[0][1] <<  " " <<  p[2][0] <<  '\r'    <<  '\n';
            cout<<  p[1][2] <<  " " <<  p[0][1] <<  '\r'    <<  '\n';
            Next(2,0,sq,n,p);
            Next(0,1,sq,n,p);
            Next(1,2,sq,n,p);
        }
    }
    else
    {
        M = n[1][0];
        for(    int i = 1;  i   <=  M;  i++    )
        {
            cout    <<  p[0][2] <<  " " << p[1][0]    <<  '\r'  <<  '\n';
            cout    <<  p[2][1] <<  " " << p[0][2]    <<  '\r'  <<  '\n';
            Next(1,0,sq,n,p);
            Next(2,1,sq,n,p);
            Next(0,2,sq,n,p);
        }
    }
}

int main(int argc,char *argv[])
{
    int N;

    int Total_exchange  =   0;
    //vector<vector<int>> NEP(3,vector<int>(3)),FIRST(3,vector<int>(3));
    vector_matrix(3,3,NEP);
    vector_matrix(3,3,FIRST);

    vector<pair<int,int>> exchanges;
    cin>>N;
    vector<int> seq(N);
    for(int i=0;i<N;i++)
    {
        cin>>seq[i];

        //individual value count
        (seq[i] == 1) ? ++na : (seq[i] == 2) ? ++nb : ++nc;
    }

    Nep_First(seq,NEP,FIRST);
    //Print_first_nep(NEP,FIRST);

    Total_exchange = min(NEP[0][1],NEP[1][0])+
                min(NEP[0][2],NEP[2][0])+
                min(NEP[1][2],NEP[2][1])+
                2*abs(NEP[0][1] - NEP[1][0]);
    cout    <<  Total_exchange  << '\r' << '\n';
    Pairs(seq,NEP,FIRST);
    //cout    <<  '\n';
    //Print_first_nep(NEP,FIRST);
    Triples(seq,NEP,FIRST);
    //cout    <<  '\n';
    //Print_first_nep(NEP,FIRST);

    return 0;
}
