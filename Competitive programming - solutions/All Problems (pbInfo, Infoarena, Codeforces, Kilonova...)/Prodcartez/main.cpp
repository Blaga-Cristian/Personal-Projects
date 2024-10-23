#include <fstream>
#include <cmath>
#define ull unsigned long long int
using namespace std;
ifstream cin("produscartezian1.in");
ofstream cout("produscartezian1.out");
int n,m,v[30],b[30];
void afisare()
{
    for(int i=0;i<m;++i)cout<<b[i]+1<<" ";
    cout<<'\n';
}
void backtracking(int x)
{
    for(int i=0;i<n;++i)
    {
        b[x]=i;
        if(x==m-1)afisare();
        else backtracking(x+1);
    }
}
int main()
{
    int i;
    cin>>n>>m;
    backtracking(0);
    return 0;
}
