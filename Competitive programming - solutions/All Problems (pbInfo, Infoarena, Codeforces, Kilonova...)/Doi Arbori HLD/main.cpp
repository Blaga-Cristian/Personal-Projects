#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define ll long long

using namespace std;
const int N = 2e5 + 9, Inf = 0x3f3f3f3f;

void Next();
void Get(int&);

int n, q;
vvi G(N);

set<pii> mst[N];

struct node
{
    int mn, dmn, amn;
};

node tree[2 * N];
pii iv[2 * N];

void Build()
{
    FOR(i, n, 2 * n - 1)iv[i] = {i - n + 1, i - n + 1};
    FORR(i, n - 1, 1)iv[i] = {iv[i << 1].ff, iv[i << 1 | 1].ss};

    FOR(i, 1, 2 * n - 1)tree[i].mn = tree[i].amn = tree[i].dmn = Inf;
}

void Update(int p, int v)
{
    p += n - 1;
    tree[p].mn = tree[p].amn = tree[p].dmn = v;

    for(; p > 1; p >>= 1)
    {
        if(p & 1)p ^= 1;///p e fiul stang

        tree[p >> 1].mn = min(tree[p].mn, tree[p ^ 1].mn);
        tree[p >> 1].amn = min(tree[p].amn, tree[p ^ 1].amn + iv[p].ss - iv[p].ff + 1);
        tree[p >> 1].dmn = min(tree[p].dmn + iv[p ^ 1].ss - iv[p ^ 1].ff + 1, tree[p ^ 1].dmn);
    }
}

int Query(int l, int r, int nod = 1, int st = 1, int dr = n)
{
    int ret = Inf;
    for(l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1)
    {
        if(l & 1)ret = min(ret, tree[l ++].mn);
        if(!(r & 1))ret = min(ret, tree[r --].mn);
    }
    return ret;
}

int Query_Asc(int il, int ir)
{
    int ret = Inf;
    for(int l = il + n - 1, r = ir + n - 1; l <= r; l >>= 1, r >>= 1)
    {
        if(l & 1)ret = min(ret, iv[l].ff - il + tree[l ++].amn);
        if(!(r & 1))ret = min(ret, iv[r].ff - il + tree[r --].amn);
    }
    return ret;
}

int Query_Dsc(int il, int ir)
{
    int ret = Inf;
    for(int l = il + n - 1, r = ir + n - 1; l <= r; l >>= 1, r >>= 1)
    {
        if(l & 1)ret = min(ret, ir - iv[l].ss + tree[l ++].dmn);
        if(!(r & 1))ret = min(ret, ir - iv[r].ss + tree[r --].dmn);
    }
    return ret;
}

int t[N], w[N], head[N], bot[N], dep[N], heavy_son[N], poz[N], sz;

void Dfs(int x, int p)
{
    w[x] = 1;
    t[x] = p;
    dep[x] = dep[p] + 1;

    heavy_son[x] = -1;
    for(auto y : G[x])
    {
        if(y == p)continue;

        Dfs(y, x);

        w[x] += w[y];
        if(heavy_son[x] == -1 || w[heavy_son[x]] < w[y])
            heavy_son[x] = y;
    }
}

void Decomp(int x, int hd)
{
    head[x] = hd;
    bot[hd] = x;
    poz[x] = ++sz;

    if(heavy_son[x] != -1)Decomp(heavy_son[x], hd);

    for(auto y : G[x])
        if(y != t[x] && y != heavy_son[x])
            Decomp(y, y);
}

bool is_on[N];
void Update(int x)
{
    is_on[x] = !is_on[x];
    for(int i = x; i; i = t[head[i]])
    {
        if(is_on[x])mst[i].insert({dep[x] - dep[i], x});
        else mst[i].erase(mst[i].find({dep[x] - dep[i], x}));

        Update(poz[i], (*mst[i].begin()).ff);
    }
}

int Answer(int x, int y)
{
    int add = dep[x] + dep[y];

    int ret = Inf;
    ret = min(Query_Asc(poz[x], poz[bot[head[x]]]),
            Query_Asc(poz[y], poz[bot[head[y]]]));

    for(; head[x] != head[y]; x = t[head[x]])
    {
        if(dep[head[x]] < dep[head[y]])swap(x, y);

        ret = min(ret, min(Query(poz[head[x]], poz[x]),
                           Query_Asc(poz[x], poz[bot[head[x]]])));
    }

    if(dep[x] > dep[y])swap(x, y);

    ret = min(ret, min(Query(poz[x], poz[y]),
                       Query_Asc(poz[y], poz[bot[head[y]]])));
    add -= 2 * dep[x];

    for(int i = x; i; i = t[head[i]])
        ret = min(ret, min(Query_Dsc(poz[head[i]], poz[i]) + dep[x] - dep[i],
                            Query_Asc(poz[i], poz[bot[head[i]]]) + dep[x] - dep[i]));

    return add + 2 * ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Get(n), Get(q);

    int x, y;
    FOR(i, 2, n)
    {
        Get(x), Get(y);
        G[x].pb(y);
        G[y].pb(x);
    }

    FOR(i, 1, n)mst[i].insert({Inf, -1});
    Dfs(1, 0);
    Decomp(1, 1);
    Build();

    int op;
    FOR(i, 1, q)
    {
        Get(op);

        if(op == 1)
        {
            Get(x);
            Update(x);
        }
        else
        {
            Get(x), Get(y);
            int res = Answer(x, y);
            if(res > 4 * n)cout << "-1\n";
            else cout << res << '\n';
        }
    }

    return 0;
}


const int Lim = 1000000;
int p =  Lim - 1;
char s[Lim];

void Next()
{
    if (++p == Lim)
        std::fread(s, 1, Lim, stdin), p = 0;
}

void Get(int &x)
{
    for (; s[p] < '0' || s[p] > '9'; Next());

    for (x = 0; s[p] >= '0' && s[p] <= '9'; Next())
        x = x * 10 + s[p] - '0';
}
