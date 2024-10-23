#include <bits/stdc++.h>
#define pb push_back
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
using namespace std;
ifstream fin("pm2.in");
ofstream fout("pm2.out");
const int N = 109, Inf = 0x3f3f3f3f;

int n, k, v[N], sir[N], cnt, dp[N], dp_tarziu[N];
bool viz[N];
VVI G, GI;

void Dfs(int x)
{
    viz[x] = true;
    for(auto y : G[x])
        if(!viz[y])
            Dfs(y);

    sir[n - (++cnt) + 1] = x;
}

int main()
{
    fin >> n;

    G = GI = VVI(n + 1);
    //fill(dp, dp + n + 1, Inf);
    for(int i = 1; i <= n; ++i)fin >> v[i];

    for(int i = 1; i <= n; ++i)
    {
        int k, x;
        fin >> k;
        dp[i] = 0;
        for(int j = 1; j <= k; ++j)
        {
            fin >> x;
            G[x].pb(i);
            GI[i].pb(x);
        }
    }

    for(int i = 1; i <= n; ++i)
        if(!viz[i])
            Dfs(i);

    for(int i = 1; i <= n; ++i)
        for(auto y : G[sir[i]])
            dp[y] = max(dp[y], dp[sir[i]] + v[sir[i]]);

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, dp[i] + v[i]);
    fout << ans << '\n';

    for(int i = 1; i <= n; ++i)
        dp_tarziu[i] = ans - v[i];

    for(int i = n; i >= 1; --i)
        for(auto y : GI[sir[i]])
            dp_tarziu[y] = min(dp_tarziu[y], dp_tarziu[sir[i]] - v[y]);

    for(int i = 1; i <= n; ++i)
        fout << dp[i] << ' ' << dp_tarziu[i] << '\n';
    return 0;
}
