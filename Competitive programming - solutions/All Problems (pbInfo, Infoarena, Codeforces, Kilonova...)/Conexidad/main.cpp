#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>
#define ff first
#define ss second
#define ll long long
using namespace std;
const string TASK("tairos");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const ll N = 109, D = 10009, Mod = 1e9 + 7;

ll n, d, cnt[N], dp[D];
ll cntd[N];
///cnt[dep] = cate frunze se afla la distanta dep
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

void Dfs(int x, int dep, int p = 0)
{
    if(G[x].size() == 1 && x != 1)cnt[dep] ++;
    cntd[dep] ++;

    for(auto y : G[x])
        if(y != p)
            Dfs(y, dep + 1, x);
}

int main()
{
    cin >> n >> d;

    int x, y;
    FOR(i, 2, n)
    {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    Dfs(1, 0);
    cntd[0] = 0;

    dp[0] = 1;
    for(int i = 0; i <= d; ++i)
        for(int j = 0; j <= n; ++j)
            if(i + j <= d)
                dp[i + j] = add(dp[i + j], mul(dp[i], cnt[j]));

    ll ans = 0;
    for(int i = max(0LL, d - n); i <= d; ++i)
        ans = add(ans, mul(dp[i], cntd[d - i]));

    cout << ans << '\n';
    return 0;
}
