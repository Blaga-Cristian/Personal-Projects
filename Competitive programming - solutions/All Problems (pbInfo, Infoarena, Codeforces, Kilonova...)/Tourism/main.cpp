#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define vl vector<ll>
using namespace std;
const int N = 1e5 + 9, Mod = 1e9 + 7;

ll n, m, q, cnt, ans[N], fr[N];
vvi G(N);


ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}

bool viz[N];
void Dfs(int x)
{
    viz[x] = true;
    cnt ++;

    for(auto y : G[x])
        if(!viz[y])
            Dfs(y);
}

int main()
{
    cin >> n >> m >> q;

    int x, y;
    FOR(i, 1, m)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    FOR(i, 1, n)
        if(!viz[i])
        {
            cnt = 0;
            Dfs(i);
            fr[cnt] ++;
        }

    for(int i = 1; i <= n; ++i)
        if(fr[i])
            for(int j = 1, val = i; j <= q; ++j, val = mul(val, i))
                ans[j] = add(ans[j], mul(fr[i], val));

    FOR(i, 1, q)cout << ans[i] << ' ';
    return 0;
}
