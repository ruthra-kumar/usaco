/*
ID  : ruthrab1
TASK: wormhole
PROG: wormhole
LANG: C++
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;

vector< vector< pair<int,int>   >  >   con;
long long int Highest_x = 0;

void Gen_pair(vector<int> pool,vector<  pair<int,int>   > comb)
{
    //for(auto &X:pool)   cout    <<  X   << " ";
    //cout    <<  '\n';
    if(!pool.empty())
    {
        int i   =   0;
        for(unsigned int j=i+1;j   <   pool.size();    j++)
        {
            vector< pair<int,int>   >   t2(comb);
            //stores location of cordinates
            t2.push_back(  make_pair(pool[i],pool[j])    );
            //cout    <<  pool[i]   <<  " "   <<  pool[j] <<  '\n';
            vector<int> t1(pool);
            t1.erase(t1.begin());
            t1.erase(t1.begin()+j-1);

            Gen_pair(t1,t2);
        }
    }
    else{
            //cout    <<  '\n';
            con.push_back(comb);
    }
}

void Portal_comb(int n)
{
    //Keeps all the portals as vairables to choose from
    vector<int> Pool(n);
    for(int i=0;i<n;i++)    Pool[i]    =   i+1;

    //tmp storage to put partially generated pair combinations
    vector< pair<int,int>   > tmp;

    //Generate pairs
    Gen_pair(Pool,tmp);

}

bool Portal_at(vector<  pair<long long int,long long int>   >  co,   long long int a,long long int b)
{
    for(unsigned int i=0;   i   <   co.size();  i++)
    {
        if(   (co[i].first  ==   a)    && (co[i].second    ==  b)   )
        {
            return true;
        }
    }
    return false;
}

pair<long long int,long long int>   Get_pair(   vector< pair<long long int,long long int>   >   coord,
                                                vector< pair<int,int>   >   combo,
                                                long long int x,
                                                long long int y)
{
    pair<long long int,long long int> p;
    for(unsigned int    i=0;i   <   combo.size();    i++)
    {
        //if given coordinate os equal to one of the pair
        if( (coord[combo[i].first - 1].first ==  x)   && (  coord[ combo[i].first - 1 ].second   ==  y)  )
        {
            p   =   make_pair( (coord[combo[i].second - 1].first),   coord[combo[i].second - 1].second   );
            return p;
        }
        //checking second
        if( (coord[combo[i].second - 1].first ==  x)   && (  coord[ combo[i].second - 1 ].second   ==  y)  )
        {
            p   =   make_pair( (coord[combo[i].first - 1].first),   coord[combo[i].first- 1].second   );
            return p;
        }
    }
    return p;
}

vector< pair<long long int,long long int>   >    getList(vector< pair<long long int,long long int>   > cords    ,long long int   xlow,   long long int   xhigh,  long long int yaxis)
{
    vector< pair<long long int,long long int> > L;
    for(unsigned int    i=0;    i   <   cords.size();   i++)
    {
        if(  (cords[i].first   >  xlow    && cords[i].first   <  xhigh   )    &&  cords[i].second ==  yaxis   )
        {
            L.push_back(    cords[i]    );
        }
    }

    return L;
}

vector< pair<long long int,long long int>   >   LookforPortals(vector<  pair<long long int,long long int>   >   cords, long long int x, long long int y)
{

    vector< pair<long long int,long long int>   >   P;
    //Get all portals that are in same y axis and are to the right of current portal
    for(unsigned int    i   =   0;  i   <   cords.size();   i++)
    {
        if( cords[i].second ==  y &&    cords[i].first  >   x)
        {
            //P   =   make_pair(cords[i].first,cords[i].second);
            P.push_back(    cords[i]    );
            return  P;
        }
    }
    return P;
}

bool Check_loop(    vector< pair<long long int,long long int>   >   coord,
                    vector< pair<int,int>   >   combo)
{
    //check for same Y-Axis
    for(unsigned int i=0;    i   <   combo.size();   i++)
    {
        long long int Start   =   combo[i].first, End =   combo[i].second;
        //if there are in same Y Axis
        if(  coord[ Start-1 ].second   ==  coord[ End-1 ].second    )
        {
            //cout    <<  "Same Y-Axis";
            long long int YAXIS =   coord[  Start-1  ].second;
            long long int XLOW  =   coord[  Start-1 ].first,    XHIGH   =   coord[  End-1  ].first;
            //cout    <<  "\t"    <<  XLOW    << " "    <<  XHIGH   <<  '\n';
            //cout    <<  "("    <<  coord[Start-1].first<< ","    <<  coord[Start-1].second    <<")-(" <<coord[End-1].first<<  "," <<coord[End-1].second   <<  ")"<<  '\n';
            vector< pair<long long int,long long int>   > Portals_within   =   getList(coord,XLOW,XHIGH,YAXIS);

            //If there are some portals with this combination
            if(!Portals_within.empty())
            {
                //cout    <<  "\t\tPortals within:";
                //bool infinite   =   0;
                //go through all portals with this combination
                for(unsigned int portal=0;   portal   <   Portals_within.size();portal++)
                {
                    //cout    <<"\t("    <<  Portals_within[portal].first <<  ","  <<  Portals_within[portal].second   <<  ")\n";
                    pair<long long int, long long int>  P   =   Get_pair(   coord,combo,   Portals_within[portal].first,    Portals_within[portal].second   );
                    if(  ( P.first >=  XLOW    &&  P.first <=  XHIGH ) &&  P.second    ==  YAXIS   )
                    {
                        //if both entry and exit nodes are with the combination then it makes no difference to the original combination
                        //infinite    =   1;
                        return true;
                    }
                    /*
                    else
                    {
                        //if exit is out of the range then it will break the loop
                        //infinite    =   0;
                    }
                    */
                    //cout    <<"\t("<<  P.first <<  "-"    <<  P.second    <<  ")\n";
                }
                //return false;
            }
            //if no portals with in the combination then this is a infinite loop
            else
            {
                //cout<<"\t\tNo Portals within\t"    <<"("    <<  coord[Start-1].first    <<","  <<  coord[Start-1].second   <<")-(" <<  coord[End-1].first  <<  "," <<  coord[End-1].second <<  ")\n";
                return true;
            }
        }
        else
        {
            //Takes each coordinate as starting point
            for(unsigned int i=0;   i   <   coord.size();   i++ )
            {

                long long int X =   coord[i].first  ,   Y   =   coord[i].second;
                //long long int X =   coord[Start-1].first    ,   Y   =   coord[Start-1].second;
                long long int Start_x   =   X,Start_y   =   Y;
                while(  true    )
                {
                    //cout    <<  "\t\t"  <<  X   <<  "-" <<  Y   <<  '\n';
                    pair<long long int,long long int>   P   =    Get_pair(coord,combo,X,Y);

                    //look for portals in Y axis
                    vector<  pair<long long int,long long int>  >   Next_Portal =   LookforPortals(coord,P.first,P.second);

                    if(Next_Portal.empty())
                    {
                        break;
                    }
                    else
                    {
                        pair<long long int,long long int>   Exit_pair   =   *Next_Portal.begin();
                        if( Exit_pair.first ==  Start_x && Exit_pair.second ==  Start_y )
                        {
                            return true;
                        }
                        X   =   Exit_pair.first;
                        Y   =   Exit_pair.second;

                    }
                }

            }
        }
    }
    return false;
}

bool comp(const pair<long long int,long long int> &a,const pair<long long int,long long int> &b)
{
    if(a.first  ==  b.first)
        return a.second <   b.second;
    return a.first  <   b.first;
}

int main()
{
    fstream fin("wormhole.in",ios::in),fout("wormhole.out",ios::out);
    long long int n,x,y;
    vector< pair<long long int,long long int> > coords;
    int cnt =   0;
    fin >>  n;

    for(int i=0;    i   <   n;  i++)
    {
        fin >>  x   >>  y;
        if(x    >   Highest_x)  Highest_x   =   x;
        coords.push_back(   make_pair(x,y)   );
    }

    sort(coords.begin(),coords.end(),comp);
    fin.close();

    //Genrationg Portal combinations

    Portal_comb(n);

    for(unsigned int i=0;i   <   con.size(); i++ )
    {
        //vector< pair<int,int>   >   t   =   con[i];
        if( Check_loop( coords,con[i]  )   )
        {
        /*
            cout    <<  "Ok...";
            for(auto &Y:    con[i])
            {
                cout    <<"\t("<<  coords[Y.first-1].first <<  "," <<  coords[Y.first-1].second-76350726   <<  ")-("    <<  coords[Y.second-1].first <<  "," <<  coords[Y.second-1].second-76350726  <<  ")";

            }

            cout    <<  '\n';
            */
            cnt++;
        }
        /*
        else
        {
            cout    <<  "Fail...";
            for(auto &Y:    con[i])
            {
                cout    <<" ("<<  coords[Y.first-1].first <<  "," <<  coords[Y.first-1].second-76350726    <<  ")-("    <<  coords[Y.second-1].first <<  "," <<  coords[Y.second-1].second-76350726  <<  ") ";

            }
            cout    <<  '\n';
        }
        */
    }

    //Printing pairs
    /*
    for(auto &X:con)
    {
        for(auto &Y:X)
        {
            cout    <<  Y.first <<  " " <<  Y.second    <<  "\t";
        }
        cout    <<  '\n';
    }
    */

    fout    <<  cnt <<  '\n';
    //for(auto &X:coords) cout    <<  X.first <<  " " <<  X.second    <<  '\n';
    fout.close();
    return 0;
}
