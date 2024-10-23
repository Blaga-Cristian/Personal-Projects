#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define VP vector<PI>
#define VVP vector<VP>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define ull unsigned ll
#define pb push_back
#define FAST_IN_OUT ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
ifstream fin("viteza.in");
ofstream fout("viteza.out");


const int N = 1e5 + 9, LG = 20;

int n, m, val[N];
VVI G(N);
PI v[N];

struct qs
{
    int a, b, k, ind, ans;

    qs() : ans(-1)
    {}
}queries[N];


int first[N], last[N], idx, aib[2 * N], t[N][LG], dep[N];
void update(int x, int val)
{
    for(; x <= 2 * n; x += x & -x)
        aib[x] += val;
}
int query(int x)
{
    int ret = 0;
    for(; x; x -= x & -x)
        ret += aib[x];
    return ret;
}
void Dfs(int x, int p = 0)
{
    first[x] = ++idx;

    dep[x] = dep[p] + 1;
    t[x][0] = p;
    for(int i = 1; (1 << i) <= n; ++i)
        t[x][i] = t[t[x][i - 1]][i - 1];

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);

    last[x] = ++idx;
}
int get_lca(int a, int b)
{
    if(dep[a] < dep[b])swap(a, b);

    for(int i = LG - 1; i >= 0; --i)
        if(dep[a] - (1 << i) >= dep[b])
            a = t[a][i];

    if(a == b)return a;

    for(int i = LG - 1; i >= 0; --i)
        if(t[a][i] != t[b][i])
        {
            a = t[a][i];
            b = t[b][i];
        }


    return t[a][0];
}

int main()
{
    fin >> n >> m;

    int a, b;
    FOR(i, 1, n - 1)
    {
        fin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    FOR(i, 1, n)
    {
        fin >> val[i];
        v[i].F = val[i];
        v[i].S = i;
    }
    sort(v + 1, v + n + 1);

    FOR(i, 1, m)
    {
        fin >> queries[i].a >> queries[i].b >> queries[i].k;
        queries[i].ind = i;
    }
    sort(queries + 1, queries + m + 1, [](qs a, qs b){return a.k < b.k;});

    Dfs(1);

    for(int p = 1, lca, i = 1; i <= m; ++i)
    {
        while(p <= n && v[p].F <= queries[i].k)
        {
            update(first[v[p].S], 1);
            update(last[v[p].S], -1);
            ++ p;
        }

        a = queries[i].a;
        b = queries[i].b;
        lca = get_lca(a, b);

        queries[i].ans = query(first[a]) + query(first[b]) - 2 * query(first[lca]) + (val[lca] <= queries[i].k);
    }

    sort(queries + 1, queries + m + 1, [](qs a, qs b){return a.ind < b.ind;});
    FOR(i, 1, m)fout << queries[i].ans << '\n';
    return 0;
}
