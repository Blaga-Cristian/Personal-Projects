#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)

//#define int unsigned long long
using namespace std;
const int N = 1e5 + 9, K = 1e3 + 9, Mod = 1e9 + 7;
const bool test_cases = true;

int n, m, k;

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
ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

int fact[2 * N + 9], invfact[2 * N + 9];
void Precalc()
{
    fact[0] = 1;
    FOR(i, 1, 2 * N)fact[i] = mul(i, fact[i - 1]);

    invfact[2 * N] = PtLg(fact[2 * N], Mod - 2);
    FORR(i, 2 * N - 1, 0)invfact[i] = mul(i + 1, invfact[i + 1]);
}

ll comb(ll n, ll k)
{
    if(n < k)return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int ans[N];

int F(int x1, int y1, int x2, int y2)
{
    return comb(x2 - x1 + y2 - y1, x2 - x1);
}

void solve()
{
    cin >> n >> m >> k;

    vector<vector<int>> v;
    v.pb({n, m});

    int x, y;
    for(int i = 1; i <= k; ++i)
    {
        cin >> x >> y;
        v.pb({x, y});
    }

    sort(v.begin(), v.end());

    FOR(i, 0, v.size() - 1)ans[i] = 0;

    for(int i = 0; i < v.size(); ++i)
    {
        ans[i] = add(ans[i], F(1, 1, v[i][0], v[i][1]));
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i][0] <= v[j][0] && v[i][1] <= v[j][1])
                ans[j] = add(ans[j], -mul(ans[i], F(v[i][0], v[i][1], v[j][0], v[j][1])));
    }

    cout << ans[v.size() - 1] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Precalc();

    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
