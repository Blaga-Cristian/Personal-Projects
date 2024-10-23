#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 5009, Mod = 1e9 + 7;
const bool test_cases = false;

ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod)x -= Mod;
    if(x < 0)x += Mod;
    return x;
}

ll mul(ll x, ll y)
{
    return (x * y) % Mod;
}

ll PtLg(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; exp >>= 1, base = mul(base, base))
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}

int fact[N], invfact[N];
void Precalc()
{
    fact[0] = 1;
    for(int i = 1; i < N; ++i)fact[i] = mul(i, fact[i - 1]);

    invfact[N - 1] = PtLg(fact[N - 1], Mod - 2);
    for(int i = N - 2; i >= 0; --i)invfact[i] = mul(i + 1, invfact[i + 1]);
}

ll comb(ll n, ll k)
{
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
ll arrj(ll n, ll k)
{
    return mul(fact[n], invfact[n - k]);
}


int n;
int a[5050];
int pw[5050];
int dp[5050][5050][2];

int bfs(int s, int e, bool child) {
    if (e == n) return 1;
    if (s > e) return 0;
    int& ret = dp[s][e][child];
    if (ret) return ret;
    ret = bfs(s + 1, e, 0);
    if (!child || a[e] < a[e + 1]) {
        ret = add(ret, mul(pw[e - s], bfs(s, e + 1, 1)));
    }
    return ret;
}


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    pw[0] = 1;
    for(int i = 1; i <= n; ++i)pw[i] = mul(pw[i - 1], 2);

    cout << bfs(1, 1, 0) << '\n';
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
