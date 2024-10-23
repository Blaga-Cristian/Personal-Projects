#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
#define ff first
#define ss second
#define vvi vector<vi>
#define pb push_back
#define ll long long
#define vl vector<ll>

using namespace std;
const int N = 2e5 + 9, Mod = 1e9 + 7;
const bool test_cases = true;

ll n, k, a[N];

ll add(ll a, ll b)
{
    ll x = a + b;
    x %= Mod;
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

void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)cin >> a[i];

    ll sum = 0;
    for(int i = 1; i <= n; ++i)sum += a[i];

    ll mx = 0, cur = 0;
    for(int i = 1; i <= n; ++i)
    {
        cur = max(cur + a[i], a[i]);
        mx = max(mx, cur);
    }

    cout << add(add(sum, 0), mul(add(PtLg(2, k), -1), add(mx, 0))) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
