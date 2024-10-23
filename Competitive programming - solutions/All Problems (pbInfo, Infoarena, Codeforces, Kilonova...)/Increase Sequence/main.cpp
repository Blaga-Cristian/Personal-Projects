#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const int N = 2009, K = 2009, Mod = 1e9 + 7;

int n, h, a[N], dp[N][K];

ll add(ll x, ll y)
{
    ll z = x + y;
    if(z >= Mod)z -= Mod;
    if(z < 0)z += Mod;
    return z;
}
ll mul(ll x, ll y)
{
    return (x * y) % Mod;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> h;
    FOR(i, 1, n)cin >> a[i];

    if(a[1] == h || a[1] == h - 1)dp[1][0] = 1;
    if(a[1] == h - 1)dp[1][1] = 1;
    FOR(i, 1, n)
    {
        ///a[i] + opened = h => opened = h - a[i]
        if(h - a[i] >= 0)
        {
            dp[i][h - a[i]] = add(dp[i][h - a[i]], dp[i - 1][h - a[i]]);///do nothing
            if(h - a[i] > 0)dp[i][h - a[i]] = add(dp[i][h - a[i]], dp[i - 1][h - a[i] - 1]);///create new segment
        }

        ///a[i] + opened + 1 = h => opened = h - a[i] - 1
        if(h - a[i] - 1 >= 0)
        {
            dp[i][h - a[i] - 1] = add(dp[i][h - a[i] - 1], mul(dp[i - 1][h - a[i]], (h - a[i]))); ///close a segment
            dp[i][h - a[i] - 1] = add(dp[i][h - a[i] - 1], dp[i - 1][h - a[i] - 1]); ///creez un segment de lungime 1
            if(h - a[i] - 1 > 0)dp[i][h - a[i] - 1] = add(dp[i][h - a[i] - 1], mul(dp[i - 1][h - a[i] - 1], (h - a[i] - 1)));
        }
    }

    cout << dp[n][0];
    return 0;
}
