#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 109, Max = 200009, Mod = 1e9 + 7;

int n;
ll dp[N][N], cnt[N];

ll fact[Max], invfact[Max];
ll add(ll a, ll b)
{
    ll x = a + b;
    if(x >= Mod) x -= Mod;
    if(x < 0) x += Mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}
ll powlg(ll base, ll exp)
{
    ll ans = 1;
    while(exp)
    {
        if(exp & 1)
            ans = mul(ans, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return ans;
}
void Precalc()
{
    dp[0][0] = 1;

    fact[0] = fact[1] = 1;
    for(int i = 2; i < Max; ++i)
        fact[i] = mul(fact[i - 1], i);

    invfact[Max - 1] = powlg(fact[Max - 1], Mod - 2);
    for(int i = Max - 2; i >= 0; --i)
        invfact[i] = mul(invfact[i + 1], i + 1);
}
ll Comb(ll n, ll k)
{
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}


int main()
{
    cin >> n;
    Precalc();

    for(int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;

        for(int j = 0; j < n; ++j)cnt[j] = 0;

        for(int j = 0; j <= x; ++j)
            cnt[(i * j) % n] = add(cnt[(i * j) % n], Comb(x, j));

        for(int j = 0; j < n; ++j)
        {
            if(!cnt[j])continue;

            for(int p = 0; p < n; ++p)
                dp[i][(p + j) % n] = add(dp[i][(p + j) % n], mul(dp[i - 1][p], cnt[j]));
        }
    }

    cout << dp[n][0];
    return 0;
}
