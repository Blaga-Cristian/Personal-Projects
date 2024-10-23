#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<VI>
#define PI pair<int, int>
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back

using namespace std;
const int N = 1e5 + 9, LG = 20;

int n, q, tour[2 * N], sz, dep[N], ST[2 * N][LG], first[N];
VVI G(N);

void Dfs(int x, int p)
{
    tour[++sz] = x;
    first[x] = sz;

    for(auto y : G[x])
    {
        if(y == p)continue;

        dep[y] = dep[x] + 1;

        Dfs(y, x);

        tour[++sz] = x;
    }
}
void Precalc()
{
    Dfs(1, 0);

    for(int i = 1; i <= sz; ++i)
        ST[i][0] = tour[i];

    for(int k = 1; (1 << k) <= sz; ++k)
        for(int i = 1; i + (1 << k) - 1 <= sz; ++i)
            if(dep[ST[i][k - 1]] < dep[ST[i + (1 << (k - 1))][k - 1]])
                ST[i][k] = ST[i][k - 1];
            else
                ST[i][k] = ST[i + (1 << (k - 1))][k - 1];
}
int query(int a, int b)
{
    a = first[a], b = first[b];

    if(a > b)swap(a, b);

    int k = log2(b - a + 1);

    return dep[ST[a][k]] < dep[ST[b - (1 << k) + 1][k]] ? ST[a][k] : ST[b - (1 << k) + 1][k];
}

int main()
{
    cin >> n >> q;

    int a, b, c;
    FOR(i, 1, n - 1)
    {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    Precalc();

    while(q --)
    {
        cin >> a >> b >> c;
        int lca1 = query(a, b), lca2 = query(a, c), lca3 = query(b, c);

        if(dep[lca1] >= dep[lca2] && dep[lca1] >= dep[lca3])
            cout << lca1 << ' ' << dep[a] + dep[b] - 2 * dep[lca1] + dep[lca1] + dep[c] - 2 * dep[query(lca1, c)] << '\n';
        else if(dep[lca2] >= dep[lca1] && dep[lca2] >= dep[lca3])
            cout << lca2 << ' ' << dep[a] + dep[c] - 2 * dep[lca2] + dep[lca2] + dep[b] - 2 * dep[query(lca2, b)] << '\n';
        else if(dep[lca3] >= dep[lca1] && dep[lca3] >= dep[lca2])
            cout << lca3 << ' ' << dep[b] + dep[c] - 2 * dep[lca3] + dep[lca3] + dep[a] - 2 * dep[query(lca3, a)] << '\n';
    }
    return 0;
}
