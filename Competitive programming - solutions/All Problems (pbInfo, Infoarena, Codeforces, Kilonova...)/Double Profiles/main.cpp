#include <bits/stdc++.h>
#include <bits/extc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define ll long long

using namespace std;
using namespace __gnu_pbds;
const int N = 1e6 + 9;

int n, m;
ll xr[N], hsh[N];
vvi G(N);

mt19937_64 rnd;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i)xr[i] = rnd();

    int x, y;
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        G[x].pb(y);
        hsh[x] ^= xr[y];
        G[y].pb(x);
        hsh[y] ^= xr[x];
    }

    ll ans = 0;
    for(int x = 1; x <= n; ++x)
        for(auto y : G[x])
            if(x > y && (hsh[x] ^ hsh[y]) == (xr[x] ^ xr[y]))
                ans ++;

    cc_hash_table<ll, int> mp;
    for(int i = 1; i <= n; ++i)
    {
        ans += mp[hsh[i]];
        mp[hsh[i]] ++;
    }

    cout << ans << '\n';
    return 0;
}
