/*
ID  :   ruthrab1
TASK:   milk3
PROG:   milk3
LANG:   C++
*/

#include    <queue>
#include    <vector>
#include    <fstream>

#define SIZE    20

using namespace std;

//1 based Indexing
bool quantity[SIZE+1];

struct buckets
{

    int a,b,c;

    buckets(int x,int y,int z)
    {
        a   =   x;
        b   =   y;
        c   =   z;
    }

    bool operator   ==  (const  buckets other)
    {
        return  ((a ==  other.a)   &&  (b ==  other.b)  &&  (c   ==  other.c));
    }
};

vector<buckets> cpy;

bool    Present(buckets &other)
{
    for(unsigned    int i=0;    i   <   cpy.size(); i++)
    {
        if(cpy[i]   ==  other)
            return  true;
    }
    return  false;
}

int main()
{
    int a,b,c;
    fstream fin("milk3.in",ios::in);

    fin >>  a   >>  b   >>  c;
    fin.close();

    queue<buckets> buffer;

    buckets start(0,0,c);

    buffer.push(start);
    cpy.push_back(start);
    
    //Simple DFS along with find method to remove duplicate states
    while(!buffer.empty())
    {
        buckets tmp =   buffer.front();


        //if bucket a is empty add it to found milk contents
        if(tmp.a    ==  0)
        {
            quantity[tmp.c] =   1;

        }

        //pour from c to a or b
        if(tmp.c    !=  0)
        {
            int pos_a   =   (a-tmp.a),pos_b =   (b-tmp.b);

            buckets next1(   (pos_a <=   tmp.c)?(tmp.a+pos_a):(tmp.a+tmp.c),
                            tmp.b,
                            (pos_a  <=  tmp.c)?(tmp.c   -   pos_a):(0)
                        );
            buckets next2(  tmp.a,
                            (pos_b  <=  tmp.c)?(tmp.b+pos_b):(tmp.b+tmp.c),
                            (pos_b  <=  tmp.c)?(tmp.c   -   pos_b):(0)
                        );

            if(!Present(next1))
            {
                buffer.push(next1);
                cpy.push_back(next1);
            }
            if(!Present(next2))
            {
                buffer.push(next2);
                cpy.push_back(next2);
            }
        }
        //pour from a to b or c
        if(tmp.a    !=  0)
        {
            int pos_b   =   (b  -   tmp.b),  pos_c   =   (c  -   tmp.c);

            buckets next1(  (pos_b  <=  tmp.a)?(tmp.a   -   pos_b):(0),
                            (pos_b  <=  tmp.a)?(tmp.b+pos_b):(tmp.b+tmp.a),
                            tmp.c
                            );

            buckets next2(  (pos_c  <=  tmp.a)?(tmp.a   -   pos_c):(0),
                            tmp.b,
                            (pos_c  <=  tmp.a)?(tmp.c+pos_c):(tmp.a+tmp.c)
                            );
            if(!Present(next1))
            {
                buffer.push(next1);
                cpy.push_back(next1);
            }
            if(!Present(next2))
            {
                buffer.push(next2);
                cpy.push_back(next2);
            }
        }
        //pour from b to a or c
        if(tmp.b    !=  0)
        {
            int pos_a   =   (a  -   tmp.a),  pos_c   =   (c  -   tmp.c);

            buckets next1(  (pos_a  <=  tmp.b)?(tmp.a+pos_a):(tmp.a+tmp.b),
                            (pos_a  <=  tmp.b)?(tmp.b   -   pos_a):(0),
                            tmp.c
                            );

            buckets next2(  (pos_c  <=  tmp.a)?(tmp.a   -   pos_c):(0),
                            tmp.b,
                            (pos_c  <=  tmp.a)?(tmp.c+pos_c):(tmp.c+tmp.a)
                            );
            if(!Present(next1))
            {
                buffer.push(next1);
                cpy.push_back(next1);
            }
            if(!Present(next2))
            {
                buffer.push(next2);
                cpy.push_back(next2);
            }

        }

        buffer.pop();

    }
    fstream fout("milk3.out",ios::out);
    bool first  =   1;
    for(int i=0;i<SIZE+1;   i++)
    {
        if(quantity[i]  && first)
        {
            fout    <<  i;
            first   =   0;
        }
        else    if(quantity[i])
        {
            fout    <<  ' ' <<i;
        }

    }
    fout    <<  '\n';
    fout.close();
    return 0;
}
