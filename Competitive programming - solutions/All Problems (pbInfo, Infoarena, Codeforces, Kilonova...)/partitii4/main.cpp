#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("partitiinumar4.in");
ofstream cout("partitiinumar4.out");
int n,m,v[100],b[100];
void afisare(int x)
{
    for(int i=0;i<=x;++i)cout<<b[i]<<' ';
    cout<<'\n';
}
void backtrack(int x,int ist,int sum)
{
    if(sum>n);
    else if(sum==n)afisare(x-1);
    else
    {
        for(int i=ist;i<m;++i)
        {
            b[x]=v[i];
            backtrack(x+1,i,sum+v[i]);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>v[i];
    sort(v,v+m);
    backtrack(0,0,0);
    return 0;
}
