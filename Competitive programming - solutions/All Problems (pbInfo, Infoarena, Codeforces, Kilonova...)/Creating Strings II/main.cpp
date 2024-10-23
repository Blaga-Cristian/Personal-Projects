#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int V = 1e6 + 9, Mod = 1e9 + 7;

ll fact[V], invfact[V];
ll mul(ll a, ll b)
{
    return (a * b) % Mod;
}
ll power(ll base, ll exp)
{
    ll ret = 1;
    for(; exp; base = mul(base, base), exp >>= 1)
        if(exp & 1)
            ret = mul(ret, base);
    return ret;
}
void Precalc()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i < V; ++i)
        fact[i] = mul(fact[i - 1], i);

    invfact[V - 1] = power(fact[V - 1], Mod - 2);
    for(int i = V - 2; i >= 0; --i)
        invfact[i] = mul(invfact[i + 1], i + 1);
}

int n;
int cnt[30];
char s[V];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Precalc();
    cin.get(s, V);
    int ln = strlen(s);

    for(int i = 0; i < ln; ++i)
        cnt[s[i] - 'a']++;

    ll ans = fact[ln];
    for(int i = 0; i < 30; ++i)
        ans = mul(ans, invfact[cnt[i]]);

    cout << ans;
    return 0;
}
