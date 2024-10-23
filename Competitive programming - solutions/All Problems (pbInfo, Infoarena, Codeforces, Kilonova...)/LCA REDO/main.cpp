#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define int long long
//#define ll long long

using namespace std;
ifstream fin("lca.in");
ofstream fout("lca.out");
#define cin fin
#define cout fout

const int N = 1e5 + 9, LG = 20, P = 137, Mod = 1e9 + 7;

int n, q;
vvi G(N);


int t[N][LG], dep[N];
void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;
    t[x][0] = p;
    FOR(i, 1, LG - 1)
        t[x][i] = t[t[x][i - 1]][i - 1];

    for(auto y : G[x])
        Dfs(y, x);
}

int lca(int x, int y)
{
    if(x == y)return x;

    if(dep[x] < dep[y])swap(x, y);

    FORR(i, LG - 1, 0)
        if(dep[t[x][i]] >= dep[y])
            x = t[x][i];

    if(x == y)return x;

    FORR(i, LG - 1, 0)
        if(t[x][i] != t[y][i])
    {
        x = t[x][i];
        y = t[y][i];
    }

    return t[x][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    int p;
    FOR(i, 2, n)
    {
        cin >> p;
        G[p].pb(i);
    }

    Dfs();

    int x, y;
    FOR(i, 1, q)
    {
        cin >> x >> y;

        cout << lca(x, y) << '\n';
    }
    return 0;
}
