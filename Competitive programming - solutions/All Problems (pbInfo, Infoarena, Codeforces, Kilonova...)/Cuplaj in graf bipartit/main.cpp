#include <fstream>
#include <vector>
#include <cstring>
#define MAXN  10005
using namespace std;
ifstream cin("cuplaj.in");
ofstream cout("cuplaj.out");

int n,m,edges,a,b;
vector<vector<int>>sirad;
int l[MAXN], r[MAXN], u[MAXN];
int pairup(int n)
{
    if(u[n])return 0;
    u[n] = 1;

    for(auto i : sirad[n])
        if(!r[i])
    {
        l[n] = i;
        r[i] = n;
        return 1;
    }

    for(auto i : sirad[n])
        if(pairup(r[i]))
    {
        l[n] = i;
        r[i] = n;
        return 1;
    }

    return 0;
}
int main()
{
    cin>>n>>m>>edges;
    sirad = vector<vector<int>>(n+1);
    while(edges--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }

    int change = 1;
    while(change)
    {
        change = 0;
        memset(u,0,sizeof(u));
        for(int i=1;i<=n;++i)
            if(!l[i])
                change |= pairup(i);
    }
    int cuplaj = 0;
    for(int i=1;i<=n;++i)
        cuplaj += (l[i]>0);
    cout<<cuplaj<<'\n';
    for(int i=1;i<=n;++i)
        if(l[i] > 0)
            cout<<i<<' '<<l[i]<<'\n';
    return 0;
}
