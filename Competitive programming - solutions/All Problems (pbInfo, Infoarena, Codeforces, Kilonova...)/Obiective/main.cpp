#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
ifstream cin("obiective.in");
ofstream cout("obiective.out");
const int N = 32009;
int n,m,a,b,q,x,y;
int comp[N],used[N];
int s[N][16],sus[N][16],ll[N],depth[N];
vector<vector<int>> G,G2;

vector<int> lvl,low;
vector<bool> instk;
stack<int> stk;
int idx;
int nrctc;

void Dfs(int x)
{
    stk.push(x);
    instk[x] = true;
    lvl[x] = low[x] = ++idx;

    for(auto i : G[x])
        if(lvl[i] == -1)
        {
            Dfs(i);
            low[x] = min(low[x],low[i]);
        }
        else
            low[x] = min(low[x],lvl[i]);

    if(low[x] == lvl[x])
    {
        nrctc++;
        while(true)
        {
            int k = stk.top();
            stk.pop();
            instk[k] = false;
            comp[k] = nrctc;
            if(k == x)break;
        }
    }
}
void Tarjan()
{
    for(int i = 1; i <= n; ++i)
        if(lvl[i] == -1)
            Dfs(i);
}


void dfs(int nod)
{
    used[nod] = 1;
    for(auto vecin : G2[nod])
        if(!ll[vecin] || depth[nod] < depth[ll[nod]])
            ll[vecin] = nod;

    for(auto vecin : G2[nod])
    {
        if(used[vecin])continue;
        s[vecin][0] = nod;
        depth[vecin] = depth[nod] + 1;
        Dfs(vecin);

        if(!ll[nod] || depth[ll[vecin]] < depth[ll[nod]])
            ll[nod] = ll[vecin];
    }
}

void precalc()
{
    for(int k = 1; 1 << k <= nrctc; ++k)
        for(int i = 1; i <= nrctc; ++i)
            s[i][k] = s[s[i][k-1]][k-1];

    for(int i = 1; i <= nrctc; ++i)
        sus[i][0] = ll[i];
    for(int k = 1; 1 << k <= nrctc; ++k)
        for(int i = 1; i <= nrctc; ++i)
            sus[i][k] = sus[sus[i][k-1]][k-1];
}
int get_lca(int x,int y)
{
    if(depth[x] > depth[y])
        swap(x,y);

    int dif = depth[y] - depth[x];
    for(int i = 15; i >= 0; --i)
        if(dif & (1<<i))
            y = s[y][i];

    for(int i = 15; i >= 0; --i)
        if(s[x][i] != s[y][i])
        {
            x = s[x][i];
            y = s[y][i];
        }

    if(x != y)
        x = s[x][0];

    return x;
}
int main()
{
    cin>>n>>m;
    G = vector<vector<int>>(n+1);
    low = lvl = vector<int>(n+1,-1);
    instk = vector<bool>(n+1);

    while(m--)
    {
        cin>>a>>b;
        G[a].push_back(b);
    }

    Tarjan();

    G2 = vector<vector<int>>(nrctc + 1);
    for(int i = 1; i <= n; ++i)
        for(auto j : G[i])
            if(comp[i] != comp[j])
            {
                G2[comp[i]].push_back(comp[j]);
                used[comp[j]] = 1;
            }

    int root;
    for(int i = 1; i <= nrctc; ++i)
    {
        sort(G2[i].begin(),G2[i].end());
        G2[i].erase(unique(G2[i].begin(),G2[i].end()),G2[i].end());
        if(used[i] == 0)
            root = i;
        used[i] = 0;
    }

    dfs(root);
    precalc();

    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        x = comp[x],y = comp[y];
        int lvl = depth[get_lca(x,y)];
        int ans = 0;
        for(int i = 15; i >= 0; --i)
            if(depth[sus[x][i]] > lvl)
            {
                x = sus[x][i];
                ans += (1<<i);
            }

        if(depth[x] > lvl)
            ans ++;
        cout<<ans<<'\n';
    }
    return 0;
}
