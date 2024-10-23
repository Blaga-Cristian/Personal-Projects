#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 9, Inf = 0x3f3f3f3f;

int n, m, k, x, y, a, b, c, s, timp;
vector<vector<int>> G, apar;
int arr[4 * N], sz, t[N], v[4 * N];

void ETour(int x, int p)
{
    t[x] = p;
    arr[++sz] = x;
    apar[x].push_back(sz);

    for(auto y : G[x])
    {
        if(y == p)continue;

        ETour(y, x);

        arr[++sz] = x;
        apar[x].push_back(sz);
    }
}

struct info
{
    int lamax, ramax, sz;

    info operator + (info const& a)
    {
        return {max(lamax, a.lamax + sz),
                max(ramax + a.sz, a.ramax),
                sz + a.sz};
    }
};
info tree[4 * N];

void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        tree[nod] = {v[st], v[st], 1};
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}

info Query(int nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
        return tree[nod];

    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(nod << 1, st, mij, a, b);
    else if(a > mij)return Query(nod << 1 | 1, mij + 1, dr, a, b);
    return Query(nod << 1, st, mij, a, b) + Query(nod << 1 | 1, mij + 1, dr, a, b);
}

int QueryLA(int st, int dr)
{
    return Query(1, 1, sz, st, dr).lamax;
}
int QueryRA(int st, int dr)
{
    return Query(1, 1, sz, st, dr).ramax;
}

int main()
{
    freopen("sushi.in", "r", stdin);
    freopen("sushi.out", "w", stdout);

    cin >> n >> m;
    apar = G = vector<vector<int>>(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> k;
        for(int j = 1; j <= k; ++j)
        {
            cin >> x;
            G[i].push_back(x);
        }
    }

    ETour(1, 0);

    memset(v, -Inf, sizeof(v));
    for(int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> timp;
        int poz;
        if(y == t[x])poz = apar[x][0];
        else poz = apar[G[x][y - 1]].back() + 1;

        cout << poz;

        v[poz] = max(v[poz], timp);
    }

    Build(1, 1, sz);
    return 0;
}
