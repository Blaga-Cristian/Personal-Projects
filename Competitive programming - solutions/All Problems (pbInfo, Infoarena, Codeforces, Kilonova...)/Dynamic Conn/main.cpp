#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back

using namespace std;
const int N = 1e5 + 9;

int n, m, k, ans[N];

stack<pi> stk;
int dsu[N], sz[N], cc;

void Pre()
{
    FOR(i, 1, n)dsu[i] = 0;
    FOR(i, 1, n)sz[i] = 1;
    cc = n;
}

int find(int x){return (dsu[x] == 0) ? x : find(dsu[x]);}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if(x == y)return;
    if(sz[x] < sz[y])swap(x, y);///x e cel mai mare

    dsu[y] = x;
    sz[x] += sz[y];
    cc --;
    stk.push({x, y});///x devine tatal lui y
}

void rollback()
{
    auto[x, y] = stk.top();
    dsu[y] = 0;
    sz[x] -= sz[y];
    cc ++;
    stk.pop();
}


vector<pi> tree[4 * N];
void Update(int x, int y, int l, int r, int nod = 1, int st = 0, int dr = k)
{
    if(l <= st && dr <= r)
    {
        tree[nod].pb({x, y});
        return;
    }
    int m = (st + dr) >> 1;
    if(l <= m)Update(x, y, l, r, nod << 1, st, m);
    if(r > m)Update(x, y, l, r, nod << 1 | 1, m + 1, dr);
}

void Dfs(int nod = 1, int st = 0, int dr = k)
{
    int stk_sz = stk.size();
    for(auto [x, y] : tree[nod])unite(x, y);

    if(st == dr)ans[st] = cc;
    else
    {
        int m = (st + dr) >> 1;
        Dfs(nod << 1, st, m);
        Dfs(nod << 1 | 1, m + 1, dr);
    }

    while(stk.size() != stk_sz)rollback();
}

map<pi, int> times;

int main()
{
    cin >> n >> m >> k;
    Pre();

    int t = 0;
    int x, y;
    FOR(i, 1, m)
    {
        cin >> x >> y;
        if(x > y)swap(x, y);
        times[{x, y}] = t;
    }
    ++ t;

    int op;
    FOR(i, 1, k)
    {
        cin >> op >> x >> y;
        if(x > y)swap(x, y);
        if(op == 1)times[{x, y}] = t;
        else
        {
            Update(x, y, times[{x, y}], t - 1);
            times[{x, y}] = -1;
        }
        ++t;
    }

    for(auto e : times)
        if(e.ss != -1)
            Update(e.ff.ff, e.ff.ss, e.ss, t - 1);

    Dfs();

    FOR(i, 0, k)cout << ans[i] << ' ';
    return 0;
}
