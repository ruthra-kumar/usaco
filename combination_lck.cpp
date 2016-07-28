/*
ID  : ruthrab1
TASK: combo
PROG: combo
LANG: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define ERR_RANGE   5
using namespace std;

//Starting position and whether to find low range or high range limit
int Err_range(int Start,int N,int op)
{
    //low range if '1'
    if(op ==    1)
        return ( (Start-2+N)%N   != 0    ) ?   (Start-2+N)%N   :   (N);

    //high range if '2'
    if(op ==  2)
        return (   (Start+3+N)%N   !=  0   )   ?   (Start+3+N)%N   :   (N);

    //Increment if '3'
    return (   (Start+1+N)%N   !=  0   )   ?   (Start+1+N)%N   :   (N);
}

int main()
{
    fstream fin("combo.in",ios::in),fout("combo.out",ios::out);
    int cnt,N;
    int a,b,c,d,e,f;
    int a_cnt   =   0,b_cnt =   0,c_cnt   =   0;
    int d_cnt   =   0,e_cnt =   0,f_cnt   =   0;

    int fk_low_a,fk_high_a,fk_low_b,fk_high_b,fk_low_c,fk_high_c;
    int mk_low_d,   mk_low_e,   mk_low_f,   mk_high_d,  mk_high_e,  mk_high_f;
    //read input
    fin >>  N;
    //farmer key
    fin >>  a   >>  b   >>  c  ;
    //master key
    fin >>  d   >>  e   >>  f;
    fin.close();
    //Initializing matrix to store unique keys
    cnt =   0;
    bool Keys[N+1][N+1][N+1];
    for(int i=0;i<N+1;i++)  for(int j=0;j<N+1;j++)  for(int k=0;k<N+1;k++)  Keys[i][j][k]   =   0;

    Keys[a][b][c]   =   Keys[d][e][f]   =   1;

    fk_high_a   =   Err_range(a,N,2);
    fk_high_b   =   Err_range(b,N,2);
    fk_high_c   =   Err_range(c,N,2);

    //key range for farmer key
    for(fk_low_a    =   Err_range(a,N,1) ;  a_cnt   <   ERR_RANGE   ;  fk_low_a = Err_range(fk_low_a,N,3)   ,   ++a_cnt  )
    {
        //cout    <<  a_cnt   <<  '\n';
        b_cnt   =   0;
        for(fk_low_b    =   Err_range(b,N,1) ;  b_cnt   <   ERR_RANGE ;  fk_low_b = Err_range(fk_low_b,N,3) ,   ++b_cnt  )
        {
            c_cnt   =   0;
            //cout    <<'\t'  <<  b_cnt   <<  '\n';
            for(fk_low_c    =   Err_range(c,N,1) ;  c_cnt   <   ERR_RANGE  ;  fk_low_c = Err_range(fk_low_c,N,3)    ,   ++c_cnt )
            {
                //cout    <<  "\t\t"    <<  c_cnt   <<  '\n';
                //cout    <<   "\t\t\t" <<  fk_low_a    <<  "," <<  fk_low_b    <<  "," <<  fk_low_c    <<'\n';
                if(!Keys[fk_low_a][fk_low_b][fk_low_c])
                {
                    Keys[fk_low_a][fk_low_b][fk_low_c]  =   1;
                }
            }
        }
    }

    mk_high_d   =   Err_range(d,N,2);
    mk_high_e   =   Err_range(e,N,2);
    mk_high_f   =   Err_range(f,N,2);
    //key range for master key
    for(mk_low_d    =   Err_range(d,N,1) ;  d_cnt   <   ERR_RANGE   ;  mk_low_d    = Err_range(mk_low_d,N,3)    ,   ++d_cnt  )
    {
        e_cnt   =   0;
        for(mk_low_e    =   Err_range(e,N,1) ;  e_cnt   <   ERR_RANGE;  mk_low_e    = Err_range(mk_low_e,N,3)   ,   ++e_cnt  )
        {
            f_cnt   =   0;
            for(mk_low_f    =   Err_range(f,N,1) ;  f_cnt   <   ERR_RANGE  ;  mk_low_f    = Err_range(mk_low_f,N,3) ,   ++f_cnt  )
            {
                if(!Keys[mk_low_d][mk_low_e][mk_low_f])
                {
                    Keys[mk_low_d][mk_low_e][mk_low_f]  =   1;
                }
            }
        }
    }

    for(int i=1;i<N+1;i++)  for(int j=1;j<N+1;j++)  for(int k=1;k<N+1;k++)  if( Keys[i][j][k] ){
        //cout    <<  i<<","<<j<<","<<k<<'\n';
        cnt++;
    };
    //checking input
    //cout    <<  a   <<  b   <<  c   <<  d   <<  e   <<  f;
    fout    <<  cnt <<'\n' ;

    return 0;
}
