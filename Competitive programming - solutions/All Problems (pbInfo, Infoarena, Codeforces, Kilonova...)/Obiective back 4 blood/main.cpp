#include <fstream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
ifstream cin("obiective.in");
ofstream cout("obiective.out");
const int N = 32009,LG = 16;

int n,m,a,b,x,y;
int dep[N],in[N],out[N],anc[N][LG],lift[N][LG],timer;
bool viz[N];
vector<vector<int>>sirad;
vector<vector<int>>adt;

vector<int> low,lvl,coresp;
vector<bool> instk;
stack<int> stk;
int idx,ctare;
void extract(int x)
{
    ++ctare;
    while(true)
    {
        int node = stk.top();
        stk.pop();
        instk[node] = false;
        coresp[node] = ctare;
        if(node == x) break;
    }
}
void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    lvl[x] = low[x] = ++idx;

    for(auto i : sirad[x])
        if(lvl[i] == -1)
        {
            Dfs(i);
            low[x] = min(low[x],low[i]);
        }
        else if(instk[i]) low[x] = min(low[x],lvl[i]);

    if(lvl[x] == low[x])
        extract(x);
}
void tarjan()
{
    lvl = low = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);
    coresp = vector<int>(n+1);

    for(int i=1;i<=n;++i)
        if(lvl[i] == -1)
            Dfs(i);
}
void dfsT(int x,int p)
{
    viz[x] = true;
    dep[x] = dep[p] + 1;
    anc[x][0] = p;
    lift[x][0] = p;
    in[x] = ++timer;
    for(auto i : adt[x])
        if(viz[i])
            lift[i][0] = min(lift[i][0],x);
        else
            dfsT(i,x);
    out[x] = timer;
}

bool isanc(int u,int v)
{
    return in[u] <= in[v] && out[u] >= out[v];
}
int lca(int u,int v)
{
    if(dep[u] < dep[v])
        swap(u,v);
    if (isanc(v, u)) {
        return v;
    }
    for (int i = log2(dep[v]); i >= 0; --i) {
        if (anc[v][i] && !isanc(anc[v][i], u)) {
            v = anc[v][i];
        }
    }
    return anc[v][0];
}
int solve(int v,int d)
{
    if(dep[v] <= d)
        return 0;
    int res = 1;
    for(int i = log2(dep[v]); i >= 0; --i)
        if(dep[lift[v][i]] > d)
    {
        res += (1<<i);
        v = lift[v][i];
    }

    return res;
}
int main()
{
    cin>>n>>m;
    sirad = vector<vector<int>>(n+1);
    while(m--)
    {
        cin>>a>>b;
        sirad[a].push_back(b);
    }

    tarjan();

    for(int i = 1;i <= ctare; ++i)
        coresp[i] = ctare + 1 - coresp[i];
    adt = vector<vector<int>>(ctare+1);
    for(int i=1;i<=n;++i)
        for(auto j : sirad[i])
            if(coresp[i] != coresp[j])
                adt[coresp[i]].push_back(coresp[j]);

    for(int i = 1;i<= ctare;++i)
    {
        sort(adt.begin(),adt.end());
        adt.erase(unique(adt.begin(),adt.end()),adt.end());
    }

    for(int i =1;i<=ctare;++i)
        if(!viz[i])
            dfsT(i,0);

    for(int v = ctare; v > 0; --v)
        lift[anc[v][0]][0] = min(lift[anc[v][0]][0],lift[v][0]);

    for(int k = 1; k < LG; ++k)
        for(int i = 1;i <= ctare; ++i)
    {
        anc[i][k] = anc[anc[i][k-1]][k-1];
        lift[i][k] = lift[lift[i][k-1]][k-1];
    }

    int q;
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        u = coresp[u];
        v = coresp[v];

        int  l = lca(u,v);
        cout<<solve(u,dep[l])<<'\n';
    }
    return 0;
}
