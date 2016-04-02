
#include <iostream>
#include <fstream>
#define MAXSIZE 10
using namespace std;

class matrix{
    char **b=NULL;
    int n;

public:

    matrix(int sz):n{sz}{   //base initializer
        b = new char*[n];
        for(int i=0;i<n;++i) b[i] = new char[n];
    }

    matrix(const matrix &m){      //copy constructor
        n = m.Size();
        b = new char*[n];
        for(int i=0;i<n;++i) b[i] = new char[n];

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                b[i][j] = m.Get(i,j);
            }
        }
    }

    void Set(int x,int y,char c){
        b[x][y] = c;
    }

    char Get(int x,int y) const{
        return b[x][y];
    }

    void Print(){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<b[i][j];
            }
            cout<<endl;
        }
    }

    int Size() const { return n; }

    bool operator==(matrix y){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(b[i][j] != y.Get(i,j)) return false;
            }
        }
        return true;
    }

    ~matrix(){
        for(int i=0;i<n;++i) delete[] b[i];
    }
};

matrix Rotate(matrix m){
    int S = m.Size();
    matrix x(S);
    int i,j;
    for(i=0;i<S;++i){
        for(j=0;j<S;++j){
            x.Set(j,(S-1-i),m.Get(i,j));
        }
    }

    return x;
}

matrix Reflect(matrix m){
    int S = m.Size();
    matrix x(S);
    int i,j;
    for(i=0;i<S;++i){
        for(j=0;j<S;++j){
            x.Set(i,(S-j-1),m.Get(i,j));
        }
    }
    return x;
}

int main(int argc,char *argv[]){
    fstream fin("transform.in",ios::in),fout("transform.out",ios::out);
    int N;
    char ch;
    fin>>N;
    matrix before(N),after(N);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            fin>>ch;
            before.Set(i,j,ch);
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            fin>>ch;
            after.Set(i,j,ch);
        }
    }

    if(Rotate(before) == after){
        cout<<1<<endl;
    }
    else if(Rotate(Rotate(before)) == after){
        cout<<2<<endl;
    }
    else if(Rotate(Rotate(Rotate(before))) == after){
        cout<<3<<endl;
    }
    else if(after == Reflect(before)){
        cout<<4<<endl;
    }
    else if( (after == Rotate(Reflect(before)))
            || (after == Rotate(Rotate(Reflect(before))))
            || (after == Rotate(Rotate(Rotate(Reflect(before))))) ){
        cout<<5<<endl;
    }
    else if(before == after){
        cout<<6<<endl;
    }
    else{
        cout<<7<<endl;
    }

    return 0;
}
