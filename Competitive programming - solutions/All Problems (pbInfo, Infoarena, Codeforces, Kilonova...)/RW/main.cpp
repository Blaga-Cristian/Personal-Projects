#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
using namespace std;
string f = "dmin2.";
ifstream fin(f+"in");
ofstream fout(f+"out");

int n,m,a,b,k,x,y;
bool mat[105][105];

int main()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        mat[a][b] = 1;
    }

    for(int k = 1;k <=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j && mat[i][k] == 1 && mat[k][j] == 1)
                    mat[i][j] = 1;
    for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=n;++j)
                cout<<mat[i][j]<<' ';
    return 0;
}
