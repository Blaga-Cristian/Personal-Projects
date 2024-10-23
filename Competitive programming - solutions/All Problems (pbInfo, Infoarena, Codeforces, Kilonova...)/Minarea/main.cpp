#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define eb emplace_back
#define ll long long
#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
using namespace std;
const string TASK("sushi");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const int N = 1e5 + 9, V = 8009, Inf = 0x3f3f3f3f;
const bool test_cases = false;

int n, m, tour[2 * N], sz;
vvi G(N), app(N);

void Dfs(int x = 1, int p = 0)
{
    tour[++ sz] = x;

    for(auto y : G[x])
        if(y != p)
        {
            Dfs(y, x);
            tour[++ sz] = x;
        }
}

int tree[8 * N];
void Build(int nod = 1, int st = 1, int dr = sz)
{
    tree[nod] = -Inf;
    if(st == dr)return;
    int m = (st + dr) >> 1;
    Build(nod << 1, st, m);
    Build(nod << 1 | 1, m + 1, dr);
}
void Update(int p, int val, int nod = 1, int st = 1, int dr = sz)
{
    if(st == dr)
    {
        tree[nod] = val;
        return;
    }
    int m = (st + dr) >> 1;
    if(p <= m)Update(p, val, nod << 1, st, m);
    else Update(p, val, nod << 1 | 1, m + 1, dr);
    tree[nod] = max(tree[nod << 1] + dr - m, tree[nod << 1 | 1]);
}
int Query(int l, int r, int nod = 1, int st = 1, int dr = sz)
{
    if(l <= st && dr <= r)return tree[nod] + r - dr;
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return max(Query(l, r, nod << 1, st, m), Query(l, r, nod << 1 | 1, m + 1, dr));
}

void solve()
{
    cin >> n >> m;

    int k, x;
    FOR(i, 1, n)
    {
        cin >> k;
        FOR(j, 1, k)
        {
            cin >> x;
            G[i].pb(x);
        }
    }

    Dfs();

    map<pii, int> mp;
    FOR(i, 1, sz - 1)mp[{tour[i], tour[i + 1]}] = i;

    Build();

    int y, t;
    FOR(i, 1, m)
    {
        cin >> x >> y >> t;
        y = G[x][y - 1];
//        cout << "Placing at " << mp[{x, y}] << '\n';
        Update(mp[{x, y}], t);
    }

    FOR(i, 1, sz)app[tour[i]].pb(i);

    FOR(i, 1, n)
    {
        int ans = 0;

        ans = max(ans, Query(1, app[i][0]));
        if(app[i].back() != sz)ans = max(ans, Query(app[i].back() + 1, sz) + app[i][0] - 1);

        for(int j = 1; j < app[i].size(); ++j)
            ans = max(ans, Query(app[i][j - 1] + 1, app[i][j]));

        cout << ans << ' ';
    }
}

signed main()
{
    int t = 1;
    if(test_cases)cin >> t;
    while(t --)
        solve();
    return 0;
}
