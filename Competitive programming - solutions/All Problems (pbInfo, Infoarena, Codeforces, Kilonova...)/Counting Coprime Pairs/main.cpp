#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vpi vector<pii>
#define vvpi vector<vpi>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 9, LG = 20, Mod = 1e9 + 7;

int n, m, q, dep[N], sz[N];
int sum[N];
vvi G(N);

int t[N];
void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;
    t[x] = x;

    for(auto y : G[x])
    {
        if(y == p)continue;

        if(!t[y])
        {
            Dfs(y, x);
            if(t[y] != y)
                t[x] = t[y];
        }
        else if(dep[x] > dep[y])
            t[x] = y;
    }
}

int ST[2 * N][LG], tour[2 * N], first[N], idx;
void Prepare(int x = 1, int p = 0)
{
    tour[++ idx] = x;
    first[x] = idx;

    for(auto y : G[x])
        if(!first[y])
        {
            Prepare(y, x);
            tour[++ idx] = x;
        }
}
void Precalc()
{
    Prepare();

    for(int i = 1; i <= idx; ++i)ST[i][0] = tour[i];

    for(int k = 1; (1 << k) <= idx; ++k)
        for(int i = 1; i + (1 << k) - 1 <= idx; ++i)
        {
            ST[i][k] = ST[i][k - 1];
            if(dep[ST[i][k - 1]] > dep[ST[i + (1 << (k - 1))][k - 1]])
                ST[i][k] = ST[i + (1 << (k - 1))][k - 1];
        }
}
int lca(int x, int y)
{
    x = first[x], y = first[y];
    if(x > y)swap(x, y);
    int k = log2(y - x + 1);
    return dep[ST[x][k]] < dep[ST[y - (1 << k) + 1][k]] ?
            ST[x][k] :
            ST[y - (1 << k) + 1][k];
}

bool viz[N];
void Dfs1(int x = 1, int p = 0)
{
    viz[x] = true;
    sum[x] = sum[p] + (sz[x] > 1);

    for(auto y : G[x])
        if(!viz[y])
            Dfs1(y, x);
}

int pt[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    pt[0] = 1;
    for(int i = 1; i <= n; ++i)pt[i] = (2LL * pt[i - 1]) % Mod;

    int x, y;
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    Dfs(1);
    for(int i = 1; i <= n; ++i)sz[t[i]] ++;
    Precalc();
    Dfs1();

    cin >> q;
    for(int i = 1; i <= q; ++i)
    {
        cin >> x >> y;
        x = t[x], y = t[y];

        int v = t[lca(x, y)];

        cout << pt[sum[x] + sum[y] - 2 * sum[v] + (sz[v] > 1)] << '\n';
    }
    return 0;
}
