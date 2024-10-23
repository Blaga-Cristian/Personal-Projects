#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("trumplandia.in");
ofstream cout("trumplandia.out");
const int maxn = 200005;
struct muchie
{
    int a,b,c;
};
bool f(muchie a,muchie b)
{
    return a.c<b.c;
}
muchie P[maxn],P_backup[maxn];
int n,m,q,x,k;
int TT[maxn],L[maxn],t2[maxn],RG[maxn],new_father;
int tata_sus[maxn<<1],cost_intern[maxn<<1];
vector<int> G[maxn<<1];
long long cost;
inline int Radacina(int x)
{
    int rad = x, y;
    while(TT[rad]!=0)rad = TT[rad];

    while(TT[x]!=0)
    {
        y = TT[x];
        TT[x] = rad;
        x = y;
    }
    return rad;
}
inline void Unire(int rx,int ry)
{
    if(RG[rx]>RG[ry])TT[ry]=rx,new_father=rx;
    else
    {
        TT[rx] = ry,new_father = ry;
        if(RG[rx] == RG[ry])RG[ry]++;
    }
}
inline void dfs(int nod,int tata,int niv)
{
    T2[nod]=tata;
    L[nod] = niv;
    for(int i=0;i<G[nod].size();++i)
    {
        dfs(G[nod][i],tata,niv+1);
        T[G[nod][i]]=nod;
    }
}
int main()
{
    int a,b,c;
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i)
    {
        RG[i]=1;
        TT[i]=i;
        tata_sus[i]=i;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>P[i].a>>P[i].b>>P[i].c;
        P_backup[i] = P[i];
    }
    sort(P+1,P+m+1,f);
    k=n;
    for(int i=1;i<=m;++i)
    {
        int rx = Radacina(P[i].a);
        int ry = Radacina(P[i].b);
        if(rx!=ry)
        {
            Unire(rx,ry);
            cost += P[i].c;
            G[++k].push_back(tata_sus[rx]);
            G[k].push_back(tata_sus[ry]);
            tata_sus[new_father] = k;
            cost_intern[k] = P[i].c;
        }
    }
    cout<<1LL*cost;
    dfs(k,0,0);
    while(q--)
    {
        cin>>i;
        cout<<(1LL*(cost+P_backup[i].c-cost_intern[lca(P_backup[i].a,P_backup[i].b)]));
    }
    return 0;
}
