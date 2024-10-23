#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream cin("dijkstra.in");
ofstream cout("dijkstra.out");

const int Inf  = 0x3f3f3f3f;

int c[100][100];
int d[100];
bool s[101];
int n,p;
void ReadGraph();
void Dijkstra(int x,int d[]);
void Write();
int main()
{
    ReadGraph();
    Dijkstra(p,d);
    Write();
    return 0;
}
void ReadGraph()
{
    int a,b,val;
    cin>>n>>p;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i!=j)c[i][j]=Inf;
        }
    }
    while(cin>>a>>b>>val)
    {
        c[a][b] = c[b][a] = val;
    }
}
void Dijkstra(int x,int d[])
{
    s[x] = true;
    for(int i=1;i<=n;++i) d[i]= c[x][i];
    for(int k=1;k<n;++k)
    {
        int dmin = Inf;
        for(int y=1;y<=n;++y)
        {
            if(s[y] == 0 && d[y]< dmin)
            {
                dmin = d[y];
                x = y;
            }
        }
        s[x] = true;
        for(int y=1;y<=n;++y)
        {
            if( d[y] > d[x] + c[x][y])
                d[y] = d[x] + c[x][y];
        }
    }
}
void Write()
{
    for(int i=1;i<=n;++i)
    {

        cout<<s[i]<< ' ';
    }
}
