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
const int N = 5009, Mod = 998244353;

int n;
ll ans;
int s[N];
VVI G;

void Dfs(int v, int p = 0)
{
    vector<int> a;
    s[v] = 1;

    for(auto u : G[v])
    {
        if(u == p)continue;
        Dfs(u, v);

        a.pb(s[u]);
        s[v] += s[u];
    }

    vector<ll> dp(s[v]);
    ll cs = 0;
    for(auto x : a)
    {
        for(ll i = cs + x; i >= 0; -- i)
            for(ll pr = min(cs, i); pr >= max(0LL, i - x); -- pr)
            {
                ll j = i - pr;
                dp[i] = max(dp[i], dp[pr] + j * (cs - pr) + pr * (x - j));
            }
        cs += x;
    }

    ans += *max_element(dp.begin(), dp.end());
    dp.clear();
    a.clear();
}

void solve()
{
    cin >> n;

    G = VVI(n + 1);

    int p;
    FOR(i, 2, n)
    {
        cin >> p;
        G[i].pb(p);
        G[p].pb(i);
    }

    Dfs(1);

    cout << ans;
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
