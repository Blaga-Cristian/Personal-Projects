#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
using namespace std;
const int N = 2e5 + 9;

int n;
multiset<ll> ms[N];
vector<vector<pii>> G(N);

void Dfs(int x = 1, int p = 0)
{
    if(G[x].size() == 1 && x != 1)
    {
        ms[x].insert(0);
        return;
    }

    for(auto [y, l] : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);

        ll v = *ms[y].rbegin();
        ms[y].erase(ms[y].find(v));
        ms[y].insert(v + 2 * l);

        if(ms[x].size() < ms[y].size())swap(ms[x], ms[y]);
        for(auto e : ms[y])ms[x].insert(e);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    int u, v, l;
    FOR(i, 2, n)
    {
        cin >> u >> v >> l;
        G[u].pb({v, l});
        G[v].pb({u, l});
    }

    Dfs();

    ll ans = 0;

    int shw = 0;
    for(auto e = ms[1].rbegin(); e != ms[1].rend(); ++e)
    {
        ++ shw;
        ans += *e;
        cout << ans << '\n';
    }

    for(; shw < n; ++ shw)cout << ans << '\n';
    return 0;
}
