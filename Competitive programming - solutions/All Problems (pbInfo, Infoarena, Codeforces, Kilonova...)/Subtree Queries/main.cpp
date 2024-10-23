#include <bits/stdc++.h>
#define PI pair<int, int>
#define F first
#define S second
#define VI vector<int>
#define VVI vector<VI>
#define ll long long
using namespace std;
const int N = 2e5 + 9, LG = 20;

int n, m, v[N], tour[2 * N], first[N], last[N], sz, a, b, op, s, x;
ll tree[8 * N];
VVI G;

void Dfs(int x, int p)
{
    tour[++sz] = x;
    first[x] = sz;

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);

    tour[++sz] = x;
    last[x] = sz;
}

void Build(int nod, int st, int dr)
{
    if(st == dr)
    {
        tree[nod] = v[tour[st]];
        return;
    }
    int mij = (st + dr) >> 1;
    Build(nod << 1, st, mij);
    Build(nod << 1 | 1, mij + 1, dr);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
void Update(int nod, int st, int dr, int poz, int val)
{
    if(st == dr)
    {
        tree[nod] = val;
        return;
    }
    int mij = (st + dr) >> 1;
    if(poz <= mij)Update(nod << 1, st, mij, poz, val);
    else Update(nod << 1 | 1, mij + 1, dr, poz, val);

    tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
}
ll Query(int nod, int st, int dr, int a, int b)
{
    if(a <= st && dr <= b)
        return tree[nod];

    int mij = (st + dr) >> 1;
    if(b <= mij)return Query(nod << 1, st, mij, a, b);
    else if(a > mij)return Query(nod << 1 | 1, mij + 1, dr, a, b);
    return Query(nod << 1, st, mij, a, b) + Query(nod << 1 | 1, mij + 1, dr, a, b);
}

int main()
{
    cin >> n >> m;
    G = VVI(n + 1);
    for(int i = 1; i <= n; ++i)cin >> v[i];
    for(int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }

    Dfs(1, 0);
    Build(1, 1, sz);

    while(m --)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> s >> x;
            Update(1, 1, sz, first[s], x);
            Update(1, 1, sz, last[s], x);
        }
        else
        {
            cin >> s;
            cout << (Query(1, 1, sz, first[s], last[s]) >> 1) << '\n';
        }
    }
    return 0;
}
