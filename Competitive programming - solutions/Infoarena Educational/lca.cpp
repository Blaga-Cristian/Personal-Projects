#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORR(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
//#define int long long
#define ll long long

using namespace std;
const string TASK("lca");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout

const int N = 1e5 + 9;

int n, q, dep[N], t[N], j[N];
vvi G(N);

void Dfs(int x = 1, int p = 0)
{
    dep[x] = dep[p] + 1;
    t[x] = p;

    if(dep[t[x]] - dep[j[t[x]]] == dep[j[t[x]]] - dep[j[j[t[x]]]])
        j[x] = j[j[t[x]]];
    else
        j[x] = t[x];

    for(auto y : G[x])
        if(y != p)
            Dfs(y, x);
}

int get_lca(int x, int y)
{
    if(dep[x] < dep[y])swap(x, y);

    while(dep[x] > dep[y])
        if(dep[j[x]] >= dep[y])x = j[x];
        else x = t[x];

    while(x != y)
    {
        if(j[x] != j[y])
        {
            x = j[x];
            y = j[y];
        }
        else
        {
            x = t[x];
            y = t[y];
        }
    }

    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    int f;
    FOR(i, 2, n)
    {
        cin >> f;
        G[f].pb(i);
    }

    Dfs();

    int x, y;
    FOR(i, 1, q)
    {
        cin >> x >> y;

        cout << get_lca(x, y) << '\n';
    }
    return 0;
}