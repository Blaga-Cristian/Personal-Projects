#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int N = 1e5 + 9, Mod = 1e9 + 123;

int n;
int hsh[N];
vvi G1(N), G2(N);

mt19937 rng;

pii Dfs(int x, int p, vvi const& G)
{
    int ret = 1, dep = 0;

    vector<pii> rs;
    for(auto y : G[x])
        if(y != p)
        {
            rs.pb(Dfs(y, x, G));
            dep = max(dep, 1 + rs.back().ss);
        }

    for(auto [v, d] : rs)
        ret = (ret * ((hsh[dep] + v) % Mod)) % Mod;

    return {ret, dep};
}

vector<pii> c1, c2;
int w1[N], w2[N];

void Precalc(int x, int p, vvi const& G, int* w)
{
    w[x] = 1;
    for(auto y : G[x])
        if(y != p)
        {
            Precalc(y, x, G, w);
            w[x] += w[y];
        }
}

void Get_Centroid(int x, int p, vvi const& G, vector<pii>& c, int* w)
{
    int mx = n - w[x], hv = -1;
    for(auto y : G[x])
        if(y != p)
        {
            mx = max(mx, w[y]);
            if(hv == -1 || w[hv] < w[y])hv = y;
        }

    if(!c.empty() && c.back().ss > mx)c.clear();
    if(c.empty() || c.back().ss == mx)c.pb({x, mx});

    if(hv != -1 && mx >= n - w[x])Get_Centroid(hv, x, G, c, w);
}

void solve()
{
    c1.clear();
    c2.clear();

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        G1[i].clear();
        G2[i].clear();
    }

    int x, y;
    for(int i = 2; i <= n; ++i)
    {
        cin >> x >> y;
        G1[x].pb(y);
        G1[y].pb(x);
    }

    for(int i = 2; i <= n; ++i)
    {
        cin >> x >> y;
        G2[x].pb(y);
        G2[y].pb(x);
    }

    Precalc(1, 0, G1, w1);
    Precalc(1, 0, G2, w2);

    Get_Centroid(1, 0, G1, c1, w1);
    Get_Centroid(1, 0, G2, c2, w2);

    for(int i = 0; i <= n; ++i)hsh[i] = rng() % Mod;

//    for(int i = 1; i <= n; ++i)cout << w1[i] << ' ';
//    cout << '\n';
//    for(int i = 1; i <= n; ++i)cout << w2[i] << ' ';
//    cout << '\n';

//    for(auto e : c1)cout << e.ff << ' ';
//    cout << '\n';
//    for(auto e : c2)cout << e.ff << ' ';
//    cout << '\n';

    if(Dfs(c1[0].ff, 0, G1) == Dfs(c2[0].ff, 0, G2) || (
       c2.size() == 2 &&
        Dfs(c1[0].ff, 0, G1) == Dfs(c2[1].ff, 0, G2)))
            cout << "YES\n";
    else cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
