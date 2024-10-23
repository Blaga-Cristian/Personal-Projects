#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define VPI vector<PI>
#define VVPI vector<VPI>
#define pb push_back
using namespace std;
const int N = 2e5 + 9, LG = 20, Inf = 0x3f3f3f3f;

int n, m, q, a, b, t[N][LG], dp[N][LG], dep[N];
VVPI G;

int dsu[N], sz[N];
int find(int x){return dsu[x] == 0 ? x : dsu[x] = find(dsu[x]);}
void unite(int x, int y)
{
    int rx = find(x), ry = find(y);
    if(rx == ry)return;
    if(sz[rx] > sz[ry])swap(rx, ry);
    dsu[rx] = ry;
    sz[ry] += sz[rx] + 1;
}

bool viz[N];
void Dfs(int x, int p = 0)
{
    viz[x] = true;

    for(int k = 1; k < LG; ++k)
    {
        dp[x][k] = max(dp[x][k - 1], dp[t[x][k - 1]][k - 1]);
        t[x][k] = t[t[x][k - 1]][k - 1];
    }

    for(auto aux : G[x])
    {
        int y = aux.F, c = aux.S;

        if(viz[y])continue;

        t[y][0] = x;
        dp[y][0] = c;
        dep[y] = dep[x] + 1;
        Dfs(y, x);
    }
}
int query(int a, int b)
{
    if(a == b)return 0;

    if(dep[a] < dep[b])swap(a, b);

    int ans = 0;
    for(int k = LG - 1; k >= 0; --k)
        if(dep[a] - (1 << k) <= dep[b])
        {
            ans = max(ans, dp[a][k]);
            a = t[a][k];
        }

    if(a == b)return ans;

    for(int k = LG - 1; k >= 0; --k)
        if(t[a][k] != t[b][k])
        {
            ans = max(ans, max(dp[a][k], dp[b][k]));
            a = t[a][k];
            b = t[b][k];
        }

    return max(ans, max(dp[a][0], dp[b][0]));
}


int main()
{
    cin >> n >> m >> q;
    G = VVPI(n + 1);
    for(int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        if(find(a) != find(b))
        {
            G[a].pb({b, i});
            G[b].pb({a, i});
            unite(a, b);
        }
    }


    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            Dfs(i);

    while(q --)
    {
        cin >> a >> b;
        if(find(a) != find(b))cout << "-1\n";
        else cout << query(a, b) << '\n';
    }
    return 0;
}
