#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 9, Mod = 1e9 + 7;
const bool test_cases = false;

int n, k;

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


void solve()
{
    cin >> n >> k;

    int ans = 0;
    for(int i = 1; i <= min(n, k); ++i)
        ans = add(ans, mul(comb(n - 1, i - 1), arrj(k, i)));
    ans = mul(ans, fact[n - 1]);

    cout << ans << '\n';
}

int main()
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
