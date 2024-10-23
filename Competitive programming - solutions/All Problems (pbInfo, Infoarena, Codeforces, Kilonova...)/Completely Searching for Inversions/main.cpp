#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define VI vector<int>
#define VVI vector<VI>
#define VP vector<PI>
#define VVP vector<VP>
#define pb push_back
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define ull unsigned ll
using namespace std;
const bool has_test_cases = false;
const int N = 1e5 + 9, Mod = 998244353;

int n;
ull dp[N], cnt1[N], cnt0[N];
bool viz[N];
VVP G;

ull add(ull a, ull b)
{
    ull x = a + b;
    if(x >= Mod) x-= Mod;
    if(x < 0) x += Mod;
    return x;
}
void Dfs(int x = 1)
{
    viz[x] = true;
    dp[x] = cnt0[x] = cnt1[x] = 0;

    for(auto [y, v] : G[x])
    {
        if(!viz[y])Dfs(y);

        dp[x] = ((((dp[x] + dp[y]) % Mod + cnt1[x] * cnt0[y]) % Mod + (v == 0) * cnt1[x]) % Mod + (v == 1) * cnt0[y]) % Mod;
        cnt1[x] = (cnt1[x] + cnt1[y] + (v == 1)) % Mod;
        cnt0[x] = (cnt0[x] + cnt0[y] + (v == 0)) % Mod;
    }
}


void solve()
{
    cin >> n;

    G = VVP(n + 1);
    fill(viz + 1, viz + n + 1, false);
    fill(dp + 1, dp + n + 1, 0);
    fill(cnt0 + 1, cnt0 + n + 1, 0);
    fill(cnt1 + 1, cnt1 + n + 1, 0);

    int x, l, w;
    FOR(i, 1, n)
    {
        cin >> x;
        FOR(j, 1, x)
        {
            cin >> l >> w;
            G[i].pb({l, w});
        }
    }

    Dfs();

    cout << dp[1];
}

int main()
{
    FAST_IN_OUT

    int t = 1;
    if(has_test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
