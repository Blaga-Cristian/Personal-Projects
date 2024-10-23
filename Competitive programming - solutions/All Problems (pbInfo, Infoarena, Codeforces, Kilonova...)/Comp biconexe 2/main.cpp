#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
ifstream cin("biconex.in");
ofstream cout("biconex.out");

#define maxn 500010
#define mod 666013

int n, m, a, b, cc;
int p2[maxn], f[maxn], tata[maxn], sol[maxn], niv[maxn], d[maxn];
vector<int> v[maxn];

void citestegraf();
void df(int nod);
void ScriecompBi();
int main()
{
    citestegraf();

    p2[0] = 1;
    for(int i=1;i<=n;++i)
        p2[i] = (p2[i-1]*2)%mod;

    niv[1] = 1;
    df(1);

    ScriecompBi();
    return 0;
}
void citestegraf()
{
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
void df(int nod)
{
    if(f[nod])
        return;

    int fiu, cc=0;

    f[nod]=1;
    d[nod]=niv[nod];

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];

        if(fiu==tata[nod])
            continue;

        if(f[fiu])
        {
            d[nod]=min(d[nod], niv[fiu]);
            continue;
        }

        niv[fiu]=niv[nod]+1;
        tata[fiu]=nod;
        df(fiu);

        if(d[fiu]>=niv[nod])
            ++cc;
        d[nod]=min(d[nod], d[fiu]);
    }

    if(tata[nod]!=0)
        ++cc;

    sol[nod]=cc;
}
void ScriecompBi()
{
    for(int i=1;i<=n;++i)
        cout<<(p2[sol[i]]-2 + mod)%mod<<'\n';
}
