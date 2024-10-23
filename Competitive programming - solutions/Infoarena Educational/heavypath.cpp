#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>
#define pb push_back
#define ll long long
//#define int long long
using namespace std;

const string TASK("heavypath");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;
const bool test_cases = false;

int n, m, v[N], t[N], head[N], heavy_son[N], w[N], NEXT_INDEX, dep[N], pos[N];
vvi G(N);

int tree[4 * N];
void Update(int p, int v, int nod = 1, int st = 1, int dr = n)
{
    if(st == dr)
    {
        tree[nod] = v;
        return;
    }
    int m = (st + dr) >> 1;
    if(p <= m)Update(p, v, nod << 1, st, m);
    else Update(p, v, nod << 1 | 1, m + 1, dr);

    tree[nod] = max(tree[nod << 1], tree[nod << 1 | 1]);
}
int Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    if(l <= st && dr <= r)return tree[nod];
    int m = (st + dr) >> 1;
    if(r <= m)return Query(l, r, nod << 1, st, m);
    else if(l > m)return Query(l, r, nod << 1 | 1, m + 1, dr);
    return max(Query(l, r, nod << 1, st, m), Query(l, r, nod << 1 | 1, m + 1, dr));
}


void Dfs(int x = 1, int p = 1)
{
    t[x] = p;
    dep[x] = dep[p] + 1;
    w[x] = 1;

    heavy_son[x] = -1;

    for(auto y : G[x])
        if(y != p)
        {
            Dfs(y, x);
            if(heavy_son[x] == -1 || w[heavy_son[x]] < w[y])heavy_son[x] = y;
            w[x] += w[y];
        }
}

void Build_Vec(int x = 1, int hd = 1)
{
    pos[x] = ++NEXT_INDEX;
    head[x] = hd;
    Update(pos[x], v[x]);

    if(heavy_son[x] != -1)Build_Vec(heavy_son[x], hd);

    for(auto y : G[x])
        if(y != t[x] && y != heavy_son[x])
            Build_Vec(y, y);
}

int Answer(int x, int y)
{
    int ret = -1;

    for(; head[x] != head[y]; x = t[head[x]])
    {
        if(dep[head[x]] < dep[head[y]])swap(x, y);
        ret = max(ret, Query(pos[head[x]], pos[x]));
    }

    if(dep[x] > dep[y])swap(x, y);
    ret = max(ret, Query(pos[x], pos[y]));

    return ret;
}

void solve()
{
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)cin >> v[i];

    int u, v;
    for(int i = 2; i <= n; ++i)
    {
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    Dfs();
    Build_Vec();

    int t, x, y;
    for(int i = 1; i <= m; ++i)
    {
        cin >> t >> x >> y;
        if(t == 0)Update(pos[x], y);
        else cout << Answer(x, y) << '\n';
    }
}

signed main()
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